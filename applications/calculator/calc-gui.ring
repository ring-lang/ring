/*
 +---------------------------------------------------------------------------------------------------------
 +     Program Name : Calculator
 +     Date  : 2016-2017
 +     Author: Magdy Ragab
 +           : Gal Zsolt (~ CalmoSoft ~)
 +           : Bert Mariani  2017-08-25
 +---------------------------------------------------------------------------------------------------------
*/

import System.GUI

# Load Ring Libraries
    Load "lightguilib.ring"
    Load "sqlitelib.ring"

UserIcons = CurrentDir() +"/"

decimals(2)
enum   = ""
result = ""

_style  = "border: 1px solid #c0c0c0; background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #eef, stop: 1 #ccf); font-size: 15pt"
_styleN = "border: 1px solid #dddddd; background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #bbf, stop: 1 #aaf); font-size: 15pt"


win2 = null

MyApp = New qApp 
{

    win1 = new qWidget() 
    {
   
        butSize = 50
        Xspace  = 55 ; YSpace  = 55
        Xpos    = 10 ; Ypos    = 10
         
        setwinicon(self,"images/calc.png")
        setwindowtitle("Ring Calculator")
        setwindowmodality(false)
        setFixedSize(290,355 )

        oComboBox = new ComboBox(win1) 
        {
            setGeometry(Xpos, Ypos,270,30)
            setstylesheet("background-color: lightgray; color:blue; font-size: 10pt; ")                                  
        }




        edit1 = new qlineedit(win1) 
        {
            setGeometry(Xpos, Ypos +30, 270,30)
            setAlignment(Qt_AlignHCenter)
            setTextChangedEvent("changedText()")   ### Keyboard chars
            
            setReturnPressedEvent("checkEnter()")      
            setStyleSheet("background-color: lightyellow;color:darkyellow;font-size: 15pt;")         
        }
        

        ###--------------------------
        
        Ypos = Ypos +65  ### Skip DisplayLines, Now at KeyButtons       
    
        ###--------------------------
        
        pushSquareRootX = new qpushbutton(win1) {
            setGeometry(Xpos+(0*Xspace), Ypos+(0*Yspace), butSize, butSize)
            #settext("/x")
            seticon(new qicon(new qpixmap(UserIcons +"SquareRootX.png")))
            setIconSize(pushSquareRootX.size())
            setclickevent("math('v')")
            setStyleSheet(_style)

        }


        pushSquareX = new qpushbutton(win1) {
            setGeometry(Xpos+(1*Xspace), Ypos+(0*Yspace), butSize, butSize)
            #settext("x^2")
            seticon(new qicon(new qpixmap(UserIcons +"SquareX.png")))
            setIconSize(pushSquareX.size())  
            setclickevent("math('^')")
            setStyleSheet(_style)

        }


        pushFactorialX = new qpushbutton(win1) {
            setGeometry(Xpos+(2*Xspace), Ypos+(0*Yspace), butSize, butSize)
            #settext("1/x")
            seticon(new qicon(new qpixmap(UserIcons +"FactorialX.png")))
            setIconSize(pushFactorialX.size())
            setclickevent("math('!')")
            setStyleSheet(_style)

        }

        pushPi = new qpushbutton(win1) {
            setGeometry(Xpos+(3*Xspace), Ypos+(0*Yspace), butSize, butSize)
            #settext("Pi")
            seticon(new qicon(new qpixmap(UserIcons +"Pi.png")))
            setIconSize(pushPi.size())
            setclickevent("typeNumbers('3.141592')")
            setStyleSheet(_style)

        }       
        
        
        pushClear =  new qpushbutton(win1) {
            setGeometry(Xpos+(4*Xspace), Ypos+(0*Yspace), butSize, butSize)
            settext("C")
            setclickevent("clearCalc()")
            setStyleSheet("font-weight:bold;font-size:28pt;color:red;border:1px solid #c0c0c0;background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #fff, stop: 1 #fcc);")
 
        }
        
        ###--------------------------
        
        btn7 = new qpushbutton(win1) {
            setGeometry(Xpos+(0*Xspace), Ypos+(1*Yspace), butSize, butSize)
            settext("7")
            setclickevent("typeNumbers(7)")
            setStyleSheet(_styleN)

        }


        btn8 = new qpushbutton(win1) {
            setGeometry(Xpos+(1*Xspace), Ypos+(1*Yspace), butSize, butSize)
            settext("8")
            setclickevent("typeNumbers(8)")
            setStyleSheet(_styleN)

        }


        btn9 = new qpushbutton(win1) {
            setGeometry(Xpos+(2*Xspace), Ypos+(1*Yspace), butSize, butSize)
            settext("9")
            setclickevent("typeNumbers(9)")
            setStyleSheet(_styleN)

        }

        pushDivide = new qpushbutton(win1) {
            setGeometry(Xpos+(3*Xspace), Ypos+(1*Yspace), butSize, butSize)
            settext("/")
            setclickevent("math('/')")
            setStyleSheet(_style)

        }

        pushMemo =  new qpushbutton(win1) {
            setGeometry(Xpos+(4*Xspace), Ypos+(1*Yspace), butSize, butSize)
            settext("Memo")
            setclickevent("Memo()")
            setStyleSheet("border: 1px solid #dddddd; background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #bbf, stop: 1 #aaf); font-size: 12pt" )
        

        }       
 
        ###--------------------------
        
        btn4 = new qpushbutton(win1) {
            setGeometry(Xpos+(0*Xspace), Ypos+(2*Yspace), butSize, butSize)
            settext("4")
            setclickevent("typeNumbers(4)")
            setStyleSheet(_styleN)

        }

        btn5 = new qpushbutton(win1) {
            setGeometry(Xpos+(1*Xspace), Ypos+(2*Yspace), butSize, butSize)
            settext("5")
            setclickevent("typeNumbers(5)")
            setStyleSheet(_styleN)

        }

        btn6 = new qpushbutton(win1) {
            setGeometry(Xpos+(2*Xspace), Ypos+(2*Yspace), butSize, butSize)
            settext("6")
            setclickevent("typeNumbers(6)")
            setStyleSheet(_styleN)   

        }

        pushMultiply = new qpushbutton(win1) {
            setGeometry(Xpos+(3*Xspace), Ypos+(2*Yspace), butSize, butSize)
            settext("*")
            setclickevent("math('*')")
            setStyleSheet(_style)
        }
        
        pushBraketOpen =  new qpushbutton(win1) {
            setGeometry(Xpos+(4*Xspace), Ypos+(2*Yspace) , butSize, butSize)
            settext("(")
            setclickevent("math('(')")
            setStyleSheet(_style)

        }       
        
        ###--------------------------
                
        btn1 = new qpushbutton(win1) {
            setGeometry(Xpos+(0*Xspace), Ypos+(3*Yspace), butSize, butSize)
            settext("1")
            setclickevent("typeNumbers(1)")
            setStyleSheet(_styleN)

        }

        btn2 = new qpushbutton(win1) {
            setGeometry(Xpos+(1*Xspace), Ypos+(3*Yspace), butSize, butSize)
            settext("2")
            setclickevent("typeNumbers(2)")
            setStyleSheet(_styleN)

        }

        btn3 = new qpushbutton(win1) {
            setGeometry(Xpos+(2*Xspace), Ypos+(3*Yspace), butSize, butSize)
            settext("3")
            setclickevent("typeNumbers(3)")
            setStyleSheet(_styleN)

        }

        pushMinus = new qpushbutton(win1) {
            setGeometry(Xpos+(3*Xspace), Ypos+(3*Yspace), butSize, butSize)
            settext("-")
            setclickevent("math('-')")
            setStyleSheet(_style)

        }

        pushBraketClose = new qpushbutton(win1) {
            setGeometry(Xpos+(4*Xspace), Ypos+(3*Yspace) , butSize, butSize)
            settext(")")
            setclickevent("math(')')")
            setStyleSheet(_style)

        }       
        
        
        ###--------------------------
        
        pushPercent = new qpushbutton(win1) {
            setGeometry(Xpos+(0*Xspace), Ypos+(4*Yspace), butSize, butSize)
            settext("%")
            setclickevent("math('%')")
            setStyleSheet(_style)

        }


        btn0 = new qpushbutton(win1) {
            setGeometry(Xpos+(1*Xspace), Ypos+(4*Yspace), butSize, butSize)
            settext("0")
            setclickevent("typeNumbers(0)")
            setStyleSheet(_styleN)

        }

        btnDot = new qpushbutton(win1) {
            setGeometry(Xpos+(2*Xspace), Ypos+(4*Yspace), butSize, butSize)
            settext(".")
            setclickevent("typeNumbers('.')")
            setStyleSheet(_styleN)

        }


        pushPlus =  new qpushbutton(win1) {
            setGeometry(Xpos+(3*Xspace), Ypos+(4*Yspace), butSize, butSize)
            settext("+")
            setclickevent("math('+')")
            setStyleSheet(_style)

        }



        ### Equal
        pushEqual = new qpushbutton(win1) {
            setGeometry(Xpos+(4*Xspace), Ypos+(4*Yspace), butSize, butSize)
            settext("=")
            setclickevent("checkEnter()")
            setStyleSheet("border:1px solid #c0c0c0;background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #fff, stop: 1 #cfc);font-size: 15pt")

        }
 
        ###--------------------------

        edit1.setfocus(0)

        show()
    }  
    
    exec()
}

###========================================


func message(msg)
        new qmessagebox(win1) 
        {
            settext(msg)
            show()
        }
return

###================================================================
### Keyboard -- allow ONLY Digits Dot and Functions * / - + ^ v ! %
### Erase last Alpha char and restore edit1.text
###

Func changedText()
        
        keyData = edit1.text()
        lenData = len(KeyData)
        
        if lenData > 0
            Char = keyData[lenData]   ### last char entered         
            
            ### Allow these keyboard chars only - Digits and Math
            if isDigit(Char) or Char="." or Char="^" or Char="v" or Char="!" or Char="%"  or Char="+"  or Char="-" or Char="*" or Char="/" or Char="(" or Char=")"  
                ### do nothing
            else
                ### Restore old data before last char
                keyDataOld = substr( keyData, 1, lenData-1)
                edit1.settext(keyDataOld)
            ok
            
            if Char = "="
                checkEnter()  ### Same as ReturnKey
            ok
        ok  
        
return

###===================================
### Handle GUI -- Numbers and Dot

func typeNumbers(x)
    edit1.settext(edit1.text() + x)
    See x
return

###-----------------------------------
### Handle GUI -- Math Functions 
  
func math(x) 
    edit1.settext(edit1.text() + x )
    See x
return

###-----------------------------------
### CLEAR --Start with a Clean Slate 
   
func clearCalc()
    edit1.settext("")
    oComboBox.clear()
    result = 0
return

###----------------------------------

Func testExpression
        ### TEST Equations --- Put the here
            See nl
            eval ( "result = " + sqrt(9)       ) ; See "Test 9v: "+      result +nl
            eval ( "result = " + pow(9,2)      ) ; See "Test 9^: "+      result +nl
            eval ( "result = " + factorial(4)  ) ; See "Test 4!: "+      result +nl
            eval ( "result = " + sqrt(9+16)    ) ; See "Test (9+16)v: "+ result +nl
            eval ( "result = " + pow((4+5),2)  ) ; See "Test (4+5)^: "+  result +nl
            eval ( "result = " + sqrt(0)       ) ; See "Test 0v: "+      result +nl
            eval ( "result = " + pow(0,2)      ) ; See "Test 0^: "+      result +nl
            eval ( "result = " + factorial(1)  ) ; See "Test 1!: "+      result +nl
            eval ( "result = " + factorial(0)  ) ; See "Test 0!: "+      result +nl
            See nl 
return


###========================================
#   CALCULATE on ENTER
#    
#   Read the line and execute
#       # 2*(3+4)-5
#       # enum: 2*(3+4)-5 => result 9
#
#   + - ~ Regular math functions
#   * / ~ Regular math functions
#   ( ) ~ Brackets for grouping
#
#   %   ~ Modulo, but we want to use it as Percent
#
#   v   ~ Square Root       v = sqrt(number(enum))
#   ^   ~ Squared Pow       ^  = pow(number(edit1.text()), 2)
#   !   ~ Factorial         ! = factorial(number(enum))
#                         
#   Pi  ~ 3.141592
#
#   =   ~ Keyboard "=" is a Boolean
#
#   SAMPLE:
#       ((2+3)*(4+5))+9
#       enum: ((2+3)*(4+5))+9 => 54
#-----------------



func checkEnter()

        ### If test required to validate an expression, 
        ### Enter it above in the Func testExpression
        
			#testExpression()  ### <<<== Run built in test to verify
                  
        ### ENTER or EqualSign -- Get Entry Line  1+(2+3)+4 => 10
        
        enum     = edit1.text()     
        enumCur  = substr(enum, " ", "")
        See nl +"enumCur: "+ enumCur +nl
        
        ### ANALYSE and SWAP  "^ v !"  in the Line with Functions for Root, Square. Factorial
        
        enum = analyseEnum(enumCur)   
    
    try 
        ###-------------------------------------------------------------###
        ### ==>>> THIS IS THE CALCULATOR <<<==
        ###
        ###       EVAL -- Number x Function => Result , Line 5*6/3+4-8 => 6
        ###-------------------------------------------------------------###
        
            eval( "result = " + enum)
            See " => "+ result +nl
            
            ###----------------------
            ### MEMO pad
            
            add2History(enum, result)
            
        
        ###-------------------------------------------
        ### ComboBox update
        
        oComboBox.additem( enum +" => "+ result, 0)
        oComboBox.setcurrentindex( oComboBox.count() )
        
        ###--------------------------------------------
        ### EnterLine -- Updated with result
        
        edit1.settext("" + result)
       
     
    catch
        see "Check Calculation: "+ cCatchError + nl
        ### edit1.settext( "0 "+ cCatchError ) 

        message("Check Calculation: "+nl + cCatchError)

    done    
return

    
    
###=================================================================
#
# ANALYSE the INPUT
#
# Swap the Root, Sqre, Factorial with Functions before the Number
#
#             12345678901234567890
#                 |    |    |
#             2*(9v)*(5^)+(3!)
#    enumCur: 2*(9v)*(5^)+(3!)  Position "Root Square Fact": 5 10 15  
#
#             (9-4)v
#    enumCur  sqrt(9-5)         Position "Root Square Fact": 6 0 0
#
#    v   ~ Square Root    v = sqrt(number(enum))
#    ^   ~ Squared Power  ^ = pow(number(edit1.text()), 2)
#    !   ~ Factorial      ! = factorial(number(enum))
#   
###---
    
Func analyseEnum(enumCur)


    enumNew = enumCur  ### May not be any Functions "v ^ ! " to Swap In  
            
    ### SQUARE-ROOT "v" ---------------------------------------
    
        while( substr(enumCur, "v") )
            
            posRoot  = substr(enumCur, "v")      
            posLeft  = 0
            charLeft = posRoot -1               
            
                ### Typed on only Function with no data
                if charLeft = 0
                    enumNew = "sqrt(0)"
                    return
                ok
            
            ### Left of "v" -- Type *9v  or Type (4+5)v
            ### Find the previous Digit or "("
            
            ### Type (4+5)v  => sqrt(4+5)
            if enumCur[charLeft] = ")"          
                charLeft = charLeft -1      
                
                for i = charLeft to 1 step -1       
                    ### Look for OpenBraket "("
                    if enumCur[i] = "("         
                        posLeft = i -1  ###  before the "("
                        exit
                    ok  
                next
                
            ### Type 9v => sqrt(9)
            else                
                for i = charLeft to 1 step -1   
                    if isDigit(enumCur[i]) or (enumCur[i] = ".")
                        ### doNothing
                    else
                        ### found non-digit
                        posLeft = i
                        exit
                    ok  
                next
            ok  
            
            #See "Pos Left-Root: "+ posLeft +"-"+ posRoot +nl 
                        
            enumCur[posRoot] = ")"                  ### Replace v with )
            
            leftPart   =   Left(enumCur, posLeft)
            middlePart =  "sqrt("
            rightPart  = substr(enumCur, posLeft +1)
            
            # See "Left-Mid-Right: | "+leftPart +" | "+ middlePart +" | "+ rightPart +" | "+ nl
            # 2+9v+4     => 2+sqrt(9)+4      => 9
            # 2+(4+5)v+6 => 2+sqrt((4+5))+6  => 11 
            
            
            enumNew = leftPart + middlePart + rightPart        
            See "enumNew: "+ enumNew  +nl   ### DOS window Trace
            enumCur = enumNew
        end
        
    ### SQUARED "^" ---------------------------------------
    
        while( substr(enumCur, "^") )
            
            posRoot = substr(enumCur, "^")
            posLeft = 0
            charLeft = posRoot -1  

                ### Typed on only Function with no data
                if charLeft = 0
                    enumNew = "square(0)"
                    return
                ok          
            
            ### Left of "^" -- Type *9^ or Type (4+5)^
            ### Find the previous Digit or "("
            
            ### Type (4+5)^ => pow((4+5),2)
            if enumCur[charLeft] = ")"          
                charLeft = charLeft -1      
                
                for i = charLeft to 1 step -1       
                    ### Look for OpenBraket "("
                    if enumCur[i] = "("         
                        posLeft = i -1      ###  before the "("
                        exit
                    ok  
                next
                
            ### Type 9^ => pow(9,2)
            else    
                for i = posRoot -1 to 1 step -1
                    if isDigit(enumCur[i]) or (enumCur[i] = ".")                
                    else
                        posLeft = i   
                        exit
                    ok  
                next
            ok
            
            #See "Pos Left-Root: "+ posLeft +"-"+ posRoot +nl 
            
            enumCur[posRoot] = ")"          ### Replace v with )
            
            leftPart   =   Left(enumCur, posLeft)
            middlePart = substr(enumCur, posLeft+1, posRoot - posLeft -1)
            rightPart  = substr(enumCur, posRoot+1)
            
            # See "Left-Mid-Right: | "+leftPart +" | "+ middlePart +" | "+ rightPart +" | "+ nl
            # 2+9^+4     => 2+pow(9,2)+4     => 87
            # 2+(4+5)^+6 => 2+pow(((4+5))+6  => 89
            
            enumNew = leftPart + "pow(" + middlePart +",2)"+ rightPart      
            See "enumNew: "+ enumNew +nl
            enumCur = enumNew
        end

    ### FACTORIAL   ---------------------------------------
    
        while( substr(enumCur, "!") )
            
            posRoot = substr(enumCur, "!")
            posLeft = 0
            charLeft = posRoot -1               
 
                ### Typed only ! Function with no data
                if charLeft = 0 
                    enumNew = "factorial(0)"
                    return
                ok                      
                        
            ### Left of "!" -- Type *9!  or (4+5)!
            ### Find the previous Digit or "("
            
            ### Type (4+5)! 
            if enumCur[charLeft] = ")"          
                charLeft = charLeft -1      
                
                for i = charLeft to 1 step -1                   
                    ### Look for OpenBraket "("
                    if enumCur[i] = "("         
                        posLeft = i -1  ###  before the "("                                           
                        exit
                    ok  
                next
  
            else    
                ### Type 9!            
                for i = posRoot -1 to 1 step -1
                    if isDigit(enumCur[i]) or (enumCur[i] = ".")                
                    else
                        posLeft = i
                        exit
                    ok  
                next
            ok
            
            #See "Pos Left-Root: "+ posLeft +"-"+ posRoot +nl 
            
            enumCur[posRoot] = ")"
            leftPart   =  Left(enumCur, posLeft)
            middlePart = "factorial("
            rightPart  =  substr(enumCur, posLeft+1)

            # See "Left-Mid-Right: | "+leftPart +" | "+ middlePart +" | "+ rightPart +" | "+ nl
            # 2+4!+5     => 2+factorial(4)+5      => 31
            # 2+(4+5)^+6 => 2+factorial((2+3))+6  => 128
            
            enumNew = leftPart + middlePArt + rightPart       
            See "enumNew: "+ enumNew +nl
            enumCur = enumNew
        end
        
        ###---------------------------------------------------------
        ### SAMPLE RESULTS - TRACE in DOS Window
        #   enumCur: 2+(4+5)v+(6+7)^+(3+4)!+9
        #   enumNew: 2+sqrt((4+5))+(6+7)^+(3+4)!+9
        #   enumNew: 2+sqrt((4+5))+pow((6+7),2)+(3+4)!+9
        #   enumNew: 2+sqrt((4+5))+pow((6+7),2)+factorial((3+4))+9
        #    => 5223
        ###--------------------
 
        
return enumNew      

###----------------------------------------

Func Memo()
    win2 = new qWidget() 
    {
        setwindowtitle("History Of Ring Calculator")
        setwindowmodality(false)
        setparent(win1)
        setwinicon(self,"images/calc.png")
        setFixedSize(550,500)
        setwindowflags( qt_dialog & ~ qt_WindowMaximizeButtonHint)


        Table1 = new qTableWidget(win2) {
            setGeometry(10,10,530,450)
            setrowcount(0) setcolumncount(3)
            setHorizontalHeaderItem(0, new QTableWidgetItem("Function"))
            setHorizontalHeaderItem(1, new QTableWidgetItem("Result") )
            setHorizontalHeaderItem(2, new QTableWidgetItem("Date") )
            setcolumnwidth(2,200)
            setalternatingrowcolors(True)
            
            oDB     = sqlite_init()
            n       = sqlite_open(oDB,'calc.db')
            aResult = sqlite_execute(oDB,"select * from calc order by dateline desc")                       
            x       = 0
            
            for row in aResult
                insertrow(x)
                setitem(x,0,new qtablewidgetitem(row[:math]))
                setitem(x,1,new qtablewidgetitem(row[:result]))
                setitem(x,2,new qtablewidgetitem(row[:dateline]))
                x++
            next 
            
            sqlite_close(oDB)     
        }

        new qPushButton(win2) {
            setText("Delete History")
            move(340,465)
            resize(100,30)
            setClickevent("deleteHistory()")
        }

        new qPushButton(win2) {
            setText("Close")
            move(440,465)
            resize(100,30)
            setClickevent("win2.close()")
        }
         show()
    }
return

###--------------------------------------
    
Func add2History(enum,result)
    oDB = sqlite_init()
    sqlite_open(oDB,'calc.db')
    sqlite_execute(oDB, "insert into `calc` (`math`, `result`) values('"+ enum +"','"+ result +"');")
    sqlite_close(oDB)
    
Func deleteHistory
    oDB = sqlite_init()
    sqlite_open(oDB,'calc.db')
    sqlite_execute(oDB, "delete from calc ;")
    sqlite_close(oDB)
    win2.close()
    memo()
    
###-----------------------------------
