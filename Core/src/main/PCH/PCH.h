// Main includes
#include "WorldSocket.h"
#include "Common.h"
#include "MapManager.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectDefines.h"
#include "SQLStorage.h"
#include "SharedDefines.h"
/* Opcode Handler includes */
#include "OpcodeHandler.h"
#include "ClientOpcodeHandler.h"
#include "ClientServerOpcodeHandler.h"
// Not used
//#include "CompressedOpcodeHandler.h"
#include "ServerOpcodeHandler.h"
// Used in 4.x.x
//#include "SpecialOpcodeHandler.h"

// Scripts
#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GameEventMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Unit.h"
#include "GameObject.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "Chat.h"
#include "DBCStructure.h"
#include "DBCStores.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

// Main and Script includes
#include "ObjectMgr.h"

#ifdef _WIN32
#include <windows.h>
#endif