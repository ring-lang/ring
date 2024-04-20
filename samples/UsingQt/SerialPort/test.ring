load "guilib.ring"

oSerial = new QSerialPort(NULL)
oSerial.setPortName("COM1")
? oSerial.open(QIODevice_ReadWrite)  

? "port        : " + oSerial.portName()
? "isopen      : " + oSerial.isOpen()
? "baudRate    : " + oSerial.baudRate(QIODevice_ReadWrite)
? "dataBits    : " + oSerial.dataBits()
? "parity      : " + oSerial.parity()
? "stopBits    : " + oSerial.stopBits()
? "flowControl : " + oSerial.flowControl()

for t=1 to 10
	cData = "Hello "+ t 
	? "Write: " + oSerial.write(cData,len(cData)) + " bytes..."
next
oSerial.flush()

give anyKey

oSerial.close()
? :done