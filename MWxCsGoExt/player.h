#pragma once



class Player
{
private:
public:
	uintptr_t localPlayer;
	uintptr_t playerInCross;

	int crosshairId;
	int team;
	int lifeState;
	int health;
	vec3 position;



	uintptr_t getLocalPlayer();

	int getTeam();
	int getLifeState();
	int getHealth();
	int getCrosshairId();

	vec3 getPosition();
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



	uintptr_t getPlayerAddress(int i);
	uintptr_t getCrosshairId();
	int getTeam();
	int getLifeState();
	int getHealth();
	vec3 getPosition();



};