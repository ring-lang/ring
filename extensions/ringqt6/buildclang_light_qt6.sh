#!/bin/bash
# Build RingQt6 (light) for macOS - produces libringqt_light.dylib in ring/lib
. "$(dirname "$0")/qt6env.sh"
ringqt6_build ring_qt6_light.pro ringqt_light clang gencode_light_qt6.sh
