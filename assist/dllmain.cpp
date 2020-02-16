// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <iostream>
#include "Header.h" // TODO : peremestit' strukturu.
#include <string>


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
#pragma pack(push,1)
typedef struct
{
    BYTE Padding1[3];
    BYTE OEM_Name[8];
} NTFS_BootRecord;
#pragma pack(pop)

std::string byte2ch(BYTE* data, int size)
{
    return std::string((char*)data, size);
}

extern "C" __declspec(dllexport) void CheckPhysDrives(bool* rez,int DriveNum,std::string fileName)
{

    std::string fullPath = fileName + std::to_string(DriveNum);
    HANDLE fileHandle = CreateFileA(
        fullPath.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (fileHandle != INVALID_HANDLE_VALUE)
    {
        *rez = true;
    }
    else
    {
        *rez = false;      
    }
}
extern "C" __declspec(dllexport) void CheckVolume(bool* rez,std::string fileName,std::string letter)
{
    std::string fullPath = fileName + letter+":";
    HANDLE fileHandle = CreateFileA(
        fullPath.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (fileHandle != INVALID_HANDLE_VALUE)
    {
        *rez = true;
    }
    else
    {
        *rez = false;
    }
}


