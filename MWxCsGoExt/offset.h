#pragma once
#include <Windows.h>

uintptr_t client_module = 0;
uintptr_t engine_module = 0;
uintptr_t server_module = 0;
uintptr_t module_size;


constexpr uintptr_t m_ArmorValue = 0xB24C;
constexpr uintptr_t m_Collision = 0x318;
constexpr uintptr_t m_CollisionGroup = 0x470;
constexpr uintptr_t m_Local = 0x2FAC;
constexpr uintptr_t m_MoveType = 0x258;
constexpr uintptr_t m_OriginalOwnerXuidHigh = 0x31A4;
constexpr uintptr_t m_OriginalOwnerXuidLow = 0x31A0;
constexpr uintptr_t m_aimPunchAngle = 0x301C;
constexpr uintptr_t m_aimPunchAngleVel = 0x3028;
constexpr uintptr_t m_bGunGameImmunity = 0x38A4;
constexpr uintptr_t m_bHasDefuser = 0xB25C;
constexpr uintptr_t m_bHasHelmet = 0xB240;
constexpr uintptr_t m_bInReload = 0x3275;
constexpr uintptr_t m_bIsDefusing = 0x3898;
constexpr uintptr_t m_bIsScoped = 0x388E;
constexpr uintptr_t m_bSpotted = 0x939;
constexpr uintptr_t m_bSpottedByMask = 0x97C;
constexpr uintptr_t m_clrRender = 0x70;
constexpr uintptr_t m_dwBoneMatrix = 0x2698;
constexpr uintptr_t m_fAccuracyPenalty = 0x32E0;
constexpr uintptr_t m_fFlags = 0x100;
constexpr uintptr_t m_flFallbackWear = 0x31B0;
constexpr uintptr_t m_flFlashDuration = 0xA308;
constexpr uintptr_t m_flFlashMaxAlpha = 0xA304;
constexpr uintptr_t m_flNextPrimaryAttack = 0x3208;
constexpr uintptr_t m_hActiveWeapon = 0x2EE8;
constexpr uintptr_t m_hMyWeapons = 0x2DE8;
constexpr uintptr_t m_hObserverTarget = 0x3360;
constexpr uintptr_t m_hOwner = 0x29BC;
constexpr uintptr_t m_hOwnerEntity = 0x148;
constexpr uintptr_t m_iAccountID = 0x2FB8;
constexpr uintptr_t m_iClip1 = 0x3234;
constexpr uintptr_t m_iCompetitiveRanking = 0x1A84;
constexpr uintptr_t m_iCompetitiveWins = 0x1B88;
constexpr uintptr_t m_iCrosshairId = 0xB2B8;
constexpr uintptr_t m_iEntityQuality = 0x2F9C;
constexpr uintptr_t m_iFOVStart = 0x31D8;
constexpr uintptr_t m_iGlowIndex = 0xA320;
constexpr uintptr_t m_iHealth = 0xFC;
constexpr uintptr_t m_iItemDefinitionIndex = 0x2F9A;
constexpr uintptr_t m_iItemIDHigh = 0x2FB0;
constexpr uintptr_t m_iObserverMode = 0x334C;
constexpr uintptr_t m_iShotsFired = 0xA2C0;
constexpr uintptr_t m_iState = 0x3228;
constexpr uintptr_t m_iTeamNum = 0xF0;
constexpr uintptr_t m_lifeState = 0x25B;
constexpr uintptr_t m_nFallbackPaintKit = 0x31A8;
constexpr uintptr_t m_nFallbackSeed = 0x31AC;
constexpr uintptr_t m_nFallbackStatTrak = 0x31B4;
constexpr uintptr_t m_nForceBone = 0x267C;
constexpr uintptr_t m_nTickBase = 0x3404;
constexpr uintptr_t m_rgflCoordinateFrame = 0x440;
constexpr uintptr_t m_szCustomName = 0x302C;
constexpr uintptr_t m_szLastPlaceName = 0x3588;
constexpr uintptr_t m_thirdPersonViewAngles = 0x31C8;
constexpr uintptr_t m_vecOrigin = 0x134;
constexpr uintptr_t m_vecVelocity = 0x110;
constexpr uintptr_t m_vecViewOffset = 0x104;
constexpr uintptr_t m_viewPunchAngle = 0x3010;
constexpr uintptr_t dwClientState = 0x586A74;
constexpr uintptr_t dwClientState_GetLocalPlayer = 0x180;
constexpr uintptr_t dwClientState_IsHLTV = 0x4CC8;
constexpr uintptr_t dwClientState_Map = 0x28C;
constexpr uintptr_t dwClientState_MapDirectory = 0x188;
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
constexpr uintptr_t dwGameDir = 0x624BF0;
constexpr uintptr_t dwGameRulesProxy = 0x514CF94;
constexpr uintptr_t dwGetAllClasses = 0xC7D26C;
constexpr uintptr_t dwGlobalVars = 0x586778;
constexpr uintptr_t dwGlowObjectManager = 0x5177CC0;
constexpr uintptr_t dwInput = 0x5082C68;
constexpr uintptr_t dwInterfaceLinkList = 0x855CD4;
constexpr uintptr_t dwLocalPlayer = 0xC5B80C;
constexpr uintptr_t dwMouseEnable = 0xC611D8;
constexpr uintptr_t dwMouseEnablePtr = 0xC611A8;
constexpr uintptr_t dwPlayerResource = 0x3077A6C;
constexpr uintptr_t dwRadarBase = 0x506CCD4;
constexpr uintptr_t dwSensitivity = 0xC61074;
constexpr uintptr_t dwSensitivityPtr = 0xC61048;
constexpr uintptr_t dwSetClanTag = 0x88680;
constexpr uintptr_t dwViewMatrix = 0x4C29A04;
constexpr uintptr_t dwWeaponTable = 0x508370C;
constexpr uintptr_t dwWeaponTableIndex = 0x322C;
constexpr uintptr_t dwYawPtr = 0xC60E38;
constexpr uintptr_t dwZoomSensitivityRatioPtr = 0xC65EF8;
constexpr uintptr_t dwbSendPackets = 0xD086A;
constexpr uintptr_t dwppDirect3DDevice9 = 0xA2F20;
constexpr uintptr_t m_pStudioHdr = 0x293C;
constexpr uintptr_t m_pitchClassPtr = 0x506CF80;
constexpr uintptr_t m_yawClassPtr = 0xC60E38;



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



