#pragma once
#include <Windows.h>

#pragma pack(push,1)
typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
} NTFS_BootRecord;
#pragma pack(pop)
