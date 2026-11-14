#!/bin/bash
# Build RingQt6 (nobluetooth) for macOS - produces libringqt.dylib in ring/lib
. "$(dirname "$0")/qt6env.sh"
ringqt6_build ring_qt6_nobluetooth.pro ringqt clang gencode_nobluetooth_qt6.sh
