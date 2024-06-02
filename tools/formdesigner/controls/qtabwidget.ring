/*
**	Project : Form Designer 
**	File Purpose :  QTabWidget Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QTabWidget from QTabWidget

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	nPagesCount = 0
	cPagesTitles = ""

	aTabs = []

	func PagesCountValue
		return ""+nPagesCount

	func SetPagesCountValue cValue
		nPagesCount = NumOrZero(cValue)
		if nPagesCount > 0 {
			for x = len(aTabs) + 1 to nPagesCount {
				aTabs + [new qWidget(),"Page " + x]
				inserttab(len(aTabs)-1,aTabs[len(aTabs)][1],aTabs[len(aTabs)][2])
			}
			if nPagesCount < len(aTabs) {	# Delete Tabs
				nCount = len(aTabs)-nPagesCount
				for x = 1  to nCount {
					removeTab(len(aTabs)-1)
					del(aTabs,len(aTabs))
				}
			}
		}
		if nPagesCount = 0 and len(aTabs) > 0 {
			nCount = len(aTabs)
			for x = nCount to 1 step -1 {
				removeTab(x-1)
			}
			aTabs = []
		}

	func PagesTitlesValue
		return cPagesTitles

	func SetPagesTitlesValue cValue
		cPagesTitles = cValue
		aItems = split(cPagesTitles,",")
		for x = 1 to len(aItems) {
			if x <= len(aTabs) {
				aTabs[x][2] = aItems[x]
				setTabText(x-1,aItems[x])
			}
		}

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_PAGESCOUNT,False)			 # "Pages Count"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_PAGESTITLESSCOMMA,False)		 # "Pages Titles (S: Comma)"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Pages Count Value
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(PagesCountValue())
		# Set the Pages Titles Value
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(PagesTitlesValue())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		switch nRow {
			case C_AFTERCOMMON
				setPagesCountValue(cValue)
			case C_AFTERCOMMON + 1
				setPagesTitlesValue(cValue)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :PagesCount =  "' + oDesigner.PrepareStringForFormFile(PagesCountValue()) + '"'
		cOutput += "," + nl + cTabs + ' :PagesTitles =  "' + oDesigner.PrepareStringForFormFile(PagesTitlesValue()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		for x = 1 to len(aTabs) {
			cOutput += '	#{f1}page#{f2} = new qwidget()' + nl +
                       	'inserttab(#{f3},#{f1}page#{f2},"#{f4}")'
			if not x = len(aTabs) {
				cOutput += nl
			}
			cOutput  = substr(cOutput,"#{f1}",oDesigner.oModel.GetObjectName(self))
			cOutput  = substr(cOutput,"#{f2}",""+x)
			cOutput  = substr(cOutput,"#{f3}",""+(x-1))
			cOutput  = substr(cOutput,"#{f4}",oDesigner.PrepareStringForFormFile(aTabs[x][2]))
		}
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setPagesCountValue(itemdata[:PagesCount])
		setPagesTitlesValue(itemdata[:PagesTitles])

