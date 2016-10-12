cDir = currentdir()
chdir(exefolder()+"../extensions/ringcurl")
eval('load "libcurl.ring"')
chdir(cDir)
