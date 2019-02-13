###  Visualize Sort - Animated
###  2019-01-27  Bert Mariani
###  

Load "guilib.ring"
WinX     = 850
WinY     = 700

ButtonX  = 620
ButtonW  = 100
ButtonH  =  30

LabelX   = 830
LabelY   = 550

MonaX    = 830
MonaY    = 550


### Setup Random Values --------------------

idx   = 0       ### Index for Global list sorted left <= right  BUBBLE
speed = 5       ### Sort n passes before re-display
swapCount   = 0   
arrayAccess = 0

min_idx = 0     ### Selection Sort - mininum value found

width    = 400
height   = 500
values   = list(width)

for i = 1 to width
    values[i] = random(height)
    # See "Values: "+ i +" "+ values[i] +nl
end

### MergeSortNR
n     = len(values) ### 
gTemp = list(n)     ### For MergeSort need gTemp[values] same size
size  = 1           ### For MergeSort  1,2,4,8,16 ...


###See "ValuesBefore: "+nl+nl See values  See nl+nl

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
              settext("Draw-Sort")
              setclickevent("Draw()")
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
            comboList = ["Bubble","Selection","Insertion","Merge"]
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
        
        oTimer = new qTimer(win1) 
        {       
            setinterval(100)                        ### 100 Delay Sort Steps 1 millisecond
            settimeoutevent("DrawSort()")           ### <<<=== SORT Delay bewteen Display
            #start()
        }  

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

###-------------------------------------
### Speed of Move Animation
### Slider 10 -99

Func SliderEventValueChg()

    #See "SliderValue: "+ Slider1.value() +nl
    oTimer.setinterval( (100 - Slider1.value()) * 20 )      ### Value 50 * 10 => 0.500 seconds
return

###=======================================

Func Draw()

    SortType = comboSortType.currentText()
    See "SortType: "+ SortType +nl
    
    ### Seed NEW Random Array
    for i = 1 to width
        values[i] = random(height)
    end 
    
    ### Reset Index and Values
    idx = 0 
    swapCount = 0
    arrayAccess = 0
    
    ### MergeSortNR need TempArray
    n     = len(values) ### 
    gTemp = list(n)     ### For MergeSort need gTemp[values] same size
    
    oTimer.start()
return
 
###------------------
Func Stop()
    oTimer.stop()
return 

###-----------------

Func Leave()
    MyApp.quit()
return
  
###=================================================
### Comparisons,  Array Acesses,  Delay
  
Func DrawSort()

SortType = comboSortType.currentText()

switch SortType

    on "Bubble"
        if idx = 0 idx = 0 ok   ### Stop - ReStart leave idx alone
        Bubble(values)

    on "Selection"
        if idx = 0 idx = 1 ok   ### Stop - ReStart leave idx alone
        Selection(values)

    on "Insertion" 
        if idx = 0 idx = 2 ok   ### Stop - ReStart leave idx alone
        Insertion(values)

    on "Merge"
        if idx = 0 idx = 0 ok   ### Stop - ReStart leave idx alone
        mergeSortNR(values)     ### "Calling MergeSort Non-Recursive
        

off     ### Switch OFF

DrawUpdate(values)
CheckFinishedSort()

return

###================================================================

Func DrawUpdate(values)
            
    ### Draw vertical lines from values[] array
    ### First Black out canvas-picture
    
    MonaLisa.fill(colorBlack)

    space = 2
    daVinci.setpen(penUseR)
    for i =  1 to width     
        daVinci.drawline(i*space, height, i*space, height - values[i])   
    next
        
        Canvas.setpixmap(MonaLisa)          ### Need this setpixmap to display imageLabel   
        win1.setwindowtitle("Sort Animated --- SwapCount: "+ swapCount +" ArrayAccess: "+ arrayAccess +" Index: "+ idx +" SpeedLoop: "+ speed)
        win1.show()                         ### Need this show      to display imageLabel

return

###=============================================================

Func CheckFinishedSort()    
    
    ### Check if FINISHED, Restore fresh values and index
    
    # See "GI: "+ idx +nl
    if (idx > width )
        oTimer.stop()
        See "Finished: "+ idx  +nl  
    
    ok
        
return

###===============================================================

Func Swap( arrayList, a, b) 
 
  temp         = arrayList[a]
  arrayList[a] = arrayList[b]
  arrayList[b] = temp

return

###=====================

Func Bubble(values)
    ###-------------
    ### BUBBLE SORT
    ### Speed up by sorting multiple passes before drawing
    
     for s = 1 to speed
     
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
        
        idx++
            if idx > width
             exit
            ok  
    end
    
return

###-------------------------------------------
Func Selection(values)
    ###---------------
    ### SELECTION SORT

    for s = 1 to speed 
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
    end
    
return

###------------------------------------------

Func Insertion(values)
    
    ###----------------
    ### INSERTION SORT
   
    for s = 1 to speed 
       
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
    end
    
return

###//////////////////////////////////////////////////


###============================================
Func MergeSortNR(values)


    ### l1 Lower bound of first pair and so on 
    ### k  Index for gTemp array 
    
    #See "MergeSort size: "+size +nl    
        if size > width ###  ReStart New MergeSort Chart
            size = 1
        ok
    
    while size < n                                      
                                                        
        l1 = 1                                      
        k  = 1   
        
        while( l1  <= n)                
                                                        
            h1 = l1 + size -1                           
            l2 = h1 + 1
            h2 = l2 + size -1
                                
            ### h1 or h2 exceeds the limit of values 
            if( h2  >= n )  h2 = n  ok
            if( h1  >= n )  h1 = n  ok
            
            ### Merge the two pairs with lower limits l1 and l2
            i = l1
            j = l2
                
            ### Insert Left or Right Side that has lower value
            while( i <= h1 && j <= h2 )
                arrayAccess++
                
                if( values[i] <= values[j] )
                    gTemp[k] = values[i]                                
                    k++ i++
                    swapCount++
                else
                    gTemp[k] = values[j]                    
                    k++ j++
                    swapCount++
                ok
            end                                         

            
            ### Rest of Left
            while( i <= h1 ) ###&& i <= n )
                gTemp[k] = values[i]                        
                k++ i++ 
                swapCount++             
            end

            
            ### Rest of Right
            while( j <= h2 ) ### && j <= n)
                gTemp[k] = values[j]                                
                k++ j++
                swapCount++
            end

            
            ### Merging completed
            ### Take the next two pairs for merging 
            l1 = h2+1 
            
        end                                             

    
        ### Any pair left 
        i = l1
        while k < n                             
            gTemp[k] = values[i]
            k++ i++
            swapCount++
        end

        ### Copy gTemp back to Array
        for i = 1 to (n) step 1                     
            values[i] = gTemp[i]
            swapCount++         
        next

                ###-------------------------------------------
                ### Show Sorted Groups by Size 1,2,4,8.16 ...
                
                #See "Sort Size = "+size +nl    
                #for i = 1 to (n) step 1                        
                #   See ""+ values[i] +" "  
                #       #if !(i % (size))
                #       #   See "| "
                #       #ok
                #next
                #   See nl
        
        size = size * 2     ###<<< next grouping to sort  1,2,4,8,16,32 ....
    
        ### Exit when array elements exceeded
        idx = size
        if idx > width
         exit
        ok  


        return  ### ALLOW Intermediate DrawChart
    end                                                 

                ###-------------------------------
                # 
                # See nl+"FINAL Sorted List is :"+ nl                           
                # for i = 1 to (n) step 1                           
                #   See ""+ values[i] +" "                              
                # next
                #   See nl                                              
return

###======================





