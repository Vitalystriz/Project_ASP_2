//
// Created by vitaly on 28.04.2026.
//

#include "App.h"
#include <utility>

    App::App(IMenu* menu, std::map<std::string, ICommand*> map): menu(menu), commands_map(std::move(map)) {}
    void App::run() {
        while(true) {
             std::string command = menu->nextCommand();
            if (command == "exit") {
                menu->exitMessage();
                break;
            }
            try {
                commands_map[command]->execute(menu->getArgs());
            }
            catch (...) {
                menu->displayError();
            }

        }


    }
