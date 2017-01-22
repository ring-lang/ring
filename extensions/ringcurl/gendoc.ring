# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2017.01.22

#===============================================
C_OUTPUTFILE = "ringlibcurlfuncsdoc.txt"
C_CHAPTERNAME = "RingLibCurl Functions Reference"
cFile = read("libcurl.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
funcAfterClass = ""	# Not used
#===============================================

load "../codegen/gendoc.ring"
