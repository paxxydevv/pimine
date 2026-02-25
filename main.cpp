#include "src/install.h"
#include "src/clean.h"
#include "src/run.h"
#include <iostream>
#include <string>
#include <unistd.h>
int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg == "--clean") {
			clear(); // hey so if you are wondering about this function name i was too lazy to change it. It doesnt have any affects to the code
		}
		else if (arg == "--version") {
			std::cout << "Version 0.3 base release" << std::endl;
			exit(1);
		}
		else if (arg == "--run") {
			run();
		}
	}
	std::string choice;
	std::cout << "Welcome to pimine!" << std::endl;
	std::cout << "Build date 0.3 - Version Picker!" << std::endl;
	std::cout << "Do you wish to install the minecraft server now? (Y, n): ";
	std::cin >> choice;
	if (choice == "" or choice == "Y" or choice == "Yes" or choice == "yes" or choice == "y") {
		install();
	}
	if (choice == "n" or choice == "no" or choice == "No" or choice == "NO" or choice == "N") {
		std::cout << "Exiting...";
		exit(0);
	}

}
