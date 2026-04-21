cd ..\..\include

copy /Y ..\build\vmcgoto\rconfig_updated.h rconfig.h

cd ..\build

call buildgccstatic.bat ..\build\vmcgoto\vmcgoto.c

cd ..\include

copy /Y ..\build\vmcgoto\rconfig_default.h rconfig.h
 
cd ..\build