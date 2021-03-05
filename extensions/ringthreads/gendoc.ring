# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2016.09.22

#===============================================
C_OUTPUTFILE = "ringthreadsfuncsdoc.txt"
C_CHAPTERNAME = "Ringthreads Functions Reference"
cFile = read("threads.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
funcAfterClass = ""	# Not used
#===============================================

load "../codegen/gendoc.ring"
