aCodeTemplates = [ 
	["[comment] Separator (====)", func {
		return "#"+Copy("=",70) + "#" + nl 
	} ],
	["[Comment] Insert Date & Time" , func {
		return "# Date   : " + Date() + nl + "# Time   : " + Time() + nl  
	} ],
	["[Comment] Author Name", func {
		return "# Author :" + nl
	} ],
	["[Comment] Function Description", func {
		return "/*" + nl +
			" Function Name :" + nl + 
			" Parameters    :" + nl +
			" Output        :" + nl + 
			" Description   :" + nl +  
		"*/" + nl
	} ]  
]

