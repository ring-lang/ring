@echo off
setlocal enabledelayedexpansion

cd ..\bin

:: List of required DLL files
set "files=ring.dll ringqt.dll ringqt_core.dll ringqt_light.dll ring_allegro.dll ring_cjson.dll ring_consolecolors.dll ring_fastpro.dll ring_freeglut.dll ring_httplib.dll ring_internet.dll ring_libcurl.dll ring_libui.dll ring_libzip.dll ring_murmurhash.dll ring_mysql.dll ring_odbc.dll ring_opengl21.dll ring_openssl.dll ring_pdfgen.dll ring_pgsql.dll ring_raylib.dll ring_rogueutil.dll ring_sockets.dll ring_sqlite.dll ring_stbimage.dll ring_threads.dll ring_tilengine.dll ring_uv.dll ring_winapi.dll ring_wincreg.dll ring_winlib.dll"

echo Checking for required DLL files...

:: Loop through each file and check existence
for %%f in (%files%) do (
    if not exist "%%f" (
        echo Missing file: %%f
    )
)

echo Check complete.
endlocal