/*            application : eval
                 author : heba atef
                  date :30.12.2017
*/
func main
	while true 
            ? "enter expression : "  give cexpr
        if lower(trim(cexpr)) =  "exit"
      exit
         ok
try 
             
?eval(" return " + cexpr)
catch 
? "error"

done

end   	
