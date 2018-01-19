# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2018.01.19

#===============================================
C_OUTPUTFILE = "ringlibuvfuncsdoc.txt"
C_CHAPTERNAME = "RingLibUV Functions Reference"
cFile = read("libuv.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
funcAfterClass = ""	# Not used
#===============================================

load "../codegen/gendoc.ring"
