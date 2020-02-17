#pragma once
typedef void (*checkIsNTFS)(bool&,bool&,bool&,bool&, std::string);
typedef void (*checkPhys)(bool&, int, std::string);
typedef void (*checkVol)(bool&, bool&, bool&, std::string, std::string,std::string&);

