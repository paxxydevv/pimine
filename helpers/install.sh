#!/bin/bash
set -e
echo "Checking Minecraft server installation..."

INSTALL_DIR="$HOME/minecraft-server"
mkdir -p "$INSTALL_DIR"
cd "$INSTALL_DIR"

if [[ -f "server.jar" ]]; then
    echo "server already exists. Skipping download."
else
    echo "Fetching latest Minecraft server..."
    URL=$(curl -s https://launchermeta.mojang.com/mc/game/version_manifest.json \
        | grep -o '"url": "[^"]*"' \
        | head -1 \
        | cut -d '"' -f4 \
        | xargs curl -s \
        | grep -o '"url": "https://[^"]*server.jar"' \
        | cut -d '"' -f4)
    curl -fLo server.jar "$URL"
    echo "EULA agreement accepted automatically."
    echo "eula=true" > eula.txt
fi

echo "Minecraft server installed in $INSTALL_DIR"
