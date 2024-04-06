#====================================================#
# Try Ring Online (Using RingQt for WebAssembly)
# 2024, Mahmoud Fayed 
#====================================================#

C_SAMPLENAME = 1
C_SAMPLECODE = 2

aSamples  = [
	["Hello World",`
	? "Hello, World!"

	See "Hello, World!" + nl

	put "Hello, World!" + nl

	print("Hello, World!")
	`],
	["Print Numbers",`
	for t=1 to 10 
	    ? t
	    if t=3 
	        ? :three
	    ok
	next
	`],
	["Say Hello",`
	? "Enter your name: "  give name  ? "Hello " + name

	for c in name
	    ? c
	next
	`],
	[ "Sum Two Numbers",`
	? "Enter Number(1): " give nNum1
	? "Enter Number(2): " give nNum2
	? "Sum: " + (0+nNum1+nNum2)
	`],
	["Using Functions",`
	one() two() three()
	? sum(10,10)

	message() anotherMessage()

	func one   ? :one 
	func two   ? :two 
	func three ? :three

	# We can use braces
	func sum(x,y) {
	    return x+y
	}

	# We can use end|endfunction
	def message 
	    ? "I Love Programming!"
	end

	function anotherMessage() 
	    ? "What about you?"
	endfunction 
	`],
	[ "Using Objects",`
	new point { x=10 y=20 z=30 ? self }

	class point x y z
	`],
	["Variable Scope",`
	nCount = 10    # Global variable

	func main
	    nID = 1    # Local variable
	    see "Count = " + nCount + nl + "ID = " + nID
	`],
	["Using Lists",`
	aList = ["one","two","three"]
	aList2 = aList  # Deep Copy

	aList[1] = 1    # Index starts from 1  
  
	? alist[1]      # print 1
	? aList2[1]     # print one

	# We can use lists during definition 
	myList = [ [:a,:b,:c] , myList[1] , myList[1] ]
	see myList      # print a b c a b c a b c
	`],
	["Exit From 2 Loops",`
	for x = 1 to 10 {
	    for y = 1 to 10 {
	        see "x=" + x + " y=" + y + nl
	        if x = 3 and y = 5 {
	            exit 2     # exit from 2 loops
	        }
	    }
	}

	? "NICE TO MEET YOU!"
	`],
	["Using Eval()",`
	? "Creating a new class dynamically..."
	eval("class Point x y z")

	? "Printing the instance..."
	? new Point {x=10 y=20 z=30}
	`],
	["Change Keywords (Arabic Syntax)",`
	ChangeRingKeyword see اطبع
	ChangeRingKeyword give ادخل
	ChangeRingKeyword if لو
	ChangeRingKeyword but امالو
	ChangeRingKeyword else عداذلك
	ChangeRingKeyword ok تمام
	
	سطرجديد = nl
	
	اطبع "السلام عليكم ورحمة الله وبركاته" + سطرجديد

	اطبع "كم عمرك" + سطرجديد
	ادخل العمر

	العمر = 0 + العمر
	لو العمر < 10
	        اطبع "اسمك ايه ياجميل؟" + سطرجديد
	امالو العمر < 30
	        اطبع "اسمك ايه ياابو الشباب؟" + سطرجديد 
	امالو العمر < 60
	        اطبع "اسم حضرتك ايه؟" +سطرجديد
	عداذلك
	        اطبع "والله حضرتك منورنا ... اتشرف ب اسم حضرتك؟" + سطرجديد
	تمام

	ادخل الاسم
	اطبع " اهلا وسهلا يا: " + الاسم
	
	`],
	["Call Method Using Braces",`
	new point {            
	    x=10  y=20  z=30       
	    print()                # Call the print() method
	}
                      
	class point            

	    x y z

	    ? "Hello, World!"                  

	    func print             
	        ? self 

	    func braceStart
	        ? "Welcome"

	    func braceEnd
	        ? "Goodbye!"

	`],
	["Using BraceExprEval()",`
	new Sum {
	    10
	    20  40
	    100 2000 
	    -20
	    201.5
	}

	class Sum

	    nSum = 0

	    func braceExprEval nValue
	        if ! isNumber(nValue) return ok
	        nSum += nValue

	    func braceEnd
	        ? "Sum: " + nSum
	`],
	["Natural Commands",`
	TimeForFun = new journey

	# The first surprise!
	TimeForFun {
	    Hello it is me     # What a beautiful programming world!
	}

	# Our Class
	class journey

	    hello=0 it=0 is=0 me=0

	    func GetHello
	        See "Hello" + nl
	    func braceEnd
	        See "Goodbye!" + nl	
	`],
	["Main Menu",`

	while True

        see "

        Main Menu
        ===========
        [1] Say Hello
        [2] Sum two numbers
        [3] Stars
        [4] Fact
        [5] Exit

        " give nMenu ? nl

        Switch nMenu
        On 1 sayhello()
        On 2 Sum()
        On 3 Stars()
        On 4
             ? "Enter Number : " give x
             ? "Output : "

             Try
                 ? Fact(number(x))
             Catch
                 ? "Error in parameters!" 
             Done

        On "5" return
        Other ? "bad option" 
        Off

	end

	func sayhello
            ? "Enter your name ? " give fname
            ? "Hello " + fname + nl

	func sum
            ? "number 1 : " give num1 ? "number 2 : " give num2
            ? "Sum : " + ( 0 + num1 + num2 )

	func stars
            for x = 1 to 10
                see space(8)
                for y = 1 to x see "*" next see nl
            next

	func fact x if x = 0 return 1 else return x * fact(x-1) ok

	func space x y = "" for t=1 to x y += " " next return y

	`]
]
