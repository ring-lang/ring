# ListFunction.ring 
#   Lists the Functions in a Ring program.
#   Function Block shows the Called Functions
#   Function Calling a Function Block
#                   
# Author: Bert Mariani
# Date..: 2025-10-21
#
# Updated by Fayed to set the source file using cFilePath variable
# Date..: 2025-11-14
#

load "stdlibcore.ring"     

cFilePath = exefolder()+"../tools/ringfmt/ringfmt.ring"

aFuncList = [["", ""]]   // Dynamic Array [1][a,b,c,d,e,...]

//============================
func main

    txtList = ReadFromFile()
    
    //--- Read Trimed Lines --- k->FUNC ---     
    See "<= Line# Func# Name ===========================>"+ nl+nl
    k = 1   
    for i = 1 to len(txtList)
         Line = txtList[i]
        tLine = trim(Line)
         
        fLinePos = subStr( tLine, "func" )  
        if fLinePos = 1
           See "F: "+i +": "+ k +": "+ tLine +nl     // Func Name
            
            aLine = split(tLine, " ")                // Func-Name-Parm
            
            if k = 1                                 // Line with Func
            
                #--- First Func - update the initial (1,1) array
                aFuncList[1][1] = aLine[2]           // 1 FuncName ftom split
            
            else
                #--- Add new row for Calling Funcs [1][a..b..c..d..]
                add(aFuncList,  [ aLine[2] ] )       // add subFunc
            ok          
    
            k++
            
        ok
        
        #--- CLASS
        cLinePos = subStr( tLine, "Class") 
        if cLinePos = 1
            See nl+"C: "+i +": "+ tLine +nl+nl
        ok
                
    next
            
    
    # -------------------------------   
    // ListFunctions()
    
    ListFunctionSubFunction(txtList)
    
    ListSubFuncCallsFunc(txtList) 
    
    ListFuncArray()
	
	See nl+"<===== END ====================================>" +nl
    
return
 
//==================================

Func ListFunctionSubFunction(txtList)

    # -------------------------
    # Find Exact Matching Func 
            
    See nl+"<===== List of FUNC Block with Called Func ====>"+nl
    for i = 1 to len(txtList)
        Line  = txtList[i]
        tLine = trim(Line)
        
        //--- Find FUNC Routine 
        posF = subStr(tLine, "func")
        if posF = 1
            aLine    = split(tLine, " ")    // Func-Name-Parm
            //FuncName = aLine[2]           // Name
            
            See nl+"FUNC.: "+ i +"| "+ Line +"|"+ nl
            continue
        ok 
         
            //--- Find subFunc  called in FUNC Routine        
            for k = 1 to len(aFuncList)
                nameFunc = aFuncList[k][1]
                
               
                    //--- Name of nameFunc must Match Exactly to name in  Line
                    //--- Will Match processFiles VS processFile
                    // 251    processFiles()
                    //           Func: 5 processFiles
                    //           Func: 9 processFile
                    //   CallFunc: 251 5 |processFiles |   processFiles()
                    //   CallFunc: 251 9 |processFile  |   processFiles()
                    //---           
             
                pos  = subStr(tLine, nameFunc )
                pos2 = subStr(tLine, "(" )
                
                if pos2 > pos                        //  processFiles(
                    exactName = subStr( tLine, pos, pos2 - pos)
                
                    value = strcmp(exactName, nameFunc)
                    if  value =   0                   // exact match         
                        //See nl+"---ExactMatch N-F: |"+ i +"|"+ exactName +"|"+ nFunc +"|"+ nl                
                     
                        posC = subStr(tLine, "#"   )
                        posS = subStr(tLine, "//"  )
                       
                        posComment = 0
                        if posC > 0 OR posS >0          
                          posComment =  max(posC, posS)
                        ok  
                       
                       
                        //--- Ignore if Comment Before Func
                        // Get Calling Func and Index of Called FUNC
                        
                        if pos > 0  
                            if posComment > 0 AND pos > posComment 
                               //See "Ignore Comment Line: "+nl 
                               
                            else
                                #--- Find matching subFunc pointing to FUNC in aFuncList

                                Index = Find(aFuncList, nameFunc, 1)
                                See ".func: "+ i +"|    > "+ exactName +" #"+ Index +nl
                                
                                //Index = Find(aFuncList, FuncName, 1)
                                //Add(aFuncList[Index], nameFunc)                           
                            ok
                            
                        ok
                    ok
                ok
                
            next
         
    
    next
                
return

//==============================================================
// Functions Calling Function Block --- Dynamic 2D Array Display

Func ListFuncArray()

    # Display the array
    See nl+"<===== List of Func Block Called by Func ======>" +nl
    See    "<---   Dynamic 2D Array                     --->" +nl+nl
       
    for i = 1 to len(aFuncList)
        See "FUNC: " + i + " " + aFuncList[i][1] +":  "+ (len(aFuncList[i]) -1) +nl
        
        for j = 2 to len(aFuncList[i])
            See "         << "+ aFuncList[i][j] +nl
        next        
        See nl

    next

return

//==================================

Func ListFunctions()
                         
     See nl+"<===== aList of Functions Blocks  =============>"+nl+nl  
         for k = 1 to len( aFuncList )
             See "Func: "+ k +" | "+ aFuncList[k][1] +" |"+ nl
         next    

return

//==================================

func ReadFromFile()
  
    //------------------------------------------
    // Format lines from File to List of Strings
   
    txtCode  = read(cFilePath)
    txtList  = str2List(txtCode)
    
    return txtList  
    
end

//==================================

//================================== 

Func ListSubFuncCallsFunc(txtList)

    # =============================
    # Find Exact Matching Func 
                             
    //See nl+"<===== List of FUNC Block Called by subFunc ===>"+nl
    for i = 1 to len(txtList)
        Line  = txtList[i]
        tLine = trim(Line)
        
        //--- Find FUNC Routine 
        posF = subStr(tLine, "func")
        if posF = 1
            aLine    = split(tLine, " ")  // Func-Name-Parm
            FuncName = aLine[2]           // Name
            
            //See nl+"FUNC.: "+ i +"| "+ Line +"|"+ nl
            //continue
        ok 
         
            //--- Find subFunc  called in FUNC Routine        
            for k = 1 to len(aFuncList)
                nameFunc = aFuncList[k][1]
                
               
                    //--- Name of nameFunc must Match Exactly to name in  Line
                    //--- Will Match processFiles VS processFile
                    // 251    processFiles()
                    //           Func: 5 processFiles
                    //           Func: 9 processFile
                    //   CallFunc: 251 5 |processFiles |   processFiles()
                    //   CallFunc: 251 9 |processFile  |   processFiles()
                    //---           
             
                pos  = subStr(tLine, nameFunc )
                pos2 = subStr(tLine, "(" )
                
                if pos2 > pos                        //  processFiles(
                    exactName = subStr( tLine, pos, pos2 - pos)
                
                    value = strcmp(exactName, nameFunc)
                    if  value =   0                   // exact match         
                        //See nl+"---ExactMatch N-F: |"+ i +"|"+ exactName +"|"+ nFunc +"|"+ nl                
                     
                        posC = subStr(tLine, "#"   )
                        posS = subStr(tLine, "//"  )
                       
                        posComment = 0
                        if posC > 0 OR posS >0          
                          posComment =  max(posC, posS)
                        ok  
                       
                       
                        //--- Ignore if Comment Before Func
                        // Get Calling Func and Index of Called FUNC
                        
                        if pos > 0  
                            if posComment > 0 AND pos > posComment 
                               //See "Ignore Comment Line: "+nl 
                               
                            else
                                #--- Find matching subFunc pointing to FUNC in aFuncList

                                //Index = Find(aFuncList, nameFunc, 1)
                                //See ".func: "+ i +"|    > "+ exactName +" #"+ Index +nl
                                
                                Index = Find(aFuncList, nameFunc, 1)
                                Add(aFuncList[Index],FuncName)                           
                            ok                          
                        ok
                    ok
                ok
                
            next 
    next

return
//============================
