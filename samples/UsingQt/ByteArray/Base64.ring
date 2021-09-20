#=======================================#
#  Description : Base64 Sample
#  Author      : Mansour Ayouni
#=======================================#

# Loading RingQt

	load "guilib.ring"
    
# Creating a QByteArray object

	oQByteArray = new QByteArray()

# Adding a string to the QByteArray object
	oQByteArray.append("my string")

# Encoding the content of the QByteArray in a base64 string
	? oQByteArray.toBase64().data()
     

# To do the inverse operation:
# You put your base64 string inside a QByteArray object

	oQByteArray = new QByteArray()
	oQByteArray.append("bXkgc3RyaW5n")
	? oQByteArray.fromBase64(oQByteArray).data()