load "internetlib.ring"

cStr= download("https://ring-lang.github.io/")
see cStr
write("download.txt",cStr)
