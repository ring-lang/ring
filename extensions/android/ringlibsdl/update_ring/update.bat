rem	Simple Batch file to update Ring in the Android-LibSDL Version 
rem	Author : Mahmoud Fayed <msfclipper@yahoo.com>

copy ..\..\..\..\language\src\*.c ..\project\app\src\main\cpp\ring\src\
copy ..\..\..\ringsdl\ring_libsdl.c ..\project\app\src\main\cpp\ring\src\
copy ext.c ..\project\app\src\main\cpp\ring\src\
copy ..\..\..\..\language\include\*.h ..\project\app\src\main\cpp\ring\include\
copy ext.h ..\project\app\src\main\cpp\ring\include\
copy ..\..\..\..\libraries\gameengine\gameengine.ring ..\project\app\src\main\assets\
copy ..\..\..\..\libraries\gameengine\gameengine.rh ..\project\app\src\main\assets\
copy ..\..\..\..\libraries\gameengine\classes\*.ring ..\project\app\src\main\assets\classes
copy ..\..\..\..\libraries\gameengine\gl_allegro.ring ..\project\app\src\main\assets\
copy ..\..\..\..\libraries\gameengine\gl_libsdl.ring ..\project\app\src\main\assets\
copy ..\..\..\ringsdl\libsdl.ring ..\project\app\src\main\assets\
copy ..\..\..\ringsdl\ring_libsdl.rh ..\project\app\src\main\assets\
copy ..\..\..\ringsdl\sdl.rh ..\project\app\src\main\assets\