/*--------------------------------------------------------------------------
/	Name         : Windows CRegistry Class Extension In Ring
/	Purpose      : Help access and edit windows registry entries and values
/						easily from within Ring Programming Language
/
/	Author Name  : Majdi Sobain
/	Author Email : MajdiSobain@Gmail.com
/
/					Copyright (c) 2016
/--------------------------------------------------------------------------*/



LoadLib("ring_wincreg.dll")
Load "wincreg.rh"

RCRegRetObj = NULL

/* this function is used to avoid Type() functions conflicts from within RCRegEntry Class */
Func cTypeForRCRegEntry para
	Return Type(para)
	

Class RCRegistry		# Short for Ring CRegistry Class

	Self.Key = NULL		# This is the Key Handle
	Self.RegEntry = New RCRegEntry(0,"")

	Func operator cOperator,Para
		Switch cOperator
			On "[]"
				If IsString(Para) = False
					Raise("Error : The name of the entry must be string")
				Ok
				If IsNULL(Key) Raise("Error : There is no opened key") Ok
				RegEntry.Init(Key, Para)
				Return RegEntry
			Off

	Func KeyExists HKEY, SubKey
		Return CRegKeyExists(HKEY, SubKey)

	Func OpenKey ParaList
		If IsList(ParaList) = False 
			Raise("Error : This function expects parameters as a list 'OpenKey([para1,para2])' ") 
		Ok
		Switch Len(ParaList)
			On 2 
				Key = CRegOpenKey(ParaList[1], ParaList[2])
				Return Key
			On 3 
				Key = CRegOpenKey(ParaList[1], ParaList[2], ParaList[3])
				Return Key
			On 4 
				Key = CRegOpenKey(ParaList[1], ParaList[2], ParaList[3], ParaList[4])
				Return Key
			Other 
				Raise("Error : Incorrect Number of Parameters passed" + nl +
				"          This function expects parameters as a list 'OpenKey([para1,para2])' ")
			Off 

	Func OpenKey2 HKEY, SubKey
		Key = CRegOpenKey(HKEY, SubKey)
		Return Key

	Func OpenKey3 HKEY, SubKey, Flags
		Key = CRegOpenKey(HKEY, SubKey, Flags)
		Return Key

	Func OpenKey4 HKEY, SubKey, Flags, Access64Tree
		Key = CRegOpenKey(HKEY, SubKey, Flags, Access64Tree)
		Return Key

	Func SetFlags Flags
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		CRegSetFlags(Key, Flags)

	Func GetFlags 
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		Return CRegGetFlags(Key)

	Func Access64Tree choice
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		CRegAccess64Tree(Key, choice)
		
	Func IsVirtualized
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		Return CRegIsVirtualized(Key)
		
	Func IsVirtualized2
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		Return CRegIsVirtualized(Key, True)

	Func EntriesCount
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		Return CRegEntriesCount(Key)

	Func SubKeyExists SubKey
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		Return CRegSubKeyExists(Key, SubKey)

	Func SubKeysCount
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		Return CRegSubKeysCount(Key)
		
	Func GetSubKeyAt index
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		Return CRegGetSubKeyAt(Key, index)
	
	Func GetSubKeys
		wcrlSubKeys = []
		For wcrii = 1 to SubKeysCount()
			Add(wcrlSubKeys, GetSubKeyAt(wcrii))
		Next
		Return wcrlSubKeys
	
	Func Refresh
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		CRegRefresh(Key)

	Func GetEntryAt index		# Return Entry Handle
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		Return CRegGetAt(Key, index)

	Func GetEntryName entry		# Accepts Entry Handle
		Return CRegGetName(entry)

	Func GetEntries
		wcrlNamesList = []
		For wcrii = 1 To EntriesCount()
			Add(wcrlNamesList, GetEntryName(GetEntryAt(wcrii)))
		Next
		Return wcrlNamesList
		
	Func CopyTo entryhandle,DestKey
		CRegCopy(entryhandle, DestKey)

	Func CopyAllTo DestKey
		For wcrii = 1 to EntriesCount()
			CRegCopy(GetEntryAt(wcrii), DestKey)
		Next

	Func CloseKey
		If IsNULL(Key) = False 
			CRegCloseKey(Key)
			Key = NULL
		Ok

	Func DeleteKey
		If IsNULL(Key) Raise("Error : There is no opened key") Ok
		CRegDeleteKey(Key)
		Key = NULL
		
	Func DeleteKey2 HKEY, SubKey
		wcrvTempKey = Key
		OpenKey([HKEY, SubKey])
		DeleteKey()
		Key = wcrvTempKey
		
	Func StringToBinary Str
		wcrvres = ""
		If Len(Str) > 0
			For wcrii = 1 To Len(Str)
				wcrvtm = Hex(Ascii(Str[wcrii]))
				If Len(wcrvtm) = 1
					wcrvres += "0" + wcrvtm
				Else
					wcrvres += wcrvtm
				Ok
				If wcrii < Len(Str)
					wcrvres += ","
				Ok
			Next
		Ok
		Return wcrvres

	Func BinaryToString Bin
		wcrvres = ""
		If Len(Bin) > 1
			Bin = SubStr(Bin, ",", NL)
			Bin = Str2List(Bin)
			For wcrihx in Bin
				wcrvres += Char(Dec(wcrihx))
			Next
		Ok
		Return wcrvres
		
		
	
Class RCRegEntry			# Short for Ring CRegistry Entry Class

	Self.Key = 0
	Self.EntryName = ""
	
	Func Init passedkey, passedentryName
		Key = passedkey
		EntryName = passedentryName
	
	Func Create type
		If Exists() = False
			Switch type
				On REG_SZ
					SetString("")
				On REG_DWORD
					SetDWORD(0)
				On REG_MULTI_SZ
					SetMulti("")
				On REG_QWORD
					SetQWORD(0)
				On REG_EXPAND_SZ
					SetExpandSZ("")
				On REG_BINARY
					SetBinary("")
				Other
					If EntryName = "" EntryName = "Default" Ok
					Raise("Error : Unknown type has been passed to create (" + EntryName + ")")
				Off
		Else
			If EntryName = "" EntryName = "Default" Ok
			Raise("Error : Cannot create (" + EntryName + ") because it is already existed")
		Ok
		
	Func GetValue
		wcrvvalue = 0
		Switch Type()
				On REG_SZ
					wcrvvalue = GetString()
				On REG_DWORD
					wcrvvalue = GetDWORD()
				On REG_MULTI_SZ
					wcrvvalue = GetMultiList()
				On REG_QWORD
					wcrvvalue = GetQWORD()
				On REG_EXPAND_SZ
					wcrvvalue = GetExpandSZ()
				On REG_BINARY
					wcrvvalue = GetBinary()
				Other
					If EntryName = "" EntryName = "Default" Ok
					Raise("Error : Unknown type of (" + EntryName + ") to be retrieved")
				Off
		Return wcrvvalue

	Func SetValue value
		If Exists() = True
			Switch Type()
				On REG_SZ
					SetString(value)
				On REG_DWORD
					SetDWORD(value)
				On REG_MULTI_SZ
					SetMultiList(value)
				On REG_QWORD
					SetQWORD(value)
				On REG_EXPAND_SZ
					SetExpandSZ(value)
				On REG_BINARY
					SetBinary(value)
				Other
					If EntryName = "" EntryName = "Default" Ok
					Raise("Error : Unknown type of (" + EntryName + ") to be set")
				Off
		Else
			Switch cTypeForRCRegEntry(value)
				On "STRING"
					CRegSetValue(Key, EntryName, value)
				On "NUMBER"
					CRegSetValue(Key, EntryName, value)
				Other
					Raise("Error : SetValue() function could just set String or Numbers to newly created entries")
				Off	
		Ok

	Func SetValue2 value, type
		Switch type
			On REG_SZ
				SetString(value)
			On REG_DWORD
				SetDWORD(value)
			On REG_MULTI_SZ
				SetMultiList(value)
			On REG_QWORD
				SetQWORD(value)
			On REG_EXPAND_SZ
				SetExpandSZ(value)
			On REG_BINARY
				SetBinary(value)
			Other
				If EntryName = "" EntryName = "Default" Ok
				Raise("Error : Unknown type of (" + EntryName + ") to be set")
			Off
		
	Func SetString value
		If cTypeForRCRegEntry(value) != "STRING"
			Raise ("Error : SetString() could just accept strings")
		Ok
		CRegSetValue(Key, EntryName, value)
	
	Func GetString
		wcrvvalue = ""
		If Type() = REG_SZ
			wcrvvalue = CRegGetValue(Key, EntryName)
		Else
			Raise ("Error : GetString() could just return strings (REG_SZ)")
		Ok
		Return wcrvvalue
		
	Func SetDWORD value
		If IsNumber(value) = False
			Raise ("Error : SetDWORD() could just accept numbers")
		Else
			If IsDigit(String(value)) = False
				Raise ("Error : SetDWORD() could just accept real numbers(not floated)")
			Else
				If value < 0 Or value > 4294967295
					Raise ("Error : SetDWORD() : the value is out of range (0 - 4294967295)")
				Ok
			Ok
		Ok
		CRegSetValue(Key, EntryName, value)
				
	Func GetDWORD
		wcrvvalue = 0
		If Type() = REG_DWORD
			wcrvvalue = floor(CRegGetValue(Key, EntryName))	# To retrieve integer number
		Else
			Raise ("Error : GetDWORD() could just return DWORD numbers")
		Ok
		Return wcrvvalue

	Func SetMulti value
		CRegSetMulti(Key, EntryName, value)

	Func MultiAdd newValue
		If Exists() = True And IsMultiString() = True And MultiCount() > 0
			CRegMultiAdd(Key, EntryName, newValue)
		Else
			SetMulti(newValue)
		Ok

	Func MultiSetAt index, newValue
		CRegMultiSetAt(Key, EntryName, index, newValue)

	Func MultiGetAt index
		Return CRegMultiGetAt(Key, EntryName, index)

	Func MultiRemoveAt index
		CRegMultiRemoveAt(Key, EntryName, index)

	Func MultiCount
		Return CRegMultiCount(Key, EntryName)

	Func MultiClear
		CRegMultiClear(Key, EntryName)

	Func SetMultiList valuesList
		If IsList(valuesList) = False 
			Raise("Error : SetMultiList() function accepts only lists")
		Ok
		If Len(valuesList) > 0 
			If Exists() And IsMultiString() MultiClear() Ok
			For wcriv in valuesList
				Switch cTypeForRCRegEntry(wcriv)
					On "STRING"
						MultiAdd(wcriv) 
					ON "NUMBER"
						MultiAdd(String(wcriv)) 
					Other
						Raise ("Error : MultiString could just accept strings or numerical strings")
					Off
			Next
		Ok

	Func GetMultiList
		wcrlMultiList = []
		If MultiCount() > 0
			For wcrii = 1 to MultiCount()
				Add(wcrlMultiList, MultiGetAt(wcrii))
			Next
		Ok
		Return wcrlMultiList
		
	Func GetExpandSZ
		Return CRegGetExpandSZ(Key, EntryName)
		
	Func SetExpandSZ value
		Return CRegSetExpandSZ(Key, EntryName, value)
		
	Func GetExpandedSZ
		Return CRegGetExpandedSZ(Key, EntryName)
		
	Func GetQWORD
		Return CRegGetQWORD(Key, EntryName)
		
	Func GetQWORDs
		wcrvv = CRegGetQWORD(Key, EntryName)
		If IsNumber(wcrvv)
			wcrvv = String(wcrvv)
		Ok
		Return wcrvv
		
	Func SetQWORD value
		Return CRegSetQWORD(Key, EntryName, value)
		
	Func GetBinary
		Return CRegGetBinary(Key, EntryName)
		
	Func SetBinary value
		Return CRegSetBinary(Key, EntryName, value)
		
	Func BinaryLength
		Return CRegBinaryLength(Key, EntryName)
		
	Func Exists
		Return CRegExists(Key, EntryName)

	Func Rename newName
		CRegRename(Key, EntryName, newName)

	Func CopyTo newKeyHandle
		CRegCopy(Key, EntryName, newKeyHandle)
		
	Func Clear
		If Exists() = True
			Switch Type()
				On REG_SZ
					SetValue("")
				On REG_DWORD
					SetValue(0)
				On REG_MULTI_SZ
					SetMulti("")
				On REG_QWORD
					SetQWORD(0)
				On REG_EXPAND_SZ
					SetExpandSZ("")
				On REG_BINARY
					SetBinary("")
				Other
					If EntryName = "" EntryName = "Default" Ok
					Raise("Error : Unknown type has been passed to create (" + EntryName + ")")
				Off
		Else
			If EntryName = "" EntryName = "Default" Ok
			Raise("Error : Cannot clear (" + EntryName + ") because it is not existed")
		Ok

	Func Delete
		CRegDelete(Key, EntryName)

	Func IsString
		Return CRegIsString(Key, EntryName)

	Func IsDWORD
		Return CRegIsDword(Key, EntryName)

	Func IsMultiString
		Return CRegIsMultiString(Key, EntryName)

	Func IsBinary
		Return CRegIsBinary(Key, EntryName)
		
	Func IsExpandSZ
		Return CRegIsExpandSZ(Key, EntryName)
		
	Func IsQWORD
		Return CRegIsQWORD(Key, EntryName)
		
	Func Type
		Return CRegType(Key, EntryName)

	Func TypeName
		wcrlaList = ["REG_NONE", "REG_SZ", "REG_EXPAND_SZ", "REG_BINARY", "REG_DWORD", "REG_DWORD_BIG_ENDIAN", "REG_LINK", "REG_MULTI_SZ",
				 "REG_RESOURCE_LIST", "REG_FULL_RESOURCE_DESCRIPTOR", "REG_RESOURCE_REQUIREMENTS_LIST", "REG_QWORD"]
		return wcrlaList[Type() + 1]   # increment by 1 is due to list index that starts with one

	Func SetObject obj
		wcroO2R = New Objects2Reg(Self)
		wcroO2R.SetObject(obj)
			
	Func GetObject
		wcroO2R = New Objects2Reg(Self)
		Return wcroO2R.GetObject()

		
Class Objects2Reg
	Self.EntryObj = NULL
	Self.CollecterList = []

	Func init EntObj
		EntryObj = EntObj
	
	Func SetObject obj		# From Collector to Registry
		ConfObject(obj, EntryObj.EntryName /*ObjectName*/)		# From Input to Collector
		wcrvTempD = List2Str(CollecterList)
		wcroReg = New RCRegistry
		EntryObj.SetBinary(wcroReg.StringToBinary(wcrvTempD))
		
	Func ConfObject obj, objectName
		wcrlResList = ["--RING--OBJECT--"]
		If IsObject(obj) = False 
			Raise("Error : ConfObject() can just accept objects, and their names")
		Ok
		Add(wcrlResList, "-CName--" + ClassName(obj))
		Add(wcrlResList, "........")
		wcrlaList = Attributes(obj)
		wcrvObjNum = 1
		For wcrva in wcrlaList
			wcrvv = 0
			eval("wcrvv = obj." + wcrva)
			Switch cTypeForRCRegEntry(wcrvv)
				On "STRING"
					Add(wcrlResList, "-S--" + wcrva + " = '" + wcrvv + "'")
				On "NUMBER"
					Add(wcrlResList, "-N--" + wcrva + " = " + String(wcrvv))
				On "LIST"
					Add(wcrlResList, "-L--" + wcrva)
					AddToInputList(wcrlResList, wcrvv, "-L--", obj, objectName)
				On "OBJECT"
					If ClassName(wcrvv) = ClassName(obj) 
						See "Warning : There's ignored object recursion. Object Recursion will end in overflow problems"
					Ok
					wcrvnObjEntName = objectName + "-o" + wcrvObjNum
					Add(wcrlResList, "-O--" + wcrva + " = '" + wcrvnObjEntName + "'" )
					ConfObject(wcrvv, wcrvnObjEntName)
					wcrvObjNum += 1
				Other
				
				Off
			
			Add(wcrlResList, "........")
		Next
		ToCollector(wcrlResList, objectName)
		
	Func ToCollector srcList, objectName
		wcrlFinalRes = List2Str(srcList)
		wcrlFinalRes = SubStr(wcrlFinalRes, NL, "@!^")
		Add(CollecterList, objectName)
		Add(CollecterList, wcrlFinalRes)
	
	Func AddToInputList ResLst, currentlist, prefix, CurrObj, ObName
		wcrvObjNum = 1
		For wcrii = 1 To Len(currentlist)
			Switch cTypeForRCRegEntry(currentlist[wcrii])
				On "STRING"
					Add(ResLst, prefix + "-S--" + currentlist[wcrii] )
				On "NUMBER"
					Add(ResLst, prefix + "-N--" + currentlist[wcrii])
				On "LIST"
					AddToInputList(ResLst, currentlist[wcrii], prefix + "-L--", CurrObj, ObName) 
				On "OBJECT"
					If ClassName(currentlist[wcrii]) = ClassName(CurrObj) 
						See "Warning : There's ignored object recursion. Object Recursion will end in overflow problems" 
					Ok
					wcrvnObjEntName = ObName + "-l" + String(Len(prefix)/4) + "o" + wcrvObjNum
					Add(ResLst, prefix + "-O--" + wcrvnObjEntName )
					ConfObject(currentlist[wcrii], wcrvnObjEntName)
					wcrvObjNum += 1
				Other
					
				Off
			Add(ResLst, prefix + "........")
		Next

	Func GetObject		# From Registry to Collector + Request Retrieving The Main Object
		If EntryObj.IsBinary() = False
			Raise("Error : Unknown Object saving type entry (Entry Is not Binary)")
		Ok
		wcroReg = New RCRegistry
		wcrvRwaData = wcroReg.BinaryToString(EntryObj.GetBinary())
		CollecterList = Str2List(wcrvRwaData)
		
		Return RetObject(FromCollector(EntryObj.EntryName))	# The main object
			
	Func FromCollector Objname
		wcrvObjIndex = Find(CollecterList, Objname)
		wcrlTempLst = SubStr(CollecterList[wcrvObjIndex +1], "@!^", NL)
		wcrlTempLst = Str2List(wcrlTempLst)
		Return wcrlTempLst
	
	Func RetObject objList		# Return Objects from Collector
		wcrvLocRetObj = NULL
		If Len(objList) > 0 
			If objList[1] != "--RING--OBJECT--"
				Raise("Error : Unknown Ring Object saving format at (--RING--OBJECT--)")
			Ok
			If Left(objList[2], 8) = "-CName--"
				If Find(Classes(), SubStr(objList[2], 9)) = 0
					Raise("Error : Cannot return Ring Object because it's class is not in the available classes list")
				Ok
				Eval("wcrvLocRetObj = New " + SubStr(objList[2], 9))
			Else
				Raise("Error : Unknown Ring Object saving format at (-CName--)")
			Ok
			For wcrio = 1 to Len(objList)
				wcrlattlst = []
				wcrvchvalue = Left(objList[wcrio], 4)
				Switch wcrvchvalue
					On "...."
						Loop
					On "-S--"
						Eval("Add(wcrlattlst, :" + SubStr(objList[wcrio], 5) + ")")
						If Find(Attributes(wcrvLocRetObj), wcrlattlst[1][1])
							Eval("wcrvLocRetObj." + wcrlattlst[1][1] + " = '" + wcrlattlst[1][2] + "'")
						Else
							AddAttribute(wcrvLocRetObj, wcrlattlst[1][1])
							Eval("wcrvLocRetObj." + wcrlattlst[1][1] + " = '" + wcrlattlst[1][2] + "'")
						Ok
					On "-N--"
						Eval("Add(wcrlattlst, :" + SubStr(objList[wcrio], 5) + ")")
						If Find(Attributes(wcrvLocRetObj), wcrlattlst[1][1])
							Eval("wcrvLocRetObj." + wcrlattlst[1][1] + " = " + wcrlattlst[1][2])
						Else
							AddAttribute(wcrvLocRetObj, wcrlattlst[1][1])
							Eval("wcrvLocRetObj." + wcrlattlst[1][1] + " = " + wcrlattlst[1][2])
						Ok
					On "-L--"
						lstname = ""
						Eval("lstname = '" + SubStr(objList[wcrio], 5) + "'")
						If Find(Attributes(wcrvLocRetObj), lstname)
							lst = AddToOutputList(objList, wcrio + 1, "-L--") 
							Eval("wcrvLocRetObj." + lstname + " = lst")
						Else
							AddAttribute(wcrvLocRetObj, lstname)
							lst = AddToOutputList(objList, wcrio + 1, "-L--") 
							Eval("wcrvLocRetObj." + lstname + " = lst")
						Ok
												
						For wcrii = wcrio to Len(objList)		# this loop to help jump already added list
							If objList[wcrii] = "........"
								wcrio = wcrii
								Exit
							Ok
						Next
					On "-O--"
						Eval("Add(wcrlattlst, :" + SubStr(objList[wcrio], 5) + ")")
						If Find(Attributes(wcrvLocRetObj), wcrlattlst[1][1])
							wcrlTempLst = FromCollector(wcrlattlst[1][2])
							wcrvob = RetObject(wcrlTempLst)
							Eval("wcrvLocRetObj." + wcrlattlst[1][1] + " = wcrvob")
						Else
							AddAttribute(wcrvLocRetObj, wcrlattlst[1][1])
							wcrlTempLst = FromCollector(wcrlattlst[1][2])
							wcrvob = RetObject(wcrlTempLst)
							Eval("wcrvLocRetObj." + wcrlattlst[1][1] + " = wcrvob")
						Ok
					Other
					
					Off
				wcrlattlst = []
			Next
		Ok
		RCRegRetObj = wcrvLocRetObj
		Return RCRegRetObj

		
	Func AddToOutputList srcObjList, currentIndex, prefix
		wcrlopList = []
		wcrvlastindex = 0
		For wcrij = currentIndex To Len(srcObjList)
			If srcObjList[wcrij] = SubStr(prefix, 5) + "........"
				wcrvlastindex = wcrij
				Exit
			Ok
		Next
		For wcrik = currentIndex To wcrvlastindex
			wcrvchkvalue = SubStr(srcObjList[wcrik], Len(prefix) +1 , 4)
			Switch wcrvchkvalue
				On "...."
					Loop
				On "-S--"
					Add(wcrlopList, SubStr(srcObjList[wcrik], Len(prefix) + 5))
				On "-N--"
					Add(wcrlopList, Number(SubStr(srcObjList[wcrik], Len(prefix) + 5)))
				On "-L--"
					wcrlnlist = AddToOutputList(srcObjList, wcrik, prefix + "-L--")
					Add(wcrlopList, wcrlnlist)
					For wcrii = wcrik to Len(srcObjList)	# this loop to help jump already added list
						If srcObjList[wcrii] = prefix + "........"
							wcrik = wcrii 
							Exit
						Ok
					Next
				On "-O--"
					wcrlTempLst = FromCollector(SubStr(srcObjList[wcrik], Len(prefix) + 5))
					wcrvob = RetObject(wcrlTempLst)
					Add(wcrlopList, wcrvob)
				Other
				
				Off
		Next
		
		Return wcrlopList
		
