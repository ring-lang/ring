RingQt6 - Linux/macOS build scripts
===================================

Requirements
============

* Ring built from source (libring.so in /usr/lib on Linux, ring/lib/libring.dylib on macOS)
* Qt 6 (6.4 or later, tested with Qt 6.12) and a C++17 compiler

(1) Install the dependencies

    ./installdeps_ubuntu_qt6.sh [core|light|full]     Ubuntu/Debian
    ./installdeps_macos_qt6.sh                        macOS (Homebrew)

(2) Build the shared library (copied to ring/lib) - The C++ code is generated for the platform first

    Linux                          macOS                           Output
    ./buildgcc_core_qt6.sh         ./buildclang_core_qt6.sh        libringqt_core   (Qt Core)
    ./buildgcc_light_qt6.sh        ./buildclang_light_qt6.sh       libringqt_light  (Core + GUI + Widgets)
    ./buildgcc_qt6.sh              ./buildclang_qt6.sh             libringqt        (Full - No Bluetooth)

Use the QMAKE environment variable to select a specific Qt 6 installation, for example

    QMAKE=$HOME/Qt/6.12.0/gcc_64/bin/qmake ./buildgcc_qt6.sh

Then use `load "guilib.ring"` (or lightguilib.ring/qtcore.ring) as usual.

Code generation
===============

The C++ code in the cpp folder (and the Ring classes in libraries/guilib/classes) are generated for Windows
(they contain Windows-only classes like QAxBase). The build scripts above run the matching code generator
for the current platform before building

    ./gencode_core_qt6.sh          (used by buildgcc_core_qt6.sh / buildclang_core_qt6.sh)
    ./gencode_light_qt6.sh         (used by buildgcc_light_qt6.sh / buildclang_light_qt6.sh)
    ./gencode_nobluetooth_qt6.sh   (used by buildgcc_qt6.sh / buildclang_qt6.sh)

This requires the Ring executable (ring/bin/ring) and ring/extensions/codegen.
Set RINGQT6_NOGENCODE=1 to skip this step.
