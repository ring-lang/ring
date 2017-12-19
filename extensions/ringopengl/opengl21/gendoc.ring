# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2017.08.08

#===============================================
C_OUTPUTFILE = "ringopengl21funcsdoc.txt"
C_CHAPTERNAME = "RingOpenGL (OpenGL 2.1) Functions Reference"
cFile = read("opengl21.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
funcAfterClass = ""	# Not used
#===============================================

load "../../codegen/gendoc.ring"
