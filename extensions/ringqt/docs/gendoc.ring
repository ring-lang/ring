# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2016.09.22
#===============================================

load "stdlibcore.ring"

cDir = currentdir()
chdir("../classes")
cFile = read("qt.cf")
if isWindows()
	C_OUTPUTFILE = "..\docs\qtclassesdoc.txt"
else 
	C_OUTPUTFILE = "../docs/qtclassesdoc.txt"
ok
C_CHAPTERNAME = "RingQt Classes Reference"
lStart = False		# False = Classes Doc.   True = Functions Doc.

# The next list for RingQt classes that are not defined in Qt
aRingQtClasses = ["RingCodeHighlighter","QAllEvents"]

# The next list for RingQt Names and their Qt Names
aRingQtToQtClasses = [
	:QApp = "QApplication"
]

funcAfterClass = func cClassName {
	if find(aRingQtClasses,cClassName) = 0
		nPos = find(aRingQtToQtClasses,lower(cClassName),1)
		if nPos > 0
			cClassName = aRingQtToQtClasses[nPos][2]
		ok
		if cClassName = "QWebView"
			return windowsnl() + "C++ Reference : http://doc.qt.io/archives/qt-5.5/qwebview.html" + windowsnl() + windowsnl()
		else
			return windowsnl() + "C++ Reference : http://doc.qt.io/qt-5/" + cClassName + ".html" + windowsnl() + windowsnl()
		ok
	ok
}
#===============================================

load "../../codegen/gendoc.ring"
chdir(cDir)
