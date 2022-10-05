#####################################
# Application  :  Object
# Author        : Azzeddine Remmal            
# Date           : 06.01.2018                  
####################################



# ------Project ----> Files (*.ring)
# ------Program ----> Statements 
# ------Statement ----> Keywords + Expressions 

see "Hello, World!" + nl
#-------- -Keyword Expression 

# --------Statement ----> 'See' <Expression> 
# --------Statement ----> <Expression>

"Hello, World!"
12

#========

see "Welcome" + nl
? "Hello" 

? "ONE" + Tab + "TWO" + Tab + "THREE"

? ""
for x=1 to 10
	see cr 
	see x
next
? ""

#============
# ----------NL, TAB & CR --------------> Variables 

TAB = CHAR(9)+CHAR(9)

? "ONE" + Tab + "TWO" + Tab + "THREE"


nl = Windowsnl()	                         # ----char(13) + char(10)
cString = "Hello" + nl + "How are you" + nl
write("mytest.txt",cString)
system("notepad mytest.txt")
