#!/bin/bash
# Install the Qt 6 development packages required to build RingQt6 (Ubuntu/Debian)
# Usage: installdeps_ubuntu_qt6.sh [core|light|full]    (default: full)
# Qt 6.4 or later is required (Ubuntu 22.10+/Debian 12+), qt6-speech/qt6-webengine need Ubuntu 24.04+/Debian 13+

BUILD="${1:-full}"
BASE="build-essential libgl1-mesa-dev libglu1-mesa-dev qt6-base-dev qt6-base-dev-tools qt6-5compat-dev"
case "$BUILD" in
	core|light)
		PKGS="$BASE" ;;
	full)
		PKGS="$BASE qt6-multimedia-dev qt6-serialport-dev qt6-positioning-dev qt6-speech-dev \
		      qt6-3d-dev qt6-charts-dev qt6-svg-dev qt6-webengine-dev qt6-declarative-dev \
		      libqt6opengl6-dev libqt6sql6-sqlite libqt6sql6-mysql libqt6sql6-psql libqt6sql6-odbc \
		      qml6-module-qtquick qml6-module-qtquick-controls qml6-module-qtquick-window \
		      qml6-module-qtquick-layouts qml6-module-qtcharts" ;;
	*)
		echo "Usage: $0 [core|light|full]"; exit 1 ;;
esac
sudo apt-get update
sudo apt-get install -y $PKGS
