# Form/Window Controller - Source Code File
# Author: Bert Mariani
# Date..: 2022-02-05

load "TaskView.ring"
load "internetLib.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:Rosetta_FormDesigner_TaskController)
		exec()
	}
}

class Rosetta_FormDesigner_TaskController from windowsControllerParent

	oView = new TaskView

//========================================================
// Get List of Ring Tasks from Rosetta Code. Category Ring
// $url    = "http://rosettacode.org/wiki/Category:Ring"
// $url    = "http://rosettacode.org/wiki/Category:Programming_Tasks"

$url    = "http://rosettacode.org/wiki/Category:Ring"

cOutput =  download($url)
cDataR  =  str2list(cOutput) 
cDataL  =  []                                  // Create a List of Lines from data downloaded

for i = 1 to len(cDataR)
	
	Pos1  = substr(cDataR[i], '<li><a href="/wiki/' )      // Start -- <li><a href="/wiki/ -- single quotes
	Line1 = substr(cDataR[i], Pos1, len(cDataR[i]))

	if len(Line1) > 4			
		Pos2     = substr(Line1, "title" )                  // End -- " title="
		TaskName = substr(Line1, Pos1+19, Pos2 -Pos1 -21 )  // Extract task name 
                oView.ListWidget1.additem( TaskName )	

                Add(cDataL, TaskName)                               // List of Ring Tasks
	
	ok
next


//----------------------------------------------------------------
//
$url    = "http://rosettacode.org/wiki/Category:Programming_Tasks"

cOutput =  download($url)
cDataT  =  str2list(cOutput)                                   // Create a List of Lines from data downloaded

oView.ListWidget1.additem( nl+"============ NO RING CODE FOR THE FOLLOWING ============"+nl ) 

for i = 1 to len(cDataT)
	
	Pos1  = substr(cDataT[i], '<li><a href="/wiki/' )      // Start -- <li><a href="/wiki/ -- single quotes
	Line1 = substr(cDataT[i], Pos1, len(cDataT[i]))

	if len(Line1) > 4			
		Pos2     = substr(Line1, "title" )                  // End -- " title="
		TaskName = substr(Line1, Pos1+19, Pos2 -Pos1 -21 )  // Extract task name 

                if !( find(cDataL, TaskName) )                      // Does Ring Task exist
                      oView.ListWidget1.additem( TaskName )
                ok		
	ok
next

// =====================================================
// Get Ring Code from Rosetta Code
// $url = "https://rosettacode.org/mw/index.php?title=Koch_curve&action=edit"  
// -----------------------------------------------------

func GetTaskCode(TaskName)
	
	$urlA = "https://rosettacode.org/mw/index.php?title="
	$urlB = TaskName
	$urlC = "&action=edit"

	$urlABC = $urlA + $urlB + $urlC
	See "URL: "+ $urlABC +nl
	  
	cStr  = download($urlABC)
	cList = str2list(cStr)

	oView.TextEdit1.setText("")     // Clear TextEdit1 Output Right window
        oView.TextEdit1.setstylesheet("color:black; background-color:#ffffff;") 

	See nl+"============" +nl
	for i = 1 to len(cList)
		Pos1 = substr(cList[i],"&lt;lang ring>")             //Start of code
		if Pos1 = 1	
			for j = i+1 to len(cList)
				Pos2 = substr(cList[j],"&lt;/lang>") // End of code
				if Pos2 = 1  exit 2  ok              // Exit
				oView.TextEdit1.append(cList[j])			
			next
                ok
	next
        oView.TextEdit1.moveCursor(1,0)  //set to start at top


        if i > len(cList)
           oView.TextEdit1.setstylesheet("color:red; background-color:#ffffff;")
           oView.TextEdit1.append("### NO RING CODE found for this Task")  // No Ring Code exists
        ok 
return


//===============================

func DisplayCode
oView {
	TaskName = LineEdit1.text()
	See "TaskName: "+ TaskName +nl
      }
	GetTaskCode(TaskName)
return

//-------------------------------------------

func ListWidgetClicked 	
oView {
	nbrOfItems = ListWidget1.count()
	curItemNbr = ListWidget1.currentrow()
	curValue   = ListWidget1.item(ListWidget1.currentrow()).text()
	
	See "NbrItems: "+ nbrOfItems +" curItemNbr: "+ curItemNbr +" curValue: "+ curValue +nl

        LineEdit1.setText(curValue)
	LineEdit2.setText(""+ curItemNbr)	
      }

      DisplayCode()
return		

//-------------------------------------------

func Run
oView {
	cString =  TextEdit1.toPlainText()
	See nl+nl+"TextRead:============ "+nl 
	See cString 
	See nl+ "TextEnd.:============"+ nl+nl
      }

      Write("Test.ring",cString)           // Create a xxx.ring file.gui.abstractitemview() 
      System ("ring.exe Test.ring")        // Execute the file

return
// =========================================
