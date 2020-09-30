/*
**	Project : Form Designer 
**	File Purpose :  Menubar Designer 
**	Date : 2017.04.27
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "menubardesignerView.ring"

if IsMainSourceFile() { 

	new qApp {
		StyleFusion()
		openWindow(:menubardesignerController)
		exec()
	}
}

class MenubarDesignerController from windowsControllerParent

	oView = new menubardesignerView  {
		win.setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint )
		win.setwindowmodality(2)
	}
	oRoot = new qtreewidgetitem()
	oRoot.settext(0,"The Menubar Tree")
	oView.TreeWidget1.addtoplevelitem(oRoot)

	# Object-Text-Image-ShortCut-Action
		aTreeItems = [[oRoot.pObject,"The Menubar","","",""]]

	func NewAction
		oParent = oView.TreeWidget1.currentitem()
		AddChild(oParent,"New Item","","","")

	func AddChild oParent,cText,cImage,cShortcut,cAction
		oItem = new qTreeWidgetItem()
		oItem.setText(0,cText)
		oParent.AddChild(oItem)
		aTreeItems + [oItem.pObject,cText,cImage,cShortcut,cAction]
		return oItem

	func IsRoot
		oItem = oView.TreeWidget1.currentitem()
		if ptrcmp(oItem.pObject ,oRoot.pObject) {
			return True
		}
		return False

	func DeleteAction
		oItem = oView.TreeWidget1.currentitem()
		if not IsRoot() {
			DeleteItemFromList(oItem)
			oItem.parent().takechild(oItem.parent().indexofchild(oItem))
		}

	func DeleteItemFromList oItem
		if oItem.ChildCount() > 0 {
			nCount = oItem.ChildCount()
			for x=nCount to 1 step -1 {
				DeleteItemFromList(oItem.child(x-1))
			}
		}
		del(aTreeItems,find(aTreeItems,oItem.pObject,1) )

	func CleanTextBoxes
		oView.	ItemText.setText("")
		oView.ItemImage.setText("")
		oView.ItemShortcut.setText("")
		oView.ItemAction.setText("")

	func ItemClickAction
		oItem = oView.TreeWidget1.currentitem()
		if IsRoot() {
			CleanTextBoxes()
			return
		}
		nPos = find(aTreeItems,oItem.pObject,1)
		oView.	ItemText.setText(aTreeItems[nPos][2])
		oView.ItemImage.setText(aTreeItems[nPos][3])
		oView.ItemShortcut.setText(aTreeItems[nPos][4])
		oView.ItemAction.setText(aTreeItems[nPos][5])

	func ItemTextChangeAction
		oItem = oView.TreeWidget1.currentitem()
		nPos = find(aTreeItems,oItem.pObject,1)
		cText = oView.ItemText.Text()
		if IsRoot() {
			CleanTextBoxes()
			return
		}
		aTreeItems[nPos][2] = cText
		oItem.setText(0,cText)

	func ItemImageChangeAction
		oItem = oView.TreeWidget1.currentitem()
		nPos = find(aTreeItems,oItem.pObject,1)
		cText = oView.ItemImage.Text()
		if IsRoot() {
			CleanTextBoxes()
			return
		}
		aTreeItems[nPos][3] = cText

	func ItemShortcutChangeAction
		oItem = oView.TreeWidget1.currentitem()
		nPos = find(aTreeItems,oItem.pObject,1)
		cText = oView.ItemShortcut.Text()
		if IsRoot() {
			CleanTextBoxes()
			return
		}
		aTreeItems[nPos][4] = cText


	func ItemActionChangeAction
		oItem = oView.TreeWidget1.currentitem()
		nPos = find(aTreeItems,oItem.pObject,1)
		cText = oView.ItemAction.Text()
		if IsRoot() {
			CleanTextBoxes()
			return
		}
		aTreeItems[nPos][5] = cText

	func CloseAction
		if isParent() {
			parent().oModel.FormObject().setMenubarValue(Tree2String())
		}
		oView.Close()

	func Tree2String
		cString = "aMenuData = " + ItemAsString(oRoot)
		return cString

	func ItemAsString oItem
		nPos = find(aTreeItems,oItem.pObject,1)
		cString = "[ :Text = '#{f1}' , :Image = '#{f2}' ,
			         :Shortcut = '#{f3}' , :Action = '#{f4}' ,
				:Children = [#{f5}] ]"
		cString = substr(cString,"#{f1}",aTreeItems[nPos][2])
		cString = substr(cString,"#{f2}",aTreeItems[nPos][3])
		cString = substr(cString,"#{f3}",aTreeItems[nPos][4])
		cString = substr(cString,"#{f4}",aTreeItems[nPos][5])
		cChildren = ""
		for x = 1 to oItem.ChildCount() {
			if x = 1 {
				cChildren += ItemAsString(oItem.Child(x-1))
			else
				cChildren += "," + ItemAsString(oItem.Child(x-1))
			}
		}
		cString = substr(cString,"#{f5}",cChildren)
		return cString

	func String2Tree cString
		cString = Trim(cString)
		if cString = NULL { return }
		eval(cString)
		AddChildren(oRoot,aMenuData[:Children])

	func AddChildren oParent,aChildren
		for Item in aChildren {
			cText = Item[:Text]
			cImage = Item[:Image]
			cShortCut = Item[:ShortCut]
			cAction = Item[:Action]
			oItem = AddChild(oParent,cText,cImage,cShortcut,cAction)
			AddChildren(oItem,Item[:Children])
		}

	func SetMenubar cMenu
		String2Tree(cMenu)
