o1 = NEW test 
o1.x++
o1 { 
  x++
  show()
}

? "============"

aList = [ NEW test]
aList[1] { 
  x++
  x++
  show()
}


CLASS test 

  x = 0
  
  FUNC getx 

    ? :getter 
    RETURN x 
    
  FUNC setx v 

    ? :setter 
    x = v 
    
  FUNC show 

    ? x 
    