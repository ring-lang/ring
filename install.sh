# Simple Script to copy ring binary file and libraries to the system
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

# To be able to call ring from any folder 
	
cp bin/ring /usr/local/bin
cp lib/libring.dylib /usr/local/lib
	
# Make the RingAllegro library ready for use directly
	
cp lib/libringallegro.dylib /usr/local/lib
cp extensions/ringallegro/gamelib.ring /usr/local/bin
cp extensions/ringallegro/allegro.rh /usr/local/bin
	
# Make the RingQt library ready for use directly
	
cp lib/libringqt.dylib /usr/local/lib
cp extensions/ringqt/guilib.ring /usr/local/bin
cp extensions/ringqt/ring_qt.ring /usr/local/bin
cp extensions/ringqt/qt.rh /usr/local/bin
	
