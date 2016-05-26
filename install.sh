# Simple Script to copy ring binary file and libraries to the system
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

# To be able to call ring from any folder 
	
cp bin/ring /usr/bin
cp lib/libring.dylib /usr/lib
	
# Make the RingAllegro library ready for use directly
	
cp lib/libringallegro.dylib /usr/lib
cp extensions/ringallegro/gamelib.ring /usr/bin
cp extensions/ringallegro/allegro.rh /usr/bin
	
# Make the RingQt library ready for use directly
	
cp lib/libringqt.dylib /usr/lib
cp extensions/ringqt/guilib.ring /usr/bin
cp extensions/ringqt/ring_qt.ring /usr/bin
cp extensions/ringqt/qt.rh /usr/bin
	
