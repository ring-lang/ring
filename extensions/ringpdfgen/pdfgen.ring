if isWindows()
	LoadLib("ring_pdfgen.dll")
but ismacosx()
	LoadLib("libring_pdfgen.dylib")
else
	LoadLib("libring_pdfgen.so")
ok

load "ring_pdfgen.rh"

func pdf_info aList

	cNewStr = "" 

	creator  = aList[:creator]
	producer = aList[:producer]
	title    = aList[:title]
	author   = aList[:author]
	subject  = aList[:subject]
	date     = aList[:date]

	creator  += copy(" ",64-len(creator)) 
	producer += copy(" ",64-len(producer)) 
	title    += copy(" ",64-len(title)) 
	author   += copy(" ",64-len(author)) 
	subject  += copy(" ",64-len(subject)) 
	date     += copy(" ",64-len(date)) 

	cNewStr = creator+producer+title+author+subject+date

	return cNewStr

func pdf_create nWidth,nHeight,aInfo

	info = pdf_info(aInfo)
	return pdf_create_2(nWidth, nHeight, varptr(:info,"struct pdf_info") )