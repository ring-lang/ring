cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_allegro.c -I"..\..\libdepwin\allegro5.2.4\include" -I"..\..\include"
link /DEBUG ring_allegro.obj  ..\..\lib\ring.lib ..\..\libdepwin\allegro5.2.4\lib\allegro.lib ..\..\libdepwin\allegro5.2.4\lib\allegro_image.lib ..\..\libdepwin\allegro5.2.4\lib\allegro_dialog.lib ..\..\libdepwin\allegro5.2.4\lib\allegro_ttf.lib ..\..\libdepwin\allegro5.2.4\lib\allegro_acodec.lib ..\..\libdepwin\allegro5.2.4\lib\allegro_primitives.lib ^
..\..\libdepwin\allegro5.2.4\lib\allegro_audio.lib ..\..\libdepwin\allegro5.2.4\lib\allegro_color.lib ..\..\libdepwin\allegro5.2.4\lib\allegro_font.lib ..\..\libdepwin\allegro5.2.4\lib\allegro_video.lib ..\..\libdepwin\allegro5.2.4\lib\allegro_primitives.lib ..\..\libdepwin\allegro5.2.4\lib\allegro_memfile.lib ^
		..\..\libdepwin\allegro5.2.4\lib\allegro_physfs.lib ^
	  /DLL /OUT:..\..\bin\ring_allegro.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_allegro.obj