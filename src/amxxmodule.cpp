/* AMX Mod X
*
* by the AMX Mod X Development Team
*  originally developed by OLO
*
* Parts Copyright (C) 2001-2003 Will Day <willday@hpgx.net>
*
*  This program is free software; you can redistribute it and/or modify it
*  under the terms of the GNU General Public License as published by the
*  Free Software Foundation; either version 2 of the License, or (at
*  your option) any later version.
*
*  This program is distributed in the hope that it will be useful, but
*  WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
*  General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software Foundation,
*  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
*  In addition, as a special exception, the author gives permission to
*  link the code of this program with the Half-Life Game Engine ("HL
*  Engine") and Modified Game Libraries ("MODs") developed by Valve,
*  L.L.C ("Valve"). You must obey the GNU General Public License in all
*  respects for all of the code used other than the HL Engine and MODs
*  from Valve. If you modify this file, you may extend this exception
*  to your version of the file, but you are not obligated to do so. If
*  you do not wish to do so, delete this exception statement from your
*  version.
*
*  Description: AMX Mod X Module Interface Functions
*/

#include "precompiled.h"

/************* AMXX Stuff *************/

// *** Globals ***
// Module info
static amxx_module_info_s g_ModuleInfo =
{
	Plugin_info.name,
	Plugin_info.author,
	Plugin_info.version,
	FALSE,
	Plugin_info.logtag,
	"resemiclip",
	"resemiclip"
};

// Storage for the requested functions
PFN_ADD_NATIVES				g_fn_AddNatives;
PFN_ADD_NEW_NATIVES			g_fn_AddNewNatives;
PFN_BUILD_PATHNAME			g_fn_BuildPathname;
PFN_BUILD_PATHNAME_R		g_fn_BuildPathnameR;
PFN_GET_AMXADDR				g_fn_GetAmxAddr;
PFN_PRINT_SRVCONSOLE		g_fn_PrintSrvConsole;
PFN_GET_MODNAME				g_fn_GetModname;
PFN_GET_AMXSCRIPTNAME		g_fn_GetAmxScriptName;
PFN_GET_AMXSCRIPT			g_fn_GetAmxScript;
PFN_FIND_AMXSCRIPT_BYAMX	g_fn_FindAmxScriptByAmx;
PFN_FIND_AMXSCRIPT_BYNAME	g_fn_FindAmxScriptByName;
PFN_SET_AMXSTRING			g_fn_SetAmxString;
PFN_GET_AMXSTRING			g_fn_GetAmxString;
PFN_GET_AMXSTRINGLEN		g_fn_GetAmxStringLen;
PFN_FORMAT_AMXSTRING		g_fn_FormatAmxString;
PFN_COPY_AMXMEMORY			g_fn_CopyAmxMemory;
PFN_LOG						g_fn_Log;
PFN_LOG_ERROR				g_fn_LogErrorFunc;
PFN_RAISE_AMXERROR			g_fn_RaiseAmxError;
PFN_REGISTER_FORWARD		g_fn_RegisterForward;
PFN_EXECUTE_FORWARD			g_fn_ExecuteForward;
PFN_PREPARE_CELLARRAY		g_fn_PrepareCellArray;
PFN_PREPARE_CHARARRAY		g_fn_PrepareCharArray;
PFN_PREPARE_CELLARRAY_A		g_fn_PrepareCellArrayA;
PFN_PREPARE_CHARARRAY_A		g_fn_PrepareCharArrayA;
PFN_IS_PLAYER_VALID			g_fn_IsPlayerValid;
PFN_GET_PLAYER_NAME			g_fn_GetPlayerName;
PFN_GET_PLAYER_IP			g_fn_GetPlayerIP;
PFN_IS_PLAYER_INGAME		g_fn_IsPlayerIngame;
PFN_IS_PLAYER_BOT			g_fn_IsPlayerBot;
PFN_IS_PLAYER_AUTHORIZED	g_fn_IsPlayerAuthorized;
PFN_GET_PLAYER_TIME			g_fn_GetPlayerTime;
PFN_GET_PLAYER_PLAYTIME		g_fn_GetPlayerPlayTime;
PFN_GET_PLAYER_CURWEAPON	g_fn_GetPlayerCurweapon;
PFN_GET_PLAYER_TEAM			g_fn_GetPlayerTeam;
PFN_GET_PLAYER_TEAMID		g_fn_GetPlayerTeamID;
PFN_GET_PLAYER_DEATHS		g_fn_GetPlayerDeaths;
PFN_GET_PLAYER_MENU			g_fn_GetPlayerMenu;
PFN_GET_PLAYER_KEYS			g_fn_GetPlayerKeys;
PFN_IS_PLAYER_ALIVE			g_fn_IsPlayerAlive;
PFN_GET_PLAYER_FRAGS		g_fn_GetPlayerFrags;
PFN_IS_PLAYER_CONNECTING	g_fn_IsPlayerConnecting;
PFN_IS_PLAYER_HLTV			g_fn_IsPlayerHLTV;
PFN_GET_PLAYER_ARMOR		g_fn_GetPlayerArmor;
PFN_GET_PLAYER_HEALTH		g_fn_GetPlayerHealth;
#ifdef MEMORY_TEST
PFN_ALLOCATOR				g_fn_Allocator;
PFN_REALLOCATOR				g_fn_Reallocator;
PFN_DEALLOCATOR				g_fn_Deallocator;
#endif
PFN_AMX_EXEC				g_fn_AmxExec;
PFN_AMX_EXECV				g_fn_AmxExecv;
PFN_AMX_ALLOT				g_fn_AmxAllot;
PFN_AMX_FINDPUBLIC			g_fn_AmxFindPublic;
PFN_LOAD_AMXSCRIPT			g_fn_LoadAmxScript;
PFN_UNLOAD_AMXSCRIPT		g_fn_UnloadAmxScript;
PFN_REAL_TO_CELL			g_fn_RealToCell;
PFN_CELL_TO_REAL			g_fn_CellToReal;
PFN_REGISTER_SPFORWARD		g_fn_RegisterSPForward;
PFN_REGISTER_SPFORWARD_BYNAME	g_fn_RegisterSPForwardByName;
PFN_UNREGISTER_SPFORWARD	g_fn_UnregisterSPForward;
PFN_MERGEDEFINITION_FILE	g_fn_MergeDefinition_File;
PFN_AMX_FINDNATIVE			g_fn_AmxFindNative;
PFN_GETPLAYERFLAGS			g_fn_GetPlayerFlags;
PFN_GET_PLAYER_EDICT		g_fn_GetPlayerEdict;
PFN_FORMAT					g_fn_Format;
PFN_REGISTERFUNCTION		g_fn_RegisterFunction;
PFN_REQ_FNPTR				g_fn_RequestFunction;
PFN_AMX_PUSH				g_fn_AmxPush;
PFN_SET_TEAM_INFO			g_fn_SetTeamInfo;
PFN_PLAYER_PROP_ADDR		g_fn_PlayerPropAddr;
PFN_REG_AUTH_FUNC			g_fn_RegAuthFunc;
PFN_UNREG_AUTH_FUNC			g_fn_UnregAuthFunc;
PFN_FINDLIBRARY				g_fn_FindLibrary;
PFN_ADDLIBRARIES			g_fn_AddLibraries;
PFN_REMOVELIBRARIES			g_fn_RemoveLibraries;
PFN_OVERRIDENATIVES			g_fn_OverrideNatives;
PFN_GETLOCALINFO			g_fn_GetLocalInfo;
PFN_AMX_REREGISTER			g_fn_AmxReRegister;
PFN_REGISTERFUNCTIONEX		g_fn_RegisterFunctionEx;
PFN_MESSAGE_BLOCK			g_fn_MessageBlock;

// *** Exports ***
C_DLLEXPORT int AMXX_Query(int *interfaceVersion, amxx_module_info_s *moduleInfo)
{
	// check parameters
	if (!interfaceVersion || !moduleInfo)
		return AMXX_PARAM;

	// check interface version
	if (*interfaceVersion != AMXX_INTERFACE_VERSION)
	{
		// Tell amxx core our interface version
		*interfaceVersion = AMXX_INTERFACE_VERSION;
		return AMXX_IFVERS;
	}

	// copy module info
	memcpy(moduleInfo, &g_ModuleInfo, sizeof(amxx_module_info_s));

#ifdef FN_AMXX_QUERY
	FN_AMXX_QUERY();
#endif // FN_AMXX_QUERY
	// Everything ok :)
	return AMXX_OK;
}

// request function
#define REQFUNC(name, fptr, type) if ((fptr = (type)reqFnptrFunc(name)) == 0) return AMXX_FUNC_NOT_PRESENT
// request optional function
#define REQFUNC_OPT(name, fptr, type) fptr = (type)reqFnptrFunc(name)

C_DLLEXPORT int AMXX_CheckGame(const char *game)
{
#ifdef FN_AMXX_CHECKGAME
	return FN_AMXX_CHECKGAME(game);
#else
	return AMXX_GAME_OK;
#endif
}
C_DLLEXPORT int AMXX_Attach(PFN_REQ_FNPTR reqFnptrFunc)
{
	// Check pointer
	if (!reqFnptrFunc)
		return AMXX_PARAM;

	g_fn_RequestFunction = reqFnptrFunc;

	// Req all known functions
	// Misc
	REQFUNC("BuildPathname", g_fn_BuildPathname, PFN_BUILD_PATHNAME);
	REQFUNC("BuildPathnameR", g_fn_BuildPathnameR, PFN_BUILD_PATHNAME_R);
	REQFUNC("PrintSrvConsole", g_fn_PrintSrvConsole, PFN_PRINT_SRVCONSOLE);
	REQFUNC("GetModname", g_fn_GetModname, PFN_GET_MODNAME);
	REQFUNC("Log", g_fn_Log, PFN_LOG);
	REQFUNC("LogError", g_fn_LogErrorFunc, PFN_LOG_ERROR);
	REQFUNC("MergeDefinitionFile", g_fn_MergeDefinition_File, PFN_MERGEDEFINITION_FILE);
	REQFUNC("Format", g_fn_Format, PFN_FORMAT);
	REQFUNC("RegisterFunction", g_fn_RegisterFunction, PFN_REGISTERFUNCTION);
	REQFUNC("RegisterFunctionEx", g_fn_RegisterFunctionEx, PFN_REGISTERFUNCTIONEX);

	// Amx scripts
	REQFUNC("GetAmxScript", g_fn_GetAmxScript, PFN_GET_AMXSCRIPT);
	REQFUNC("FindAmxScriptByAmx", g_fn_FindAmxScriptByAmx, PFN_FIND_AMXSCRIPT_BYAMX);
	REQFUNC("FindAmxScriptByName", g_fn_FindAmxScriptByName, PFN_FIND_AMXSCRIPT_BYNAME);
	REQFUNC("LoadAmxScript", g_fn_LoadAmxScript, PFN_LOAD_AMXSCRIPT);
	REQFUNC("UnloadAmxScript", g_fn_UnloadAmxScript, PFN_UNLOAD_AMXSCRIPT);
    REQFUNC("GetAmxScriptName", g_fn_GetAmxScriptName, PFN_GET_AMXSCRIPTNAME);

	// String / mem in amx scripts support
	REQFUNC("SetAmxString", g_fn_SetAmxString, PFN_SET_AMXSTRING);
	REQFUNC("GetAmxString", g_fn_GetAmxString, PFN_GET_AMXSTRING);
	REQFUNC("GetAmxStringLen", g_fn_GetAmxStringLen, PFN_GET_AMXSTRINGLEN);
	REQFUNC("FormatAmxString", g_fn_FormatAmxString, PFN_FORMAT_AMXSTRING);
	REQFUNC("CopyAmxMemory", g_fn_CopyAmxMemory, PFN_COPY_AMXMEMORY);
	REQFUNC("GetAmxAddr", g_fn_GetAmxAddr, PFN_GET_AMXADDR);

	REQFUNC("amx_Exec", g_fn_AmxExec, PFN_AMX_EXEC);
	REQFUNC("amx_Execv", g_fn_AmxExecv, PFN_AMX_EXECV);
	REQFUNC("amx_FindPublic", g_fn_AmxFindPublic, PFN_AMX_FINDPUBLIC);
	REQFUNC("amx_Allot", g_fn_AmxAllot, PFN_AMX_ALLOT);
	REQFUNC("amx_FindNative", g_fn_AmxFindNative, PFN_AMX_FINDNATIVE);

	// Natives / Forwards
	REQFUNC("AddNatives", g_fn_AddNatives, PFN_ADD_NATIVES);
	REQFUNC("AddNewNatives", g_fn_AddNewNatives, PFN_ADD_NEW_NATIVES);
	REQFUNC("RaiseAmxError", g_fn_RaiseAmxError, PFN_RAISE_AMXERROR);
	REQFUNC("RegisterForward", g_fn_RegisterForward, PFN_REGISTER_FORWARD);
	REQFUNC("RegisterSPForward", g_fn_RegisterSPForward, PFN_REGISTER_SPFORWARD);
	REQFUNC("RegisterSPForwardByName", g_fn_RegisterSPForwardByName, PFN_REGISTER_SPFORWARD_BYNAME);
	REQFUNC("UnregisterSPForward", g_fn_UnregisterSPForward, PFN_UNREGISTER_SPFORWARD);
	REQFUNC("ExecuteForward", g_fn_ExecuteForward, PFN_EXECUTE_FORWARD);
	REQFUNC("PrepareCellArray", g_fn_PrepareCellArray, PFN_PREPARE_CELLARRAY);
	REQFUNC("PrepareCharArray", g_fn_PrepareCharArray, PFN_PREPARE_CHARARRAY);
	REQFUNC("PrepareCellArrayA", g_fn_PrepareCellArrayA, PFN_PREPARE_CELLARRAY_A);
	REQFUNC("PrepareCharArrayA", g_fn_PrepareCharArrayA, PFN_PREPARE_CHARARRAY_A);
	// Player
	REQFUNC("IsPlayerValid", g_fn_IsPlayerValid, PFN_IS_PLAYER_VALID);
	REQFUNC("GetPlayerName", g_fn_GetPlayerName, PFN_GET_PLAYER_NAME);
	REQFUNC("GetPlayerIP", g_fn_GetPlayerIP, PFN_GET_PLAYER_IP);
	REQFUNC("IsPlayerInGame", g_fn_IsPlayerIngame, PFN_IS_PLAYER_INGAME);		
	REQFUNC("IsPlayerBot", g_fn_IsPlayerBot, PFN_IS_PLAYER_BOT);	
	REQFUNC("IsPlayerAuthorized", g_fn_IsPlayerAuthorized, PFN_IS_PLAYER_AUTHORIZED);
	REQFUNC("GetPlayerTime", g_fn_GetPlayerTime, PFN_GET_PLAYER_TIME);
	REQFUNC("GetPlayerPlayTime", g_fn_GetPlayerPlayTime, PFN_GET_PLAYER_PLAYTIME);
	REQFUNC("GetPlayerCurweapon", g_fn_GetPlayerCurweapon, PFN_GET_PLAYER_CURWEAPON);
	REQFUNC("GetPlayerTeamID", g_fn_GetPlayerTeamID, PFN_GET_PLAYER_TEAMID);
	REQFUNC("GetPlayerTeam",g_fn_GetPlayerTeam, PFN_GET_PLAYER_TEAM);
	REQFUNC("GetPlayerDeaths", g_fn_GetPlayerDeaths, PFN_GET_PLAYER_DEATHS);
	REQFUNC("GetPlayerMenu", g_fn_GetPlayerMenu, PFN_GET_PLAYER_MENU);
	REQFUNC("GetPlayerKeys", g_fn_GetPlayerKeys, PFN_GET_PLAYER_KEYS);
	REQFUNC("IsPlayerAlive", g_fn_IsPlayerAlive, PFN_IS_PLAYER_ALIVE);
	REQFUNC("GetPlayerFrags", g_fn_GetPlayerFrags, PFN_GET_PLAYER_FRAGS);
	REQFUNC("IsPlayerConnecting", g_fn_IsPlayerConnecting, PFN_IS_PLAYER_CONNECTING);
	REQFUNC("IsPlayerHLTV", g_fn_IsPlayerHLTV, PFN_IS_PLAYER_HLTV);
	REQFUNC("GetPlayerArmor", g_fn_GetPlayerArmor, PFN_GET_PLAYER_ARMOR);
	REQFUNC("GetPlayerHealth", g_fn_GetPlayerHealth, PFN_GET_PLAYER_HEALTH);
	REQFUNC("GetPlayerFlags", g_fn_GetPlayerFlags, PFN_GETPLAYERFLAGS);
	REQFUNC("GetPlayerEdict", g_fn_GetPlayerEdict, PFN_GET_PLAYER_EDICT);
	REQFUNC("amx_Push", g_fn_AmxPush, PFN_AMX_PUSH);
	REQFUNC("SetPlayerTeamInfo", g_fn_SetTeamInfo, PFN_SET_TEAM_INFO);
	REQFUNC("PlayerPropAddr", g_fn_PlayerPropAddr, PFN_PLAYER_PROP_ADDR);
	REQFUNC("RegAuthFunc", g_fn_RegAuthFunc, PFN_REG_AUTH_FUNC);
	REQFUNC("UnregAuthFunc", g_fn_UnregAuthFunc, PFN_UNREG_AUTH_FUNC);

	//Added in 1.75 
	REQFUNC("FindLibrary", g_fn_FindLibrary, PFN_FINDLIBRARY);
	REQFUNC("AddLibraries", g_fn_AddLibraries, PFN_ADDLIBRARIES);
	REQFUNC("RemoveLibraries", g_fn_RemoveLibraries, PFN_REMOVELIBRARIES);
	REQFUNC("OverrideNatives", g_fn_OverrideNatives, PFN_OVERRIDENATIVES);
	REQFUNC("GetLocalInfo", g_fn_GetLocalInfo, PFN_GETLOCALINFO);
	REQFUNC("AmxReregister", g_fn_AmxReRegister, PFN_AMX_REREGISTER);

	REQFUNC("MessageBlock", g_fn_MessageBlock, PFN_MESSAGE_BLOCK);

#ifdef MEMORY_TEST
	// Memory
	REQFUNC_OPT("Allocator", g_fn_Allocator, PFN_ALLOCATOR);
	REQFUNC_OPT("Reallocator", g_fn_Reallocator, PFN_REALLOCATOR);
	REQFUNC_OPT("Deallocator", g_fn_Deallocator, PFN_DEALLOCATOR);
#endif

	REQFUNC("CellToReal", g_fn_CellToReal, PFN_CELL_TO_REAL);
	REQFUNC("RealToCell", g_fn_RealToCell, PFN_REAL_TO_CELL);

#ifdef FN_AMXX_ATTACH
	FN_AMXX_ATTACH();
#endif // FN_AMXX_ATACH

	return AMXX_OK;
}

C_DLLEXPORT int AMXX_Detach()
{
#ifdef FN_AMXX_DETACH
	FN_AMXX_DETACH();
#endif // FN_AMXX_DETACH

	return AMXX_OK;
}

C_DLLEXPORT int AMXX_PluginsLoaded()
{
#ifdef FN_AMXX_PLUGINSLOADED
	FN_AMXX_PLUGINSLOADED();
#endif // FN_AMXX_PLUGINSLOADED
	return AMXX_OK;
}

C_DLLEXPORT void AMXX_PluginsUnloaded()
{
#ifdef FN_AMXX_PLUGINSUNLOADED
	FN_AMXX_PLUGINSUNLOADED();
#endif // FN_AMXX_PLUGINSUNLOADED
}

C_DLLEXPORT void AMXX_PluginsUnloading()
{
#ifdef FN_AMXX_PLUGINSUNLOADING
	FN_AMXX_PLUGINSUNLOADING();
#endif // FN_AMXX_PLUGINSUNLOADING
}

// Advanced MF functions
void MF_Log(const char *fmt, ...)
{
	char msg[3072];
	va_list arglst;
	va_start(arglst, fmt);
	vsnprintf(msg, sizeof(msg) - 1, fmt, arglst);
	va_end(arglst);

	g_fn_Log("[%s] %s", MODULE_LOGTAG, msg);
}

void MF_LogError(AMX *amx, int err, const char *fmt, ...)
{
	char msg[3072];
	va_list arglst;
	va_start(arglst, fmt);
	vsnprintf(msg, sizeof(msg) - 1, fmt, arglst);
	va_end(arglst);

	g_fn_LogErrorFunc(amx, err, "[%s] %s", MODULE_LOGTAG, msg);
}