#pragma once
#include <Windows.h>
#include "mem.h"

uintptr_t client_module = 0;
uintptr_t engine_module = 0;
uintptr_t server_module = 0;
uintptr_t module_size;


constexpr uintptr_t m_Local = 0x2FAC;
constexpr uintptr_t m_aimPunchAngle = 0x301C;
constexpr uintptr_t m_aimPunchAngleVel = 0x3028;
constexpr uintptr_t m_bHasDefuser = 0xB25C;
constexpr uintptr_t m_bHasHelmet = 0xB240;
constexpr uintptr_t m_bInReload = 0x3275;
constexpr uintptr_t m_bIsDefusing = 0x3898;
constexpr uintptr_t m_bIsScoped = 0x388E;
constexpr uintptr_t m_bSpotted = 0x939;
constexpr uintptr_t m_bSpottedByMask = 0x97C;
constexpr uintptr_t m_dwBoneMatrix = 0x2698;
constexpr uintptr_t m_fAccuracyPenalty = 0x32E0;
constexpr uintptr_t m_fFlags = 0x100;
constexpr uintptr_t m_hActiveWeapon = 0x2EE8;
constexpr uintptr_t m_hMyWeapons = 0x2DE8;
constexpr uintptr_t m_hObserverTarget = 0x3360;
constexpr uintptr_t m_hOwner = 0x29BC;
constexpr uintptr_t m_hOwnerEntity = 0x148;
constexpr uintptr_t m_iAccountID = 0x2FB8;
constexpr uintptr_t m_iCrosshairId = 0xB2B8;
constexpr uintptr_t m_iFOVStart = 0x31D8;
constexpr uintptr_t m_iGlowIndex = 0xA320;
constexpr uintptr_t m_iHealth = 0xFC;
constexpr uintptr_t m_iState = 0x3228;
constexpr uintptr_t m_iTeamNum = 0xF0;
constexpr uintptr_t m_lifeState = 0x25B;
constexpr uintptr_t m_nForceBone = 0x267C;
constexpr uintptr_t m_nTickBase = 0x3404;
constexpr uintptr_t m_thirdPersonViewAngles = 0x31C8;
constexpr uintptr_t m_vecOrigin = 0x134;
constexpr uintptr_t m_vecVelocity = 0x110;
constexpr uintptr_t m_vecViewOffset = 0x104;
constexpr uintptr_t m_viewPunchAngle = 0x3010;
constexpr uintptr_t dwClientState = 0x586A74;
constexpr uintptr_t dwClientState_GetLocalPlayer = 0x180;
constexpr uintptr_t dwClientState_MaxPlayer = 0x310;
constexpr uintptr_t dwClientState_PlayerInfo = 0x5240;
constexpr uintptr_t dwClientState_State = 0x108;
constexpr uintptr_t dwClientState_ViewAngles = 0x4D10;
constexpr uintptr_t dwEntityList = 0x4C37FDC;
constexpr uintptr_t dwForceAttack = 0x30796E8;
constexpr uintptr_t dwForceAttack2 = 0x30796F4;
constexpr uintptr_t dwForceBackward = 0x307973C;
constexpr uintptr_t dwForceForward = 0x3079718;
constexpr uintptr_t dwForceJump = 0x50DAC70;
constexpr uintptr_t dwForceLeft = 0x3079730;
constexpr uintptr_t dwForceRight = 0x30796B8;
constexpr uintptr_t dwGetAllClasses = 0xC7D26C;
constexpr uintptr_t dwGlobalVars = 0x586778;
constexpr uintptr_t dwGlowObjectManager = 0x5177CC0;
constexpr uintptr_t dwInput = 0x5082C68;
constexpr uintptr_t dwLocalPlayer = 0xC5B80C;
constexpr uintptr_t dwMouseEnable = 0xC611D8;
constexpr uintptr_t dwMouseEnablePtr = 0xC611A8;
constexpr uintptr_t dwRadarBase = 0x506CCD4;
constexpr uintptr_t dwViewMatrix = 0x4C29A04;
constexpr uintptr_t dwWeaponTable = 0x508370C;
constexpr uintptr_t dwWeaponTableIndex = 0x322C;
constexpr uintptr_t dwYawPtr = 0xC60E38;
constexpr uintptr_t dwppDirect3DDevice9 = 0xA2F20;
constexpr uintptr_t m_pitchClassPtr = 0x506CF80;
constexpr uintptr_t m_yawClassPtr = 0xC60E38;



class Offset
{
public:
	uintptr_t entDist = 0x10;
	uintptr_t entityList = 0;

	uintptr_t getEntList()
	{
		//g_memory.read(client_module + dwEntityList, &entityList, 4);
		return entityList;
	}
};

