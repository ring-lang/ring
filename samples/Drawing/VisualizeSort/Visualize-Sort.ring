###  Visualize Sort - Animated
###  2019-01-27  Bert Mariani
###  2020-09-20
###  "Bubble","Selection","Insertion","Merge","Quick","Heap","Counting","Radix"

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

gSleepDelay  = 0.1           ### Set SleepDelay for Visual display of sort array steps  
gSleepDelayB = 0.5           ### Set SleepDelay for Visual display of sort array steps 
gSpace = 2                   ### Space between bars drawn

### Setup Random Values --------------------

idx   = 0       ### Index for Global list sorted left <= right  BUBBLE
speed = 5       ### Sort n passes before re-display
swapCount   = 0   
arrayAccess = 0
SortType    = "Bubble"

width    = 400
height   = 500
values   = list(width)

###-----------------------------------------

      
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorYellow = new qcolor() { setrgb(255,255,000,255) }
colorBlack  = new qcolor() { setrgb(000,000,000,255) }

penUseR = new qpen() { setcolor(colorRed)    setwidth(1) }
penUseG = new qpen() { setcolor(colorGreen)  setwidth(1) }
penUseB = new qpen() { setcolor(colorBlue)   setwidth(1) }
penUseY = new qpen() { setcolor(colorYellow) setwidth(1) }
penUseK = new qpen() { setcolor(colorBlack) setwidth(1) }

###===========================================
        
MyApp = New qapp
{
   win1 =  new qwidget()
    {
        setwindowtitle("Draw Sort - Animated")
        setgeometry(100,100,WinX, WinY)            ### On Screen
    
        new qpushbutton(win1) 
        {   
              setgeometry(50,ButtonX, ButtonW, ButtonH)
              settext("Draw")
              setclickevent("DrawSort()")
        }
        new qpushbutton(win1) 
        {
              setgeometry(200,ButtonX,ButtonW, ButtonH)
              settext("Stop")
              setclickevent("Stop()")
        }        

        new qpushbutton(win1) 
        {
              setgeometry(350,ButtonX,ButtonW, ButtonH)
              settext("Exit")
              setclickevent("Leave()")
        }

        ###------------------------------------------
        ### SortType = comboSortType.currentText()
        
        comboSortType = new QComboBox(win1) 
        {
            setgeometry(500,ButtonX,ButtonW, ButtonH)
            comboList = ["Bubble","Selection","Insertion","Merge","Quick","Heap","Counting","Radix"]
            for x in comboList additem(x,0) next                
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

        Slider1 = new qslider(win1) 
        {
            setgeometry(50,ButtonX+ButtonH, ButtonW, ButtonH)
            setorientation(Qt_Horizontal)
            setTickInterval(50)     
            setValue(50)
            setValueChangedEvent("SliderEventValueChg()")
        }                   
        
                
       show()   ### Will show Painting ONLY after exec   
    }
   exec()
}


###====================================================

###====================================================

Func RandomValues(values, width)
    for i = 1 to width
        values[i] = random(height)
    end
return

###-------------------------------------
### Speed of Move Animation
### Slider 10 -99

Func SliderEventValueChg()

    #See "SliderValue: "+ Slider1.value() +nl
 
    gSleepDelay = (100 - Slider1.value()) * 10  / 1000     ### Value 50 * 10 => 0.500 seconds

    return

###------------------------------------

Func Stop()
    Sleep(2)
return 

###=======================================
 
Func Leave()
    MyApp.quit()
return
  
###=================================================
### Comparisons,  Array Accesses,  Delay
  
Func DrawSort()

    ### Seed NEW Random Array
    RandomValues(values, width)                  ### Generate array of random Values

    ### Reset Index and Values
    idx         = 0 
    swapCount   = 0
    arrayAccess = 0
    
SortType = comboSortType.currentText()

switch SortType

    on "Bubble"
        Bubble(values)
        See "Finished: Bubble"+nl

    on "Selection"
        Selection(values)
        See "Finished: Selection"+nl

    on "Insertion" 
        Insertion(values)
        See "Finished: Insertion"+nl

    on "Merge"
        mergeSortNR(values)         ### MergeSort Non-Recursive
        See "Finished: Merge"+nl
        
    on "Quick"
        quickSortNR(values)         ### QuickSort Non-Recursive
        See "Finished: Quick"+nl

    on "Heap"
        heapSort(values)     
        See "Finished: Heap"+nl 

    on "Counting"
        CountingSort(values)  
        See "Finished: Counting"+nl    

    on "Radix"
        RadixSort(values)  
        See "Finished: Radix"+nl         
            

off     ### Switch OFF

DrawUpdate(values)

return

###================================================================

Func DrawUpdate(values)
            
    ### Draw vertical lines from values[] array
    ### First Black out canvas-picture
    
    MonaLisa.fill(colorBlack)


    daVinci.setpen(penUseR)
    for i =  1 to width     
        daVinci.drawline(i*gSpace, height, i*gSpace, height - values[i])   
    next
        
        Canvas.setpixmap(MonaLisa)          ### Need this setpixmap to display imageLabel   
        win1.setwindowtitle("Sort Animated "+SortType +" :: SwapCount: "+ swapCount +" ArrayAccess: "+ arrayAccess +" Index: "+ idx +" Delay: "+ gSleepDelay )
        win1.show()                         ### Need this show      to display imageLabel
            
        MyApp.ProcessEvents()               ###<<< EXEC the Draw
        Sleep(gSleepDelay)
                
return

###=========================================================
###=========================================================

Func Swap( arrayList, a, b) 
 
  temp         = arrayList[a]
  arrayList[a] = arrayList[b]
  arrayList[b] = temp

return

###=========================================================

Func Bubble(values)
    ###-------------
    ### BUBBLE SORT
    ### Speed up by sorting multiple passes before drawing
    idx = 0 
    
    for i = 1 to width 
     
        ### Bubble Sort one pass
        for j = 1 to (width -idx -1)  
            a = values[j]
            b = values[j+1]
            arrayAccess++
                              
            if (a > b)   
                Swap( values, j, j+1 )
                swapCount++
            ok                  
        end  
        
        DrawUpdate(values)      ### Draw Intermediate Chart
        
    next 
return

###-------------------------------------------
Func Selection(values)
    ###---------------
    ### SELECTION SORT

    idx = 1 
    
    for s = 1 to width 
        min_idx = idx
        
        for j = (idx+1) to width
            a = values[j]
            b = values[min_idx]
            arrayAccess++
            
            if (a < b) 
                min_idx = j
            ok
        end     
        
        Swap( values, min_idx, idx)
        swapCount++

        idx++
        if idx > width
            exit
        ok
    
        DrawUpdate(values)      ### Draw Intermediate Chart 
    end
      
return

###------------------------------------------

Func Insertion(values)
    
    ###----------------
    ### INSERTION SORT
    
    idx = 2
   
    for s = 1 to width
       
       key = values[idx] 
       j   = idx -1
           
        while (j >= 1 && values[j] > key)  
            values[j+1] = values[j];                            
            j = j-1
            arrayAccess++      
        end
       
        values[j+1] = key

        swapCount++     
       
        idx++    
        if idx > width
            exit
        ok  
        
        DrawUpdate(values)      ### Draw Intermediate Chart 
    end
    
return

###//////////////////////////////////////////////////


###============================================
Func MergeSortNR(values)

    ### MergeSortNR
    idx   = 0
    n     = len(values) ### 
    gTemp = list(n)     ### For MergeSort need gTemp[values] same size
    size  = 1           ### For MergeSort GROUPS 1,2,4,8,16 ... 
    
    ### L1 Lower bound of first pair and so on 
    ### K  Index for gTemp array 
    
    if size > width ###  ReStart New MergeSort Chart
        size = 1
    ok
    
    while size < n                                      
                                                        
        L1 = 1                                      
        K  = 1   
        
        while( L1  <= n)                
                                                        
            H1 = L1 + size -1                           
            L2 = H1 + 1
            h2 = L2 + size -1
                                
            ### H1 or h2 exceeds the limit of values 
            if( h2  >= n )  h2 = n  ok
            if( H1  >= n )  H1 = n  ok
            
            ### Merge the two pairs with lower limits L1 and L2
            i = L1
            j = L2
                
            ### Insert Left or Right Side that has lower value
            while( i <= H1 && j <= h2 )
                arrayAccess++
                
                if( values[i] <= values[j] )
                    gTemp[K] = values[i]                                
                    K++ i++
                    swapCount++
                else
                    gTemp[K] = values[j]                    
                    K++ j++
                    swapCount++
                ok
            end                                         

            
            ### Rest of Left
            while( i <= H1 ) ###&& i <= n )
                gTemp[K] = values[i]                        
                K++ i++ 
                swapCount++             
            end

            
            ### Rest of Right
            while( j <= h2 ) ### && j <= n)
                gTemp[K] = values[j]                                
                K++ j++
                swapCount++
            end

            
            ### Merging completed
            ### Take the next two pairs for merging 
            L1 = h2+1 
            
        end                                             

    
        ### Any pair left 
        i = L1
        while K < n                             
            gTemp[K] = values[i]
            K++ i++
            swapCount++
        end

        ### Copy gTemp back to Array
        for i = 1 to (n) step 1                     
            values[i] = gTemp[i]
            swapCount++         
        next
 
        size = size * 2     ###<<< next grouping to sort  1,2,4,8,16,32 ....
    
        ### Exit when array elements exceeded
        
        idx = size
        if idx > width
            exit
        ok  

        DrawUpdate(values)      ### Draw Intermediate Chart 
        
    end                                                 

                                                    
return

###=============================================================
###=============================================================

###=============================================================
### A utility function to print contents of arr 
### Array, number of elements

Func SeeArr(arr)
    N = len(arr)
    for  i = 1 to n  
        See ""+ arr[i] +" "
    next 
        See nl
return
  
###============================================================
### A utility function to swap two elements 
### Array, A-position, B-position

Func SwapQS ( arr, a, b ) 
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
                SwapQS (arr, i, j)   
                swapCount++
                arrayAccess++
            ok 
        next
    
    SwapQS (arr, (i + 1), H) 
    swapCount++
    
return (i + 1)


###============================================================
### QUICK SORT
###   A[] --> Array to be sorted,  
###   L   --> Starting index,  LowBound
###   H   --> Ending index     HighBound

Func quickSortNR(arr)

    N   = len(arr )  
    
    L = 1
    H = N
 
    ### Create an auxiliary stack of size  ( sqrt size is enough)
    ### stack = list( H - L + 1 )
     stackSize = ceil ( sqrt( H - L +1 )) + 4
     stack = list(stackSize)
  
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
                    
        DrawUpdate(arr)     ###<<< DRAW array
     
    end 
    
    
return 
  

###================================================
###================================================
###================================================

###-------------------------------------
### HEAP SORT
 
Func heapSort(arr) 

    N = len(arr)
    
    ### Build heap (rearrange array) 
    for i = N / 2  to 1 step -1         
        heapify(arr, N, i) 
    next
  
    ### One by one extract an element from heap 
    for i = N to 1 step -1              
  
        ### Move current root to end 
        swap(arr, 1, i)     
        swapCount++
  
        ### Call max heapify on the reduced heap 
        heapify(arr, i, 1)                  
        
        DrawUpdate(arr) ###<<<
    next 
return 
  
###------------------------------------------------------------------------------------------  
### To heapify a subtree rooted with node i which is  an index in arr[]. N is size of heap 

Func heapify( arr, N, i) 
 
    largest = i         ### Initialize largest as root 
    L = 2*i + 0         ### Left  = 2*i + 1 
    R = 2*i + 1         ### Right = 2*i + 2 
  
    ### If left child is larger than root 
    if (L < N && arr[L] > arr[largest]) 
        largest = L 
        arrayAccess++
    ok
  
    ### If right child is larger than largest so far 
    if (R < N && arr[R] > arr[largest]) 
        largest = R 
        arrayAccess++
    ok
    
    
    ### If largest is not root 
    if (largest != i) 
    
        swap(arr , i, largest) 
        swapCount++
        arrayAccess++
        #SEE "Heapify: Largest: "+ largest +" i:"+ i +" L:"+L +" R:"+ R +nl
  
        ### RECURSIVELY heapify the affected sub-tree 
        heapify(arr, N, largest)        ###<<< RECURSIVE 
    ok
    
return 
  
###============================================================

###================================================
###================================================
###================================================


###===============================

Func CountingSort(Arr) 

    N = len(Arr)

    ### First, find the maximum value in Arr[]
    K = 0
    for  i=1 to N 
        K = max(K, Arr[i])
        if Arr[i] = 0
            Arr[i] = 1      ### Fix Random: for trying to Index at 0 for Aux[Arr[i]] 
            #See "Fixed random 0 at Arr[i]:"+i +nl
        ok
    next

    Aux = list(K+1)         ###<<<  Create Aux Array
    
    ### Initialize the elements of Aux[] with 0
    for i=1 to K+1
        Aux[i] = 0
    next


    ### Store the frequencies of each distinct element of Arr[],
    ### by mapping its value as the index of Aux[] array
    
    for i = 1 to N 
        Aux[Arr[i]] = 1 + Aux[Arr[i]]   ### Count how many times a value goes in array cell
        arrayAccess++
    next

    j = 1
    for i=1  to K+1 
        tmp = Aux[i]
        
        ### Aux[] stores which element occurs how many times,
        ### Add i in sortedA[] according to the number of times i occurred in Arr[]
        
        while(tmp) 
            Arr[j] = i
            j++
            tmp--
            arrayAccess++
        end
        
        DrawUpdate(Arr)     ###<<< Draw Chart Intermediate
        
    next
return Arr


###===================================================

###---------------------------------------------------
 
Func RadixSort(arr) 

   //arr = [82,901,100,12,150,77,3145,2687,55,23]  // Test Array
   n   = len(arr)
   
   See "Initial array: "+nl
   //printA(arr, n) 
 
   DrawUpdate(Arr)     ###<<< Draw Chart Intermediate
   Sleep(gSleepDelayB)

   radixSortA(arr, n);
 
   See "------------"+nl+nl
   See "Final array: "+nl
   //printA(arr, n)
      
return 0

###---------------------------------------------------  
// Sort arr[] of size n using Radix Sort.

Func radixSortA(arr, n)
   
   m      = getMax(arr, n)  
   digits = len(""+ m)  
 
   // Calling countSort() for digit at (place)th place in every input.
   
   place = 1
   for i = 0 to digits - 1 
      
      See "------------"+nl+nl
      See "Place: "+ place +nl
      
      countSort(arr, n, place)
      place = place * 10

   next

return



###--------------------------------------------------- 
// CountSort method of arr[].

Func countSort(arr, n, place)

   // Count[i] array will be counting the number of array values having that 'i' digit at their (place)th place.  
   
   //output = Arr         // Replace with Visual Arr background
   output = list(n)
   count  = list(11)  
 
   // Count the number of times each digit occurred at (place)th place in every input.
   for i = 1 to n
      here = floor((arr[i] / place) % 10)
      count[  here +1] += 1    // ++;
   next
 
   // Calculating their cumulative count.
   for i = 2 to 10;             // 1
      count[i] += count[i-1];
   next
          
   // Inserting values according to the digit '(arr[i] / place) % 10' fetched into count[(arr[i] / place) % 10].
   for i = n to 1 step -1     
   
      here = floor((arr[i] / place) % 10 +1)      
      output[ count[ here ] ]  = arr[i]
              count[ here ]   -= 1
              
      DrawUpdate(output)     ###<<< Draw Chart Intermediate -- Visual Movement
   next
   
   arr = output

   See "arr Sort: "+nl
   //printA( arr,  n)
   
   DrawUpdate(Arr)     ###<<< Draw Chart Intermediate - Visualize
   Sleep(gSleepDelayB)
            
return      

 
###---------------------------------------------------  
// Get maximum value from array

Func getMax( arr, n)
   mx = arr[1]
   for i = 1 to n
      if (arr[i] > mx)
         mx = arr[i]
      ok
   next
return mx

###---------------------------------------------------   
// A utility function to printA an array 


Func printA(arr, n) 
 
    for i = 1 to n 
        See " | "+ arr[i] 
    next 
    See nl+nl
    
return


###--------------------------------------------------- 
// Sorted Data ->1->3->12->54->96->129->542->886->1125->3125
