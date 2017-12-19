# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2017.08.11

#===============================================
C_OUTPUTFILE = "ringopengl20funcsdoc.txt"
C_CHAPTERNAME = "RingOpenGL (OpenGL 2.0) Functions Reference"
cFile = read("opengl20.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
funcAfterClass = ""	# Not used
#===============================================

load "../../codegen/gendoc.ring"
