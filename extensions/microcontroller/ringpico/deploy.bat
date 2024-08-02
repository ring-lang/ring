setlocal enableextensions enabledelayedexpansion

call config.bat

rem Copy the uf2 file to the Raspberry Pi Pico 
copy build\ringpico.uf2 %RING_PICO_DRIVE%

endlocal