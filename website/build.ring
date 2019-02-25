/*
	Ring programming language - Simple Website Generator
	Version 1.0
	http://ring-lang.net
	2016, Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load the pages list from the pages.data file!
eval(read("pages.data"))

# Message after finishing an operation
C_DONE = "Done..." + nl

# The main function generate the HTML files using the aPages list
Func Main
	about()
	checkfile(C_HEADER) checkfile(C_FOOTER)
	See "Reading header : " + C_HEADER  + nl
	cHeader = read(C_HEADER) + nl
	See "Reading footer : " + C_FOOTER  + nl
	cFooter = read(C_FOOTER)
	for x in aPages	
		checkfile(x)
		createPage(cHeader,x,cFooter,
			   substr(x,".template",".html"))
	next
	See C_DONE

# the createPage function generate html file 
# The function add the header and the footer to the content
Func createPage cHeader,cContent,cFooter,cOutput
	See "Content File : " + cContent + nl
	See "Add header..." + nl
	cStr = cHeader	
	See "Add content..."  + nl
	# Using template() then template2() to support using template() in the template file
	# As we have in the download16.template
	cContent = template(cContent,NULL)
	cStr += template2(cContent,NULL) + nl
	See "Add Footer..." + nl
	cStr += cFooter
	See "Writing file : " + cOutput  + nl
	write(cOutput,cStr)

# The function check if the file exist or not before using it
Func checkfile cFileName
	if not fexists(cFileName) raise("Error, File " + cFileName + " doesn't exist!") ok

# The function print the application information
Func about
	See "
========================================================
Simple Website Generator - Version 1.0
2016, Mahmoud Fayed <msfclipper@yahoo.com>
========================================================
"

# The function execute Ring code inside template files
# Then put the result/output from Ring code in the template content
Func Template cFile,oObject
	? "File " + cFile
	cStr = Read(cFile)
	return Template2(cStr,oObject)

Func Template2 cStr,oObject
	aList = []
	cResult = ""
	cCode = ""
	nPos = substr(cStr,"<%")
	if nPos = 0
		aList + cStr
		cCode += "cResult += aList[" + len(aList) + "]" + nl
	ok
	while nPos > 0
		cText = left(cStr,nPos-1)
		if cText != ""
			aList + cText
			cCode += "cResult += aList[" + len(aList) + "]" + nl
		ok
		cStr = substr(cStr,nPos+2)
		nPos = substr(cStr,"%>")
		if nPos > 0					
			if left(cStr,1) = "="
				cCode += "cResult += (" + substr(cStr,2,nPos-2) + ")" + nl	
			else
				cCode += left(cStr,nPos-1) + nl						
			ok
			cStr = substr(cStr,nPos+2)
		ok
		nPos = substr(cStr,"<%")
		if nPos = 0
			aList + cStr
			cCode += "cResult += aList[" + len(aList) + "]" + nl
		ok
	end
	if not isnull(oObject)
		oObject { 
			eval(cCode)
		}
	else
		eval(cCode)
	ok
	return cResult
