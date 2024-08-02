rem Copy the uf2 file to the Raspberry Pi Pico 

set RING_PICO_SDK=c:\pl\pico151
set RING_PICO_EXAMPLES=c:\pl\pico151examples
set RING_PICO_DRIVE=d:\

copy %RING_PICO_EXAMPLES%\pico-examples\build\hello_world\ringpico\ringpico.uf2 %RING_PICO_DRIVE%
