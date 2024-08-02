setlocal enableextensions enabledelayedexpansion

call config.bat

rem Copy the uf2 file to the Raspberry Pi Pico 
copy %RING_PICO_EXAMPLES%\pico-examples\build\hello_world\ringpico\ringpico.uf2 %RING_PICO_DRIVE%

endlocal