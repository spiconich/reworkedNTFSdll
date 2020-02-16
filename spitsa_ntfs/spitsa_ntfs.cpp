#include <iostream>
#include <Windows.h>
#include <string>

typedef void (*checkPhys)(bool&,int,std::string); // TODO: replace to header
typedef void (*checkVol)(bool&,std::string, std::string);
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
            int foundDriveCount = 0;
            bool checkResult = false;
            std::string fileName = "\\\\.\\PhysicalDrive";
            std::cout << "       ------------------------------------" << std::endl;
            for (int DriveNum = 0; DriveNum < 30; DriveNum++)
            {
                checkResult = false;
                dllCheckPhysDrives(checkResult, DriveNum,fileName);
                if (checkResult == true)
                {  
                    std::cout << "       "<<fileName << DriveNum << "             exist " << std::endl;
                    foundDriveCount++;
                }
            }
            std::cout << "\n"<<"       Summary physical drives founded : " << foundDriveCount << std::endl;
            std::cout << "       ------------------------------------\n"<<"\n" << std::endl;
            if (foundDriveCount == 0)
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
                    fileName = fileName = "\\\\.\\";
                    const int alphCount = 26;
                    int foundVolumes = 0;
                    std::string letters[alphCount] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
                    for (int letterNum = 0; letterNum < 26; letterNum++)
                    {
                        checkResult = false;
                        dllCheckVolume(checkResult, fileName, letters[letterNum]);
                        if (checkResult == true)
                        {
                            std::cout << "       " << fileName<< letters[letterNum] << "                          exist \n";
                            foundVolumes++;
                        }
                    };
                    std::cout << "\n" << "       Summary volume drives founded : " << foundVolumes << std::endl;
                    std::cout << "       ------------------------------------\n" << "\n" << std::endl;
                    if (foundVolumes == 0)
                    {
                        std::cout << "\n" << "  No drives exist, stopping programm...";
                        std::cin;  //TODO : ERROR COLOR ??
                    }
                    else
                    {   //TODO: GET INFO?
                    }
                }
            }
        }
    }
}

