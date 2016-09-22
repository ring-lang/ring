# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2016.09.22

#===============================================
C_OUTPUTFILE = "qtclassesdoc.txt"
C_CHAPTERNAME = "RingQt Classes Reference"
cFile = read("qt.cf")
lStart = False		# False = Classes Doc.   True = Functions Doc.
#===============================================

load "../codegen/gendoc.ring"
