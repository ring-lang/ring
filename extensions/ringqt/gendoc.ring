# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2016.09.22

#===============================================
C_OUTPUTFILE = "qtclassesdoc.txt"
C_CHAPTERNAME = "RingQt Classes Reference"
cFile = read("qt.cf")
lStart = False		# False = Classes Doc.   True = Functions Doc.

# The next list for RingQt classes that are not defined in Qt
aRingQtClasses = ["RingCodeHighlighter"]

# The next list for RingQt Names and their Qt Names
aRingQtToQtClasses = [
	:QApp = "QApplication"
]

funcAfterClass = func cClassName {
	if find(aRingQtClasses,cClassName) = 0
		nPos = find(aRingQtToQtClasses,lower(cClassName),1)
		if nPos > 0
			see nPos + nl
			cClassName = aRingQtToQtClasses[nPos][2]
		ok
		return windowsnl() + "C++ Reference : http://doc.qt.io/qt-5/" + cClassName + ".html" + windowsnl() + windowsnl()
	ok
}
#===============================================

load "../codegen/gendoc.ring"
