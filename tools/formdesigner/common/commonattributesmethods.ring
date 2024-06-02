/*
**	Project : Form Designer 
**	File Purpose :  Common Attributes  and Methods
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class CommonAttributesMethods


	func CreateCommonAttributes
		AddAttribute(self,:cTextColor)
		AddAttribute(self,:cBackColor)
		AddAttribute(self,:cFontProperty)
		AddAttribute(self,:cCurrentParentName)
		cTextColor = ""
		cBackColor = ""
		cFontProperty = "Arial"
		cCurrentParentName = "win"

	func TextColor
		return cTextColor

	func setTextColor cValue
		cTextColor=cValue
		updatestylesheets()

	func BackColor
		return cBackColor

	func setBackColor cValue
		cBackColor=cValue
		updatestylesheets()

	func FontProperty
		return cFontProperty

	func setFontProperty cValue
		cFontProperty = cValue
		oFont = new qfont("",0,0,0)
		oFont.fromstring(cValue)
		setfont(oFont)
		oFont.delete()

	func CurrentParentName
		return cCurrentParentName

	func SetCurrentParentName cValue
		cCurrentParentName = cValue

	func updatestylesheets
		if cTextColor != NULL {
			setstylesheet("color:"+cTextColor+";background-color:"+cBackColor+";")
		else 
			setstylesheet("background-color:"+cBackColor+";")
		}

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)

	func AddObjectCommonProperties  oDesigner
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_NAME,False) 	# "Name"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_X,False) 		# "X"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_Y,False) 		# "Y"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_WIDTH,False) 	# "Width"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_HEIGHT,False) 	# "Height"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TEXTCOLOR,True) 	# "Text Color"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_BACKCOLOR,True) 	# "Back Color"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_FONT,True) 	# "Font"

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)

	func UpdateCommonProperties oDesigner,nRow,nCol,cValue
		if nCol = 1 {
			switch nRow {
				case 0	# Name
					oDesigner.oModel.SetObjectName(oDesigner,self,cValue)
					oDesigner.AddObjectsToCombo()
					# Because we may prevent name change (duplication)
						DisplayCommonProperties(oDesigner)
				case 1 	# x
					move(NumOrZero(cValue),y())
				case 2 	# y
					move(x(),NumOrZero(cValue))
				case 3	# width
					resize(NumOrZero(cValue),height())
				case 4 	# height
					resize(width(),NumOrZero(cValue))
				case 5	# Text color
					setTextColor(cValue)
				case 6	# back color
					setBackColor(cValue)
				case 7	# font
					setFontProperty(cValue)
			}
		}

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)

	func DisplayCommonProperties oDesigner
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Name
			oPropertiesTable.item(0,1).settext(
				oDesigner.oModel.GetObjectName(self))
		# Set the X
			oPropertiesTable.item(1,1).settext(""+x())
		# Set the Y
			oPropertiesTable.item(2,1).settext(""+y())
		# Set the Width
			oPropertiesTable.item(3,1).settext(""+width())
		# Set the Height
			oPropertiesTable.item(4,1).settext(""+height())
		# Set the Text Color
			oPropertiesTable.item(5,1).settext(textcolor())
		# Set the BackColor
			oPropertiesTable.item(6,1).settext(backcolor())
		# Set the Font
			oPropertiesTable.item(7,1).settext(fontproperty())

		oPropertiesTable.Blocksignals(False)

	func DialogButtonAction oDesigner,nRow
		CommonDialogButtonAction(oDesigner,nRow)

	func CommonDialogButtonAction oDesigner,nRow
		if nRow = 5 {	# Text Color
			oDesigner.oGeneral.cColorOperation = :TextColor
			oDesigner.oGeneral.SelectColor()
		elseif nRow = 6 	# Back Color
			oDesigner.oGeneral.cColorOperation = :BackColor
			oDesigner.oGeneral.SelectColor()
		elseif nRow = 7	# Font
			oDesigner.oGeneral.cFontOperation = :Font
			oDesigner.oGeneral.SelectFont()
		}

	func ApplyTextColor oDesigner,cColor 
		setTextColor(cColor)
		DisplayProperties(oDesigner)

	func ApplyBackColor oDesigner,cColor
		setBackColor(cColor)
		DisplayProperties(oDesigner)

	func ApplyFont oDesigner,cFont 
		setFontProperty(cFont)
		DisplayProperties(oDesigner)


	func  ObjectDataAsString oDesigner,nTabsCount
		return ObjectDataAsString2(oDesigner,nTabsCount)

	func ObjectDataAsString2 oDesigner,nTabsCount
		cTabs = std_copy(char(9),nTabsCount)
		cOutput = cTabs + " :x = #{f1} , : y = #{f2}  , " + nl
		cOutput += cTabs + " :width =  #{f3} , :height = #{f4} , " + nl
		cOutput += cTabs + ' :textcolor =  "#{f5}" , ' + nl
		cOutput += cTabs + ' :backcolor =  "#{f6}" , ' + nl
		cOutput += cTabs + ' :font =  "#{f7}" , ' + nl
		cOutput += cTabs + ' :parent =  "#{f8}"  '
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(""+x()))
		cOutput = substr(cOutput,"#{f2}",oDesigner.PrepareStringForFormFile(""+y()))
		cOutput = substr(cOutput,"#{f3}",oDesigner.PrepareStringForFormFile(""+width()))
		cOutput = substr(cOutput,"#{f4}",oDesigner.PrepareStringForFormFile(""+height()))
		cOutput = substr(cOutput,"#{f5}",oDesigner.PrepareStringForFormFile(textcolor()))
		cOutput = substr(cOutput,"#{f6}",oDesigner.PrepareStringForFormFile(backcolor()))
		cOutput = substr(cOutput,"#{f7}",oDesigner.PrepareStringForFormFile(fontproperty()))
		cOutput = substr(cOutput,"#{f8}",oDesigner.PrepareStringForFormFile(CurrentParentName()))
		return cOutput

	func GenerateCode oDesigner
		cOutput = char(9) + char(9) +
		oDesigner.oModel.GetObjectName(self) + " = " +
		'new #{f1}(#{f10}) {
			move(#{f2},#{f3})
			resize(#{f4},#{f5})
			setstylesheet("color:#{f6};background-color:#{f7};")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("#{f8}")
			setfont(oFont)
			oFont.delete()
#{f9}
		}' + nl
		cClass = substr(classname(self),"formdesigner_","")
		if cClass  = "qimage" or cClass = "qhyperlink"  {
			cClass = "qlabel"
		}
		# Index start from 1
		if  oDesigner.oModel.FormObject().IndexTypeValue() = 0 {
			# Remove the 'q' letter from the class name 
				cClass = substr(cClass,2)	
		}
		cOutput = substr(cOutput,"#{f1}",cClass)
		cOutput = substr(cOutput,"#{f2}",""+x())
		cOutput = substr(cOutput,"#{f3}",""+y())
		cOutput = substr(cOutput,"#{f4}",""+width())
		cOutput = substr(cOutput,"#{f5}",""+height())
		cOutput = substr(cOutput,"#{f6}",textcolor())
		cOutput = substr(cOutput,"#{f7}",backcolor())
		cOutput = substr(cOutput,"#{f8}",fontproperty())
		cOutput = substr(cOutput,"#{f9}",AddTabs(GenerateCustomCode(oDesigner),3))
		cOutput = substr(cOutput,"#{f10}",CurrentParentName())
		return cOutput

	func AddTabs cText,nCount
		cTabs = std_copy(char(9),nCount)
		cText = cTabs + cText
		cText = substr(cText,nl,nl+cTabs)
		return cText

	func GenerateCustomCode oDesigner
		return ""

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)

	func RestoreCommonProperties oDesigner,item
		itemdata = item[:data]
		blocksignals(true)
		setMouseTracking(True)
		setFocusPolicy(0)
		oDesigner.oModel.SetObjectName(oDesigner,self,item[:name])
		move(itemdata[:x],itemdata[:y])
		resize(itemdata[:width],itemdata[:height])
		setTextColor(itemdata[:textcolor])
		setBackColor(itemdata[:backcolor])
		if itemdata[:font] = NULL { itemdata[:font] = "Arial" }
		setFontProperty(itemdata[:font])
		setCurrentParentName(itemdata[:parent])
		refreshCorners(oDesigner.oModel.ActiveObject())
		blocksignals(false)

	func PrepareEvent cCode,cEvent,cReplace
		# Remove " " around event if we uses Code
		cEvent = std_lower(cEvent)
		if substr(cEvent,"(") > 0 {
			cCode = substr(cCode,char(34)+cReplace+char(34),cReplace)
		else
			if cEvent != "" {
				cCode = substr(cCode,char(34)+cReplace+char(34),"Method(:"+cReplace+")")
			}
		}
		return cCode

