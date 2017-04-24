echo off
echo The file ring_ext.h.light will replace the file ring_ext.h
echo This change execlude the libraries MySQL, OpenSSL and LibCurl from the project
echo To build use the light version of the batch files like buildvclight.bat
del ring_ext.h
copy ring_ext.h.light ring_ext.h
