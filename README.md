# PiMine

![Version](https://img.shields.io/badge/version-0.1-blue)
![License](https://img.shields.io/badge/license-MIT-green)

**IMPORTANT** This is a solo project. Please create an issue if you wish to join this project. There might be a lot of bugs — we'd love it if you reported them to us. Thanks for your support!

**PiMine** is a lightweight CLI tool that gets a fully working Minecraft Java Edition server running on your Raspberry Pi (3, 4, or 5) — or any Linux machine — in minutes.

Skip the usual pain: no manual Java setup, no downloading jars yourself, no editing EULA files by hand. Just run the binary, answer a couple of quick questions, and your server is live for you and you[...] 

### Key Features
- **Precompiled binaries included** right in our latest releases!!! — one for ARM (Raspberry Pi) and one for x86-64 Linux — run them directly, no build step required in most cases  
- Automatically installs missing dependencies (Java, curl, git, etc.)  
- Downloads the latest stable Minecraft server jar  
- Accepts the EULA for you    
- Starts the server right away  
- Low overhead — performs well on Pi 4/5 with reasonable player counts  

### Quick Start (Using Precompiled Binaries — Easiest Way)

The binaries are already in the repo releases: `mypiserver-arm` and `mypiserverx86-64`.

**0.1:** Clone the repo:
```bash
git clone https://github.com/paxxydevv/pimine.git
cd pimine
```

**0.2:** Make it executable:
```bash
chmod +x mypiserver-arm
chmod +x mypiserverx86-64
```

**0.3:** Launch it!
```bash
./mypiserver-arm             # on Raspberry Pi 3/4/5
./mypiserverx86-64           # on desktop/server Linux (x86-64)
```

**0.4:** Customize it!
Precompiled binaries don't support easier customizations. You have to build from the source. Follow 1.1.

### Building from Source (If You Want to Customize or any other reason at all!)

**1.1:** Warning:
It is recommended you use the precompiled binaries as they have been tested. To compile on x86-64 and use them on ARM devices, you must use a cross compiler or directly compile on your ARM device.

**1.2:** Clone the repo:
```bash
git clone https://github.com/paxxydevv/pimine.git
cd pimine
```

**1.3:** Customize it!
- To make RAM customizations, check `src/run.cpp`
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


**1.5:** Compile and run:
```bash
chmod +x (your compiled binary name)
./(your compiled binary name)
```

**1.6:** That's it!
If you have any issues compiling, please create an issue. The compilation process may change in newer versions, so check this section every time a new version releases!

### Troubleshooting

**Issue: "Command not found" when running the binary**
- Make sure you ran `chmod +x` on the binary first
- Verify you're in the correct directory: `ls -la | grep mypiserver`

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

- **Version 0.2 goals:**
  - New version picker (support for Minecraft 1.21+) !releasing today!
  - Support for Paper/Purpur/Spigot servers
  - Easier customization interface
  - Discord server
  - Web dashboard (port 2500) for easy server management

- **Note:** Due to limited contributors, updates may take time. Want to help? Create an issue to join the project!

### License

This project is licensed under the MIT License — see the LICENSE file for details.