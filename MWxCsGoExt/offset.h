#pragma once
#include <Windows.h>

uintptr_t client_module = 0;
uintptr_t engine_module = 0;
uintptr_t server_module = 0;
uintptr_t module_size;


uintptr_t m_aimPunchAngle = 0x302C;
uintptr_t m_bBombPlanted = 0x99D;
uintptr_t m_bHasDefuser = 0xB378;
uintptr_t m_bHasHelmet = 0xB35C;
uintptr_t m_bInReload = 0x3295;
uintptr_t m_bIsDefusing = 0x391C;
uintptr_t m_bIsScoped = 0x3914;
uintptr_t m_bSpotted = 0x93D;
uintptr_t m_dwBoneMatrix = 0x26A8;
uintptr_t m_hActiveWeapon = 0x2EF8;
uintptr_t m_iCrosshairId = 0xB3D4;
uintptr_t m_iGlowIndex = 0xA428;
uintptr_t m_iHealth = 0x100;
uintptr_t m_iTeamNum = 0xF4;
uintptr_t m_lifeState = 0x25F;
uintptr_t m_vecOrigin = 0x138;
uintptr_t m_vecVelocity = 0x114;
uintptr_t m_vecViewOffset = 0x108;
uintptr_t m_viewPunchAngle = 0x3020;
uintptr_t dwEntityList = 0x4D3C7BC;
uintptr_t dwForceAttack = 0x316DD80;
uintptr_t dwForceAttack2 = 0x316DD8C;
uintptr_t dwForceBackward = 0x316DDD4;
uintptr_t dwForceForward = 0x316DDB0;
uintptr_t dwForceJump = 0x51E0004;
uintptr_t dwForceLeft = 0x316DDC8;
uintptr_t dwForceRight = 0x316DDEC;
uintptr_t dwGameDir = 0x6274F8;
uintptr_t dwLocalPlayer = 0xD28B74;
uintptr_t dwViewMatrix = 0x4D2E0E4;
uintptr_t m_bDormant = 0xED;


class Offset
{
public:
	uintptr_t entityList = 0;
	uintptr_t entDist = 0x10;

	uintptr_t getEntList()
	{
		g_memory.read(client_module + dwEntityList, &entityList, 4);
		return entityList;
	}
};



