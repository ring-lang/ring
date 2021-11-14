# Convert Decimal Number to Roman Numeral in RING
# Nestor Kuka  2020-10-02
# https://www.thecrazyprogrammer.com/2017/09/convert-decimal-number-roman-numeral-c-c.html

see "3549 -> "
decimal2roman(3549)
? ""
 
def decimal2roman(num)
	// descending () is more efficient.
    decimal = [1000,900,500,400,100,90,50,40,10,9,5,4,1] //base values 
    symbol = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"] //roman symbols
    
    i = 1		//ring-arr-base is: 1!!
    while num 	//repeat process until num is not 0						
		while floor( num/decimal[i] ) 	//first base value that divides num is largest base value
            see symbol[i]      //print roman symbol equivalent to largest base value
            num -= decimal[i]  //subtract largest base value from num
        end
        i++ 	//move to next base value to divide num
    end
 
/*  Readme:

How it Works?

Step: 1
   Divide the given number in the order 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 to find largest base value.
Step: 2   
   Display the corresponding roman symbol of largest base value obtained by above method in output.
Step: 3   
   Subtract the given number with largest base value to get new number.
Step: 4	
   Repeat above process with the new number until it becomes 0.

---
   
Example - decimal Number: 250

    Divide it in order 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 to find largest base value. Here 250 is divided by 100. The corresponding roman symbol for 100 is C.
    
	Subtract 250 with 100 (largest base value in previous step) to get new number i.e. 150.
    
	Again divide 150 in the order mentioned earlier. It is divided by 100, so corresponding roman symbol is C.
    
	Subtract 150 with 100 to get new number i.e. 50.
    
	Divide 50 again in the order mentioned earlier. 50 is divided by 50, so corresponding roman symbol is L.
    
	Subtract 50 with 50. The new number obtained is 0 so we stop here.
    
	The final roman numeral is CCL.
	
---

	SYMBOL       VALUE
	I             1
	IV            4
	V             5
	IX            9
	X             10
	XL            40
	L             50
	XC            90
	C             100
	CD            400
	D             500
	CM            900 
	M             1000      	
*/
