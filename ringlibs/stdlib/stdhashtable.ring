# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlist.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	hashtable_class_test()
ok

func hashtable_class_test
	
	ohashtable = new hashtable
	See "Test the hashtable Class Methods" + nl
	ohashtable { 
		Add("Egypt","Cairo")
		Add("KSA","Riyadh")
		see self["Egypt"] + nl
		see self["KSA"] + nl
		see contains("Egypt") + nl
		see contains("USA") + nl
		see index("KSA")  + NL
		print()
		delete(index("KSA"))
		see copy("*",60) + nl
		print()
	}

Class hashtable from list
 
	Func Init x
		if  islist(x)
			super.init(x)
		else
			raise("Error: HashTable Class - Init Method - Bad Parameter")
		ok

	Func Add cKey,cValue
		super.add([cKey,cValue])

	Func Set cKey,cValue
		Add(cKey,cValue)

	Func GetValue cKey
		return self[cKey]

	Func Contains cKey
		if self[cKey] != NULL
			return True
		else 
			del(vValue,len(vValue))
			return false 
		ok

	Func Index cKey
		return FindinColumn(1,cKey)
