/*
**
** Get Data (Use the Web API)
**
*/

func getDataFromTheInternet

	btnGetData.setEnabled(False)

	aData       = []
	lDisplayMap = True 

	useWebAPI(cAttendancePercentageURL,:getAttendancePercentage)
	useWebAPI(cInsURL,:getIns)
	useWebAPI(cSubjectURL,:getSubject)

	loadingLabels()

func loadingLabels 

	lblAttendancePercentage.setText(C_ATTENDANCEPERCENTAGE + C_CONNECTING)
	prgAttendancePercentage.setValue(0)
	lblIns.setText(C_INS + C_CONNECTING)
	lblSubject.setText(C_SUBJECT + C_CONNECTING)

func checkDataIsReady

	if aData[:AttendancePercentage] 
		lblAttendancePercentage.setText(C_ATTENDANCEPERCENTAGE + aData[:AttendancePercentage] + "%") 
	ok

	if aData[:Ins]
		lblIns.setText(C_INS + aData[:Ins])
		checkEnableMap()
	ok

	if aData[:Subject]
		lblSubject.setText(C_SUBJECT + aData[:Subject])
		checkEnableMap()
	ok

	if aData[:AttendancePercentage] and aData[:Ins] and aData[:Subject]
		insert(aHistory, 0, [ date(), Time(), 
				    aData[:AttendancePercentage]+"%",
				    aData[:Ins],
				    aData[:Subject] ] )
		displayHistoryData()
		writeHistoryFile()
	ok

func getAttendancePercentage nManagerID

	cData = getAPIData(nManagerID)
	aData[:AttendancePercentage] = cData
	prgAttendancePercentage.setValue(0+cData)
	checkDataIsReady()

func getIns nManagerID

	cData = getAPIData(nManagerID)
	aData[:Ins] = cData
	checkDataIsReady()

func getSubject nManagerID

	cData = getAPIData(nManagerID)
	aData[:Subject] = cData
	checkDataIsReady()

