//
// Created by vitaly 30.04.2026.
//
// src/main.cpp

#include "Initialization.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error, write port, example: ./server 8080" << std::endl;
        return 1;
    }
    int port = std::stoi(argv[1]);
    // Create an instance of your Initialization class
    Initialization initializer;

    // Launch the application
    initializer.appLaunchForServerMode();
    // TODO integrate server
    // Initialize server
    // TCPServer server = TCPServer(port, &initializer);
    // server.start();
    // The program will run until appLaunch() finishes.
    return 0;
}
