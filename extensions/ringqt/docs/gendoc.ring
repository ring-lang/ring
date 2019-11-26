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
	:QApp = "QApplication",
	:QAbstractAspect = "Qt3DCore-QAbstractAspect",
	:QNode = "Qt3DCore-QNode",
	:QEntity = "Qt3DCore-QEntity",
	:QTransform = "Qt3DCore-QTransform",
	:QAspectEngine = "Qt3DCore-QAspectEngine",
	:qtorusmesh = "qt3dextras-qtorusmesh",
	:qconemesh = "qt3dextras-qconemesh",
	:qcylindermesh = "qt3dextras-qcylindermesh",
	:qcuboidmesh = "qt3dextras-qcuboidmesh",
	:qplanemesh = "qt3dextras-qplanemesh",
	:qspheremesh = "qt3dextras-qspheremesh",
	:qphongmaterial = "qt3dextras-qphongmaterial",
	:qforwardrenderer = "qt3dextras-qforwardrenderer",
	:qt3dwindow = "qt3dextras-qt3dwindow",
	:qabstractcameracontroller = "qt3dextras-qabstractcameracontroller",
	:qfirstpersoncameracontroller = "qt3dextras-qfirstpersoncameracontroller",
	:qtexturematerial = "qt3dextras-qtexturematerial",
	:qextrudedtextmesh = "qt3dextras-qextrudedtextmesh",
	:qtext2dentity = "qt3dextras-qtext2dentity",
	:qskyboxentity = "qt3dextras-qskyboxentity",
	:qconegeometry = "qt3dextras-qconegeometry",
	:qorbitcameracontroller = "qt3dextras-qorbitcameracontroller",
	:qdiffusespecularmaterial = "qt3dextras-qdiffusespecularmaterial",
	:qgoochmaterial = "qt3dextras-qgoochmaterial",
	:qmetalroughmaterial = "qt3dextras-qmetalroughmaterial",
	:morphphongmaterial = "qt3dextras-morphphongmaterial",
	:qpervertexcolormaterial = "qt3dextras-qpervertexcolormaterial",
	:qinputaspect = "qt3dinput-qinputaspect",
	:qframeaction = "qt3dlogic-qframeaction",
	:qlogicaspect = "qt3dlogic-qlogicaspect",
	:qcamera = "qt3drender-qcamera",
	:qcameralens = "qt3drender-qcameralens",
	:qmesh = "qt3drender-qmesh",
	:qtechnique = "qt3drender-qtechnique",
	:qmaterial = "qt3drender-qmaterial",
	:qeffect = "qt3drender-qeffect",
	:qrenderpass = "qt3drender-qrenderpass",
	:qsceneloader = "qt3drender-qsceneloader",
	:qpointlight = "qt3drender-qpointlight",
	:qrenderaspect = "qt3drender-qrenderaspect",
	:qtextureloader = "qt3drender-qtextureloader",
	:qobjectpicker = "qt3drender-qobjectpicker",
	:qcameraselector = "qt3drender-qcameraselector ",
	:qcullface = "qt3drender-qcullface",
	:qdepthtest = "qt3drender-qdepthtest",
	:qviewport = "qt3drender-qviewport"
]

funcAfterClass = func cClassName {
	if find(aRingQtClasses,cClassName) = 0
		cClassName = lower(trim(cClassName))
		nPos = find(aRingQtToQtClasses,cClassName,1)
		if nPos > 0
			cClassName = lower(aRingQtToQtClasses[nPos][2])
		ok
		if left(cClassName,1) != "q" or isDigit(Right(cClassName,1)) return ok
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
