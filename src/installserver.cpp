#include <iostream>
#include <cstdlib>
#include <string>
#include "run.h"

void install() {
    std::string option;

    std::cout << "Installing dependencies now..." << std::endl;
    // Install dependencies (sudo required)
    system("sudo apt update && sudo apt install -y curl git python3 openjdk-25-jre-headless");

    std::cout << "Installing latest Minecraft server now..." << std::endl;
    system("./helpers/install.sh");

    std::cout << "Installed Minecraft server!" << std::endl;
    std::cout << "Server should be in ~/minecraft-server" << std::endl;

    std::cout << "Do you wish to start the server now? (y, N): ";
    std::cin >> option;

    if (option == "y" || option == "Y") {
        run();
    } else {
        std::cout << "Thank you for using minepi <3" << std::endl;
        exit(0);
    }
}
