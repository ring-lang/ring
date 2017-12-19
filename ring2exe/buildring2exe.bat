call ../src/locatevc.bat
ring ring2exe.ring ring2exe.ring -static
copy ring2exe.exe ..\bin\ring2exe.exe
ring ring2exe.ring folder2qrc.ring -static
copy folder2qrc.exe ..\bin\folder2qrc.exe
cleartemp
