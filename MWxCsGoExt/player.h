#pragma once
#include <Windows.h>
#include "memory.h"
#include "offset.h"
#include "math.h"

Offset offset;


class CGame
{
private:
public:
	uintptr_t localPlayer = 0;
	uintptr_t playerInCross = 0;

	int crosshairId;
	int team;
	int lifeState;
	int health;
	vec3 position;



	uintptr_t getLocalPlayer()
	{
		g_memory.read(client_module + dwLocalPlayer, &localPlayer, 4);
		return localPlayer;
	}

	int getTeam()
	{
		g_memory.read(localPlayer + m_iTeamNum, &team, 4);
		return team;
	}

	int getLifeState()
	{
		g_memory.read(localPlayer + m_lifeState, &team, 4);
		return lifeState;
	}

	int getHealth()
	{
		g_memory.read(localPlayer + m_iHealth, &health, 4);
		return health;
	}

	vec3 getPosition()
	{
		g_memory.read(localPlayer + m_vecOrigin, &position, 12);
		return position;
	}

	int getCrosshairId()
	{
		g_memory.read(localPlayer + m_iCrosshairId, &crosshairId, 4);
		return crosshairId;
	}

};

class CBaseEntity
{
public:


	uintptr_t player_address = 0;
	vec3 position;

	int localCrossId;
	int crosshairId;
	int lifeState;
	int health;
	int team;
	int flags;
	ULONG active_weapon;



	uintptr_t getPlayerAddress(int i)
	{
		g_memory.read(client_module + dwEntityList + ((i)*offset.entDist), &player_address, 4);
		return player_address;
	}

	uintptr_t getCrosshairId()
	{
		g_memory.read(player_address + m_iCrosshairId, &crosshairId, 4);
		return crosshairId;
	}

	int getTeam()
	{
		// 1=spec 2=t 3=ct
		g_memory.read(player_address + m_iTeamNum, &team, 4);
		return team;
	}

	int getLifeState()
	{
		/*
		enum LifeState {
			LIFE_ALIVE = 0,// alive
			LIFE_DYING = 1, // playing death animation or still falling off of a ledge waiting to hit ground
			LIFE_DEAD = 2 // dead. lying still.
		};
		*/
		g_memory.read(player_address + m_lifeState, &lifeState, 4);
		return lifeState;
	}

	vec3 getPosition()
	{
		g_memory.read(player_address + m_vecOrigin, &position, 12);
		return position;
	}


	int getHealth()
	{
		g_memory.read(player_address + m_iHealth, &health, 4);
		return health;
	}

};