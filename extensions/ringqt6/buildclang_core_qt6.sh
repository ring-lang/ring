#!/bin/bash
# Build RingQt6 (core) for macOS - produces libringqt_core.dylib in ring/lib
. "$(dirname "$0")/qt6env.sh"
ringqt6_build ring_qt6_core.pro ringqt_core clang gencode_core_qt6.sh
