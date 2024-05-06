/*
**
** History (Table of Records)
**
*/

func readHistoryFile 

	if fexists(historyFileName()) 
		eval(read(historyFileName()))
	ok

func writeHistoryFile 

	write(historyFileName(), "aHistory = " + List2Code(aHistory) ) 

func historyFileName 

	return TempFilesPath() + "/LecturesTrackerHistory.txt"

func tempFilesPath

	QStandardPaths_GenericDataLocation = 11
	oPath = new QStandardPaths
	cPath = oPath.writableLocation(QStandardPaths_GenericDataLocation)
	return cPath 

func displayHistoryData 

	tableHistory.setRowCount(0)
	if ! aHistory return ok 
	tableHistory.addList(aHistory)
	btnOpenMap.setEnabled(True)

func selectRecordInHistory

	if ! aHistory return ok 
	nRow = tableHistory.currentRow()
	if nRow and (nRow <= len(aHistory))
		lblAttendancePercentage.setText(C_ATTENDANCEPERCENTAGE + aHistory[nRow][C_ATTENDANCECOLINHISTORY]) 
		prgAttendancePercentage.setValue(0+(substr(aHistory[nRow][C_ATTENDANCECOLINHISTORY],"%","")))
		lblIns.setText(C_INS + aHistory[nRow][C_INSCOLINHISTORY])
		lblSubject.setText(C_SUBJECT + aHistory[nRow][C_SUBJECTCOLINHISTORY])
	ok

func clearHistory 

	aHistory = []
	writeHistoryFile()
	displayHistoryData()
