@echo off

echo backing up "bizstyle" old files

IF EXIST C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\static\bizstyle.js_t.bak (
	IF NOT EXIST C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\static\bizstyle.js_t.bak.old (
	REM if there is more than one time building, original bizstyle.js_t file will be untouched
		copy C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\static\bizstyle.js_t.bak C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\static\bizstyle.js_t.bak.old
		echo bizstyle.js_t.bak.old file created
	)
)
copy C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\static\bizstyle.js_t C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\static\bizstyle.js_t.bak
echo bisstyle.js_t.bak file created

IF EXIST C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\layout.html.bak (
	IF NOT EXIST C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\layout.html.bak.old (
	REM if there is more than one time building, original layout.html file will be untouched
		copy C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\layout.html.bak C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\layout.html.bak.old
		echo layout.html.bak.old file created
    )
)
copy C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\layout.html C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\layout.html.bak
echo layout.html.bak file created

echo Copying the modified files to be used instead
copy bizstyle.js_t C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\static\bizstyle.js_t
copy layout.html C:\Python27\Lib\site-packages\sphinx\themes\bizstyle\layout.html

echo Copying Ring_WinCReg logo to be used by documentation
copy logo.png .\build\html\logo.png

echo NOW you are ready to build docs :)
