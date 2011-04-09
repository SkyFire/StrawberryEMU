/*
 * Copyright (C) 2010-2011 Strawberry-Pr0jcts <http://www.strawberry-pr0jcts.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "headers.h"
#include "wdt.h"
#include "adt.h"
#include "MPQ.h"

#include <string>
#include <vector>

#include "MPQFile.h"
#include "FileLoader.h"
#include "DBCFile.h"

#ifdef WIN32
#include "direct.h"
#else
#include <sys/stat.h>
#endif

HANDLE localeMPQ[PATCH_REV_COUNT+1];
HANDLE WorldMPQ;
HANDLE ExpansionsMPQ[3];
map_id *map_ids;
uint16 *areas;
uint16 *LiqType;
uint32 maxAreaId;

char output_path[128] = ".";
char input_path[128] = ".";

enum Extract
{
    EXTRACT_MAP = 1,
    EXTRACT_DBC = 2
};

// This option allow limit minimum height to some value (Allow save some memory)
bool  CONF_allow_height_limit = true;
float CONF_use_minHeight = -500.0f;

// This option allow use float to int conversion
bool  CONF_allow_float_to_int   = true;
float CONF_float_to_int8_limit  = 2.0f;      // Max accuracy = val/256
float CONF_float_to_int16_limit = 2048.0f;   // Max accuracy = val/65536
float CONF_flat_height_delta_limit = 0.005f; // If max - min less this value - surface is flat
float CONF_flat_liquid_delta_limit = 0.001f; // If max - min less this value - liquid surface is flat

#define ARG_MAP "--map"
#define ARG_NOMAP "--nomap"
#define ARG_DBC "--dbc"
#define ARG_NODBC "--nodbc"

bool FileExists( const char* FileName )
{
    FILE *fp = fopen(FileName,"r");
    if( fp ) 
    {
        fclose(fp);
        return true;
    } 
    return false;
}

void CreateDir( const std::string& Path )
{
#ifdef _WIN32
    _mkdir(Path.c_str());
#else
    mkdir(Path.c_str(), 0777);
#endif
}

void Usage(char* prg)
{
    printf(
        "Usage:\n"\
        "-i set input path\n"
        "-o set output path\n");
    exit(1);
}

void HandleArgs(int argc, char * arg[])
{
    for(int c = 1; c < argc; ++c)
    {
        // i - input path
        // o - output path
        if(arg[c][0] != '-')
            Usage(arg[0]);

        switch(arg[c][1])
        {
            case 'i':
                if(c + 1 < argc)
                    strcpy(input_path, arg[(c++) + 1]);
                else
                    Usage(arg[0]);
                break;
            case 'o':
                if(c + 1 < argc)
                    strcpy(output_path, arg[(c++) + 1]);
                else
                    Usage(arg[0]);
                break;
        }
    }
}

int ReadBuild(int locale)
{
    std::string path = output_path;
    path += "/dbc/";

    // include build info file also
    std::string filename = std::string("component.wow-")+langs[locale]+".txt";
    //printf("Read %s file... ", filename.c_str());
	
    CreateDir(path);
    ExtractFileToHardDrive(localeMPQ[0], filename.c_str(), (std::string(path) + filename).c_str());
	
    std::string text;
    std::string temp;
	
    std::ifstream fichier((std::string(path) + filename).c_str(), std::ios::in);
    if(!fichier)
        assert(false && "Error when loading component.wow-...");
    while(fichier)
    {
        fichier >> temp;
        text += temp;
    }
	
    size_t pos = text.find("version=\"");
    size_t pos1 = pos + strlen("version=\"");
    size_t pos2 = text.find("\"",pos1);
    if (pos == text.npos || pos2 == text.npos || pos1 >= pos2)
    {
        printf("Fatal error: Invalid  %s file format!\n", path + filename.c_str());
        exit(1);
    }
	
    std::string build_str = text.substr(pos1,pos2-pos1);
	
    int build = atoi(build_str.c_str());
    if (build <= 0)
    {
        printf("Fatal error: Invalid  %s file format!\n", path + filename.c_str());
        exit(1);
    }
	
    return build;
}

uint32 ReadMapDBC()
{
    printf("Read Map.dbc file... ");
    DBCFile dbc("DBFilesClient\\Map.dbc");
    
    if(!dbc.open())
    {
        printf("Fatal error: Invalid Map.dbc file format!\n");
        exit(1);
    }
    
    size_t map_count = dbc.getRecordCount();
    map_ids = new map_id[map_count];
    for(uint32 x = 0; x < map_count; ++x)
    {
        map_ids[x].id = dbc.getRecord(x).getUInt(0);
        strcpy(map_ids[x].name, dbc.getRecord(x).getString(1));
    }
    printf("Done! (%u maps loaded)\n", map_count);
    return map_count;
}

void ReadAreaTableDBC()
{
    printf("Read AreaTable.dbc file...");
    DBCFile dbc("DBFilesClient\\AreaTable.dbc");
    
    if(!dbc.open())
    {
        printf("Fatal error: Invalid AreaTable.dbc file format!\n");
        assert(false);
    }
    
    size_t area_count = dbc.getRecordCount();
    size_t maxid = dbc.getMaxId();
    areas = new uint16[maxid + 1];
    memset(areas, 0xff, (maxid + 1) * sizeof(uint16));
    
    for(uint32 x = 0; x < area_count; ++x)
        areas[dbc.getRecord(x).getUInt(0)] = dbc.getRecord(x).getUInt(3);
    
    maxAreaId = dbc.getMaxId();
    
    printf("Done! (%u areas loaded)\n", area_count);
}

void ReadLiquidTypeTableDBC()
{
    printf("Read LiquidType.dbc file...");
    DBCFile dbc("DBFilesClient\\LiquidType.dbc");
    if(!dbc.open())
    {
        printf("Fatal error: Invalid LiquidType.dbc file format!\n");
        exit(1);
    }
    
    size_t LiqType_count = dbc.getRecordCount();
    size_t LiqType_maxid = dbc.getMaxId();
    LiqType = new uint16[LiqType_maxid + 1];
    memset(LiqType, 0xff, (LiqType_maxid + 1) * sizeof(uint16));
    
    for(uint32 x = 0; x < LiqType_count; ++x)
        LiqType[dbc.getRecord(x).getUInt(0)] = dbc.getRecord(x).getUInt(3);
    
    printf("Done! (%u LiqTypes loaded)\n", LiqType_count);
}

// Map file format data
static char const* MAP_MAGIC         = "MAPS";
static char const* MAP_VERSION_MAGIC = "v1.1";
static char const* MAP_AREA_MAGIC    = "AREA";
static char const* MAP_HEIGHT_MAGIC  = "MHGT";
static char const* MAP_LIQUID_MAGIC  = "MLIQ";

struct map_fileheader
{
    uint32 mapMagic;
    uint32 versionMagic;
    uint32 buildMagic;
    uint32 areaMapOffset;
    uint32 areaMapSize;
    uint32 heightMapOffset;
    uint32 heightMapSize;
    uint32 liquidMapOffset;
    uint32 liquidMapSize;
};

#define MAP_AREA_NO_AREA      0x0001

struct map_areaHeader
{
    uint32 fourcc;
    uint16 flags;
    uint16 gridArea;
};

#define MAP_HEIGHT_NO_HEIGHT  0x0001
#define MAP_HEIGHT_AS_INT16   0x0002
#define MAP_HEIGHT_AS_INT8    0x0004

struct map_heightHeader
{
    uint32 fourcc;
    uint32 flags;
    float  gridHeight;
    float  gridMaxHeight;
};

#define MAP_LIQUID_TYPE_NO_WATER    0x00
#define MAP_LIQUID_TYPE_WATER       0x01
#define MAP_LIQUID_TYPE_OCEAN       0x02
#define MAP_LIQUID_TYPE_MAGMA       0x04
#define MAP_LIQUID_TYPE_SLIME       0x08

#define MAP_LIQUID_TYPE_DARK_WATER  0x10
#define MAP_LIQUID_TYPE_WMO_WATER   0x20


#define MAP_LIQUID_NO_TYPE    0x0001
#define MAP_LIQUID_NO_HEIGHT  0x0002

struct map_liquidHeader
{
    uint32 fourcc;
    uint16 flags;
    uint16 liquidType;
    uint8  offsetX;
    uint8  offsetY;
    uint8  width;
    uint8  height;
    float  liquidLevel;
};

float selectUInt8StepStore(float maxDiff)
{
    return 255 / maxDiff;
}

float selectUInt16StepStore(float maxDiff)
{
    return 65535 / maxDiff;
}
// Temporary grid data store
uint16 area_flags[ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID];

float V8[ADT_GRID_SIZE][ADT_GRID_SIZE];
float V9[ADT_GRID_SIZE+1][ADT_GRID_SIZE+1];
uint16 uint16_V8[ADT_GRID_SIZE][ADT_GRID_SIZE];
uint16 uint16_V9[ADT_GRID_SIZE+1][ADT_GRID_SIZE+1];
uint8  uint8_V8[ADT_GRID_SIZE][ADT_GRID_SIZE];
uint8  uint8_V9[ADT_GRID_SIZE+1][ADT_GRID_SIZE+1];

uint8 liquid_type[ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID];
bool  liquid_show[ADT_GRID_SIZE][ADT_GRID_SIZE];
float liquid_height[ADT_GRID_SIZE+1][ADT_GRID_SIZE+1];

bool ConvertADT(char *filename, char *filename2, int cell_y, int cell_x, uint32 build, HANDLE _mpq)
{
    ADT_file adt(filename, _mpq);
    
    if (adt.isEof())
    {
        if(_mpq == WorldMPQ)
            return ConvertADT(filename, filename2, cell_y, cell_x, build, ExpansionsMPQ[0]);
        if(_mpq == ExpansionsMPQ[0])
            return ConvertADT(filename, filename2, cell_y, cell_x, build, ExpansionsMPQ[1]);
        if(_mpq == ExpansionsMPQ[1])
            return ConvertADT(filename, filename2, cell_y, cell_x, build, ExpansionsMPQ[2]);
        if(_mpq == ExpansionsMPQ[2])
            return false;
    }
    
    adt.prepareLoadedData();
    
    memset(liquid_show, 0, sizeof(liquid_show));
    memset(liquid_type, 0, sizeof(liquid_type));
    
    // Prepare map header
    map_fileheader map;
    map.mapMagic = *(uint32 const*)MAP_MAGIC;
    map.versionMagic = *(uint32 const*)MAP_VERSION_MAGIC;
    map.buildMagic = build;
    
    // Get area flags data
    for (int i=0;i<ADT_CELLS_PER_GRID;i++)
    {
        for(int j=0;j<ADT_CELLS_PER_GRID;j++)
        {
            adt_MCNK * cell = adt.getMCNK(i,j);
            if(cell)
            {
                uint32 areaid = cell->areaid;
                if(areaid && areaid <= maxAreaId)
                {
                    if(areas[areaid] != 0xffff)
                    {
                        area_flags[i][j] = areas[areaid];
                        continue;
                    }
                    printf("File: %s\nCan't find area flag for areaid %u [%d, %d].\n", filename, areaid, cell->ix, cell->iy);
                }
            }
            area_flags[i][j] = 0xffff;
        }
    }
    //============================================
    // Try pack area data
    //============================================
    bool fullAreaData = false;
    uint32 areaflag = area_flags[0][0];
    for (int y=0;y<ADT_CELLS_PER_GRID;y++)
    {
        for(int x=0;x<ADT_CELLS_PER_GRID;x++)
        {
            if(area_flags[y][x]!=areaflag)
            {
                fullAreaData = true;
                break;
            }
        }
    }
    
    map.areaMapOffset = sizeof(map);
    map.areaMapSize   = sizeof(map_areaHeader);
    
    map_areaHeader areaHeader;
    areaHeader.fourcc = *(uint32 const*)MAP_AREA_MAGIC;
    areaHeader.flags = 0;
    if (fullAreaData)
    {
        areaHeader.gridArea = 0;
        map.areaMapSize+=sizeof(area_flags);
    }
    else
    {
        areaHeader.flags |= MAP_AREA_NO_AREA;
        areaHeader.gridArea = (uint16)areaflag;
    }
    
    //
    // Get Height map from grid
    //
    for (int i=0;i<ADT_CELLS_PER_GRID;i++)
    {
        for(int j=0;j<ADT_CELLS_PER_GRID;j++)
        {
            adt_MCNK * cell = adt.getMCNK(i,j);
            if (!cell)
                continue;
            // Height values for triangles stored in order:
            // 1     2     3     4     5     6     7     8     9
            //    10    11    12    13    14    15    16    17
            // 18    19    20    21    22    23    24    25    26
            //    27    28    29    30    31    32    33    34
            // . . . . . . . .
            // For better get height values merge it to V9 and V8 map
            // V9 height map:
            // 1     2     3     4     5     6     7     8     9
            // 18    19    20    21    22    23    24    25    26
            // . . . . . . . .
            // V8 height map:
            //    10    11    12    13    14    15    16    17
            //    27    28    29    30    31    32    33    34
            // . . . . . . . .
            
            // Set map height as grid height
            for (int y=0; y <= ADT_CELL_SIZE; y++)
            {
                int cy = i*ADT_CELL_SIZE + y;
                for (int x=0; x <= ADT_CELL_SIZE; x++)
                {
                    int cx = j*ADT_CELL_SIZE + x;
                    V9[cy][cx]=cell->ypos;
                }
            }
            for (int y=0; y < ADT_CELL_SIZE; y++)
            {
                int cy = i*ADT_CELL_SIZE + y;
                for (int x=0; x < ADT_CELL_SIZE; x++)
                {
                    int cx = j*ADT_CELL_SIZE + x;
                    V8[cy][cx]=cell->ypos;
                }
            }
            // Get custom height
            adt_MCVT *v = cell->getMCVT();
            if (!v)
                continue;
            // get V9 height map
            for (int y=0; y <= ADT_CELL_SIZE; y++)
            {
                int cy = i*ADT_CELL_SIZE + y;
                for (int x=0; x <= ADT_CELL_SIZE; x++)
                {
                    int cx = j*ADT_CELL_SIZE + x;
                    V9[cy][cx]+=v->height_map[y*(ADT_CELL_SIZE*2+1)+x];
                }
            }
            // get V8 height map
            for (int y=0; y < ADT_CELL_SIZE; y++)
            {
                int cy = i*ADT_CELL_SIZE + y;
                for (int x=0; x < ADT_CELL_SIZE; x++)
                {
                    int cx = j*ADT_CELL_SIZE + x;
                    V8[cy][cx]+=v->height_map[y*(ADT_CELL_SIZE*2+1)+ADT_CELL_SIZE+1+x];
                }
            }
        }
    }
    //============================================
    // Try pack height data
    //============================================
    float maxHeight = -20000;
    float minHeight =  20000;
    for (int y=0; y<ADT_GRID_SIZE; y++)
    {
        for(int x=0;x<ADT_GRID_SIZE;x++)
        {
            float h = V8[y][x];
            if (maxHeight < h) maxHeight = h;
            if (minHeight > h) minHeight = h;
        }
    }
    for (int y=0; y<=ADT_GRID_SIZE; y++)
    {
        for(int x=0;x<=ADT_GRID_SIZE;x++)
        {
            float h = V9[y][x];
            if (maxHeight < h) maxHeight = h;
            if (minHeight > h) minHeight = h;
        }
    }
    
    // Check for allow limit minimum height (not store height in deep ochean - allow save some memory)
    if (CONF_allow_height_limit && minHeight < CONF_use_minHeight)
    {
        for (int y=0; y<ADT_GRID_SIZE; y++)
            for(int x=0;x<ADT_GRID_SIZE;x++)
                if (V8[y][x] < CONF_use_minHeight)
                    V8[y][x] = CONF_use_minHeight;
        for (int y=0; y<=ADT_GRID_SIZE; y++)
            for(int x=0;x<=ADT_GRID_SIZE;x++)
                if (V9[y][x] < CONF_use_minHeight)
                    V9[y][x] = CONF_use_minHeight;
        if (minHeight < CONF_use_minHeight)
            minHeight = CONF_use_minHeight;
        if (maxHeight < CONF_use_minHeight)
            maxHeight = CONF_use_minHeight;
    }
    
    map.heightMapOffset = map.areaMapOffset + map.areaMapSize;
    map.heightMapSize = sizeof(map_heightHeader);
    
    map_heightHeader heightHeader;
    heightHeader.fourcc = *(uint32 const*)MAP_HEIGHT_MAGIC;
    heightHeader.flags = 0;
    heightHeader.gridHeight    = minHeight;
    heightHeader.gridMaxHeight = maxHeight;
    
    if (maxHeight == minHeight)
        heightHeader.flags |= MAP_HEIGHT_NO_HEIGHT;
    
    // Not need store if flat surface
    if (CONF_allow_float_to_int && (maxHeight - minHeight) < CONF_flat_height_delta_limit)
        heightHeader.flags |= MAP_HEIGHT_NO_HEIGHT;
    
    // Try store as packed in uint16 or uint8 values
    if (!(heightHeader.flags & MAP_HEIGHT_NO_HEIGHT))
    {
        float step;
        // Try Store as uint values
        if (CONF_allow_float_to_int)
        {
            float diff = maxHeight - minHeight;
            if (diff < CONF_float_to_int8_limit)      // As uint8 (max accuracy = CONF_float_to_int8_limit/256)
            {
                heightHeader.flags|=MAP_HEIGHT_AS_INT8;
                step = selectUInt8StepStore(diff);
            }
            else if (diff<CONF_float_to_int16_limit)  // As uint16 (max accuracy = CONF_float_to_int16_limit/65536)
            {
                heightHeader.flags|=MAP_HEIGHT_AS_INT16;
                step = selectUInt16StepStore(diff);
            }
        }
        
        // Pack it to int values if need
        if (heightHeader.flags&MAP_HEIGHT_AS_INT8)
        {
            for (int y=0; y<ADT_GRID_SIZE; y++)
                for(int x=0;x<ADT_GRID_SIZE;x++)
                    uint8_V8[y][x] = uint8((V8[y][x] - minHeight) * step + 0.5f);
            for (int y=0; y<=ADT_GRID_SIZE; y++)
                for(int x=0;x<=ADT_GRID_SIZE;x++)
                    uint8_V9[y][x] = uint8((V9[y][x] - minHeight) * step + 0.5f);
            map.heightMapSize+= sizeof(uint8_V9) + sizeof(uint8_V8);
        }
        else if (heightHeader.flags&MAP_HEIGHT_AS_INT16)
        {
            for (int y=0; y<ADT_GRID_SIZE; y++)
                for(int x=0;x<ADT_GRID_SIZE;x++)
                    uint16_V8[y][x] = uint16((V8[y][x] - minHeight) * step + 0.5f);
            for (int y=0; y<=ADT_GRID_SIZE; y++)
                for(int x=0;x<=ADT_GRID_SIZE;x++)
                    uint16_V9[y][x] = uint16((V9[y][x] - minHeight) * step + 0.5f);
            map.heightMapSize+= sizeof(uint16_V9) + sizeof(uint16_V8);
        }
        else
            map.heightMapSize+= sizeof(V9) + sizeof(V8);
    }
    
    // Get liquid map for grid (in WOTLK used MH2O chunk)
    adt_MH2O * h2o = adt.a_grid->getMH2O();
    if (h2o)
    {
        for (int i=0;i<ADT_CELLS_PER_GRID;i++)
        {
            for(int j=0;j<ADT_CELLS_PER_GRID;j++)
            {
                adt_liquid_header *h = h2o->getLiquidData(i,j);
                if (!h)
                    continue;
                
                int count = 0;
                uint64 show = h2o->getLiquidShowMap(h);
                for (int y=0; y < h->height;y++)
                {
                    int cy = i*ADT_CELL_SIZE + y + h->yOffset;
                    for (int x=0; x < h->width; x++)
                    {
                        int cx = j*ADT_CELL_SIZE + x + h->xOffset;
                        if (show & 1)
                        {
                            liquid_show[cy][cx] = true;
                            ++count;
                        }
                        show>>=1;
                    }
                }
                
                uint32 type = LiqType[h->liquidType];
                switch (type)
                {
                    case LIQUID_TYPE_WATER: liquid_type[i][j] |= MAP_LIQUID_TYPE_WATER; break;
                    case LIQUID_TYPE_OCEAN: liquid_type[i][j] |= MAP_LIQUID_TYPE_OCEAN; break;
                    case LIQUID_TYPE_MAGMA: liquid_type[i][j] |= MAP_LIQUID_TYPE_MAGMA; break;
                    case LIQUID_TYPE_SLIME: liquid_type[i][j] |= MAP_LIQUID_TYPE_SLIME; break;
                    default:
                        printf("\nCan't find Liquid type %u for map %s\nchunk %d,%d\n", h->liquidType, filename, i, j);
                        break;
                }
                // Dark water detect
                if (type == LIQUID_TYPE_OCEAN)
                {
                    uint8 *lm = h2o->getLiquidLightMap(h);
                    if (!lm)
                        liquid_type[i][j]|=MAP_LIQUID_TYPE_DARK_WATER;
                }
                
                if (!count && liquid_type[i][j])
                    printf("Wrong liquid detect in MH2O chunk");
                
                float *height = h2o->getLiquidHeightMap(h);
                int pos = 0;
                for (int y=0; y<=h->height;y++)
                {
                    int cy = i*ADT_CELL_SIZE + y + h->yOffset;
                    for (int x=0; x<= h->width; x++)
                    {
                        int cx = j*ADT_CELL_SIZE + x + h->xOffset;
                        if (height)
                            liquid_height[cy][cx] = height[pos];
                        else
                            liquid_height[cy][cx] = h->heightLevel1;
                        pos++;
                    }
                }
            }
        }
    }
    else
    {
        // Get from MCLQ chunk (old)
        for (int i=0;i<ADT_CELLS_PER_GRID;i++)
        {
            for(int j=0;j<ADT_CELLS_PER_GRID;j++)
            {
                adt_MCNK *cell = adt.getMCNK(i, j);
                if (!cell)
                    continue;
                
                adt_MCLQ *liquid = cell->getMCLQ();
                int count = 0;
                if (!liquid || cell->sizeMCLQ <= 8)
                    continue;
                
                for (int y=0; y < ADT_CELL_SIZE; y++)
                {
                    int cy = i*ADT_CELL_SIZE + y;
                    for (int x=0; x < ADT_CELL_SIZE; x++)
                    {
                        int cx = j*ADT_CELL_SIZE + x;
                        if (liquid->flags[y][x] != 0x0F)
                        {
                            liquid_show[cy][cx] = true;
                            if (liquid->flags[y][x]&(1<<7))
                                liquid_type[i][j]|=MAP_LIQUID_TYPE_DARK_WATER;
                            ++count;
                        }
                    }
                }
                
                uint32 c_flag = cell->flags;
                if(c_flag & (1<<2))
                    liquid_type[i][j]|=MAP_LIQUID_TYPE_WATER;            // water
                if(c_flag & (1<<3))
                    liquid_type[i][j]|=MAP_LIQUID_TYPE_OCEAN;            // ochean
                if(c_flag & (1<<4))
                    liquid_type[i][j]|=MAP_LIQUID_TYPE_MAGMA;            // magma/slime
                
                if (!count && liquid_type[i][j])
                    printf("Wrong liquid detect in MCLQ chunk");
                
                for (int y=0; y <= ADT_CELL_SIZE; y++)
                {
                    int cy = i*ADT_CELL_SIZE + y;
                    for (int x=0; x<= ADT_CELL_SIZE; x++)
                    {
                        int cx = j*ADT_CELL_SIZE + x;
                        liquid_height[cy][cx] = liquid->liquid[y][x].height;
                    }
                }
            }
        }
    }
    
    //============================================
    // Pack liquid data
    //============================================
    uint8 type = liquid_type[0][0];
    bool fullType = false;
    for (int y=0;y<ADT_CELLS_PER_GRID;y++)
    {
        for(int x=0;x<ADT_CELLS_PER_GRID;x++)
        {
            if (liquid_type[y][x]!=type)
            {
                fullType = true;
                y = ADT_CELLS_PER_GRID;
                break;
            }
        }
    }
    
    map_liquidHeader liquidHeader;
    
    // no water data (if all grid have 0 liquid type)
    if (type == 0 && !fullType)
    {
        // No liquid data
        map.liquidMapOffset = 0;
        map.liquidMapSize   = 0;
    }
    else
    {
        int minX = 255, minY = 255;
        int maxX = 0, maxY = 0;
        maxHeight = -20000;
        minHeight = 20000;
        for (int y=0; y<ADT_GRID_SIZE; y++)
        {
            for(int x=0; x<ADT_GRID_SIZE; x++)
            {
                if (liquid_show[y][x])
                {
                    if (minX > x) minX = x;
                    if (maxX < x) maxX = x;
                    if (minY > y) minY = y;
                    if (maxY < y) maxY = y;
                    float h = liquid_height[y][x];
                    if (maxHeight < h) maxHeight = h;
                    if (minHeight > h) minHeight = h;
                }
                else
                    liquid_height[y][x] = CONF_use_minHeight;
            }
        }
        map.liquidMapOffset = map.heightMapOffset + map.heightMapSize;
        map.liquidMapSize = sizeof(map_liquidHeader);
        liquidHeader.fourcc = *(uint32 const*)MAP_LIQUID_MAGIC;
        liquidHeader.flags = 0;
        liquidHeader.liquidType = 0;
        liquidHeader.offsetX = minX;
        liquidHeader.offsetY = minY;
        liquidHeader.width   = maxX - minX + 1;
        liquidHeader.height  = maxY - minY + 1;
        liquidHeader.liquidLevel = minHeight;
        
        if (maxHeight == minHeight)
            liquidHeader.flags |= MAP_LIQUID_NO_HEIGHT;
        
        // Not need store if flat surface
        if (CONF_allow_float_to_int && (maxHeight - minHeight) < CONF_flat_liquid_delta_limit)
            liquidHeader.flags |= MAP_LIQUID_NO_HEIGHT;
        
        if (!fullType)
            liquidHeader.flags |= MAP_LIQUID_NO_TYPE;
        
        if (liquidHeader.flags & MAP_LIQUID_NO_TYPE)
            liquidHeader.liquidType = type;
        else
            map.liquidMapSize+=sizeof(liquid_type);
        
        if (!(liquidHeader.flags & MAP_LIQUID_NO_HEIGHT))
            map.liquidMapSize += sizeof(float)*liquidHeader.width*liquidHeader.height;
    }
    
    // Ok all data prepared - store it
    FILE *output=fopen(filename2, "wb");
    if(!output)
    {
        printf("Can't create the output file '%s'\n", filename2);
        return false;
    }
    fwrite(&map, sizeof(map), 1, output);
    // Store area data
    fwrite(&areaHeader, sizeof(areaHeader), 1, output);
    if (!(areaHeader.flags&MAP_AREA_NO_AREA))
        fwrite(area_flags, sizeof(area_flags), 1, output);
    
    // Store height data
    fwrite(&heightHeader, sizeof(heightHeader), 1, output);
    if (!(heightHeader.flags & MAP_HEIGHT_NO_HEIGHT))
    {
        if (heightHeader.flags & MAP_HEIGHT_AS_INT16)
        {
            fwrite(uint16_V9, sizeof(uint16_V9), 1, output);
            fwrite(uint16_V8, sizeof(uint16_V8), 1, output);
        }
        else if (heightHeader.flags & MAP_HEIGHT_AS_INT8)
        {
            fwrite(uint8_V9, sizeof(uint8_V9), 1, output);
            fwrite(uint8_V8, sizeof(uint8_V8), 1, output);
        }
        else
        {
            fwrite(V9, sizeof(V9), 1, output);
            fwrite(V8, sizeof(V8), 1, output);
        }
    }
    
    // Store liquid data if need
    if (map.liquidMapOffset)
    {
        fwrite(&liquidHeader, sizeof(liquidHeader), 1, output);
        if (!(liquidHeader.flags&MAP_LIQUID_NO_TYPE))
            fwrite(liquid_type, sizeof(liquid_type), 1, output);
        if (!(liquidHeader.flags&MAP_LIQUID_NO_HEIGHT))
        {
            for (int y=0; y<liquidHeader.height;y++)
                fwrite(&liquid_height[y+liquidHeader.offsetY][liquidHeader.offsetX], sizeof(float), liquidHeader.width, output);
        }
    }
    fclose(output);
    
    return true;
}

void LoadMapMPQFiles()
{
    char filename[512];
	
    //Locale-xxXX.MPQ
    sprintf(filename,"%s/Data/world.MPQ", input_path);
    printf("Loading %s\n", filename);
    if(!SFileOpenArchive(filename, 0, MPQ_OPEN_READ_ONLY, &WorldMPQ))
    {
        printf("%i\n", GetLastError());
        assert(false && "\nLoad of MPQ failed");
    }
	
    for(int i = 0; i < PATCH_REV_COUNT; ++i)
    {
        char ext[7] = "";
        sprintf(ext, "-%i", patchRev[i]);
		
        sprintf(filename,"%s/Data/wow-update%s.MPQ", input_path, ext);
        printf("    -%i\n", patchRev[i]);
        if(!SFileOpenPatchArchive(WorldMPQ, filename, "base", MPQ_OPEN_READ_ONLY))
        {
            printf("%i\n", GetLastError());
            assert(false && "Load of MPQ patch failed");
        }
    }
    if(!SFileIsPatchedArchive(WorldMPQ))
        assert(false && "An error occured");
    
    for(int j = 0; j < 2; j++)
    {
        sprintf(filename, "%s/Data/expansion%u.MPQ", input_path, j+1);
        printf("Loading %s\n", filename);
        if(!SFileOpenArchive(filename, 0, MPQ_OPEN_READ_ONLY, &ExpansionsMPQ[j]))
        {
            printf("%i\n", GetLastError());
            assert(false && "\nLoad of MPQ failed");
        }
        
        if(!IsValidMpqHandle((TMPQArchive*)ExpansionsMPQ[j]))
        {
            printf("Load of Expansion%u.MPQ Failed!\n", j+1);
            printf("\nPlease verify you downloaded all the MPQs. You should replace\n'SET accountType \"xx\"'\nin your WTF/config.wtf and WTF/launcher.wtf by\n'SET accountType \"CT\"'\nand then restart your launcher\n");
            exit(1);
        }
        
        for(int i = 0; i < PATCH_REV_COUNT; ++i)
        {
            char ext[7] = "";
            sprintf(ext, "-%i", patchRev[i]);
            
            sprintf(filename,"%s/Data/wow-update%s.MPQ", input_path, ext);
            printf("    -%i\n", patchRev[i]);
            if(!SFileOpenPatchArchive(ExpansionsMPQ[j], filename, "base", MPQ_OPEN_READ_ONLY))
            {
                printf("%i\n", GetLastError());
                assert(false && "Load of MPQ patch failed");
            }
        }
    }
}

void ExtractMapsFromMpq(uint32 build)
{
    char mpq_filename[1024];
    char output_filename[1024];
    char mpq_map_name[1024];
    
    printf("Extracting maps...\n");
    
    LoadMapMPQFiles();
    
    uint32 map_count = ReadMapDBC();
    
    ReadAreaTableDBC();
    ReadLiquidTypeTableDBC();
    
    std::string path = output_path;
    path += "/maps/";
    CreateDir(path);
    
    std::vector<std::string> not_found;
    
    printf("Convert map files\n");
    HANDLE actualMPQ = WorldMPQ;
    for(uint32 z = 0; z < map_count; ++z)
    {
        // Loadup map grid data
        sprintf(mpq_map_name, "World\\Maps\\%s\\%s.wdt", map_ids[z].name, map_ids[z].name);
        WDT_file wdt(mpq_map_name, actualMPQ);
        if (wdt.isEof())
        {
            if(actualMPQ == WorldMPQ)
            {
                z--;
                actualMPQ = ExpansionsMPQ[0];
                continue;
            }
            if(actualMPQ == ExpansionsMPQ[0])
            {
                z--;
                actualMPQ = ExpansionsMPQ[1];
                continue;
            }
            if(actualMPQ == ExpansionsMPQ[1])
            {
                z--;
                actualMPQ = ExpansionsMPQ[2];
                continue;
            }
            actualMPQ = WorldMPQ;
            not_found.push_back(map_ids[z].name);
            printf("Extract %s (%d/%d) -- not found\n", map_ids[z].name, z+1, map_count);
            continue;
        }
        if(actualMPQ == WorldMPQ)
            printf("Extract %s (%d/%d) -- World.MPQ\n", map_ids[z].name, z+1, map_count);
        if(actualMPQ == ExpansionsMPQ[0])
            printf("Extract %s (%d/%d) -- expansion1.MPQ\n", map_ids[z].name, z+1, map_count);
        if(actualMPQ == ExpansionsMPQ[1])
            printf("Extract %s (%d/%d) -- expansion2.MPQ\n", map_ids[z].name, z+1, map_count);
        if(actualMPQ == ExpansionsMPQ[2])
            printf("Extract %s (%d/%d) -- expansion3.MPQ\n", map_ids[z].name, z+1, map_count);
        actualMPQ = WorldMPQ;
        
        wdt.prepareLoadedData();
        
        for(uint32 y = 0; y < WDT_MAP_SIZE; ++y)
        {
            for(uint32 x = 0; x < WDT_MAP_SIZE; ++x)
            {
                if (!wdt.main->adt_list[y][x].exist)
                    continue;
                sprintf(mpq_filename, "World\\Maps\\%s\\%s_%u_%u.adt", map_ids[z].name, map_ids[z].name, x, y);
                sprintf(output_filename, "%s/maps/%03u%02u%02u.map", output_path, map_ids[z].id, y, x);
                ConvertADT(mpq_filename, output_filename, y, x, build, WorldMPQ);
            }
            // draw progress bar
            //printf("Processing........................%d%%\r", (100 * (y+1)) / WDT_MAP_SIZE);
        }
    }
    printf("\n");
    delete [] areas;
    delete [] map_ids;
    //printf("Map not extracted : %u\n", not_found.size());
    //for(int i = 0; i < not_found.size(); i++)
    //    printf("    %s\n", not_found[i].c_str());
}

void ExtractDBCFiles(int locale, bool basicLocale)
{
    printf("Extracting dbc files...\n");
	
    std::set<std::pair<int, std::string> > dbcfiles;
	
    int foundCount = 0;
	
    for(int i = 0; i < PATCH_REV_COUNT + 1; i++)
    {
        TMPQArchive * archive = (TMPQArchive *)localeMPQ[i];
        TFileEntry * pFileEntry = archive->pFileTable;
        TFileEntry * pFileTableEnd = archive->pFileTable + archive->dwFileTableSize;
		
        // Parse the entire block table
        while(pFileEntry < pFileTableEnd)
        {
            // Only take existing files
            if( pFileEntry->dwFlags & MPQ_FILE_EXISTS && 
			   (pFileEntry->dwFlags & MPQ_FILE_PATCH_FILE) == 0 && 
			   (pFileEntry->dwFlags & MPQ_FILE_DELETE_MARKER) == 0 && 
			   pFileEntry->szFileName != NULL)
            {
                std::string name = pFileEntry->szFileName;
                if (i != 0)
                {
                    if(name.find(langs[locale]) == 0)
                        name = name.substr(strlen(langs[locale]) + 1);
                    else
                    {
                        pFileEntry++;
                        continue;
                    }
                }
				
                if (name.rfind(".dbc") == name.length() - strlen(".dbc")
                    || name.rfind(".db2") == name.length() - strlen(".db2"))
                {
                    //Verify if this dbc isn't in the list yet. StormLibs return some extra dbcs :P
                    if(i != 0)
                    {
                        bool alreadyExist = false;
                        for(std::set<std::pair<int, std::string> >::iterator itr = dbcfiles.begin(); itr != dbcfiles.end(); itr++)
                        {
                            if(itr->second == name)
                            {
                                alreadyExist = true;
                                break;
                            }
                        }
                        if(alreadyExist)
                        {
                            pFileEntry++;
                            continue;
                        }
                    }
                    dbcfiles.insert(std::pair<int, std::string>(i, name));
                    foundCount++;
                }
            }
			
            // Move to the next file entry
            pFileEntry++;
        }
    }
    printf("Found %i dbc files\n", foundCount);
	
    std::string path = output_path;
    path += "/dbc/";
    if(!basicLocale)
    {
        path += langs[locale];
        path += "/";
    }
	CreateDir(path);
	
    // extract DBCs
    int count = 0;
    for (std::set<std::pair<int, std::string> >::iterator iter = dbcfiles.begin(); iter != dbcfiles.end(); ++iter)
    {
        std::string filename = path;
        filename += (iter->second.c_str() + strlen("DBFilesClient\\"));
		
        if(ExtractFileToHardDrive(localeMPQ[iter->first], iter->second.c_str(), filename.c_str()) == ERROR_SUCCESS)
            ++count;
        else
            assert(false);
    }
    printf("Extracted %u DBC files\n\n", count);
}

void LoadLocaleMPQFiles(int const locale)
{
    char filename[512];
	
    //Locale-xxXX.MPQ
    sprintf(filename,"%s/Data/%s/locale-%s.MPQ", input_path, langs[locale], langs[locale]);
    printf("Loading %s\n", filename);
    if(!SFileOpenArchive(filename, 0, MPQ_OPEN_READ_ONLY, &localeMPQ[0]))
    {
        printf("%i\n", GetLastError());
        assert(false && "\nLoad of MPQ failed");
    }
	
    for(int i = 0; i < PATCH_REV_COUNT; ++i)
    {
        char ext[7] = "";
        sprintf(ext, "-%i", patchRev[i]);
		
        sprintf(filename,"%s/Data/wow-update%s.MPQ", input_path, ext);
        if(!SFileOpenPatchArchive(localeMPQ[0], filename, langs[locale], MPQ_OPEN_READ_ONLY))
        {
            printf("%i\n", GetLastError());
            assert(false && "Load of MPQ patch failed");
        }
    }
    if(!SFileIsPatchedArchive(localeMPQ[0]))
        assert(false && "An error occured");
	
    //Others
    for(int i = 0; i < PATCH_REV_COUNT; ++i)
    {
        char ext[7] = "";
        sprintf(ext, "-%i", patchRev[i]);
		
        sprintf(filename,"%s/Data/wow-update%s.MPQ", input_path, ext);
        printf("Loading %s\n", filename);
        if(!SFileOpenArchive(filename, 0, MPQ_OPEN_READ_ONLY, &localeMPQ[i+1]))
        {
            printf("%i\n", GetLastError());
            assert(false && "Load of MPQ failed");
        }
		
        for(int j = i; j < PATCH_REV_COUNT; ++j)
        {
            char ext[7] = "";
            sprintf(ext, "-%i", patchRev[j]);
			
            sprintf(filename,"%s/Data/wow-update%s.MPQ", input_path, ext);
            if(!SFileOpenPatchArchive(localeMPQ[i+1], filename, langs[locale], MPQ_OPEN_READ_ONLY))
            {
                printf("%i\n", GetLastError());
                assert(false && "Load of MPQ patch failed");
            }
        }
        if(!SFileIsPatchedArchive(localeMPQ[i+1]))
            assert(false && "An error occured");
    }
}



int main(int argc, char * arg[])
{
    printf("DBC/Map Extractor\n");
    printf("===================\n\n");
    
    bool extractDBC = true;
    bool extractMap = true;

    HandleArgs(argc, arg);
    
    for (int i = 0; i < argc; ++i)  
    {
        if(strcmp(arg[i], ARG_MAP) == 0)
            extractMap = true;
        if(strcmp(arg[i], ARG_NOMAP) == 0)
            extractMap = false;
        if(strcmp(arg[i], ARG_DBC) == 0)
            extractDBC = true;
        if(strcmp(arg[i], ARG_NODBC) == 0)
            extractDBC = false;
    }
    
    int FirstLocale = -1;
    int build = 0;
	
    for (int i = 0; i < LANG_COUNT; i++)
    {
        char tmp1[512];
        sprintf(tmp1, "%s/Data/%s/locale-%s.MPQ", input_path, langs[i], langs[i]);
        if (FileExists(tmp1))
        {
            printf("Detected locale: %s\n", langs[i]);
			
            //Open MPQs
            LoadLocaleMPQFiles(i);
			
            //Extract DBC files
            if(FirstLocale < 0)
            {
                FirstLocale = i;
                build = ReadBuild(FirstLocale);
                printf("Detected base client build: %u\n", build);
                if(build != CLIENT_BUILD)
                {
                    printf("ERROR: your client is not up-to-date. Client build should be %u", CLIENT_BUILD);
                    return 0;
                }
                if(extractDBC)
                    ExtractDBCFiles(i, true);
            }
            else if(extractDBC)
                ExtractDBCFiles(i, false);
        }
    }
	
    if(FirstLocale < 0)
    {
        printf("No locales detected\n");
        return 0;
    }
    
    if(extractMap)
        ExtractMapsFromMpq(build);
	
    return 0;
}