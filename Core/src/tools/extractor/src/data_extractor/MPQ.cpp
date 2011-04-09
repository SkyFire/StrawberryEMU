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
#include "MPQ.h"

int ExtractFileToHardDrive(HANDLE &MPQ_handle, const char * szArchivedFile, const char * szFileName)
{
    HANDLE hFile  = NULL;          // Archived file handle
    TFileStream* handle = NULL;          // Disk file handle
    int    nError = ERROR_SUCCESS; // Result value
    
    if(nError == ERROR_SUCCESS)            
    {
        if(!SFileOpenFileEx(MPQ_handle, szArchivedFile, SFILE_OPEN_PATCHED_FILE, &hFile))
            nError = GetLastError();
    }
	
    // Create the target file
    if(nError == ERROR_SUCCESS)
    {
		handle = FileStream_CreateFile(szFileName);
        if(handle == NULL)
            nError = GetLastError();
    }
	
    // Read the file from the archive
    if(nError == ERROR_SUCCESS)
    {
        // Get the size of the full patched file
        DWORD dwFileSize = SFileGetFileSize(hFile, NULL);
        if(dwFileSize != 0)
        {
            // Allocate space for the full file
            BYTE * pbFullFile = new BYTE[dwFileSize];
            if(!SFileReadFile(hFile, pbFullFile, dwFileSize))
			{           
				nError = GetLastError();
				printf("Failed to read full patched file data \"%s\"\n", szFileName);
				assert(false);
			}
			FileStream_Write(handle, NULL, pbFullFile, dwFileSize);
			delete [] pbFullFile;
        }
    }
	
    // Cleanup and exit
    if(handle != NULL)
        FileStream_Close(handle);
    if(hFile != NULL)
        SFileCloseFile(hFile);
	
    return nError;
}

char* ExtractFileToMemory(HANDLE &MPQ_handle, const char * szArchivedFile, int & size )
{
    HANDLE hFile  = NULL;          // Archived file handle
    int    nError = ERROR_SUCCESS; // Result value
    char * pbFullFile = NULL;
    
    if(nError == ERROR_SUCCESS)            
    {
        if(!SFileOpenFileEx(MPQ_handle, szArchivedFile, SFILE_OPEN_PATCHED_FILE, &hFile))
            nError = GetLastError();
    }
	
    // Read the file from the archive
    if(nError == ERROR_SUCCESS)
    {
        // Get the size of the full patched file
        size = SFileGetFileSize(hFile, NULL);
        if(size != 0)
        {
            // Allocate space for the full file
            pbFullFile = new char[size];
            if(!SFileReadFile(hFile, pbFullFile, size))
			{           
				nError = GetLastError();
				printf("Failed to read full patched file data \"%s\"\n", szArchivedFile);
				assert(false);
			}
        }
    }
	
    // Cleanup and exit
    if(nError == ERROR_SUCCESS && hFile != NULL)
        SFileCloseFile(hFile);
	
    return pbFullFile;
}