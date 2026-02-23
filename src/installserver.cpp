#include <iostream>
#include <cstdlib>
#include <string>
#include "run.h"
#include <vector>
void install() {
    std::vector<std::string> versions = {
    "1.21.11",
    "1.21.10",
    "1.21.9",
    "1.21.8",
    "1.21.7",
    "1.21.6",
    "1.21.5",
    "1.21.4",
    "1.21.3",
    "1.21.2",
    "1.21.1",
    "1.21",
    "1.20.6",
    "1.20.5",
    "1.20.4",
    "1.20.3",
    "1.20.2",
    "1.20.1",
    "1.20",
    "1.19.4",
    "1.19.3",
    "1.19.2",
    "1.19.1",
    "1.19",
    "1.18.2",
    "1.18.1",
    "1.18",
    "1.17.1",
    "1.17",
    "1.16.5"
    };
    std::cout << "Available minecraft versions:" << std::endl;
    for (size_t i = 0; i < versions.size(); ++i) {
	    std::cout << i+1 << ") " << versions[i] << "\n";
    }
    std::string option;
    int choice;
    std::cout << "Select a version to install (1-" << versions.size() << "):";
    std::cin >> choice;
    if (choice < 1 || choice > versions.size()) {
		std::cout << "Invalid choice, installing latest by default. ";
		choice = 1;
    }
    std::cout << "Installing dependencies now..." << std::endl;
    // Install dependencies (sudo required) becuase minecraft need some dependencies to run and function!
    system("sudo apt update && sudo apt install -y curl git python3 openjdk-25-jre-headless jq");
    system("clear");
    std::string selected_version = versions[choice-1];
    std::cout << "Installing "+selected_version+"_Minecraft server now..." << std::endl;
    std::string cmd = "./helpers/install.sh " + selected_version;
    system(cmd.c_str());
    std::cout << "Installed Minecraft server!" << std::endl;
    std::cout << "Server should be in ~/minecraft-server" << std::endl;

    std::cout << "Do you wish to start the server now? (y, N): ";
    std::cin >> option;

    if (option == "y" || option == "Y") {
        run();
    } else {
        std::cout << "Thank you for using pimine:<3" << std::endl;
        exit(0);
    }
}
