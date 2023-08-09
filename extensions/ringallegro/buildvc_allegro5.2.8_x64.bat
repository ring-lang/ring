cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat auto %1
cl /c /DEBUG ring_allegro.c -I"..\..\extensions\libdepwin\allegro5.2.8\include" -I"..\..\language\include"
link /DEBUG ring_allegro.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_image.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_dialog.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_ttf.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_acodec.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_primitives.lib ^
..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_audio.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_color.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_font.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_video.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_primitives.lib ..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_memfile.lib ^
		..\..\extensions\libdepwin\allegro5.2.8\lib\x64\allegro_physfs.lib ^
	  /DLL /OUT:..\..\bin\ring_allegro.dll
del ring_allegro.obj
endlocal