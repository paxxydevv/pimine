#!/bin/bash

VERSION="$1"
if [ -z "$VERSION" ]; then
  VERSION="1.21.11"  # fallback to latest
fi

INSTALL_DIR=~/minecraft-server
mkdir -p "$INSTALL_DIR"
cd "$INSTALL_DIR"

echo "Downloading Minecraft server version $VERSION..."

# Get the URL of the server jar from Mojang's manifest
MANIFEST=$(curl -s https://launchermeta.mojang.com/mc/game/version_manifest.json)
JAR_URL=$(echo "$MANIFEST" | jq -r ".versions[] | select(.id==\"$VERSION\") | .url" | xargs curl -s | jq -r .downloads.server.url)

curl -O "$JAR_URL"
echo "Download complete."
