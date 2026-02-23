#include "src/install.h"
#include <iostream>
#include <string>
#include <unistd.h>
int main() {
	std::string choice;
	std::cout << "Welcome to pimine!" << std::endl;
	std::cout << "Build date 0.2 - Bug patches" << std::endl;
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
