#include "ICommand.h"
//
// Created by vitaly on 29.04.2026.
//
#include "HelpCommand.h"

    void HelpCommand::execute(std::map<std::string, std::vector<std::string>> map) {
        execute();
    }
    void HelpCommand::execute() {
        std::cout << "--- Recommendation System CLI ---" << std::endl;
        std::cout << "Available commands:" << std::endl;
        std::cout << "- help" << std::endl;
        std::cout << "- add <userId> <productId1> <productId2> ..." << std::endl;
        std::cout << "- recommend <userId> <productId>" << std::endl;
        std::cout << "- exit" << std::endl;
        std::cout << "---------------------------------" << std::endl;
    }




