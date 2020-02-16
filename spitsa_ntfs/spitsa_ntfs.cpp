#include <iostream>
#include <Windows.h>
#include <string>
#include "diffDef.h"


int calcAndShowAlldrives(checkPhys dllCheckPhysDrives)
{
    int foundDriveCount = 0;
    bool checkResult = false;
    std::string fileName = "\\\\.\\PhysicalDrive";
    std::cout << "       ------------------------------------" << std::endl;
    for (int DriveNum = 0; DriveNum < 30; DriveNum++)
    {
        checkResult = false;
        std::string sysType="";
        dllCheckPhysDrives(checkResult, DriveNum, fileName);
        if (checkResult == true)
        {
            std::cout << "       " << fileName << DriveNum << "             exist " << std::endl;
            foundDriveCount++;
        }
    }
    std::cout << "\n" << "       Summary physical drives founded : " << foundDriveCount << std::endl;
    std::cout << "       ------------------------------------\n" << "\n" << std::endl;
    return foundDriveCount;
}

int calcAndShowAllVolumes(checkVol dllCheckVolume)
{
    std::string fileName = "\\\\.\\";
    const int alphCount = 26;
    int foundVolumes = 0;
    std::string letters[alphCount] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
    for (int letterNum = 0; letterNum < 26; letterNum++)
    {
        bool checkResult = false;
        bool checkPointer = false;
        bool checkReading = false;
        std::string sysType = "";
        dllCheckVolume(checkResult, checkPointer, checkReading, fileName, letters[letterNum], sysType);
        if (checkResult == true)
        {
            std::cout << "       " << fileName << letters[letterNum] << "           exist " << std::endl;
            foundVolumes++;
            if (checkPointer == false)
            {
                std::cout << "       GOT PROBLEMS WITH READING ITS SYS TYPE (SetFilePointer PROBLEM) " << std::endl;
            }
            else
            {
                if (checkReading == false)
                {
                    std::cout << "       GOT PROBLEMS WITH READING ITS SYS TYPE (Reading info PROBLEM) " << std::endl;
                }
                else
                {
                    //TODO: SHOW SYS TYPE! (sysType string) 

                }
            }
        }
    };
    std::cout << "\n" << "       Summary volume drives founded : " << foundVolumes << std::endl;
    std::cout << "       ------------------------------------\n" << "\n" << std::endl;
    return foundVolumes;
}

int main()
{   
    HMODULE hLib = LoadLibrary(L"assist.dll");
    if (hLib == NULL)
    {
        std::cout << "No able to attach dll !" << std::endl;
    }
    else
    {
        checkPhys dllCheckPhysDrives = (checkPhys)GetProcAddress(hLib, "CheckPhysDrives");
        if (!dllCheckPhysDrives)
        {
            std::cout << "Error while getting func address (Phys)" << std::endl; //TODO : ERROR COLOR ??
        }
        else
        {
            if (calcAndShowAlldrives(dllCheckPhysDrives) == 0)
            {
                std::cout << "\n" << "  No drives exist, stopping programm..." << std::endl;
                std::cin;  //TODO : ERROR COLOR ??
            }
            else
            {
                checkVol dllCheckVolume = (checkVol)GetProcAddress(hLib, "CheckVolume");
                if (!dllCheckVolume)
                {
                    std::cout << "Error while getting func address (Volumes)"<< std::endl; //TODO : ERROR COLOR ??
                }
                else
                {   
                    if (calcAndShowAllVolumes(dllCheckVolume) == 0)
                    {
                        std::cout << "\n" << "  No drives exist, stopping programm..." << std::endl;
                        std::cin;  //TODO : ERROR COLOR ??
                    }
                    else
                    {   //TODO: GET MORE INFO?
                    }
                }
            }
        }
    }
}

