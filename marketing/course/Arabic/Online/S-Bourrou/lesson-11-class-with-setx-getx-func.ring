/* 
        Application: Class example
        Author     : S.Bourrou
        Date       : 27-10-2019

 */

new myAttrib {
     x=76 y=73 
     printme() 
	?x		
}

class myAttrib x y
          
    func printme
          ? "X: " + x +  " Y: " +y

    func getx # protect the x
 	 ?"MSG from getx func"
	return x # given the x

    func setx value 
         x = value # you can control the value of x (e.g x = value + 1000 )
         ?"MSG from setx func!"
	 


      
