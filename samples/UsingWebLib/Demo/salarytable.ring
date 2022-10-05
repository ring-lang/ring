Import System.Web

Class SalaryModel from ModelBase
	cSearchColumn = "Name"

Class SalaryController From ControllerBase
	cMainURL = website+"?page=16&"
	aColumnsNames = ["id","name","salary"]

	Func showtable
		nTime = clock()
		super.showtable()
		nTime = clock() - nTime
		see "Time : " + nTime + "ms"

Class SalaryView From ViewBase

	oLanguage = new SalaryLanguageEnglish
	
	Func HiddenVars oPage
		oPage.hidden("page",16)
		
	Func AddFuncScript oPage,oController
		return 	oPage.scriptfuncajax("myadd",oController.cMainURL+oController.cOperation+"=add","mysubpage")

	Func FormViewContent oController,oTranslation,oPage
		return [
			[ oTranslation.aColumnsTitles[2], "textbox", "name", oController.oModel.Name, oPage.stylewidth("100%")    ],
			[ oTranslation.aColumnsTitles[3], "textbox", "salary", oController.oModel.Salary, oPage.stylewidth("50%") ]
		       ]

Class SalaryLanguageEnglish
	cTitle = "Salary Table"
	cBack = "back"
	aColumnsTitles = ["ID","Name","Salary"]
	cOptions = "Options"
	cSearch = "Search"
	cSearchColumn = "Name"
	comboitems = ["Select Option...","Edit","Delete"]
	cAddRecord = "Add Record"
	cEditRecord = "Edit Record"
	cRecordDeleted = "Record Deleted!"
	aMovePages = ["First","Prev","Next","Last"]
	cPage = "Page"
	cOf = "of"
	cRecordsCount = "Records Count"
	cSave = "Save"
	temp = new page
	cTextAlign = temp.StyleTextRight()
	cNoRecords = "No records!"
	
Class SalaryLanguageArabic
	cTitle = "جدول الرواتب"
	cBack = "عودة"
	aColumnsTitles = ["الكود","الإسم","الراتب"]
	cOptions = "خيارات"
	cSearch = "بحث"
	cSearchColumn = "الإسم"
	comboitems = ["فضلا إختار...","تعديل","حذف"]
	cAddRecord = "إضافة سجل"
	cEditRecord = "تعديل سجل"
	cRecordDeleted = "تم حذف السجل!"
	aMovePages = ["بداية","السابق","التالى","نهاية"]
	cPage = "الصفحة"
	cOf = "من"
	cRecordsCount = "عدد السجلات"
	cSave = "حفظ"
	temp = new page
	cTextAlign = temp.StyleTextLeft()
	cNoRecords = "لايوجد سجلات"
