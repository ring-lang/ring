o1 = New test 
For t = 1 To 5
    o1.x++
Next 

For t = 1 To 5
    o1 { 
        x++
    }
Next 


Class test 

    x = New myclass 

    
    Func getx 

        ? :getter 
        Return x 

        
    Func setx obj 

        ? :setter 
        ? "value: "+obj.value+nl 
        x = obj 
        Return x 

        
    Func braceStart 

        ? :braceStart 

        
    Func braceEnd 

        ? :braceEnd 

        
    Func braceExprEval value 

        ? :braceExprEval 
        ? "Type: "+type(value)
        ? value 

        
Class myclass 

    value = 1000

    
    Func operator cOp, vValue 

        ? "Operator Overloading"
        ? "Operator: "+cOP 
        value++
        Return self 
        