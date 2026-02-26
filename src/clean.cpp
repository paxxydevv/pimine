#include <iostream>
void clear() {
	std::cout << "This program will clear everthing pimine has installed and clear it off your system!" << std::endl; 
	std::cout << "Press enter to begin.." << std::endl;
	std::cin;
	std::cout << "[1/3] Clearing and removing install_dir" << std::endl;
	system("rm -rf ~/minecraft-server");
	std::cout << "[2/3] Deleting visudo rule.." << std::endl;
	system("sudo rm -f /etc/sudoers.d/pimine");
	std::cout << "[3/3 Finishing up..]" << std::endl;
	std::cout << "All files have been cleared! You can now safely delete the pimine folder if you have it." << std::endl;
	std::cout << "Its sad to see you go but thanks for using pimine!" << std::endl;
	exit(1);
}
