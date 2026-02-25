# PiMine

![Version](https://img.shields.io/badge/version-0.3-blue)
![License](https://img.shields.io/badge/license-MIT-green)


**PiMine** is a lightweight CLI tool that gets a fully working Minecraft Java Edition server running on your Raspberry Pi (3, 4, or 5) — or any Linux machine — in minutes.

Skip the usual pain: no manual Java setup, no downloading jars yourself, no editing EULA files by hand. Just run the binary, answer a couple of quick questions, and your server is live for you and you[...] 

### Key Features
- **Precompiled binaries included** right in our latest releases!!! — one for ARM (Raspberry Pi) and one for x86-64 Linux — run them directly, no build step required in most cases  
- Automatically installs missing dependencies (Java, curl, git, etc.)  
- Downloads the latest stable Minecraft server jar  
- Accepts the EULA for you    
- Starts the server right away  
- Low overhead — performs well on Pi 4/5 with reasonable player counts
- Very maintaned repo.
- Fast support times.

### Quick Start (Using Precompiled Binaries — Easiest Way)

The binaries are already in the repo releases: `pimine-arm` and `pimine-x86-64`.

**0.1:** Install the precompiled binaries:
**ARM**
```bash
wget https://github.com/paxxydevv/pimine/releases/download/Base_release_0.3/pimine-arm.tar.gz # Arm raspberry pi sbms etc.
```
**x86-64**
```bash
wget https://github.com/paxxydevv/pimine/releases/download/Base_release_0.3/pimine-x86-64.tar.gz # Lunix desktop machines.
```

**0.2:** Unzip it!
**ARM**
```bash
tar -xzf pimine-arm.tar.gz # arm
```
**x86-64**
```bash
tar -xzf pimine-x86-64.tar.gz # x86-64
```

**0.3:** Make it executable:
**ARM**
```bash
chmod +x pimine-arm
```
**x86-64**
```bash
chmod +x pimine-x86-64
```

**0.4:** Launch it!
```bash
./pimine-arm             # on Raspberry Pi 3/4/5
./pimine-x86-64           # on desktop/server Linux (x86-64)
```

**0.5:** Customize it!
Precompiled binaries now support easier customisation.
You can easily change max ram, port, host website (wip) etc.
You can do it so by changing pimine.conf

**0.6:** Startup arguments:
In the 0.3 update we released startup arguments you can use them by:
- "--run" This argument will try to launch the server in the normal install dir.
- "--clean" This argument will try to clear all of the pimines file if you ever wanted to delete.
- "--version" This argument will show the pimine version.
Please let us know if you would like anohter startup argument.

### Building from Source (If You Want to Customize or any other reason at all!)

**1.1:** Warning:
It is recommended you use the precompiled binaries as they have been tested. To compile on x86-64 and use them on ARM devices, you must use a cross compiler or directly compile on your ARM device.

**1.2:** Clone the repo:
```bash
git clone https://github.com/paxxydevv/pimine.git
cd pimine
```

**1.3:** Customize it!
- To make RAM customizations, check `pimine.conf`
- To make server customizations, add your own server link in `helpers/installer.sh` (some servers might require different Java versions)
- Don't touch the header (`.h`) files unless you add or remove a `.cpp` file

**1.4:** Install build tools:
```bash
# Debian-based distros (Raspberry Pi OS, Ubuntu, etc.)
sudo apt install build-essential

# Arch-based distros
sudo pacman -S gcc

# Fedora-based distros
sudo dnf install gcc-c++

# If your distro isn't here, it's mostly:
sudo (package manager) install gcc
```
**1.4 INFO**:
We have a built in tool in helpers/easycompiler.sh
```bash
./helpers/easycompiler.sh
```

**1.5:** Compile and run:
```bash
chmod +x (your compiled binary name)
./(your compiled binary name)
```
**1.6:** Startup arguments:
In the 0.3 update we released startup arguments you can use them by:
- "--run" This argument will try to launch the server in the normal install dir.
- "--clean" This argument will try to clear all of the pimines file if you ever wanted to delete.
- "--version" This argument will show the pimine version.
Please let us know if you would like anohter startup argument.

**1.7:** That's it!
If you have any issues compiling, please create an issue. The compilation process may change in newer versions, so check this section every time a new version releases!

### Troubleshooting

**Issue: "Command not found" when running the binary**
- Make sure you ran `chmod +x` on the binary first
- Verify you're in the correct directory: `ls -la | grep pimine(arm or x86-64)`

**Issue: Java not found**
- The binary should auto-install Java, but if it fails, try manually installing: `sudo apt install default-jre` (Debian) or equivalent for your distro

**Issue: Port 25565 already in use**
- Another server is using the Minecraft port. Stop it or change the port in your server configuration

**Issue: Server crashes on startup**
- Check that you have enough RAM available (minimum 512MB recommended for Pi)
- Review the server logs for specific error messages

**Issue: Script says there are missing dependencies**
- That almost always means you are not using a Debian-based distro. We hardcoded installation of required dependencies.
- Please manually install them. You will need: curl, git, python3 (not required, recommended), openjdk-25-jre-headless, jq
- Or check your internet connection!

### What's Next?
- **Version 0.4 goals:**
  - Web dashboard.
- **Note:** Due to limited contributors, updates may take time. Want to help? Create an issue and pr to join the project!

### License
This project is licensed under the MIT License — see the LICENSE file for details.
### Extra support:
Tiktok: paxx.cracks.the.h
### Extra Note
**IMPORTANT** This is a solo project. Please create an issue if you wish to join this project. There might be a lot of bugs — we'd love it if you reported them to us. Thanks for your support!
**IMPORTANT** We are possibly thinking to remove x86-64 due to lack of support we are having right now.
**How can you help me?** 
- If this helped you, please consider starring the repo!
- Found a bug? Open an issue — I respond quickly!
