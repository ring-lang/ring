/*
    Author      =>  Abdallah Mohamed Elsharif
    Email       =>  elsharifabdallah53@gmail.com
    Date        =>  4-12-2020
*/


Load "lib/constants.ring"

if iswindows()
        LoadLib("socket.dll")
but ismacosx()
        LoadLib("socket.dylib")
else
        LoadLib("socket.so")
ok
