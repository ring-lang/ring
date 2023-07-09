export RINGQT_WEBASSEMBLY=
export RINGQT_ANDROID=
export RINGQT_NOCORE=
export RINGQT_NOGUI=
export RINGQT_NOWIDGETS=
export RINGQT_NOTESTLIB=

export RINGQT_NOMULTIMEDIA=1
export RINGQT_NOMULTIMEDIAWIDGETS=1
export RINGQT_NOPRINTSUPPORT=1
export RINGQT_NONETWORK=1
export RINGQT_NOSQL=1
export RINGQT_NOPOSITIONING=1
export RINGQT_NOWEBKITWIDGETS=1
export RINGQT_NOWEBENGINEWIDGETS=1
export RINGQT_NOSERIALPORT=1
export RINGQT_NOAXCONTAINER=1
export RINGQT_NOQUICKWIDGETS=1
export RINGQT_NOQML=1
export RINGQT_NOSPEECH=1
export RINGQT_NOQT3D=1
export RINGQT_NOWEBKIT=1
export RINGQT_NOBLUETOOTH=1
export RINGQT_NOCHARTS=1


../../bin/ring ../codegen/parsec.ring classes/qt.cf cpp/src/ring_qt_light.cpp ../../libraries/guilib/classes/ring_qt_light.ring
cd events
../../../bin/ring qtevents.ring
cd ..
