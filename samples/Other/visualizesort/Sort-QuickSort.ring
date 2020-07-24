###  Draw QuickSort - Animated
###  2019-02018  Bert Mariani
###  QuickSort Non Recursive
###
###  MyApp.ProcessEvents()  ###<<< EXEC the Draw MonaLisa between each step of array sorting

Load "guilib.ring"
load "stdlib.ring"

WinX     = 850
WinY     = 700

ButtonX  = 620
ButtonW  = 100
ButtonH  =  30

LabelX   = 830
LabelY   = 550

MonaX    = 830
MonaY    = 550

gSleepDelay = 0.1           ### Set SleepDelay for Visual display of sort array steps  
gSpace = 2                  ### Space between bars drawn

### Setup Random Values --------------------

width    = 400          ### Array Size =  400
height   = 500
values   = list(width)  ### Global

###-----------------------------------------
      
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorBlack  = new qcolor() { setrgb(000,000,000,255) }

penUseR = new qpen() { setcolor(colorRed)    setwidth(1) }
penUseK = new qpen() { setcolor(colorBlack) setwidth(1) }

###===========================================
        
MyApp = New qapp
{
   win1 =  new qwidget()
    {
        setwindowtitle("Draw QuickSortNR - Animated")
        setgeometry(100,100,WinX, WinY)      ### On Screen      
        
        new qpushbutton(win1) 
        {   
              setgeometry(50,ButtonX, ButtonW, ButtonH)
              settext("Draw-QuickSort-NR")
              setclickevent("DrawQuickSortNR()")
        }
    
        
        ###==================================
        
        Canvas = new qlabel(win1)
        {        
            setgeometry(10,10,LabelX, LabelY)  ### In Window
            
            MonaLisa = new qPixMap2( MonaX, MonaY) 

            daVinci  = new qpainter() 
            {
               begin(MonaLisa)             
               setpen(penUseR)         
               #endpaint()      ### This will Stop the Painting
            }
            
            setpixmap(MonaLisa)        
        }       

        ###==================================           
        
                
       show()   ### Will show Painting ONLY after exec   
    }
   exec()
}


###====================================================
### Draw MonaLisa Painting

Func DrawUpdate(values)
            
    ### Draw vertical lines from values[] array
    ### First Black out canvas-picture
    
    MonaLisa.fill(colorBlack)

    daVinci.setpen(penUseR)
    for i =  1 to width     
        daVinci.drawline(i*gSpace, height, i*gSpace, height - values[i])   
    next
            
        Canvas.setpixmap(MonaLisa)              ### Need this setpixmap to display imageLabel   
        win1.setwindowtitle("QuickSort Animated:")
        win1.show()                             ### Need this show to display imageLabel

        MyApp.ProcessEvents()                   ###<<< EXEC the Draw
return

###=============================================================
Func RandomValues(values, width)
    for i = 1 to width
        values[i] = random(height)
    end
return

###=============================================================
### Driver program to test above functions 
Func DrawQuickSortNR()

    RandomValues(values, width)                  ### Generate array of random Values
    arr = values

        ### Fixed Values for Testing
        #   arr = [4, 3, 5, 2, 1, 3, 2, 3] 
        #   arr = [4, 3, 7, 2, 6, 8, 9, 5]
        #   arr = [9,8,7,6,5,4,3,2,1]
        #   arr = [9,5,8,7,11,4,2,6,11,21,11,13,19,12]   ### 14
     
    n = len(arr) 
    See nl+nl+"Start  : " SeeArr( arr, n ) 
    
    quickSortNR( arr, 1, n )     ### 0, n - 1 ) 
    See nl+nl+"End..  : " SeeArr( arr, n ) 
    
    DrawUpdate(arr)  ### DRAW MONA LISA
    
return 0 

###================================================
### A utility function to print contents of arr 
### Array, number of elements

Func SeeArr( arr, n ) 
    for  i = 1 to n  
        See ""+ arr[i] +" "
    next 
        See nl
return
  
###============================================================
### A utility function to swap two elements 
### Array, A-position, B-position

Func Swap ( arr, a, b ) 
    t      = arr[a] 
    arr[a] = arr[b] 
    arr[b] = t 
return 
  

###============================================================= 
### This function is same in both iterative and recursive
### Array, LowBound, HighBound, Pivot is HighBound Element

Func Partition (arr, L, H) 

    x = arr[H] 
    i = L-1        
    
        for j = L to (H -1)
   
            if (arr[j] <= x)         
                i++ 
                swap (arr, i, j)            
            ok 
        next
    
    swap (arr, (i + 1), H) 
    
return (i + 1)


###============================================================
  
###   A[] --> Array to be sorted,  
###   L   --> Starting index,  LowBound
###   H   --> Ending index     HighBound

Func quickSortNR(arr, L, H)

    Count = 1 
 
    ### Create an auxiliary stack of size
    stack = list( H - L + 1 )
  
    ### initialize top of stack 
    top = 0  ### -1 
  
    ### push initial values of L and H to stack 
    top++    stack[ top ] = L 
    top++    stack[ top ] = H 
    
    ### Keep popping from stack while is not empty 
    while ( top >= 1)     ### 0 ) 
    
        ### Pop H and L 
        H = stack[top]   stack[top] = 0  top--  
        L = stack[top]   stack[top] = 0  top-- 
        
  
        ### Set pivot element at its correct position in sorted array 
        P = Partition( arr, L, H )   ### <<<<<<
  
     
        ### If there are elements on left side of pivot, then push left side to stack 
        if ( P-1 > L )        
            top++  stack[top] = L 
            top++  stack[top] = P - 1 
            
        ok 
  
        ### If there are elements on right side of pivot, then push right side to stack 
        if ( P+1 < H )        
            top++  stack[top] = P + 1 
            top++  stack[top] = H 
        ok 
    
    
        ### Call the DrawUpdate function for Intermediate Draw of the  MonaLisa
        ### It has the ProcessEvents to allow Exec of the MyApp
        
        #See "Count:"+ count +nl    
        Count++ 
        Sleep(gSleepDelay)   ### Set Delay                         
        DrawUpdate(arr)     ###<<< DRAW array

        
    end 
    
    DrawUpdate(arr)     ###<<< DRAW array
    
return 
  

###================================================
