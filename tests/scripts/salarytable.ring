load "tests\weblib.ring"
import System.Web

website = "ring.index"
aPageVars = []
aPageVars["page"] = "16"
aPageVars["part"] = "1"

new Salary { routing() } 

Class Salary

	cServer = "localhost"
	cUserName = "root"
	cPassword = "root"
	cDatabase = "mahdb"
	cTitle = "Salary Table"
	cBack = "back"
	cTableName = "salary"
	aColumnsTitles = ["ID","Name","Salary"]
	cOptions = "Options"
	cSearch = "Search"
	comboitems = ["Select Option...","Edit","Delete"]
	cAddRecord = "Add Record"
	cEditRecord = "Edit Record"
	cRecordDeleted = "Record Deleted!"
	aMovePages = ["First","Prev","Next","Last"]
	nRecordsPerPage = 5
	nRecordsCount = 0
	nPagesCount = 0
	nActivePage = 0
	aQueryResult = []

	con = mysql_init()
	mysql_connect(con, cServer, cUserName, cPassWord,cDatabase)

	func Routing
		switch aPageVars["operation"]
		on NULL showtable()
		on 1    addrecord()
		on 2    saverecord()
		on 3    deleterecord()
		on 4    editrecord()
		on 5	updaterecord()
		off		

	func AddRecord

		FormView(cAddRecord,2,false,"","")

	func SaveRecord

		mysql_query(con, "insert into " + cTableName + "(name,salary) values ('" + 
				 aPageVars["name"] + "'," + aPageVars["salary"] + ")" )
		New Page
		{
			script(scriptredirection( website + "?page=16&part=last" ))
		}

	func EditRecord

		mysql_query(con, "select * from " + cTableName + " where id = " + aPageVars["recid"] )
		aQueryResult = mysql_result(con)
		FormView(cEditRecord,5,true,aQueryResult[1][2],aQueryResult[1][3])

	func UpdateRecord

		mysql_query(con, "update " + cTableName + " set name='"+ aPageVars["name"] + "' , salary = " + 
					aPageVars["salary"] + " where id = " + aPageVars["recid"] )
		New Page {  script(scriptredirection( website + "?page=16&part=1" ))  }

	func DeleteRecord

		mysql_query(con, "delete from " + cTableName + " where id = " + aPageVars["recid"] )
		New Page
		{
			text(cRecordDeleted)
		}

	func ShowTable

		mysql_query(con, "SELECT count(*) FROM " + cTableName +
				 " where name like '" + aPageVars["searchname"] + "%'")

		nRecordsCount = mysql_result(con)[1][1]

		nPagesCount = ceil(nRecordsCount / nRecordsPerPage)

		if aPageVars["part"] = "last"
			aPageVars["part"] = string(nPagesCount)
		ok

		nActivePage = number(aPageVars["part"])

		if ( nActivePage < 1 or nActivePage > nPagesCount ) and nRecordsCount > 0
			ErrorMsg("The page number is not correct")
			return
		ok

		nStart = (nActivePage-1)*nRecordsPerPage

		if aPageVars["searchname"] = NULL
			mysql_query(con, "SELECT * FROM "+ cTableName+" limit " + nStart + "," + nRecordsPerPage)
		else
			mysql_query(con, "SELECT * FROM "+ cTableName+" where name like '" + aPageVars["searchname"] + "%'" +
			" limit " + nStart + "," + nRecordsPerPage)
		ok

		aQueryResult = mysql_result(con)

		GridView(self)

	func GridView  me

		# we get self object in local variable called Me 
		# because using New Page { } will hide object attributes

		#me = 1
		#good

		New Page
		{

/*			
			divstart( [ :style = stylesize("100%","4%") + styletextcenter() + stylegradient(55)])
				text( Me.cTitle )
			divend()

			divstart( [ :style = stylesize("100%","5%") + stylegradient(4) ] )

				divstart( [ :style = stylesize("100%","5%") + stylegradient(13) ] )

					link([ :url = website, :title = Me.cBack] )
				
				divend()

			divend()

			divstart( [ :style = stylesize("100%","10%") + stylegradient(11) ] )

				divstart([ :style= stylewidth("30%") + styleHorizontalCenter() ])
					newline()
					formstart(website)
						hidden("page",16)
						hidden("part",1)
						divstart([ :style = stylefloatleft() + stylewidth("15%") ])
							text("Name : ")
						divend()
						divstart([ :style = stylefloatleft() + stylewidth("60%") ])
							textbox([ :name = "searchname" , 
							          :value = aPageVars["searchname"] ,
								  :style = stylewidth("100%") ])
						divend()
						divstart([ :style = stylefloatleft() + stylemarginleft("2%") + stylewidth("15%") ])
							submit(Me.cSearch)
						divend()
					formend()				
				divend()
			divend()

			divstart( [ :style = stylesize("100%","100%") + stylegradient(4) ] )

			divstart( [ :style = stylefloatleft() + stylesizefull() + stylemargintop("2%") ] )

				divstart( [ :style = stylesize("50%","50%")  + styleHorizontalCenter() ])
		
					style(styletable() + styletablerows("t01"))

*/
					
					if Me.nRecordsCount > 0

/*			
					tablestart([:id = :t01 , :style="width:100%"])


		
						rowstart([ :style = stylegradient(57) ]) 
							for x in Me.aColumnsTitles headerstart([]) text(x) headerend() next 
							headerstart([]) text(Me.cOptions) headerend()
						rowend() 
*/
						aSize = [100,200,100]



						nID = 1

						for x in Me.aQueryResult

							rowstart([ :id = "gridrow" + nID ])
								for x2=1 to len( x )
									cellstart([ :style = stylewidth(""+aSize[x2]+"px") ]) 
										text(x[x2]) 
									cellend() 
								next
								cellstart([]) 						
									combobox([ :id = "options"+nID,
										   :name = "options",
										   :items = Me.comboitems,
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

					ok

					divstart([ :style = stylegradient(5)  ])
						if Me.nActivePage > 1
							#first
							link([ :url = website+"?page=16&part=1"+
							"&searchname="+aPageVars["searchname"], :title = Me.aMovePages[1] ])
							#prev
							link([ :url = website+"?page=16&part="+(Me.nActivePage-1)+
							"&searchname="+aPageVars["searchname"], :title = Me.aMovePages[2] ])
						else
							text(" " + Me.aMovePages[1] + " ")
							text(" " + Me.aMovePages[2] + " ")
						ok
						if Me.nActivePage < Me.nPagesCount
							#next
							link([ :url = website+"?page=16&part="+(Me.nActivePage+1)+
								"&searchname="+aPageVars["searchname"], :title = Me.aMovePages[3] ])
							#last
							link([ :url = website+"?page=16&part=last"+
								"&searchname="+aPageVars["searchname"], :title = Me.aMovePages[4] ])

						else
							text(" " + Me.aMovePages[3] + " ")
							text(" " + Me.aMovePages[4] + " ")

						ok

						divstart([ :style =  stylefloatright() ])
						text(" Records Count ( " + Me.nRecordsCount + " ) : " +
						     "Page " + Me.nActivePage + " of " + Me.nPagesCount )
						divend()
					divend()

					divstart([ :id = "result" , :style = stylewidth("100%") + styleheight("10%") ]) 
					divend()
					
					divstart([ :style = stylewidth("100%") + styleheight("10%") ])
						button([ :value = Me.cAddRecord, :onclick = "myadd()" , :style = stylegradient(20) ])
					divend()

					divstart([ :id = "mysubpage" , :style = stylewidth("100%")+stylemargintop("2%")+styleheight("70%") ]) 
					divend()					
				divend()
			divend()
			divend()

			Script( scriptuseajax() + 
				scriptfuncajax("myadd",website+"?page=16&operation=1","mysubpage") + 
				scriptfuncclean("myclean","result") +
				scriptfuncselect("selectrecord",Me.comboitems,
						 "mysubpage","result","gridrow","myclean",3000,
						 website+"?page=16&operation=4&recid=",
						 website+"?page=16&operation=3&recid=") )	

		}

	func FormView cTitle,nOperation,lrecid,v1,v2

		Me = self

		New Page
		{
			divstart([ :style = stylesizefull() + stylegradient(55) ])				

			divstart([ :style = styletextcenter() + stylewidth("100%") + styleheight("30px") + stylegradient(56) ])
				text(" " + Me.cTitle + " - " + cTitle)
			divend()

				divstart([:style=StyleFloatLeft()+StyleWidth("10%")+stylemarginleft("10%") ])
					newline()
					text( Me.aColumnsTitles[2] + " : " )  		newline() newline()
					text( Me.aColumnsTitles[3] + " : " ) 		newline() newline()
				divend()

				formpost(website)

					hidden("page",16)
					hidden("operation",nOperation)

					if lrecid = true
						hidden("recid",aPageVars["recid"])
					ok

					divstart([ :style = styleFloatLeft()+StyleWidth("70%") ])
						newline()
						textbox([ :name = "Name" , :value = v1 , :style = stylewidth("100%") ]) 
						newline() newline()
						textbox([ :name = "Salary" , :value = v2 , :style = stylewidth("50%") ]) 	
						newline() newline()
						submit("Save")
					divend()

				formend()

			divend()
		}
