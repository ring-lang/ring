cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat auto %1
cl /c /DEBUG ring_allegro.c -I"..\..\extensions\libdepwin\allegro5.2.8_x64\include" -I"..\..\language\include"
link /DEBUG ring_allegro.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_image.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_dialog.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_ttf.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_acodec.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_primitives.lib ^
..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_audio.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_color.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_font.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_video.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_primitives.lib ..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_memfile.lib ^
		..\..\extensions\libdepwin\allegro5.2.8_x64\lib\allegro_physfs.lib ^
	  /DLL /OUT:..\..\bin\ring_allegro.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_allegro.obj
endlocal