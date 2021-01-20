/*
    Author      =>  Abdallah Mohamed Elsharif
    Email       =>  elsharifabdallah53@gmail.com
    Date        =>  4-12-2020
*/


Load "lib/constants.ring"

if iswindows()
        LoadLib("sockets.dll")
but ismacosx()
        LoadLib("sockets.dylib")
else
        LoadLib("sockets.so")
ok
