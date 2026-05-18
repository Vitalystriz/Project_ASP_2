//
// Created by vitaly on 29.04.2026.
//

#ifndef INITIALIZATION_H
#define INITIALIZATION_H


#include <map>

#include "DataManager.h"
#include "command/ICommand.h"
class Initialization {
  public:
    std::map<std::string, ICommand*> createCommandMapForCLIMode(DataManager* dm);
    std::map<std::string, ICommand*> createCommandMapForServerMode(DataManager* dm);
    void appLaunch();
};



#endif //INITIALIZATION_H
