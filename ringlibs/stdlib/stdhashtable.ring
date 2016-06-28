# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	eval("Load 'stdlist.ring'")
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

	Func Contains cKey
		if self[cKey] != NULL
			return True
		else return false ok

