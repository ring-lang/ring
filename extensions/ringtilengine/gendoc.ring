# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2016.09.22

#===============================================
C_OUTPUTFILE = "ringtilenginefuncsdoc.txt"
C_CHAPTERNAME = "RingTilengine Functions Reference"
cFile = read("tilengine.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
funcAfterClass = ""	# Not used
#===============================================

load "../codegen/gendoc.ring"
