# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2017.08.08

#===============================================
C_OUTPUTFILE = "ringopengl30funcsdoc.txt"
C_CHAPTERNAME = "RingOpenGL (OpenGL 3.0) Functions Reference"
cFile = read("opengl30.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
funcAfterClass = ""	# Not used
#===============================================

load "../../codegen/gendoc.ring"
