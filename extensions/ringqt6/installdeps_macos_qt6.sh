#!/bin/bash
# Install Qt 6 (Homebrew) required to build RingQt6 (macOS)
# The "qt" formula contains all the Qt 6 modules (core/light/full builds)

if ! command -v brew >/dev/null 2>&1; then
	echo "Error: Homebrew is required - https://brew.sh"
	exit 1
fi
xcode-select -p >/dev/null 2>&1 || xcode-select --install

# Qt 5 (qt@5) and Qt 6 (qt) can't be linked together (conflicting binaries)
# Unlink Qt 5 (RingQt for Qt 5 libraries are not affected, use "brew link qt@5" to link it again)
if brew list --versions qt@5 >/dev/null 2>&1; then
	echo "Unlink qt@5 (conflicts with qt)"
	brew unlink qt@5
fi

brew install qt
