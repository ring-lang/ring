load "guilib.ring"

? :start

oFile = new QFile()
oFile.setFileName("مرحبا.txt")
oFile.open_3(QIODevice_ReadOnly | QIODevice_WriteOnly)

cString = "السلام عليكم"
nSize = len(cString)

oFile.write(cString,nSize)
oFile.close()

? :Done