#include <iostream>
#include <cstdlib>
#include <string>

void run() {
    std::cout << "Starting Minecraft server..." << std::endl;

    // Determine the correct home directory (even if running with sudo)
    const char* sudo_user = getenv("SUDO_USER");  // non-root user if sudo is used
    std::string home_dir;

    if (sudo_user) {
        home_dir = std::string("/home/") + sudo_user;
    } else {
        home_dir = getenv("HOME");
    }

    std::string folder = home_dir + "/minecraft-server";

    std::string cmd_first_run = "echo 'Current folder:' && cd " + folder +
                                " && pwd && java -Xms512M -Xmx2G -jar server.jar nogui || true";
    system(cmd_first_run.c_str());

    // Ensure EULA is accepted
    std::string eula_cmd = "echo 'eula=true' > " + folder + "/eula.txt";
    system(eula_cmd.c_str());

    std::cout << "EULA accepted. Running server properly now..." << std::endl;

    // Run server properly
    std::string cmd_run = "cd " + folder + " && java -Xms512M -Xmx2G -jar server.jar nogui";
    system(cmd_run.c_str());
}
