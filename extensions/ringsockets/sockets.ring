/*
    Author      =>  Abdallah Mohamed Elsharif
    Email       =>  elsharifabdallah53@gmail.com
    Date        =>  4-12-2020
*/


Load "lib/constants.ring"

if iswindows()
        LoadLib("ring_sockets.dll")
but ismacosx()
        LoadLib("libring_sockets.dylib")
else
        LoadLib("libring_sockets.so")
ok
