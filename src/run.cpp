#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

std::string minram = "1G";   // defaults
std::string maxram = "2G";
std::string port = "25565";
bool createsite = false;

void readConfig() {
    std::ifstream file("pimine.conf");

    if (!file.is_open()) {
        std::cout << "No config found. Using defaults.\n";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t pos = line.find('=');
        if (pos == std::string::npos) continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        
        key.erase(0, key.find_first_not_of(" "));
        key.erase(key.find_last_not_of(" ") + 1);
        value.erase(0, value.find_first_not_of(" "));
        value.erase(value.find_last_not_of(" ") + 1);

        if (key == "minram") minram = value;
        else if (key == "maxram") maxram = value;
        else if (key == "port") port = value;
        else if (key == "createsite") createsite = (value == "true");
    }
}

void run() {
    std::cout << "Starting Minecraft server...\n";
    readConfig();

    const char* sudo_user = getenv("SUDO_USER");
    std::string home_dir;

    if (sudo_user)
        home_dir = std::string("/home/") + sudo_user;
    else
        home_dir = getenv("HOME");

    std::string folder = home_dir + "/minecraft-server";

    
    std::string eula_cmd = "echo 'eula=true' > " + folder + "/eula.txt";
    system(eula_cmd.c_str());

    std::string check_props = folder + "/server.properties";
    std::ifstream props(check_props);

    if (!props.good()) {
        std::cout << "First launch: generating server files...\n";

        std::string first_run =
            "cd " + folder +
            " && java -Xms" + minram +
            " -Xmx" + maxram +
            " -jar server.jar nogui & "
            "sleep 10 && pkill -f server.jar";

        system(first_run.c_str());
    }

    std::string port_cmd =
        "cd " + folder +
        " && sed -i 's/^server-port=.*/server-port=" + port + "/' server.properties";

    system(port_cmd.c_str());

    std::cout << "Running Minecraft server on port " << port << "...\n";

    std::string run_cmd =
        "cd " + folder +
        " && java -Xms" + minram +
        " -Xmx" + maxram +
        " -jar server.jar nogui";

    system(run_cmd.c_str());
}
