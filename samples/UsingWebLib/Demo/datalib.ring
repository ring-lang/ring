Load "mysqllib.ring"

Import System.Web

Class Database

	cServer = "localhost"
	cUserName = "root"
	cPassword = "root"
	cDatabase = "mahdb"

	Func Connect

		con = mysql_init() 
		if not mysql_connect(con, cServer, cUserName, cPassWord,cDatabase)
			raise("Error (DataLib-1) : Can't connect to the database server!")
		ok

	Func Disconnect

		mysql_close(con)

	Func Query cQuery

		mysql_query(con,cQuery)

	Func QueryResult

		return mysql_result(con)

	Func QueryResultWithColumns
		# return columns names + query result
		return mysql_result2(con)

	Func QueryValue
		aResult = mysql_result(con)
		if islist(aResult) and len(aResult) >= 1
			aResult = aResult[1]
			if len(aResult) >= 1
				return aResult[1]
			ok
		ok
		return 0

	Func EscapeString x
		if isstring(x)
			return MySQL_Escape_String(con,x)
		else
			return MySQL_Escape_String(con,string(x))
		ok

	Private
		con = NULL

Class ModelBase from Database

	cTableName = ""
	cSearchColumn = "name"
	aColumns = []
	aQueryResult = []
	ID = 0

	# set table name from class name
	classname = lower(classname(self))
	if right(classname,5) = :model
		cTablename = left(classname,len(classname)-5)
	ok

	Func Insert 

		cValues = ""
		for x in aColumns
			cValues += "'" + EscapeString(aPageVars[x]) + "',"
		Next
		cValues = left(cValues,len(cValues)-1)	# remove last comma		
		cColumns = ""
		for x in aColumns
			cColumns += x + ","
		next
		cColumns = left(cColumns,len(cColumns)-1)  	
		query("insert into " + cTableName + "("+cColumns+") values (" + 
				 cValues + ")" )

	Func Update nID

		cStr = ""
		for x in aColumns
			cStr += x + " = '" + EscapeString(aPageVars[x]) + "' , " # the space after comma is necessary
		Next
		cStr = left(cStr,len(cStr)-2)  		
		query("update " + cTableName + " set " + cStr + " where id = " + nID )

	Func UpdateColumn cColumn,cValue
		query("update " + cTableName + " set " + cColumn + " = '" + EscapeString(cValue) + "' where id = " + self.ID )


	Func Count cValue

		query("SELECT count(*) FROM " + cTableName +
				 " where "+cSearchColumn+" like '" + EscapeString(cValue) + "%'")
		return queryValue()

	Func Read nStart,nRecordsPerPage

		query("SELECT * FROM "+ cTableName+" limit " + EscapeString(nStart) + "," + EscapeString(nRecordsPerPage) )
		aQueryResult = queryResult()

	Func Search cValue,nStart,nRecordsPerPage

		query("SELECT * FROM "+ cTableName+" where "+cSearchColumn+" like '" + EscapeString(cValue) + "%'" +
			" limit " + EscapeString(nStart) + "," + EscapeString(nRecordsPerPage) )
		aQueryResult = queryResult()

	Func Find nID

		query("select * from " + cTableName + " where id = " + EscapeString(nID) )
		aResult = queryResult()[1]
		# move the result from the array to the object attributes
		ID = nID
		cCode = ""
		for x = 2 to len(aResult)
			cCode += aColumns[x-1] + " = hex2str('" + str2hex(aResult[x]) + "')" + nl
		next
		eval(cCode)

	Func FindWith cColumn,cValue

		query("select * from " + cTableName + " where "+cColumn+" = '" + EscapeString(cValue) + "'" )
		aResult = queryResult()
		if len(aResult) > 0
			aResult = aResult[1]
		else
			return 0
		ok
		# move the result from the array to the object attributes
		ID = aResult[1]
		cCode = ""
		for x = 2 to len(aResult)
			cCode += aColumns[x-1] + " = hex2str('" + str2hex(aResult[x]) + "')" + nl
		next
		eval(cCode)
		return 1

	Func Delete ID

		query("delete from " + cTableName + " where id = " + EscapeString(ID) )

	Func Clear

		cCode = ""
		for x in aColumns
			cCode += x + ' = ""' + nl
		next
		eval(cCode)

	Func LoadModel

		# create the columns array
		query("SELECT * FROM "+ cTableName + " limit 0,1")
		aQueryResult = QueryResultWithColumns()[1]
		for x = 2 to len(aQueryResult)
			aColumns + lower(trim(aQueryResult[x]))
		next

		# create attribute for each column
		for x in aColumns
			addattribute(self,x)
		next

	Func Connect

		Super.Connect()
		if nLoadModel = 0
			nLoadModel = 1
			LoadModel()
		ok

	private

		nLoadModel = 0


Class ControllerBase
	
	nRecordsPerPage = 5
	nRecordsCount = 0
	nPagesCount = 0
	nActivePage = 0

	# Dynamic creation of oView = new tablenameView and oModel = new tablename.Model
	classname = lower(classname(self))
	if right(classname,10)  = :controller
		tablename = left(classname,len(classname)-10)
		cCode = "oView = new " + tablename+"View" + nl
		cCode += "oModel = new " + tablename+"Model" + nl
		eval(cCode)
		oModel.connect()
	ok

	cSearchName = "searchname"
	cPart = "part"
	cPageError = "The page number is not correct"
	cLast = "last"
	cOperation = "operation"
	cRecID = "recid"

	aColumnsNames = ["id"]
	for t in oModel.aColumns
		aColumnsNames + t
	next

	cMainURL = website + "?"

	func Routing

		switch  	aPageVars[cOperation]
		on NULL 	showtable()
		on :add    	addrecord()
		on :save    	saverecord()
		on :delete	deleterecord()
		on :edit	editrecord()
		on :update	updaterecord()
		off

	func ShowTable

		nRecordsCount = oModel.Count( aPageVars[cSearchName] )

		nPagesCount = ceil(nRecordsCount / nRecordsPerPage)

		if aPageVars[cPart] = cLast
			aPageVars[cPart] = string(nPagesCount)
		ok

		nActivePage = number(aPageVars[cPart])
		if nActivePage = 0 nActivePage = 1 ok		

		if ( nActivePage > nPagesCount ) and nRecordsCount > 0
			ErrorMsg(cPageError)
			return
		ok

		nStart = (nActivePage-1)*nRecordsPerPage

		if aPageVars[cSearchName] = NULL
			oModel.Read( nStart,nRecordsPerPage )
		else
			oModel.Search( aPageVars[cSearchName],nStart,nRecordsPerPage )
		ok

		oView.GridView(self)

	func AddRecord

		oModel.clear()
		oView.FormViewAdd(Self,:save,false) # false mean don't include record id

	func SaveRecord

		oModel.Insert()
		oView.SaveView(self)

	func EditRecord

		oModel.Find( aPageVars[cRecID] )
		oView.FormViewEdit(Self,:update,true) # true mean include record id

	func UpdateRecord
		oModel.update( aPageVars[cRecID] )
		oView.UpdateView(self)

	func DeleteRecord

		oModel.Delete( aPageVars[cRecID] )
		oView.DeleteView()

	func braceend

		oModel.Disconnect()

Class ViewBase

	Func HiddenVars	
		# No hidden variables

	Func FormViewAdd oController,cOperation,lrecid

		FormView(oController,oLanguage.cAddRecord,cOperation,lrecid)

	Func FormViewEdit oController,cOperation,lrecid

		FormView(oController,oLanguage.cEditRecord,cOperation,lrecid)

	Func DeleteView

		oTranslation = oLanguage
		New Page
		{
			text(oTranslation.cRecordDeleted)
		}

	Func SaveView oController 

		New Page
		{
			script(scriptredirection( oController.cMainURL+oController.cPart+"="+oController.cLast ))
		}

	Func UpdateView oController

		New Page 
		{  
			script(scriptredirection( oController.cMainURL+oController.cPart+"=" + aPageVars["ActivePage"] ))  
		}

	func GridView oController

		# we get self object in local variable called oTranslation 
		# because using New Page { } will hide object attributes

		oTranslation = oLanguage
		oThisView = self

		New Page
		{

			Cookie("ActivePage",oController.nActivePage)

			divstart( [ :style = stylesize("100%","4%") + styletextcenter() + stylegradient(55)])
				text( oTranslation.cTitle )
			divend()

			divstart( [ :style = stylesize("100%","5%") + stylegradient(4) ] )
				divstart( [ :style = stylesize("100%","5%") + stylegradient(13) ] )
					link([ :url = website, :title = oTranslation.cBack] )				
				divend()
			divend()

			divstart( [ :style = stylesize("100%","10%") + stylegradient(11) ] )
				divstart([ :style= stylewidth("30%") + styleHorizontalCenter() ])
					newline()
					formstart(website)

						oThisView.HiddenVars(self)

						hidden(oController.cPart,1)
						tablestart([ :style = styletablenoborder() ])
						rowstart([])
						cellstart([ :style = styletablenoborder() + stylewidth("10%") ])
							text(oTranslation.aColumnsTitles[2]+" : ")
						cellend()
						cellstart([ :style = styletablenoborder() + stylewidth("70%") ])
							textbox([ :name = oController.cSearchName , 
							          :value = aPageVars[oController.cSearchName] ,
								  :style = stylewidth("100%") ])
						cellend()
						cellstart([ :style = styletablenoborder() + stylewidth("20%")  ])
							submit([ :value = oTranslation.cSearch , :style = stylewidth("100%")] )
						cellend()
						rowend()
						tableend()
					formend()				
				divend()
			divend()

			divstart( [ :style = stylesize("100%","100%") + stylegradient(4) ] )
			divstart( [ :style = stylefloatleft() + stylesizefull() + stylemargintop("2%") ] )
				divstart( [ :style = stylesize("50%","50%")  + styleHorizontalCenter() ])		
					style(styletable() + styletablerows("t01"))	
				
					if oController.nRecordsCount > 0	
		
					tablestart([:id = :t01 , :style="width:100%"])		
						rowstart([ :style = stylegradient(57) ]) 
							for x in oTranslation.aColumnsTitles headerstart([]) text(x) headerend() next 
							headerstart([]) text(oTranslation.cOptions) headerend()
						rowend() 
						aSize = [100,200,100]
						nID = 1
						for x in oController.oModel.aQueryResult
							rowstart([ :id = "gridrow" + nID ])
								nSizeIndex = 0
								for x2=1 to len(x)
									if x2 > 1 and x2 <= len(oController.oModel.aColumns) + 1
										if find(oController.aColumnsNames,oController.oModel.aColumns[x2-1]) = 0
											loop
										ok
									ok
									nSizeIndex++
									cellstart([ :style = stylewidth(""+aSize[nSizeIndex]+"px") ]) 
										text(x[x2]) 
									cellend() 
								next
								cellstart([]) 						
									combobox([ :id = "options"+nID,
										   :name = "options",
										   :items = oTranslation.comboitems,
										   :onchange = "selectrecord(this.id"+","+x[1]+","+nID+")",
										   :style = stylewidth("100%") + stylecolor("black") +
											    stylebackcolor("white")+
										            stylefontsize("14px") ,
										   :value = "Select Option..." ] )						
									nID++
								cellend()
							rowend()
						next
					tableend()					

					divstart([ :style = stylegradient(5)  ])
						tablestart([ :style = styletablenoborder() + stylewidth("100%") ])
						rowstart([])
						cellstart([ :style = styletablenoborder() + stylewidth("50%") ])
						if oController.nActivePage > 1
							#first
							link([ :url = oController.cMainURL+oController.cPart+"=1"+
							"&searchname="+aPageVars["searchname"], :title = oTranslation.aMovePages[1] ])
							#prev
							link([ :url = oController.cMainURL+oController.cPart+"="+(oController.nActivePage-1)+
							"&searchname="+aPageVars["searchname"], :title = oTranslation.aMovePages[2] ])
						else
							text(" " + oTranslation.aMovePages[1] + " ")
							text(" " + oTranslation.aMovePages[2] + " ")
						ok
						if oController.nActivePage < oController.nPagesCount
							#next
							link([ :url = oController.cMainURL+oController.cPart+"="+(oController.nActivePage+1)+
								"&searchname="+aPageVars["searchname"], :title = oTranslation.aMovePages[3] ])
							#last
							link([ :url = oController.cMainURL+oController.cPart+"="+oController.cLast+""+
								"&searchname="+aPageVars["searchname"], :title = oTranslation.aMovePages[4] ])

						else
							text(" " + oTranslation.aMovePages[3] + " ")
							text(" " + oTranslation.aMovePages[4] + " ")

						ok
						cellend()
						cellstart([  :style = styletablenoborder() + oTranslation.cTextAlign ])					
						text(" "+oTranslation.cRecordsCount+" ( " + oController.nRecordsCount + " ) : " +
						     oTranslation.cPage + " " + oController.nActivePage + " "+ oTranslation.cOf +" " + oController.nPagesCount )
						
						cellend()
						rowend()
						tableend()
					divend()
					else
						divstart([ :style =  stylewidth("100%")+styleheight("10%") + stylecolor("blue") +
									stylebackcolor("white") + styletextcenter() ])	
							text(oTranslation.cNoRecords)
						divend()
					ok

					divstart([ :id = "result" , :style = stylewidth("100%") + styleheight("10%") ])
					divend()
					
					divstart([ :style = stylewidth("100%") + styleheight("10%") ])
						button([ :value = oTranslation.cAddRecord, :onclick = "myadd()" , :style = stylegradient(20) ])
					divend()

					divstart([ :id = "mysubpage" , :style = stylewidth("100%")+stylemargintop("2%")+styleheight("70%") ]) 
					divend()					
				divend()
			divend()
			divend()

			Script( oThisView.AddFuncScript(self,oController) + 
				scriptfuncclean("myclean","result") +
				scriptfuncselect("selectrecord",oTranslation.comboitems,
						 "mysubpage","result","gridrow","myclean",3000,
						 oController.cMainURL+oController.cOperation+"=edit&"+oController.cRecID+"=",
						 oController.cMainURL+oController.cOperation+"=delete&"+oController.cRecID+"=") )	

		}



	func FormView oController,cTitle,cOperation,lrecid

		oTranslation = oLanguage
		oThisView = self

		oPage = New Page

		aContent = FormViewContent(oController,oTranslation,oPage)

		oPage {
			divstart([ :id = 'div1' , :style = stylesizefull() + stylegradient(55) ])				

			divstart([ :style = styletextcenter() + stylewidth("100%") + styleheight("30px") + stylegradient(56) ])
				text(" " + oTranslation.cTitle + " - " + cTitle)
				button([ :value = "x" , :style = stylefloatright() , :onclick = "$('#div1').remove();" ])
			divend()

			divstart([:style=StyleFloatLeft()+StyleWidth("80%")+stylemarginleft("10%") ])
					newline()
					formpost(website)

						oThisView.HiddenVars(self)

						hidden(oController.cOperation,cOperation)

						if lrecid = true
							hidden(oController.cRecID,aPageVars[oController.cRecID])
						ok

						tablestart([ :style = StyleTableNoBorder() + stylesize("100%","70%")  ])
							for x in aContent
								rowstart([])
									cellstart([ :style = StyleTableNoBorder() + stylewidth("1%")  ])
										text( x[1] + " : " )   		 
									cellend()
									cellstart([ :style = StyleTableNoBorder()   ])  				
										if x[2] = "textbox"
											textbox([ :name = x[3] , :value = x[4] , :style = x[5] ]) 
										ok
									cellend()								 
								rowend()
							next
							rowstart([ :Style = stylewidth("10%") ])
								cellstart([ :style = styletablenoborder() ])
								cellend()
								cellstart([ :style = StyleTableNoBorder() ])
									submit([ :value = oTranslation.cSave , :style = stylewidth("15%")])
								cellend()
							rowend()
						tableend()			
					formend()
				divend()
			divend()
		}

