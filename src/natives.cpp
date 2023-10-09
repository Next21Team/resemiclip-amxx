#include "precompiled.h"

cell AMX_NATIVE_CALL resemiclip_set_user_mask(AMX *amx, cell *params)
{
	enum args_e {arg_count, arg_index, arg_mask};

	int id = params[arg_index];
	int mask = params[arg_mask];

	if(!MF_IsPlayerValid(id))
	{
		MF_LogError(amx, AMX_ERR_NATIVE, "%s: unknown player %d", __FUNCTION__, id);
		return FALSE;
	}

	CGamePlayer *pPlayer = PLAYER_FOR_NUM(id - 1);
	pPlayer->SetMask(mask);

	return TRUE;
}

cell AMX_NATIVE_CALL resemiclip_get_user_mask(AMX *amx, cell *params)
{
	enum args_e {arg_count, arg_index};

	int id = params[arg_index];

	if(!MF_IsPlayerValid(id))
	{
		MF_LogError(amx, AMX_ERR_NATIVE, "%s: unknown player %d", __FUNCTION__, id);
		return 0;
	}

	CGamePlayer *pPlayer = PLAYER_FOR_NUM(id - 1);

	return pPlayer->GetMask();
}

cell AMX_NATIVE_CALL resemiclip_take_control(AMX *amx, cell *params)
{
	enum args_e {arg_count, arg_take};

	bControllingByAMXX = params[arg_take];

	return bControllingByAMXX;
}

AMX_NATIVE_INFO Semiclip_Natives[] =
{
	{"resemiclip_set_user_mask", resemiclip_set_user_mask},
	{"resemiclip_get_user_mask", resemiclip_get_user_mask},
	{"resemiclip_take_control", resemiclip_take_control},

	{nullptr, nullptr}
};

void OnAmxxAttach()
{
	RegisterNatives_Semiclip();
}

void RegisterNatives_Semiclip()
{
	MF_AddNatives(Semiclip_Natives);
}