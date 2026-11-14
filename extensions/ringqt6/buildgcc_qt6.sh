#!/bin/bash
# Build RingQt6 (nobluetooth) for Linux - produces libringqt.so in ring/lib
. "$(dirname "$0")/qt6env.sh"
ringqt6_build ring_qt6_nobluetooth.pro ringqt gcc gencode_nobluetooth_qt6.sh
