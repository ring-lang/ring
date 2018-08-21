cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_allegro.c -I"..\..\libdepwin\allegro\include" -I"..\..\include"
link /DEBUG ring_allegro.obj  ..\..\lib\ring.lib ..\..\libdepwin\allegro\lib\allegro.lib ..\..\libdepwin\allegro\lib\allegro_image.lib ..\..\libdepwin\allegro\lib\allegro_dialog.lib ..\..\libdepwin\allegro\lib\allegro_ttf.lib ..\..\libdepwin\allegro\lib\allegro_acodec.lib ..\..\libdepwin\allegro\lib\allegro_primitives.lib ^
..\..\libdepwin\allegro\lib\allegro_audio.lib ..\..\libdepwin\allegro\lib\allegro_color.lib ..\..\libdepwin\allegro\lib\allegro_font.lib ..\..\libdepwin\allegro\lib\allegro_video.lib ..\..\libdepwin\allegro\lib\allegro_primitives.lib ..\..\libdepwin\allegro\lib\allegro_memfile.lib ^
		..\..\libdepwin\allegro\lib\allegro_physfs.lib ^
	  /DLL /OUT:..\..\bin\ring_allegro.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_allegro.obj