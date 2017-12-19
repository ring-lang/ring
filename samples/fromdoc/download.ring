load "internetlib.ring"

cStr= download("http://doublesvsoop.sourceforge.net/")
see cStr
write("download.txt",cStr)
