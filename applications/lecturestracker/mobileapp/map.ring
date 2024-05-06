/*
**
** Map Functions
**
*/

func openMap

	new QDesktopServices {
		OpenURL(new QURL(prepareMapURL()))
	}

func checkEnableMap

	if ! lDisplayMap return ok 
	if aData[:Ins] and aData[:Subject]
		lDisplayMap = False 
		btnOpenMap.setEnabled(True)
		btnGetData.setEnabled(True)
	ok

func prepareMapURL 

	return cMapURL + C_LAT + "," + C_LONG
