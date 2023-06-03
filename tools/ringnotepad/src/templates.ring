aCodeTemplates = [ 
	[T_RINGNOTEPAD_TEMPLATESEPARATOR, func {
		return "#"+Copy("=",70) + "#" + nl 
	} ],
	[T_RINGNOTEPAD_TEMPLATEDATETIME , func {
		return "# Date   : " + Date() + nl + "# Time   : " + Time() + nl  
	} ],
	[T_RINGNOTEPAD_TEMPLATEAUTHOR, func {
		return "# Author :" + nl
	} ],
	[T_RINGNOTEPAD_TEMPLATEFUNCDESC, func {
		return "/*" + nl +
			" Function Name :" + nl + 
			" Parameters    :" + nl +
			" Output        :" + nl + 
			" Description   :" + nl +  
		"*/" + nl
	} ]  
]

