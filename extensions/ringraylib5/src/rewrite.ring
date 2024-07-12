#======================================================================================#
# Simple tool for rewriting extensions functions that uses objects instead of pointers
# 2020, Mahmoud Fayed <msfclipper@yahoo.com>
#======================================================================================#

# Change this list with the Types (pointers) that have (classes)
aTypes = ["Vector2","Vector3","Matrix","Quaternion"]

# Change this String to contains the functions that you want to rewrite! 
cFunctionsList = "
Vector2 Vector2Zero(void)
Vector2 Vector2Add(Vector2 v1, Vector2 v2)
float Vector2Length(Vector2 v)
Matrix MatrixIdentity(void)
Matrix MatrixAdd(Matrix left, Matrix right)
"

C_OUTPUT = 1
C_NAME   = 2
C_PARA   = 3

func main
	aFunctionsList = str2list(cFunctionsList)
	for cLine in aFunctionsList 
		cLine = trim(cLine)
		cLine = substr(cLine,char(9),"")
		if cLine != ""
			? Process(cLine)
		ok
		? nl
	next

func Process cLine
	aData = ThreeParts(cLine)
	cOutput = WriteFunction(aData)
	return cOutput

func ThreeParts cLine
	# Get three parts (output - function name - parameters)
	nPos1 = substr(cLine,"(")
	for x = nPos1 to 1 step -1
		switch cLine[x] 	
		on " " 
			nPos2 = x
			cFuncName = substr(cLine,nPos2+1,nPos1-nPos2-1)
			exit
		on "*"
			nPos2 = x + 1
			cFuncName = substr(cLine,nPos2,nPos1-nPos2)
			exit
		off
	next

	cFuncOutput = left(cLine,nPos2-1)
	cFuncPara = substr(cLine,nPos1+1,len(cLine)-nPos1-1)
	return [cFuncOutput,cFuncName,ParaList(cFuncPara)]

func ParaList cPara
	# convert string of parameters separated by , to a list
	aList = []
	nPos = substr(cPara,",") 
	while nPos
		aList + ParaTypeNoName( left(cPara,nPos-1) )
		cPara = substr(cPara,nPos+1)
		nPos = substr(cPara,",") 
	end
	aList + ParaTypeNoName( cPara )
	return aList

func ParaTypeNoName cLine
	# get the parameter type and name, remove name and keep the type only
	cLine = trim(cLine)
	nMax = len(cLine)
	for x = nMax to 1 step -1
		if cLine[x] = "*" or cLine[x] = " "
			return left(cLine,x)
		ok
	next
	return cLine

func WriteFunction aData
	cOutput = "func " + aData[C_NAME] + " "
	nPara = len(aData[C_PARA])
	for t=1 to nPara
		if aData[C_PARA][t] = "void" exit ok
		cOutput += "p"+t 
		if t!= nPara cOutput+="," ok
	next
	cOutput += nl
	if ! find(aTypes,aData[C_OUTPUT])
		cOutput += char(9) + "return " + aData[C_NAME] + "_2("
		cOutput += CallParameters(aData)
		cOutput += ")" + nl
	else 
		cOutput += Char(9) + "o" + aData[C_OUTPUT] + " = new " + aData[C_OUTPUT] + nl +
			Char(9) + "o"+aData[C_OUTPUT]+".setData( " 
				cOutput += aData[C_NAME] + "_2("
				cOutput += CallParameters(aData)
		cOutput += ") )" + nl
		cOutput += char(9) + "return o" + aData[C_OUTPUT] 
	ok	
	return cOutput	

func CallParameters aData
	cOutput = ""
	nPara = len(aData[C_PARA])
	for t=1 to nPara
		if aData[C_PARA][t] = "void" exit ok
		if ! find(aTypes,trim(aData[C_PARA][t]))
			cOutput += "p"+t 
		else 
			cOutput += "GPData(p"+t + ")"
		ok
		if t!= nPara cOutput+="," ok
	next
	return cOutput