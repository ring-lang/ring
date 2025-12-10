func ضبط_الدوال obj
	aAttributes = attributes(obj)
	aMethods = methods(obj)
	for cAttr in aAttributes
		cGetterMethod = "معرفة_قيمة_"+cAttr
		if isMethod(obj,cGetterMethod)
			cCode = `
				fFunc = func {
					return `+cGetterMethod+`()
				}
			`
			eval(cCode)
			addMethod(obj,"get"+cAttr, fFunc)
		ok
		cSetterMethod = "اسناد_قيمة_"+cAttr
		if isMethod(obj,cSetterMethod)
			cCode = `
				fFunc = func value {
					return `+cSetterMethod+`(value)
				}
			`
			eval(cCode)
			addMethod(obj,"set"+cAttr, fFunc)
		ok
	next
