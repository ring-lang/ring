#!/bin/bash
# Generate the C++ code and the Ring classes of RingQt6 (full - without Bluetooth)
# The generated files are already provided - Use this script after modifying the .cf files
cd "$(dirname "$0")"
export RINGQT_WEBASSEMBLY=
export RINGQT_ANDROID=

export RINGQT_NOCORE=
export RINGQT_NOGUI=
export RINGQT_NOWIDGETS=
export RINGQT_NOTESTLIB=
export RINGQT_NOOPENGL=

export RINGQT_NOMULTIMEDIA=
export RINGQT_NOMULTIMEDIAWIDGETS=
export RINGQT_NOPRINTSUPPORT=
export RINGQT_NONETWORK=
export RINGQT_NOSQL=
export RINGQT_NOPOSITIONING=
export RINGQT_NOSERIALPORT=
export RINGQT_NOAXCONTAINER=
export RINGQT_NOQUICKWIDGETS=
export RINGQT_NOQML=
export RINGQT_NOSPEECH=
export RINGQT_NOQT3D=
export RINGQT_NOCHARTS=
export RINGQT_NOGRAPHICSSVG=
export RINGQT_NOSVG=

export RINGQT_NOWEBKIT=1
export RINGQT_NOWEBKITWIDGETS=1
export RINGQT_NOBLUETOOTH=1
export RINGQT_NOWEBENGINEWIDGETS=

../../bin/ring ../codegen/parsec.ring classes/qt.cf cpp/src/ring_qt.cpp ../../libraries/guilib/classes/ring_qt.ring
cd events
../../../bin/ring qtevents.ring
cd ..

