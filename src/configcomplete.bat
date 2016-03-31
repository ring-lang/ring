echo off
echo The file ring_ext.h.complete will replace the file ring_ext.h
echo This change include the libraries MySQL, OpenSSL and LibCurl in the project
echo To build use the complete version of the batch files like buildvccomplete.bat
del ring_ext.h
copy ring_ext.h.complete ring_ext.h
