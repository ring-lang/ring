#######################################################################
# Application  : Read-Eval-Print-Loop (REPL) - Console Application    #
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>                 #
# Developing   : Azzeddine Remmal (azzeddine.remmal@gmail.com)        #
# Date         : 03-08-2023                                           #
# Description  : Developing the Ring REPLConsole adding CMD commands  #
#######################################################################
load "stdlib.ring"
load "consolecolors.ring"




cHelp = " Linck To Documention : https://ring-lang.github.io/doc1.18/introduction.html#
          To execute CMD commands,
          you only have to type > 
          and  the command directly
Example:
 .../ring:>>echo Hello Ring > text.txt   == To create a file and write to it  
 .../ring:>>cd ..\                       == To change Path
 .../ring:>>type text.txt                == To display the content of a file
 .../ring:>>md Html Css Js               == To create a folder or folders
 .../ring:>>rd Html Css Js               == To delete a folder or folders
 .../ring:>>Del text.txt                 == to delete a file
 .../ring:>>cls                          == to clean the screen

"
see cc_print(CC_FG_YELLOW|CC_BG_BLACK,"     The Ring programming language version :") 
see cc_print(CC_FG_CYAN|CC_BG_BLACK, version()) + nl 
see cc_print(CC_FG_YELLOW|CC_BG_BLACK,"REPL (Read-Eval-Print-Loop)If you need help, enter >Help") + nl
currentDir = currentDir()	

while True

        see cc_print(CC_FG_Green|CC_BG_BLACK,nl+currentDir)
	see cc_print(CC_FG_BLUE | CC_BG_BLACK , "/ring:>")
        give cRingCode
        cCode = lower(trim(cRingCode))
	if left(cCode, 1) = ">"
	     aComand = split(cCode, " ")
	      cComand1 = substr(aComand[1],">", "" )
	     //? aComand 
		if len(aComand) = 1
			if cComand1 = "ls"
				ListFile()	
			elseif cComand1 = "help"
			        see cc_print(CC_FG_DARK_GREEN|CC_BG_BLACK,nl + cHelp + nl)
	          	else
				system(cComand1)
		         ok
		elseif len(aComand) = 2
			if cComand1 = "cd"
			     chdir(aComand[2]) 
			     currentDir = currentDir()
		        else
	              	      cCode1 = cComand1 + " " + aComand[2]
			      system(cCode1)
			 ok
					  
	 	else 
			cCode2 = substr(cCode,2)
			system(cCode2)
						
	 	ok
				  
	else
	      try
					eval(cCode)
	        
	      catch
	          see cc_print(CC_FG_RED|CC_BG_BLACK,cCatchError)
	      done 
	ok
end


func ListFile()
    
		aOutput = dir(currentDir())
		for i = 1 to len(aOutput)
		     if aOutput[i][2] = 1 
			 see "dir : " ? cc_print(CC_FG_BLUE|CC_BG_BLACK,aOutput[i][1])
		     but aOutput[i][2] = 0
			 cfileSize = ""+  Getfilesize(currentDir() +"/"+ aOutput[i][1])
			 see "file : " see cc_print(CC_FG_Yellow|CC_BG_BLACK,aOutput[i][1]+" ") +
			 cc_print(CC_FG_CYAN|CC_BG_BLACK, cfileSize  ) + 
			 cc_print(CC_FG_DARK_YELLOW|CC_BG_BLACK," - bytes" ) + nl
		    ok
		next




