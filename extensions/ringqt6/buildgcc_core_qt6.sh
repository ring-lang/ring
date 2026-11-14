#!/bin/bash
# Build RingQt6 (core) for Linux - produces libringqt_core.so in ring/lib
. "$(dirname "$0")/qt6env.sh"
ringqt6_build ring_qt6_core.pro ringqt_core gcc gencode_core_qt6.sh
