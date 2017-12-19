#!ring -cgi

Load "weblib.ring"
Load "datalib.ring"

website = "mysalarytable.ring"

Import System.Web

New salaryController { Routing() }

Class SalaryModel from ModelBase
Class SalaryController From ControllerBase
Class SalaryView From ViewBase
	oLanguage = new SalaryLanguageEnglish	
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
