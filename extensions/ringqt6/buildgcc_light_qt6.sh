#!/bin/bash
# Build RingQt6 (light) for Linux - produces libringqt_light.so in ring/lib
. "$(dirname "$0")/qt6env.sh"
ringqt6_build ring_qt6_light.pro ringqt_light gcc gencode_light_qt6.sh
