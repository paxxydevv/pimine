#!/bin/bash
export TERM=xterm
VERSION="$1"
if [ -z "$VERSION" ]; then
  VERSION="1.21.11"  # fallback to latest
fi
SERVER_TYPE=$(grep 'type' pimine.conf | cut -d= -f2)

INSTALL_DIR=~/minecraft-server
mkdir -p "$INSTALL_DIR"
cd "$INSTALL_DIR"
echo "Downloading Minecraft server version $SERVER_TYPE $VERSION..."

if [ "$SERVER_TYPE" = "vanilla" ]; then
	MANIFEST=$(curl -s https://launchermeta.mojang.com/mc/game/version_manifest.json)
	JAR_URL=$(echo "$MANIFEST" | jq -r ".versions[] | select(.id==\"$VERSION\") | .url" | xargs curl -s | jq -r .downloads.server.url)
	curl -O "$JAR_URL"
elif [ "$SERVER_TYPE" = "paper" ]; then
    LATEST_BUILD=$(curl -s "https://api.papermc.io/v2/projects/paper/versions/$VERSION" | jq -r '.builds | last')
    curl -fSL "https://api.papermc.io/v2/projects/paper/versions/$VERSION/builds/$LATEST_BUILD/downloads/paper-$VERSION-$LATEST_BUILD.jar" -o $INSTALL_DIR/server.jar
else
	echo "Unknown server type please check readme..."
	exit 1
fi
echo "Download complete for: $SERVER_TYPE_$VERSION"
