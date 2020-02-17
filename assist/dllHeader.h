#pragma once
#include <Windows.h>

#pragma pack(push,1)
typedef struct
{
	BYTE Padding1[3]; //0x0
	BYTE OEM_Name[8]; //0x3
	BYTE BytesPerSecor[2];//0xB
	BYTE SectorsPerClaster[1];//0xD
	BYTE ShouldBeZero1[2];//0xE
	BYTE ShouldBeZero2[1];//0x10
	BYTE ShouldBeZero3[2];//0x11
	BYTE ShouldBeZero4[2];//0x13
	BYTE DriveType[1];//0x15
	BYTE ShouldBeZero5[2];//0x16
	BYTE ShouldBeZero6[2];//0x18
	BYTE ShouldBeZero7[2];//0x1A
	BYTE NotUsing1[4];//0x1C
	BYTE ShouldBeZero8[4];//0x20
	BYTE NotUsing2[4];//0x24
	BYTE SectorsPerVolume[8];//0x28
	BYTE StartingMFTclaster[8];//0x30
	BYTE StartingMFTclasterCopy[8];//0x38
	BYTE ClastersForMFT[1];//0x40
	BYTE NotUsing3[3];//0x41
	BYTE ClastersForIndex[1];//0x44
	BYTE NotUsing4[3];//0x45
	BYTE SerialVolumeID[8];//0x48
	BYTE NotUsing5[4];//0x50
	BYTE bigLoadingCode[426];//0x54
	BYTE EndingMarker[2];//0x1FE (should be 0xAA55)

} NTFS_BootRecord;
#pragma pack(pop)
