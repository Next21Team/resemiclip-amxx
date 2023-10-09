#if defined _resemiclip_included
	#endinput
#endif
#define _resemiclip_included

#pragma reqlib resemiclip
#if !defined AMXMODX_NOAUTOLOAD
	#pragma loadlib resemiclip
#endif

static const INT32_MAX = 0xFFFFFFFF

enum (+=-1)
{
	RESEMICLIP_DISABLED,
	RESEMICLIP_ALL
}

/**
 * Taking the control of semiclip rules
 *
 * @param take      If true, the built-in module semiclip rules will stop working in favor of plugins
 *
 * @note			You have to take control of semiclip rules first before using other natives
 *
 * @return          Actual bitsum of the other players on which semiclip should work
 */
native resemiclip_take_control(bool:take);

/**
 * Sets semiclip mask for player
 *
 * @param id        Player to set the bitsum
 * @param mask   	Actual bitsum of the other players on which semiclip should work
 *
 * @note 			It's a low-level API and and it will be more convenient to use
 * 					resemiclip_set_user_ignore instead to manage semiclip relative state
 *
 * @noreturn
 */
native resemiclip_set_user_mask(id, mask);

/**
 * Returns a current semiclip mask of players on which semiclip should work
 *
 * @param id        Player from whom you need to get bitsum
 *
 * @return          Actual bitsum of the other players on which semiclip should work
 */
native resemiclip_get_user_mask(id);

/**
 * Switching the player's collision with the target player
 *
 * @param id        First player
 * @param target   	Second target player which the collision should not work with
 *					OR 
 *						RESEMICLIP_DISABLED — to enable collisions with all players
 *						RESEMICLIP_ALL — to disable collision with all players
 *
 * @noreturn
 */
stock resemiclip_set_user_ignore(id, target, bool:active = true)
{
	switch(target)
	{
		case RESEMICLIP_DISABLED:
		{
			resemiclip_set_user_mask(id, 0);
		}
		case RESEMICLIP_ALL:
		{
			resemiclip_set_user_mask(id, INT32_MAX)
		}
		default:
		{
			new idMask = resemiclip_get_user_mask(id)
			new targetMask = resemiclip_get_user_mask(target)

			if(active) 
			{
				if(idMask != INT32_MAX) resemiclip_set_user_mask(id, idMask | client_bit(target));
				if(targetMask != INT32_MAX) resemiclip_set_user_mask(target, targetMask | client_bit(id));
			}
			else 
			{
				if(idMask != INT32_MAX) resemiclip_set_user_mask(id, idMask & ~client_bit(target));
				if(targetMask != INT32_MAX) resemiclip_set_user_mask(target, targetMask & ~client_bit(id));
			}
		}
	}
}

/**
 * Checks that the collision of the player with the target player is enabled
 *
 * @param id        First player
 * @param target   	Second target player to check status of the collision with
 *
 * @return			true if the collision is enabled, false otherwise
 */
stock bool:resemiclip_get_user_ignore(id, target)
{
	return resemiclip_get_user_mask(id) & client_bit(target);
}

static client_bit(id) {
	return (1<<(id - 1));
}