# PiMine

![Version](https://img.shields.io/badge/version-0.1-blue)
![License](https://img.shields.io/badge/license-MIT-green)

**PiMine** is a lightweight CLI tool that gets a fully working Minecraft Java Edition server running on your Raspberry Pi (3, 4, or 5) — or any Linux machine — in minutes.

Skip the usual pain: no manual Java setup, no downloading jars yourself, no editing EULA files by hand. Just run the binary, answer a couple of quick questions, and your server is live for you and your friends.

### Key Features
- **Precompiled binaries included** right in the repo — one for ARM (Raspberry Pi) and one for x86-64 Linux — run them directly, no build step required in most cases  
- Automatically installs missing dependencies (Java, curl, git, etc.)  
- Downloads the latest stable Minecraft server jar  
- Accepts the EULA for you    
- Starts the server right away  
- Low overhead — performs well on Pi 4/5 with reasonable player counts  

### Quick Start (Using Precompiled Binaries — Easiest Way)

The binaries are already in the repo root: `mypiserver-arm` and `mypiserverx86-64`.

0.1: Clone the repo:
   git clone https://github.com/rasberrypimine/pimine.git
   cd pimine
0.2: Make it executable:
    chmod +x mypiserver-arm
    chmod +x mypiserverx86-64
0.3: Launch it!
   ./mypiserver-arm             # on Raspberry Pi 3/4/5
   ./mypiserverx86-64           # on desktop/server Linux (x86-64)
   
0.4: Customize it!
    Precompiled binaries doesnt support easier customizations yet. Please follow 1.1 for manual customizations.
    
### Building from Source (If You Want to Customize)
1.1: Warning:
    It is recommended you use the precompiled binaries as they have been tested.
    To compile on x86-64 and use them on arm devices you must use a cross compiler or directly compile in your arm device.
    
1.2: Clone the repo:
   git clone https://github.com/rasberrypimine/pimine.git
   cd pimine
   
1.3: Customize it!
    To make ram customizations check src/run.cpp
    To make server customizations add your own server link in helpers/installer.sh (some servers might require different JDK versions)
    Don't touch the header(.h) files unless you add or remove a cpp file.
    
1.4: Compiling!
    Compiling is pretty easy on raspberry pi and your linux device.
    Run sudo apt install build-essential (Debian based distro rasberry pi os, ubuntu etc.)
    Run sudo pacman -S gcc (Arch based distros)
    Run sudo dnf install gcc-c++ (Fedora)
    
1.5: Run it!
    Run chmod +x (your compiled binary name)
    ./(your compiled binary name)
    
1.6: Thats it!
    If you have had any issues compiling please make an issue and compling process can change later on the newer versions please check this part every time a new version releases!
    
### Whats next?
2.1: Due to lack of people in this project updates might take a while.
2.2: Check 3.1 for our goals.

### Version 0.2 goals!
3.1: We are planning a new version picker (version -- 1.21)

3.2: Support for Paper/Purpur/Spigot

3.3: More easier way to customize your pimine

3.4: And our own discord server!

3.5: A website that will run on port 2500 on your device’s IP that will make controlling your minecraft server very easy (We are working on this very heavily.)
