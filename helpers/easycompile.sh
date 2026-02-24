#!/bin/sh
echo "Welcome to PIMINE easycompiler"
set -e

echo "Detecting package manager..."

PKG=""

if command -v apt >/dev/null 2>&1; then
    PKG="apt"
elif command -v dnf >/dev/null 2>&1; then
    PKG="dnf"
elif command -v pacman >/dev/null 2>&1; then
    PKG="pacman"
elif command -v apk >/dev/null 2>&1; then
    PKG="apk"
else
    echo "Sorry your distro wasnt on our own side, Please compile on your own."
    exit 1
fi

echo "Found package manager: $PKG"
echo "Installing build dependencies..."

case $PKG in
    apt)
        sudo apt install -y build-essential cmake
        ;;
    dnf)
        sudo dnf install -y gcc gcc-c++ make cmake
        ;;
    pacman)
        sudo pacman -Sy --noconfirm base-devel cmake
        ;;
    apk)
        sudo apk add build-base cmake
        ;;
esac

echo "Preparing to compile pimine.."


cd "$(dirname "$0")/.." || exit 1

if [ -f /etc/os-release ]; then
    . /etc/os-release
    DISTRO=$ID
else
    DISTRO="unknown"
fi

OUTPUT="pimine-$DISTRO"

echo "Compiling..."

g++ -std=c++17 -O2 -Wall main.cpp src/*.cpp -o "$OUTPUT"

chmod +x "$OUTPUT"

echo ""
echo "Binary created:"
echo "   $OUTPUT"
echo "Thanks for using pimine!"
