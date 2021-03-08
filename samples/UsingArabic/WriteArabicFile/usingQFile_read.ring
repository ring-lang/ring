load "guilib.ring"

? :start

oFile = new QFile()
oFile.setFileName("مرحبا.txt")
oFile.open_3(QIODevice_ReadWrite)

? oFile.readAll().data()
oFile.close()

? :Done
