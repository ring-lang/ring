# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2017.05.01

#===============================================
C_OUTPUTFILE = "ringlibzipfuncsdoc.txt"
C_CHAPTERNAME = "RingLibZip Functions Reference"
cFile = read("libzip.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
funcAfterClass = ""	# Not used
#===============================================

load "../codegen/gendoc.ring"
