//
// Created by vitaly on 29.04.2026.
//

#include "Initialization.h"
#include <map>
#include "command/ICommand.h"
#include "App.h"
#include "menu/ConsoleMenu.h"
#include "command/HelpCommand.h"
#include "command/AddCommand.h"
#include "command/DisplayErrorClass.h"
#include "command/RecommendCommand.h"
#include "LoadingData.h"



std::map<std::string, ICommand*> Initialization::createCommandMap(DataManager* dm) {
    std::map<std::string, ICommand*> commands; // fix magic numbers trouble - done

    commands["error"] = new DisplayErrorClass();
    commands["help"] = new HelpCommand();
    commands["add"] = new AddCommand(dm);
    commands["recommend"] = new RecommendCommand(dm);
    commands["exit"] = nullptr;

    return commands;
}

void Initialization::appLaunch() {

    IMenu* menu = new ConsoleMenu();
    auto* dataManager = new DataManager();

    LoadingData loadingData;
    loadingData.load(dataManager);


    std::map<std::string, ICommand*> commands = createCommandMap(dataManager);

    App app(menu, commands);


    app.run();


    for (auto const& [key, val] : commands) {
        delete val;
    }
    delete menu;
    delete dataManager;
}