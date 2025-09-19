o1 = NEW Point 
? o1 

o1 { 

  ? "Increment x by 20"
  x += 20

  ? "x = "+x 

  ? "Decrement x by 20"
  x -= 20

  ? "x = "+x 

  ? "Multiply x by 2"
  x *= 2

  ? "x = "+x 

  ? "Divide x by 2"
  x /= 2

  ? "x = "+x 

  ? "Remainder x %= 4000000"
  x %= 4000000

  ? "x = "+x 

  ? "Power Operator ( x ** 2)"
  x**=2

  ? "x = "+x 

  ? "Shift-Left"
  x <<= 2

  ? "x = "+x 

  ? "Shift-Right"
  x >>= 2

  ? "x = "+x 

  ? "BitAnd x &= 2250032250000"
  x &= 2250032250000

  ? "x = "+x 

  ? "BitOr x |= 1"
  x |= 1

  ? "x = "+x 

  ? "BitXor x ^= 2250034250001"
  x ^= 2250034250001

  ? "x = "+x 

}


CLASS Point 

  x = 10 y = 10 z = 10

  
  FUNC getx 

    ? "Getter (value + 1000000)"
    RETURN x+1000000

    
  FUNC setx value 

    ? "Setter"
    ? "value = "+value 
    x = value 

    