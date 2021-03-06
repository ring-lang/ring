load "guilib.ring"

? :start

oFile = new QFile()
oFile.setFileName("مرحبا.txt")
oFile.open_3(QIODevice_ReadWrite)

cString = "السلام عليكم"
nSize = len(cString)

oFile.write(cString,nSize)
oFile.close()

? :Done