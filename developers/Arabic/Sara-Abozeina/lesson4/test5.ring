/*
**	Application : fgets,list,string functions
**	Author 	  : Sara Abozeina
**	Date		  :2017.12.18	
*/



		?"enter (Y) FOR yes to read  file or (N) FOR no to exit"
		? 'the option is : ' 
		cOption=getchar() 

		getchar()  getchar() 
		cOption=lower(cOption)
		if cOption ='y'  

				fh=fopen("file.txt","r+")
#number of lines in the file
				for x=1 to 2
						cStrings=fgets(fh,50)
						?upper(cStrings)
# subs after 5 chars
						?substr(cStrings,5)
						cStrings2=substr(cStrings,"Ring","_ring_",1)
						?len(cStrings2)
#from left to 5 chars
						?left(cStrings,5)	
#from right to 10 chars	
						?right(cStrings,10)	
		
				next
	
				 fclose(fh)
		but cOPtion='n'
				bye
		else
				? 'Bad option,try again'
		ok
