Import System.Web

aPageVars = []

mergemethods("page","stylefunctions")

Func LoadVars

	New Application
	{
	    	if sysget("REQUEST_METHOD") = "GET"
			cInput = sysget("QUERY_STRING")
		else
			cInput = input(sysget("CONTENT_LENGTH"))
		ok
		
		aPageVars = decode(cInput)
		aArray = getcookies()

		for x in aArray
			aPageVars+x
		next
	}

	return cInput

Func WebPage return new WebPage

Func htmlspecialchars cStr
	cResult = ""
	if isstring(cStr) and len(cStr) > 0
		for x in cStr
			if x = '&'  cResult += '&amp;'
			but x = '"' cResult += '&quot;'
			but x = "'" cResult += '&#039;'
			but x = '<' cResult += '&lt;'
			but x = '>' cResult += '&gt;'
			but x = ' ' cResult += '&nbsp;'
			else 	    cResult += x
			ok
		next
	ok
	return cResult

Func Template cFile,oObject

	cStr = Read(cFile)
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
	oObject { 
		eval(cCode)
	}
	return cResult

Func Alert cMessage
	New Page
	{
		script( "document.onready = function() { alert(" +'"' + cMessage + '"' + ") }" )
	}

func HTML2PDF cStr

	cFileName = "temp/"+tempname()
	cHTML = cFileName + ".html"
	cPDF =  cFileName + ".pdf"
	write(cHTML,cStr)
	system("wkhtmltopdf " + cHTML + " " + cPDF)
	New Page 
	{  
		script(scriptredirection(cPDF))  
	}


Package System.Web
			
	Class Application

		cStart = ""
		cCookies = ""
		cOutput = ""
		cCSS = ""
		Title = "Test"
		cBody = ""

		lBootstrap = False

		Func DecodeString cStr
			cStr = cStr + "&" 
			aOutput = [] 	
			aRes = [] 
			cValue = ""
			for x = 1 to len(cStr)
				t = cStr[x]
				if t = "="  
					aRes + cValue
					cValue = ""
				but t = "&" 
					aRes + cValue
					cValue = "" 
					aOutput + aRes
					aRes = []
				but t = "+"
					cValue = cValue + " "
				but t = "%"
					cValue = cValue + hex2str(cStr[x+1]+cStr[x+2])
					x = x+2
				but t = '"'
				else 
					cValue = cValue + t 
				ok
			next
			return aOutput

		Func Decode cInput
			if left(sysget("CONTENT_TYPE"),20) != "multipart/form-data;"
				return decodestring(cInput)
			ok

			# Decode (File Uploading)

			nPos = substr(cInput,"Content-Disposition") 
			cMark = left(cInput,nPos-3)

			VarsList = []

			while true

				NewVar = [] # List contains the new variable
				nPos = substr(cInput,'"')  # start of the name

				cInput = substr(cInput,nPos+1) #remove before start
				nPos = substr(cInput,'"')  # end of the name

				NewVar + left(cInput,nPos-1)	# add Name to List
				cInput = substr(cInput,nPos+1) # after name	

				if left(cInput,1) = ";"

					nPos = substr(cInput,'"')  # start of the file name
					cInput = substr(cInput,nPos+1) # after file name
					nPos = substr(cInput,'"')  # end of the file name
					cFile = left(cInput,nPos-1)	# File Name to be added to the List
					
					for x = 1 to 3
						nPos = substr(cInput,nl)
						cInput = substr(cInput,nPos+1) # after new line
					next

					nPos = substr(cInput,cMark) 
					NewVar + left(cInput,nPos-2)    # Get File content
					NewVar + cFile			# Add file Name
					cInput = substr(cInput,nPos)
					
				else

					for x = 1 to 2
						nPos = substr(cInput,nl)
						cInput = substr(cInput,nPos+1) # after new line
					next

					nPos = substr(cInput,nl)
					NewVar + left(cInput,nPos-1)

					cInput = substr(cInput,nPos+1) # after value

				ok

				VarsList + NewVar

				nPos = substr(cInput,cMark) 

				if substr(cInput,cMark+"--") = nPos
					exit
				ok
			end

			return VarsList
		
		Func GetFileName  aArray,cVar
			for x in aArray
				if len(x) >= 3
					if x[1] = cVar
						return x[3]
					ok
				ok
			next
			return "NULL"

		Func setcookie name,value,expires,path,domain,secure
			cCookies += "Set-Cookie: "+name+"="+value+"; expires="+expires+
				    "; path="+path+"; domain="+domain+"; "+secure + "; HttpOnly"+ nl

		Func cookie name,value
			cCookies += "Set-Cookie: "+name+"="+value+";" + nl

		Func getcookies 
			cStr = sysget("HTTP_COOKIE")
			if cStr = "NULL" 	return 	OK 
			# var1=value; var2=value; var3=value
			cStr += ";"
			aOutput = [] 	 
			nPos = substr(cStr,";")
			While nPos > 0
				nPos2 = substr(cStr,"=") 
				if nPos2 = 0 exit ok
				aRes = []
				aRes + trim(left(cStr,nPos2-1))
				aRes + substr(cStr,nPos2+1,nPos-nPos2-1)
				aOutput + aRes 
				cStr = substr(cStr,nPos+1)
				nPos = substr(cStr,";")
			end
			return aOutput

		Func URLEncode cStr
			cOut = ""
			for x in cStr
				if isalnum(x)
					cOut += x
				but x = " "
					cOut += "+"
				else
					cOut += "%"+str2hex(x)
				ok
			next
			return cOut	
		
		Func ScriptLibs
			if lBootstrap
				cStr = nl+'<meta name="viewport" content="width=device-width, initial-scale=1">' + nl +
  				       '<link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">'+nl+
				       '<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>'+nl+
			 	       '<script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>'+nl
			else
				cStr = nl+'<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>'+nl
			ok	
			return TabMLString(cStr)

		Func Print
			See cCookies + cStart + "<html>" + nl +
			"<header>"+nl+CHAR(9)+scriptlibs()+nl+
			CHAR(9)+"<title>"+nl+CHAR(9)+Char(9)+Title+nl+Char(9)+"</title>"+nl
			if cCSS != NULL
				See Char(9)+"<style>"+nl+CHAR(9)+CHAR(9)+cCSS+nl+Char(9)+"</style>"+nl
			ok
			see nl+"</header>" + nl +
			"<body"+ cBody + "> " + nl + cOutput + nl + "</body>" + nl + "</html>"

		Func style cStyle
			cCSS += cStyle 

		Func starthtml 

			cStart = "Content-type: text/html" + nl + nl +
				   "<meta charset='UTF-8'>" + nl

		Private

			nTabs = 1

			Func TabPush
				nTabs++

			Func TabPOP
				nTabs--

			Func GetTabs
				return copy(char(9),nTabs)

			Func TabMLString cStr
				aList = str2list(cStr)
				for t in aList
					t = GetTabs() + t
				next
				return list2str(aList)		
				 

	Class Page from Application
		
		StartHtml()	

		Func text x
			if isstring(x)
				cOutput += nl+GetTabs() + htmlspecialchars(x)
			but isnumber(x)
				cOutput += nl+GetTabs() + htmlspecialchars(string(x))
			ok
		
		Func html x
			cOutput += x

		Func h1 x
			html( GetTabs()+"<h1>" + x + "</h1>" )

		Func h2 x
			html( GetTabs()+"<h2>" + x + "</h2>" )

		Func h3 x
			html( GetTabs()+"<h3>" + x + "</h3>" )

		Func h4 x
			html( GetTabs()+"<h4>" + x + "</h4>" )

		Func h5 x
			html( GetTabs()+"<h5>" + x + "</h5>" )

		Func h6 x
			html( GetTabs()+"<h6>" + x + "</h6>" )

		Func p aPara
			html( nl+GetTabs()+'<p ' )
			addattributes(aPara)
			html( '>' )
			if aPara[:text] != NULL
				html( nl+GetTabs()+aPara[:text] )
			ok
			html( nl+GetTabs()+'</p>' )

		
		Func script x
			cOutput += TabMLString( nl+"<script>" + nl +
				   x  + nl +
				   "</script>" + nl )

		Func scriptredirection x
			return ' window.location = "' + x + '" ; '

		Func scriptfunc cFuncName,cCode
			cStr =  'function ' + cFuncName
			if right(cStr,1) != ")"
				cStr += '()'
			ok
			cStr += ' {' + nl + cCode +  nl + "}"
			return cStr


		Func scriptfuncalert cFuncName,cMsg
			cStr =  'function ' + cFuncName
			if right(cStr,1) != ")"
				cStr += '()'
			ok
			cStr += ' {' + nl + "alert('" + cMsg + "')" + nl + "}"
			return cStr

		Func scriptfuncajax cFuncName,cLink,cDiv
			return '
				function ' + cFuncName+ '()
				{					
					$("#' + cDiv + '").load("' + cLink + '");
				}
				'

		Func scriptfuncclean cFuncName,cDiv
			return '
				function ' + cFuncName+ '()
				{
					document.getElementById("' + cDiv + '").innerHTML = "" ;
				}
			       '

		Func scriptfuncselect cFuncName,aList,cDiv,cResult,cGridRow,cFuncClean,nTimeOut,cLink1,cLink2
			return '
				function ' + cFuncName + '(objid,recid,id) 
				{
					var x = document.getElementById(objid).value;
					document.getElementById(objid).value = "'+aList[1]+'";
					document.getElementById("'+cDiv+'").innerHTML="";

					if (x == "'+aList[3]+'") 
					{
						var mylink = "'+cLink2+'" + recid 	;					
						document.getElementById("'+cResult+'").innerHTML = ' + "'" + 
						'<object type="text/html" data='+ "'" + ' + mylink + " ></object>";' + '
					
						var element = document.getElementById("'+cGridRow+'"+id);
						element.parentNode.removeChild(element);

						setTimeout('+cFuncClean+','+nTimeOut+') ;
					}
					else if (x == "' + aList[2] + '") 
					{
						var mylink = "'+cLink1+'" + recid ; 						
						$("#mysubpage").load(mylink);					
					}
				}
				'

		Func ScriptScrollFixed cDiv,nSize
			cStr = `
			       $(window).scroll(function() { 
			       if($(this).scrollTop() > n1) { 
				         $( "#cDiv" ).css("position", "fixed");
					 $( "#cDiv" ).css("top", "0");
			       } else {
				         $( "#cDiv" ).css("position", "absolute");
					 $( "#cDiv" ).css("top", "n2");
				    }
			       });
			`

			cStr = substr(cStr,"cDiv",cDiv)
			# nSize can be number or string
			cStr = substr(cStr,"n1",""+nSize)	# "" to convert nSize to string
			cStr = substr(cStr,"n2",""+(0+nSize+1))	# 0+ to convert nSize to number

			return cStr
			
		Func newline 
			cOutput += nl+GetTabs()+"<br />"

		Func addattributes aPara

			aList = [ :class,:id,:name,:align,:style,:dir,:value,:onclick,:oncontextmenu,
				  :ondblclick,:onmousedown,:onmouseenter,:onmouseleave,
				  :onmousemove,:onmouseover,:onmouseout,:onmouseup,
				  :onkeydown,:onkeypress,:onkeyup,:onabort,:onbeforeunload,
				  :onerror,:onhashchange,:onload,:onpageshow,:onpagehide,
				  :onresize,:onscroll,:onunload,:onblur,:onchange,:onfocus,
				  :onfocusin,:onfocusout,:oninput,:oninvalid,:onreset,
				  :onsearch,:onselect,:onsubmit,:ondrag,:ondragend,:ondragenter,
				  :ondragleave,:ondragover,:ondragstart,:ondrop,:oncopy,:oncut,
				  :onpaste,:onafterprint,:onbeforeprint,:onabort,:oncanplay,
				  :oncanplaythrough,:ondurationchange,:onemptied,:onended,
				  :onerror,:onloadeddata,:onloadedmetadata,:onloadstart,
				  :onpause,:onplay,:onplaying,:onprogress,:onratechange,
				  :onseeked,:onseeking,:onstalled,:onsuspend,:ontimeupdate,
				  :onvolumechange,:onwaiting,:animationend,:animationiteration,
				  :animationstart,:transitionend, :onmessage, :onopen, 
				  :onmousewheel, :ononline, :onoffline, :onpostate, :onshow,
				  :onstorage, :ontoggle, :onwheel, :ontouchcancel, :ontouchend,
				  :ontouchmove, :ontouchstart ]
			
			for t in aPara
				for x in aList					
					if t[1] = x
						html( ' ' + lower(t[1]) + '="'+t[2]+'"')
						exit
					ok
				next
			next			
	
			
		Func link aPara
			html( nl + GetTabs() + "<a href='" )
			if aPara[:url] != NULL
				cOutput += aPara[:url] + "'"
			else
				cOutput += "'"
			ok
			addattributes(aPara)
			cOutput += "> "
			if aPara[:title] != NULL
				cOutput += aPara[:title]
			ok
			html( " </a> " )

		Func Image aPara
			cOutput += nl+GetTabs()+'<img'
			addattributes(aPara)
			if aPara["url"] != NULL
				cOutput += ' src="'+aPara["URL"]+'"'
			ok
			if aPara["alt"] != NULL
				cOutput += ' alt="'+aPara["Alt"]+'"'
			ok
			cOutput += '> '

		Func button aPara
			cOutput += nl+GetTabs()+'<input type="button"'
			addattributes(aPara)
			if aPara[:value] != NULL
				cOutput += ' value="'+aPara[:value]+'"'
			ok
			cOutput += '>'

		Func buttonlink aPara
			cOutput += nl+GetTabs()+'<input type="button"'
			addattributes(aPara)
			if aPara[:link] != NULL
				cOutput += ' onclick="window.location.href = '+"'"+aPara[:link]+"'"+'"'
			ok
			if aPara[:value] != NULL
				cOutput += ' value="'+aPara[:value]+'"'
			ok
			cOutput += '>'

		Func textbox aPara
			cOutput += nl+GetTabs()+'<input type="'
			if aPara[:type] != NULL
				cOutput += aPara[:type] + '"'
			else
				cOutput += 'text"'
			ok
			addattributes(aPara)
			cOutput += ' >' + nl

		Func editbox aPara
			cOutput += nl+GetTabs()+'<textarea '
			if aPara[:rows] != NULL
				cOutput += ' rows="'+ aPara[:rows] + '"'
			else
				cOutput += ' rows="4"'
			ok
			if aPara[:cols] != NULL
				cOutput += ' cols="'+ aPara[:cols] + '"'
			else
				cOutput += ' cols="50"'
			ok
			addattributes(aPara)
			cOutput += ' >' + nl 
			TabPush()
			if aPara[:value] != NULL
				cOutput += aPara[:value]
			ok
			TabPOP()
			cOutput += nl+GetTabs()+'</textarea>' + nl

		Func combobox aPara
			TabPush()
			cOutput += nl+GetTabs()+'<select '
			addattributes(aPara)
			cOutput += ">" + nl
			if islist(aPara[:items])

				for x in aPara[:items]	
  					cOutput += nl+GetTabs()+'<option>'+x+'</option>'
				next
				TabPOP()
			ok
			cOutput += nl+GetTabs()+"</select>" + nl

		Func listbox aPara
			cOutput += nl+GetTabs()+'<select '
			addattributes(aPara)
			cOutput += "multiple='multiple' >" + nl
			if islist(aPara[:items])
				for x in aPara[:items]	
  					cOutput += nl+GetTabs()+'<option>'+x+'</option>'
				next
			ok
			cOutput += "</select>" + nl

		Func tagstart x,aPara
			html( nl + GetTabs() + '<'+x+' ' )
			addattributes(aPara)
			html( '>' + nl )
			TabPush()

		Func tagend x
			TabPOP()
			html( nl + GetTabs() +'</'+x+'>' + nl )

		Func ulstart aPara
			tagstart("ul",aPara)

		Func ulend
			tagend("ul")

		Func listart aPara
			tagstart("li",aPara)

		Func liend
			tagend("li")

		Func List2UL aList
			ulstart([])
				for x in aList
					listart([])
						text(x)
					liend()
				next
			ulend()	

		Func divstart aPara
			html( nl + GetTabs() + '<div ' )
			addattributes(aPara)
			html( '>' + nl )
			TabPush()


		Func boxstart 
			html( nl + GetTabs() +'<div style="width:100% ; height:30px ; color: yellow ; background-color:black">' + nl)
			TabPush()

		Func divend
			TabPOP()
			html( nl + GetTabs() +'</div>' + nl )

		Func boxend
			divend()		

		Func formstart x
			if x = ""
				html( nl + GetTabs() +"<form>" + nl )
			else
				html( nl + GetTabs() +'<form action="' + x + '">' + nl )
			ok
			TabPush()


		Func formpost x
			if x = ""
				html( nl + GetTabs() +"<form>" + nl )
			else
				html( nl + GetTabs() +'<form action="' + x + '" method="post">' + nl )
			ok
			TabPush()

		Func formend
			TabPOP()
			html( nl + GetTabs() +"</form>" + nl )

		Func submit aPara
			cOutput += nl+GetTabs()+'<input type="submit" '
			addattributes(aPara)
			cOutput += '>' + nl
		
		Func hidden name,value
			cOutput += nl+GetTabs()+'<input type="hidden" name="' + name + '" value="' + value + '">' + nl

		Func formupload x
			if x = ""
				cOutput += nl+GetTabs()+"<form>" + nl
			else
				cOutput += nl+GetTabs()+'<form action="' + x + '" method="post" enctype="multipart/form-data">' + nl
			ok
			TabPush()
		
		Func uploadfile x
			cOutput += nl+GetTabs()+'<input type="file" name="'+x+'"/>'

		Func Video aPara
			cOutput += nl+GetTabs()+'<video '
			addattributes(aPara)
			if aPara[:width] != NULL
				cOutput += ' width="'+aPara[:width]+'"'
			ok
			if aPara[:height] != NULL
				cOutput += ' height="'+aPara[:height]+'"'
			ok
			cOutput +=' controls>' 
			if aPara[:file] != NULL
				cOutput += '<source src="'+aPara[:file]+'"'
			ok
			if aPara[:type] != NULL
				cOutput += ' type="'+aPara[:type]+'"' 
			ok
			cOutput += '> Your browser does not support the video tag. </video>' 

		Func Audio aPara
			cOutput += nl+GetTabs()+'<audio controls' 
			addattributes(aPara)
			cOutput += '> <source '
			if aPara[:file] != NULL
				cOutput += ' src="'+aPara[:file]+'"'
			ok
			if aPara[:type] != NULL
				cOutput += ' type="'+aPara[:type]+'"' 
			ok
			cOutput += '> Your browser does not support the audio element. </audio>'

		Func GetColor aPara
			cOutput += nl+GetTabs()+'<input' 
			addattributes(aPara)
			if aPara[:value] != NULL
				cOutput += ' value="' + aPara[:value] + '"'
			else
				cOutput += ' value="#ff0000"'
			ok				
			cOutput += 'onchange="clickColor(0, -1, -1, 5)" type="color">'

		Func Radio aPara
			cOutput += nl+GetTabs()+'<input type="radio"'
			addattributes(aPara)
			if aPara[:value] != Null
				cOutput += ' value="'+aPara[:value]+'"'
			ok
			if aPara[:status] != NULL
				cOutput += " checked"
			ok
			cOutput += '>'
			if aPara[:text] != NULL
				cOutput += aPara[:text]
			ok

		Func Checkbox aPara
			cOutput += nl+GetTabs()+'<input type="checkbox"'
			addattributes(aPara)
			if aPara[:value] != Null
				cOutput += ' value="'+aPara[:value]+'"'
			ok
			if aPara[:status] != NULL
				cOutput += " checked"
			ok
			cOutput += '>'
			if aPara[:text] != NULL
				cOutput += aPara[:text]
			ok

		Func Spinner aPara
			cOutput += nl+GetTabs()+'<input type="number"'
			addattributes(aPara)
			if aPara[:min] != NULL
				cOutput += ' min="'+aPara[:min]+'"'
			ok
			if aPara[:max] != NULL
				cOutput += ' max="'+aPara[:max]+'"'
			ok
			cOutput += '>' + nl

		Func Slider aPara
			cOutput += nl+GetTabs()+'<input type="range"'
			addattributes(aPara)
			if aPara[:min] != NULL
				cOutput += ' min="'+aPara[:min]+'"'
			ok
			if aPara[:max] != NULL
				cOutput += ' max="'+aPara[:max]+'"'
			ok
			cOutput += '>' + nl

		Func tablestart aPara
			cOutput += nl+GetTabs()+'<table '
			addattributes(aPara)
			cOutput += '>'
			TabPush()

		Func tableend
			TabPOP()
			cOutput += nl+GetTabs()+'</table>'

		Func rowstart aPara
			cOutput += nl+GetTabs()+'<tr '
			addattributes(aPara)
			cOutput += '>'
			TabPush()

		Func rowend
			TabPOP()
			cOutput += nl+GetTabs()+'</tr>'		

		Func cellstart aPara
			TabPush()
			cOutput += nl+GetTabs()+'<td '
			addattributes(aPara)
			cOutput += '>'

		Func cellend
			cOutput += nl+GetTabs()+"</td>" + nl
			TabPOP()

		Func headerstart aPara
			cOutput += nl+GetTabs()+'<th '
			addattributes(aPara)
			cOutput += '>'
			TabPush()

		Func headerend
			TabPOP()
			cOutput += nl+GetTabs()+"</th>" + nl

		Func braceend 
			print() 

	Class StyleFunctions

		Func StyleFloatLeft
			return " float: left ; "

		Func StyleFloatRight
			return " float: right ; "

		Func StyleSizeFull
			return " width: 100% ; height: 100% ;"

		Func Stylecolor x
			return " color: " + x + " ; "	

		Func Stylebackcolor x
			return " background-color: " + x + " ;"

		Func StyleTextCenter 
			return "text-align: center ;"	

		Func StyleTextRight 
			return "text-align: right ;"	

		Func StyleTextLeft
			return "text-align: left ;"	

		Func StyleSize x,y 
			return " width: " + x + " ; height: " + y + " ;" 

		Func StyleWidth x
			return " width: " + x + " ;"

		Func StyleHeight x
			return " height: " + x + " ;"

		Func StyleTop x
			return " top: " + x + " ;"

		Func StyleLeft x
			return " Left: " + x + " ;"

		Func StylePos x,y
			return " top: " + x + " ;" + " Left: " + y + " ;"

		Func StyleHorizontalCenter
			return " margin-right:auto ; margin-left:auto; "

		Func StyleMarginTop x
			return " margin-top: " + x + " ;"

		Func StyleMarginRight x
			return " margin-right: " + x + " ;"

		Func StyleMarginLeft x
			return " margin-left: " + x + " ;"

		Func StyleDivCenter nWidth,nHeight
			return "width:"+nWidth+";height:"+nHeight+";margin:auto;position:absolute;top:0;bottom:0;
				left:0;right:0; max-width:100%; max-height:100%; overflow:auto;"

		Func StyleAbsolute
			return " position:absolute ;"

		Func StyleFixed
			return " position:fixed ;"

		Func StyleZIndex x
			return " z-index: " + x + " ;"

		Func StyleFontSize x
			return  " font-size: " + x + " ;"
		
		Func StyleGradient x

			# Credits : the next styles from : http://www.colorzilla.com/gradient-editor/

			switch x 
			on 1	
				return TabMLString("background: rgb(30,87,153); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(30,87,153,1) 0%, rgba(41,137,216,1) 50%, rgba(32,124,202,1) 51%, rgba(125,185,232,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(30,87,153,1)), color-stop(50%,rgba(41,137,216,1)), color-stop(51%,rgba(32,124,202,1)), color-stop(100%,rgba(125,185,232,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(30,87,153,1) 0%,rgba(41,137,216,1) 50%,rgba(32,124,202,1) 51%,rgba(125,185,232,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(30,87,153,1) 0%,rgba(41,137,216,1) 50%,rgba(32,124,202,1) 51%,rgba(125,185,232,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(30,87,153,1) 0%,rgba(41,137,216,1) 50%,rgba(32,124,202,1) 51%,rgba(125,185,232,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(30,87,153,1) 0%,rgba(41,137,216,1) 50%,rgba(32,124,202,1) 51%,rgba(125,185,232,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#1e5799', endColorstr='#7db9e8',GradientType=0 ); /* IE6-9 */")

			on 2
				return TabMLString("background: rgb(76,76,76); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(76,76,76,1) 0%, rgba(89,89,89,1) 12%, rgba(102,102,102,1) 25%, rgba(71,71,71,1) 39%, rgba(44,44,44,1) 50%, rgba(0,0,0,1) 51%, rgba(17,17,17,1) 60%, rgba(43,43,43,1) 76%, rgba(28,28,28,1) 91%, rgba(19,19,19,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(76,76,76,1)), color-stop(12%,rgba(89,89,89,1)), color-stop(25%,rgba(102,102,102,1)), color-stop(39%,rgba(71,71,71,1)), color-stop(50%,rgba(44,44,44,1)), color-stop(51%,rgba(0,0,0,1)), color-stop(60%,rgba(17,17,17,1)), color-stop(76%,rgba(43,43,43,1)), color-stop(91%,rgba(28,28,28,1)), color-stop(100%,rgba(19,19,19,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(76,76,76,1) 0%,rgba(89,89,89,1) 12%,rgba(102,102,102,1) 25%,rgba(71,71,71,1) 39%,rgba(44,44,44,1) 50%,rgba(0,0,0,1) 51%,rgba(17,17,17,1) 60%,rgba(43,43,43,1) 76%,rgba(28,28,28,1) 91%,rgba(19,19,19,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(76,76,76,1) 0%,rgba(89,89,89,1) 12%,rgba(102,102,102,1) 25%,rgba(71,71,71,1) 39%,rgba(44,44,44,1) 50%,rgba(0,0,0,1) 51%,rgba(17,17,17,1) 60%,rgba(43,43,43,1) 76%,rgba(28,28,28,1) 91%,rgba(19,19,19,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(76,76,76,1) 0%,rgba(89,89,89,1) 12%,rgba(102,102,102,1) 25%,rgba(71,71,71,1) 39%,rgba(44,44,44,1) 50%,rgba(0,0,0,1) 51%,rgba(17,17,17,1) 60%,rgba(43,43,43,1) 76%,rgba(28,28,28,1) 91%,rgba(19,19,19,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(76,76,76,1) 0%,rgba(89,89,89,1) 12%,rgba(102,102,102,1) 25%,rgba(71,71,71,1) 39%,rgba(44,44,44,1) 50%,rgba(0,0,0,1) 51%,rgba(17,17,17,1) 60%,rgba(43,43,43,1) 76%,rgba(28,28,28,1) 91%,rgba(19,19,19,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#4c4c4c', endColorstr='#131313',GradientType=0 ); /* IE6-9 */")

			on 3
				return TabMLString("background: rgb(135,224,253); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(135,224,253,1) 0%, rgba(83,203,241,1) 40%, rgba(5,171,224,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(135,224,253,1)), color-stop(40%,rgba(83,203,241,1)), color-stop(100%,rgba(5,171,224,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(135,224,253,1) 0%,rgba(83,203,241,1) 40%,rgba(5,171,224,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(135,224,253,1) 0%,rgba(83,203,241,1) 40%,rgba(5,171,224,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(135,224,253,1) 0%,rgba(83,203,241,1) 40%,rgba(5,171,224,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(135,224,253,1) 0%,rgba(83,203,241,1) 40%,rgba(5,171,224,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#87e0fd', endColorstr='#05abe0',GradientType=0 ); /* IE6-9 */")

			on 4 
				return TabMLString("background: rgb(240,249,255); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(240,249,255,1) 0%, rgba(203,235,255,1) 47%, rgba(161,219,255,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(240,249,255,1)), color-stop(47%,rgba(203,235,255,1)), color-stop(100%,rgba(161,219,255,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(240,249,255,1) 0%,rgba(203,235,255,1) 47%,rgba(161,219,255,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(240,249,255,1) 0%,rgba(203,235,255,1) 47%,rgba(161,219,255,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(240,249,255,1) 0%,rgba(203,235,255,1) 47%,rgba(161,219,255,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(240,249,255,1) 0%,rgba(203,235,255,1) 47%,rgba(161,219,255,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#f0f9ff', endColorstr='#a1dbff',GradientType=0 ); /* IE6-9 */")

			on 5 
				return TabMLString("background: rgb(122,188,255); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(122,188,255,1) 0%, rgba(96,171,248,1) 44%, rgba(64,150,238,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(122,188,255,1)), color-stop(44%,rgba(96,171,248,1)), color-stop(100%,rgba(64,150,238,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(122,188,255,1) 0%,rgba(96,171,248,1) 44%,rgba(64,150,238,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(122,188,255,1) 0%,rgba(96,171,248,1) 44%,rgba(64,150,238,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(122,188,255,1) 0%,rgba(96,171,248,1) 44%,rgba(64,150,238,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(122,188,255,1) 0%,rgba(96,171,248,1) 44%,rgba(64,150,238,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#7abcff', endColorstr='#4096ee',GradientType=0 ); /* IE6-9 */")

			on 6
				return TabMLString("background: -moz-linear-gradient(top,  rgba(30,87,153,1) 0%, rgba(125,185,232,0) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(30,87,153,1)), color-stop(100%,rgba(125,185,232,0))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(30,87,153,1) 0%,rgba(125,185,232,0) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(30,87,153,1) 0%,rgba(125,185,232,0) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(30,87,153,1) 0%,rgba(125,185,232,0) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(30,87,153,1) 0%,rgba(125,185,232,0) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#1e5799', endColorstr='#007db9e8',GradientType=0 ); /* IE6-9 */")

			on 7
				return TabMLString("background: -moz-linear-gradient(top,  rgba(30,87,153,1) 0%, rgba(89,148,202,1) 62%, rgba(95,154,207,0.7) 68%, rgba(125,185,232,0) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(30,87,153,1)), color-stop(62%,rgba(89,148,202,1)), color-stop(68%,rgba(95,154,207,0.7)), color-stop(100%,rgba(125,185,232,0))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(30,87,153,1) 0%,rgba(89,148,202,1) 62%,rgba(95,154,207,0.7) 68%,rgba(125,185,232,0) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(30,87,153,1) 0%,rgba(89,148,202,1) 62%,rgba(95,154,207,0.7) 68%,rgba(125,185,232,0) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(30,87,153,1) 0%,rgba(89,148,202,1) 62%,rgba(95,154,207,0.7) 68%,rgba(125,185,232,0) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(30,87,153,1) 0%,rgba(89,148,202,1) 62%,rgba(95,154,207,0.7) 68%,rgba(125,185,232,0) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#1e5799', endColorstr='#007db9e8',GradientType=0 ); /* IE6-9 */")

			on 8
				return TabMLString("background: -moz-linear-gradient(top,  rgba(30,87,153,0) 0%, rgba(30,87,153,0.8) 15%, rgba(30,87,153,1) 19%, rgba(30,87,153,1) 20%, rgba(41,137,216,1) 50%, rgba(30,87,153,1) 80%, rgba(30,87,153,1) 81%, rgba(30,87,153,0.8) 85%, rgba(30,87,153,0) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(30,87,153,0)), color-stop(15%,rgba(30,87,153,0.8)), color-stop(19%,rgba(30,87,153,1)), color-stop(20%,rgba(30,87,153,1)), color-stop(50%,rgba(41,137,216,1)), color-stop(80%,rgba(30,87,153,1)), color-stop(81%,rgba(30,87,153,1)), color-stop(85%,rgba(30,87,153,0.8)), color-stop(100%,rgba(30,87,153,0))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(30,87,153,0) 0%,rgba(30,87,153,0.8) 15%,rgba(30,87,153,1) 19%,rgba(30,87,153,1) 20%,rgba(41,137,216,1) 50%,rgba(30,87,153,1) 80%,rgba(30,87,153,1) 81%,rgba(30,87,153,0.8) 85%,rgba(30,87,153,0) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(30,87,153,0) 0%,rgba(30,87,153,0.8) 15%,rgba(30,87,153,1) 19%,rgba(30,87,153,1) 20%,rgba(41,137,216,1) 50%,rgba(30,87,153,1) 80%,rgba(30,87,153,1) 81%,rgba(30,87,153,0.8) 85%,rgba(30,87,153,0) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(30,87,153,0) 0%,rgba(30,87,153,0.8) 15%,rgba(30,87,153,1) 19%,rgba(30,87,153,1) 20%,rgba(41,137,216,1) 50%,rgba(30,87,153,1) 80%,rgba(30,87,153,1) 81%,rgba(30,87,153,0.8) 85%,rgba(30,87,153,0) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(30,87,153,0) 0%,rgba(30,87,153,0.8) 15%,rgba(30,87,153,1) 19%,rgba(30,87,153,1) 20%,rgba(41,137,216,1) 50%,rgba(30,87,153,1) 80%,rgba(30,87,153,1) 81%,rgba(30,87,153,0.8) 85%,rgba(30,87,153,0) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#001e5799', endColorstr='#001e5799',GradientType=0 ); /* IE6-9 */")

			on 9
				return TabMLString("background: -moz-linear-gradient(top,  rgba(0,0,0,0.65) 0%, rgba(0,0,0,0) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(0,0,0,0.65)), color-stop(100%,rgba(0,0,0,0))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(0,0,0,0.65) 0%,rgba(0,0,0,0) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(0,0,0,0.65) 0%,rgba(0,0,0,0) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(0,0,0,0.65) 0%,rgba(0,0,0,0) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(0,0,0,0.65) 0%,rgba(0,0,0,0) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#a6000000', endColorstr='#00000000',GradientType=0 ); /* IE6-9 */")

			on 10
				return TabMLString("background: -moz-linear-gradient(top,  rgba(255,255,255,1) 0%, rgba(255,255,255,0) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(255,255,255,1)), color-stop(100%,rgba(255,255,255,0))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(255,255,255,1) 0%,rgba(255,255,255,0) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(255,255,255,1) 0%,rgba(255,255,255,0) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(255,255,255,1) 0%,rgba(255,255,255,0) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(255,255,255,1) 0%,rgba(255,255,255,0) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#ffffff', endColorstr='#00ffffff',GradientType=0 ); /* IE6-9 */")
	
			on 11
				return TabMLString("background: rgb(0,183,234); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(0,183,234,1) 0%, rgba(0,158,195,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(0,183,234,1)), color-stop(100%,rgba(0,158,195,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(0,183,234,1) 0%,rgba(0,158,195,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(0,183,234,1) 0%,rgba(0,158,195,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(0,183,234,1) 0%,rgba(0,158,195,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(0,183,234,1) 0%,rgba(0,158,195,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#00b7ea', endColorstr='#009ec3',GradientType=0 ); /* IE6-9 */")

			on 12
				return TabMLString("background: rgb(136,191,232); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(136,191,232,1) 0%, rgba(112,176,224,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(136,191,232,1)), color-stop(100%,rgba(112,176,224,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(136,191,232,1) 0%,rgba(112,176,224,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(136,191,232,1) 0%,rgba(112,176,224,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(136,191,232,1) 0%,rgba(112,176,224,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(136,191,232,1) 0%,rgba(112,176,224,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#88bfe8', endColorstr='#70b0e0',GradientType=0 ); /* IE6-9 */")

			on 13
				return TabMLString("background: rgb(254,255,255); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(254,255,255,1) 0%, rgba(221,241,249,1) 35%, rgba(160,216,239,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(254,255,255,1)), color-stop(35%,rgba(221,241,249,1)), color-stop(100%,rgba(160,216,239,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(254,255,255,1) 0%,rgba(221,241,249,1) 35%,rgba(160,216,239,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(254,255,255,1) 0%,rgba(221,241,249,1) 35%,rgba(160,216,239,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(254,255,255,1) 0%,rgba(221,241,249,1) 35%,rgba(160,216,239,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(254,255,255,1) 0%,rgba(221,241,249,1) 35%,rgba(160,216,239,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#feffff', endColorstr='#a0d8ef',GradientType=0 ); /* IE6-9 */")

			on 14 
				return TabMLString("background: rgb(37,141,200); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(37,141,200,1) 0%, rgba(37,141,200,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(37,141,200,1)), color-stop(100%,rgba(37,141,200,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(37,141,200,1) 0%,rgba(37,141,200,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(37,141,200,1) 0%,rgba(37,141,200,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(37,141,200,1) 0%,rgba(37,141,200,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(37,141,200,1) 0%,rgba(37,141,200,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#258dc8', endColorstr='#258dc8',GradientType=0 ); /* IE6-9 */")

			on 15
				return TabMLString("background: rgb(64,150,238); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(64,150,238,1) 0%, rgba(64,150,238,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(64,150,238,1)), color-stop(100%,rgba(64,150,238,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(64,150,238,1) 0%,rgba(64,150,238,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(64,150,238,1) 0%,rgba(64,150,238,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(64,150,238,1) 0%,rgba(64,150,238,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(64,150,238,1) 0%,rgba(64,150,238,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#4096ee', endColorstr='#4096ee',GradientType=0 ); /* IE6-9 */")

			on 16
				return TabMLString("background: rgb(184,225,252); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(184,225,252,1) 0%, rgba(169,210,243,1) 10%, rgba(144,186,228,1) 25%, rgba(144,188,234,1) 37%, rgba(144,191,240,1) 50%, rgba(107,168,229,1) 51%, rgba(162,218,245,1) 83%, rgba(189,243,253,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(184,225,252,1)), color-stop(10%,rgba(169,210,243,1)), color-stop(25%,rgba(144,186,228,1)), color-stop(37%,rgba(144,188,234,1)), color-stop(50%,rgba(144,191,240,1)), color-stop(51%,rgba(107,168,229,1)), color-stop(83%,rgba(162,218,245,1)), color-stop(100%,rgba(189,243,253,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(184,225,252,1) 0%,rgba(169,210,243,1) 10%,rgba(144,186,228,1) 25%,rgba(144,188,234,1) 37%,rgba(144,191,240,1) 50%,rgba(107,168,229,1) 51%,rgba(162,218,245,1) 83%,rgba(189,243,253,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(184,225,252,1) 0%,rgba(169,210,243,1) 10%,rgba(144,186,228,1) 25%,rgba(144,188,234,1) 37%,rgba(144,191,240,1) 50%,rgba(107,168,229,1) 51%,rgba(162,218,245,1) 83%,rgba(189,243,253,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(184,225,252,1) 0%,rgba(169,210,243,1) 10%,rgba(144,186,228,1) 25%,rgba(144,188,234,1) 37%,rgba(144,191,240,1) 50%,rgba(107,168,229,1) 51%,rgba(162,218,245,1) 83%,rgba(189,243,253,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(184,225,252,1) 0%,rgba(169,210,243,1) 10%,rgba(144,186,228,1) 25%,rgba(144,188,234,1) 37%,rgba(144,191,240,1) 50%,rgba(107,168,229,1) 51%,rgba(162,218,245,1) 83%,rgba(189,243,253,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#b8e1fc', endColorstr='#bdf3fd',GradientType=0 ); /* IE6-9 */")

			on 17
				return TabMLString("background: rgb(59,103,158); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(59,103,158,1) 0%, rgba(43,136,217,1) 50%, rgba(32,124,202,1) 51%, rgba(125,185,232,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(59,103,158,1)), color-stop(50%,rgba(43,136,217,1)), color-stop(51%,rgba(32,124,202,1)), color-stop(100%,rgba(125,185,232,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(59,103,158,1) 0%,rgba(43,136,217,1) 50%,rgba(32,124,202,1) 51%,rgba(125,185,232,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(59,103,158,1) 0%,rgba(43,136,217,1) 50%,rgba(32,124,202,1) 51%,rgba(125,185,232,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(59,103,158,1) 0%,rgba(43,136,217,1) 50%,rgba(32,124,202,1) 51%,rgba(125,185,232,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(59,103,158,1) 0%,rgba(43,136,217,1) 50%,rgba(32,124,202,1) 51%,rgba(125,185,232,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#3b679e', endColorstr='#7db9e8',GradientType=0 ); /* IE6-9 */")

			on 18
				return TabMLString("background: rgb(109,179,242); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(109,179,242,1) 0%, rgba(84,163,238,1) 50%, rgba(54,144,240,1) 51%, rgba(30,105,222,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(109,179,242,1)), color-stop(50%,rgba(84,163,238,1)), color-stop(51%,rgba(54,144,240,1)), color-stop(100%,rgba(30,105,222,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(109,179,242,1) 0%,rgba(84,163,238,1) 50%,rgba(54,144,240,1) 51%,rgba(30,105,222,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(109,179,242,1) 0%,rgba(84,163,238,1) 50%,rgba(54,144,240,1) 51%,rgba(30,105,222,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(109,179,242,1) 0%,rgba(84,163,238,1) 50%,rgba(54,144,240,1) 51%,rgba(30,105,222,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(109,179,242,1) 0%,rgba(84,163,238,1) 50%,rgba(54,144,240,1) 51%,rgba(30,105,222,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#6db3f2', endColorstr='#1e69de',GradientType=0 ); /* IE6-9 */")

			on 19
				return TabMLString("background: rgb(235,241,246); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(235,241,246,1) 0%, rgba(171,211,238,1) 50%, rgba(137,195,235,1) 51%, rgba(213,235,251,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(235,241,246,1)), color-stop(50%,rgba(171,211,238,1)), color-stop(51%,rgba(137,195,235,1)), color-stop(100%,rgba(213,235,251,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(235,241,246,1) 0%,rgba(171,211,238,1) 50%,rgba(137,195,235,1) 51%,rgba(213,235,251,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(235,241,246,1) 0%,rgba(171,211,238,1) 50%,rgba(137,195,235,1) 51%,rgba(213,235,251,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(235,241,246,1) 0%,rgba(171,211,238,1) 50%,rgba(137,195,235,1) 51%,rgba(213,235,251,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(235,241,246,1) 0%,rgba(171,211,238,1) 50%,rgba(137,195,235,1) 51%,rgba(213,235,251,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#ebf1f6', endColorstr='#d5ebfb',GradientType=0 ); /* IE6-9 */")

			on 20
				return TabMLString("background: rgb(228,245,252); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(228,245,252,1) 0%, rgba(191,232,249,1) 50%, rgba(159,216,239,1) 51%, rgba(42,176,237,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(228,245,252,1)), color-stop(50%,rgba(191,232,249,1)), color-stop(51%,rgba(159,216,239,1)), color-stop(100%,rgba(42,176,237,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(228,245,252,1) 0%,rgba(191,232,249,1) 50%,rgba(159,216,239,1) 51%,rgba(42,176,237,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(228,245,252,1) 0%,rgba(191,232,249,1) 50%,rgba(159,216,239,1) 51%,rgba(42,176,237,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(228,245,252,1) 0%,rgba(191,232,249,1) 50%,rgba(159,216,239,1) 51%,rgba(42,176,237,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(228,245,252,1) 0%,rgba(191,232,249,1) 50%,rgba(159,216,239,1) 51%,rgba(42,176,237,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#e4f5fc', endColorstr='#2ab0ed',GradientType=0 ); /* IE6-9 */")

			on 21
				return TabMLString("background: rgb(206,219,233); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(206,219,233,1) 0%, rgba(170,197,222,1) 17%, rgba(97,153,199,1) 50%, rgba(58,132,195,1) 51%, rgba(65,154,214,1) 59%, rgba(75,184,240,1) 71%, rgba(58,139,194,1) 84%, rgba(38,85,139,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(206,219,233,1)), color-stop(17%,rgba(170,197,222,1)), color-stop(50%,rgba(97,153,199,1)), color-stop(51%,rgba(58,132,195,1)), color-stop(59%,rgba(65,154,214,1)), color-stop(71%,rgba(75,184,240,1)), color-stop(84%,rgba(58,139,194,1)), color-stop(100%,rgba(38,85,139,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(206,219,233,1) 0%,rgba(170,197,222,1) 17%,rgba(97,153,199,1) 50%,rgba(58,132,195,1) 51%,rgba(65,154,214,1) 59%,rgba(75,184,240,1) 71%,rgba(58,139,194,1) 84%,rgba(38,85,139,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(206,219,233,1) 0%,rgba(170,197,222,1) 17%,rgba(97,153,199,1) 50%,rgba(58,132,195,1) 51%,rgba(65,154,214,1) 59%,rgba(75,184,240,1) 71%,rgba(58,139,194,1) 84%,rgba(38,85,139,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(206,219,233,1) 0%,rgba(170,197,222,1) 17%,rgba(97,153,199,1) 50%,rgba(58,132,195,1) 51%,rgba(65,154,214,1) 59%,rgba(75,184,240,1) 71%,rgba(58,139,194,1) 84%,rgba(38,85,139,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(206,219,233,1) 0%,rgba(170,197,222,1) 17%,rgba(97,153,199,1) 50%,rgba(58,132,195,1) 51%,rgba(65,154,214,1) 59%,rgba(75,184,240,1) 71%,rgba(58,139,194,1) 84%,rgba(38,85,139,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#cedbe9', endColorstr='#26558b',GradientType=0 ); /* IE6-9 */")

			on 22
				return TabMLString("background: rgb(167,199,220); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(167,199,220,1) 0%, rgba(133,178,211,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(167,199,220,1)), color-stop(100%,rgba(133,178,211,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(167,199,220,1) 0%,rgba(133,178,211,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(167,199,220,1) 0%,rgba(133,178,211,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(167,199,220,1) 0%,rgba(133,178,211,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(167,199,220,1) 0%,rgba(133,178,211,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#a7c7dc', endColorstr='#85b2d3',GradientType=0 ); /* IE6-9 */")

			on 23
				return TabMLString("background: rgb(63,76,107); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(63,76,107,1) 0%, rgba(63,76,107,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(63,76,107,1)), color-stop(100%,rgba(63,76,107,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(63,76,107,1) 0%,rgba(63,76,107,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(63,76,107,1) 0%,rgba(63,76,107,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(63,76,107,1) 0%,rgba(63,76,107,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(63,76,107,1) 0%,rgba(63,76,107,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#3f4c6b', endColorstr='#3f4c6b',GradientType=0 ); /* IE6-9 */")
	
			on 24
				return TabMLString("background: rgb(208,228,247); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(208,228,247,1) 0%, rgba(115,177,231,1) 24%, rgba(10,119,213,1) 50%, rgba(83,159,225,1) 79%, rgba(135,188,234,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(208,228,247,1)), color-stop(24%,rgba(115,177,231,1)), color-stop(50%,rgba(10,119,213,1)), color-stop(79%,rgba(83,159,225,1)), color-stop(100%,rgba(135,188,234,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(208,228,247,1) 0%,rgba(115,177,231,1) 24%,rgba(10,119,213,1) 50%,rgba(83,159,225,1) 79%,rgba(135,188,234,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(208,228,247,1) 0%,rgba(115,177,231,1) 24%,rgba(10,119,213,1) 50%,rgba(83,159,225,1) 79%,rgba(135,188,234,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(208,228,247,1) 0%,rgba(115,177,231,1) 24%,rgba(10,119,213,1) 50%,rgba(83,159,225,1) 79%,rgba(135,188,234,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(208,228,247,1) 0%,rgba(115,177,231,1) 24%,rgba(10,119,213,1) 50%,rgba(83,159,225,1) 79%,rgba(135,188,234,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#d0e4f7', endColorstr='#87bcea',GradientType=0 ); /* IE6-9 */")

			on 25
				return TabMLString("background: rgb(225,255,255); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(225,255,255,1) 0%, rgba(225,255,255,1) 7%, rgba(225,255,255,1) 12%, rgba(253,255,255,1) 12%, rgba(230,248,253,1) 30%, rgba(200,238,251,1) 54%, rgba(190,228,248,1) 75%, rgba(177,216,245,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(225,255,255,1)), color-stop(7%,rgba(225,255,255,1)), color-stop(12%,rgba(225,255,255,1)), color-stop(12%,rgba(253,255,255,1)), color-stop(30%,rgba(230,248,253,1)), color-stop(54%,rgba(200,238,251,1)), color-stop(75%,rgba(190,228,248,1)), color-stop(100%,rgba(177,216,245,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(225,255,255,1) 0%,rgba(225,255,255,1) 7%,rgba(225,255,255,1) 12%,rgba(253,255,255,1) 12%,rgba(230,248,253,1) 30%,rgba(200,238,251,1) 54%,rgba(190,228,248,1) 75%,rgba(177,216,245,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(225,255,255,1) 0%,rgba(225,255,255,1) 7%,rgba(225,255,255,1) 12%,rgba(253,255,255,1) 12%,rgba(230,248,253,1) 30%,rgba(200,238,251,1) 54%,rgba(190,228,248,1) 75%,rgba(177,216,245,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(225,255,255,1) 0%,rgba(225,255,255,1) 7%,rgba(225,255,255,1) 12%,rgba(253,255,255,1) 12%,rgba(230,248,253,1) 30%,rgba(200,238,251,1) 54%,rgba(190,228,248,1) 75%,rgba(177,216,245,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(225,255,255,1) 0%,rgba(225,255,255,1) 7%,rgba(225,255,255,1) 12%,rgba(253,255,255,1) 12%,rgba(230,248,253,1) 30%,rgba(200,238,251,1) 54%,rgba(190,228,248,1) 75%,rgba(177,216,245,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#e1ffff', endColorstr='#b1d8f5',GradientType=0 ); /* IE6-9 */")

			on 26
				return TabMLString("background: rgb(179,220,237); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(179,220,237,1) 0%, rgba(41,184,229,1) 50%, rgba(188,224,238,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(179,220,237,1)), color-stop(50%,rgba(41,184,229,1)), color-stop(100%,rgba(188,224,238,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(179,220,237,1) 0%,rgba(41,184,229,1) 50%,rgba(188,224,238,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(179,220,237,1) 0%,rgba(41,184,229,1) 50%,rgba(188,224,238,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(179,220,237,1) 0%,rgba(41,184,229,1) 50%,rgba(188,224,238,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(179,220,237,1) 0%,rgba(41,184,229,1) 50%,rgba(188,224,238,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#b3dced', endColorstr='#bce0ee',GradientType=0 ); /* IE6-9 */")

			on 27
				return TabMLString("background: rgb(213,206,166); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(213,206,166,1) 0%, rgba(201,193,144,1) 40%, rgba(183,173,112,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(213,206,166,1)), color-stop(40%,rgba(201,193,144,1)), color-stop(100%,rgba(183,173,112,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(213,206,166,1) 0%,rgba(201,193,144,1) 40%,rgba(183,173,112,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(213,206,166,1) 0%,rgba(201,193,144,1) 40%,rgba(183,173,112,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(213,206,166,1) 0%,rgba(201,193,144,1) 40%,rgba(183,173,112,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(213,206,166,1) 0%,rgba(201,193,144,1) 40%,rgba(183,173,112,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#d5cea6', endColorstr='#b7ad70',GradientType=0 ); /* IE6-9 */")

			on 28 
				return TabMLString("background: rgb(240,183,161); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(240,183,161,1) 0%, rgba(140,51,16,1) 50%, rgba(117,34,1,1) 51%, rgba(191,110,78,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(240,183,161,1)), color-stop(50%,rgba(140,51,16,1)), color-stop(51%,rgba(117,34,1,1)), color-stop(100%,rgba(191,110,78,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(240,183,161,1) 0%,rgba(140,51,16,1) 50%,rgba(117,34,1,1) 51%,rgba(191,110,78,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(240,183,161,1) 0%,rgba(140,51,16,1) 50%,rgba(117,34,1,1) 51%,rgba(191,110,78,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(240,183,161,1) 0%,rgba(140,51,16,1) 50%,rgba(117,34,1,1) 51%,rgba(191,110,78,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(240,183,161,1) 0%,rgba(140,51,16,1) 50%,rgba(117,34,1,1) 51%,rgba(191,110,78,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#f0b7a1', endColorstr='#bf6e4e',GradientType=0 ); /* IE6-9 */")

			on 29
				return TabMLString("background: rgb(169,3,41); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(169,3,41,1) 0%, rgba(143,2,34,1) 44%, rgba(109,0,25,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(169,3,41,1)), color-stop(44%,rgba(143,2,34,1)), color-stop(100%,rgba(109,0,25,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(169,3,41,1) 0%,rgba(143,2,34,1) 44%,rgba(109,0,25,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(169,3,41,1) 0%,rgba(143,2,34,1) 44%,rgba(109,0,25,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(169,3,41,1) 0%,rgba(143,2,34,1) 44%,rgba(109,0,25,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(169,3,41,1) 0%,rgba(143,2,34,1) 44%,rgba(109,0,25,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#a90329', endColorstr='#6d0019',GradientType=0 ); /* IE6-9 */")

			on 30
				return TabMLString("background: rgb(254,252,234); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(254,252,234,1) 0%, rgba(241,218,54,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(254,252,234,1)), color-stop(100%,rgba(241,218,54,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(254,252,234,1) 0%,rgba(241,218,54,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(254,252,234,1) 0%,rgba(241,218,54,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(254,252,234,1) 0%,rgba(241,218,54,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(254,252,234,1) 0%,rgba(241,218,54,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#fefcea', endColorstr='#f1da36',GradientType=0 ); /* IE6-9 */")

			on 31
				return TabMLString("background: rgb(180,221,180); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(180,221,180,1) 0%, rgba(131,199,131,1) 17%, rgba(82,177,82,1) 33%, rgba(0,138,0,1) 67%, rgba(0,87,0,1) 83%, rgba(0,36,0,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(180,221,180,1)), color-stop(17%,rgba(131,199,131,1)), color-stop(33%,rgba(82,177,82,1)), color-stop(67%,rgba(0,138,0,1)), color-stop(83%,rgba(0,87,0,1)), color-stop(100%,rgba(0,36,0,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(180,221,180,1) 0%,rgba(131,199,131,1) 17%,rgba(82,177,82,1) 33%,rgba(0,138,0,1) 67%,rgba(0,87,0,1) 83%,rgba(0,36,0,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(180,221,180,1) 0%,rgba(131,199,131,1) 17%,rgba(82,177,82,1) 33%,rgba(0,138,0,1) 67%,rgba(0,87,0,1) 83%,rgba(0,36,0,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(180,221,180,1) 0%,rgba(131,199,131,1) 17%,rgba(82,177,82,1) 33%,rgba(0,138,0,1) 67%,rgba(0,87,0,1) 83%,rgba(0,36,0,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(180,221,180,1) 0%,rgba(131,199,131,1) 17%,rgba(82,177,82,1) 33%,rgba(0,138,0,1) 67%,rgba(0,87,0,1) 83%,rgba(0,36,0,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#b4ddb4', endColorstr='#002400',GradientType=0 ); /* IE6-9 */")

			on 32
				return TabMLString("background: rgb(205,235,142); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(205,235,142,1) 0%, rgba(165,201,86,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(205,235,142,1)), color-stop(100%,rgba(165,201,86,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(205,235,142,1) 0%,rgba(165,201,86,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(205,235,142,1) 0%,rgba(165,201,86,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(205,235,142,1) 0%,rgba(165,201,86,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(205,235,142,1) 0%,rgba(165,201,86,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#cdeb8e', endColorstr='#a5c956',GradientType=0 ); /* IE6-9 */")

			on 33
				return TabMLString("background: rgb(201,222,150); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(201,222,150,1) 0%, rgba(138,182,107,1) 44%, rgba(57,130,53,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(201,222,150,1)), color-stop(44%,rgba(138,182,107,1)), color-stop(100%,rgba(57,130,53,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(201,222,150,1) 0%,rgba(138,182,107,1) 44%,rgba(57,130,53,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(201,222,150,1) 0%,rgba(138,182,107,1) 44%,rgba(57,130,53,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(201,222,150,1) 0%,rgba(138,182,107,1) 44%,rgba(57,130,53,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(201,222,150,1) 0%,rgba(138,182,107,1) 44%,rgba(57,130,53,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#c9de96', endColorstr='#398235',GradientType=0 ); /* IE6-9 */")

			on 34 
				return TabMLString("background: rgb(248,255,232); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(248,255,232,1) 0%, rgba(227,245,171,1) 33%, rgba(183,223,45,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(248,255,232,1)), color-stop(33%,rgba(227,245,171,1)), color-stop(100%,rgba(183,223,45,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(248,255,232,1) 0%,rgba(227,245,171,1) 33%,rgba(183,223,45,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(248,255,232,1) 0%,rgba(227,245,171,1) 33%,rgba(183,223,45,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(248,255,232,1) 0%,rgba(227,245,171,1) 33%,rgba(183,223,45,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(248,255,232,1) 0%,rgba(227,245,171,1) 33%,rgba(183,223,45,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#f8ffe8', endColorstr='#b7df2d',GradientType=0 ); /* IE6-9 */")

			on 35
				return TabMLString("background: rgb(169,219,128); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(169,219,128,1) 0%, rgba(150,197,111,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(169,219,128,1)), color-stop(100%,rgba(150,197,111,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(169,219,128,1) 0%,rgba(150,197,111,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(169,219,128,1) 0%,rgba(150,197,111,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(169,219,128,1) 0%,rgba(150,197,111,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(169,219,128,1) 0%,rgba(150,197,111,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#a9db80', endColorstr='#96c56f',GradientType=0 ); /* IE6-9 */")

			on 36
				return TabMLString("background: rgb(180,227,145); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(180,227,145,1) 0%, rgba(97,196,25,1) 50%, rgba(180,227,145,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(180,227,145,1)), color-stop(50%,rgba(97,196,25,1)), color-stop(100%,rgba(180,227,145,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(180,227,145,1) 0%,rgba(97,196,25,1) 50%,rgba(180,227,145,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(180,227,145,1) 0%,rgba(97,196,25,1) 50%,rgba(180,227,145,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(180,227,145,1) 0%,rgba(97,196,25,1) 50%,rgba(180,227,145,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(180,227,145,1) 0%,rgba(97,196,25,1) 50%,rgba(180,227,145,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#b4e391', endColorstr='#b4e391',GradientType=0 ); /* IE6-9 */")

			on 37
				return TabMLString("background: rgb(41,154,11); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(41,154,11,1) 0%, rgba(41,154,11,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(41,154,11,1)), color-stop(100%,rgba(41,154,11,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(41,154,11,1) 0%,rgba(41,154,11,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(41,154,11,1) 0%,rgba(41,154,11,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(41,154,11,1) 0%,rgba(41,154,11,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(41,154,11,1) 0%,rgba(41,154,11,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#299a0b', endColorstr='#299a0b',GradientType=0 ); /* IE6-9 */")

			on 38
				return TabMLString("background: rgb(143,200,0); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(143,200,0,1) 0%, rgba(143,200,0,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(143,200,0,1)), color-stop(100%,rgba(143,200,0,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(143,200,0,1) 0%,rgba(143,200,0,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(143,200,0,1) 0%,rgba(143,200,0,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(143,200,0,1) 0%,rgba(143,200,0,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(143,200,0,1) 0%,rgba(143,200,0,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#8fc800', endColorstr='#8fc800',GradientType=0 ); /* IE6-9 */")

			on 39
				return TabMLString("background: rgb(0,110,46); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(0,110,46,1) 0%, rgba(0,110,46,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(0,110,46,1)), color-stop(100%,rgba(0,110,46,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(0,110,46,1) 0%,rgba(0,110,46,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(0,110,46,1) 0%,rgba(0,110,46,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(0,110,46,1) 0%,rgba(0,110,46,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(0,110,46,1) 0%,rgba(0,110,46,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#006e2e', endColorstr='#006e2e',GradientType=0 ); /* IE6-9 */")

			on 40
				return TabMLString("background: rgb(107,186,112); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(107,186,112,1) 0%, rgba(107,186,112,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(107,186,112,1)), color-stop(100%,rgba(107,186,112,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(107,186,112,1) 0%,rgba(107,186,112,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(107,186,112,1) 0%,rgba(107,186,112,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(107,186,112,1) 0%,rgba(107,186,112,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(107,186,112,1) 0%,rgba(107,186,112,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#6bba70', endColorstr='#6bba70',GradientType=0 ); /* IE6-9 */")

			on 41
				return TabMLString("background: rgb(205,235,139); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(205,235,139,1) 0%, rgba(205,235,139,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(205,235,139,1)), color-stop(100%,rgba(205,235,139,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(205,235,139,1) 0%,rgba(205,235,139,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(205,235,139,1) 0%,rgba(205,235,139,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(205,235,139,1) 0%,rgba(205,235,139,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(205,235,139,1) 0%,rgba(205,235,139,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#cdeb8b', endColorstr='#cdeb8b',GradientType=0 ); /* IE6-9 */")

			on 42
				return TabMLString("background: rgb(143,196,0); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(143,196,0,1) 0%, rgba(143,196,0,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(143,196,0,1)), color-stop(100%,rgba(143,196,0,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(143,196,0,1) 0%,rgba(143,196,0,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(143,196,0,1) 0%,rgba(143,196,0,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(143,196,0,1) 0%,rgba(143,196,0,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(143,196,0,1) 0%,rgba(143,196,0,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#8fc400', endColorstr='#8fc400',GradientType=0 ); /* IE6-9 */")

			on 43
				return TabMLString("background: rgb(182,224,38); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(182,224,38,1) 0%, rgba(171,220,40,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(182,224,38,1)), color-stop(100%,rgba(171,220,40,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(182,224,38,1) 0%,rgba(171,220,40,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(182,224,38,1) 0%,rgba(171,220,40,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(182,224,38,1) 0%,rgba(171,220,40,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(182,224,38,1) 0%,rgba(171,220,40,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#b6e026', endColorstr='#abdc28',GradientType=0 ); /* IE6-9 */")

			on 44
				return TabMLString("background: rgb(157,213,58); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(157,213,58,1) 0%, rgba(161,213,79,1) 50%, rgba(128,194,23,1) 51%, rgba(124,188,10,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(157,213,58,1)), color-stop(50%,rgba(161,213,79,1)), color-stop(51%,rgba(128,194,23,1)), color-stop(100%,rgba(124,188,10,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(157,213,58,1) 0%,rgba(161,213,79,1) 50%,rgba(128,194,23,1) 51%,rgba(124,188,10,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(157,213,58,1) 0%,rgba(161,213,79,1) 50%,rgba(128,194,23,1) 51%,rgba(124,188,10,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(157,213,58,1) 0%,rgba(161,213,79,1) 50%,rgba(128,194,23,1) 51%,rgba(124,188,10,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(157,213,58,1) 0%,rgba(161,213,79,1) 50%,rgba(128,194,23,1) 51%,rgba(124,188,10,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#9dd53a', endColorstr='#7cbc0a',GradientType=0 ); /* IE6-9 */")

			on 45
				return TabMLString("background: rgb(230,240,163); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(230,240,163,1) 0%, rgba(210,230,56,1) 50%, rgba(195,216,37,1) 51%, rgba(219,240,67,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(230,240,163,1)), color-stop(50%,rgba(210,230,56,1)), color-stop(51%,rgba(195,216,37,1)), color-stop(100%,rgba(219,240,67,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(230,240,163,1) 0%,rgba(210,230,56,1) 50%,rgba(195,216,37,1) 51%,rgba(219,240,67,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(230,240,163,1) 0%,rgba(210,230,56,1) 50%,rgba(195,216,37,1) 51%,rgba(219,240,67,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(230,240,163,1) 0%,rgba(210,230,56,1) 50%,rgba(195,216,37,1) 51%,rgba(219,240,67,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(230,240,163,1) 0%,rgba(210,230,56,1) 50%,rgba(195,216,37,1) 51%,rgba(219,240,67,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#e6f0a3', endColorstr='#dbf043',GradientType=0 ); /* IE6-9 */")

			on 46
				return TabMLString("background: rgb(191,210,85); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(191,210,85,1) 0%, rgba(142,185,42,1) 50%, rgba(114,170,0,1) 51%, rgba(158,203,45,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(191,210,85,1)), color-stop(50%,rgba(142,185,42,1)), color-stop(51%,rgba(114,170,0,1)), color-stop(100%,rgba(158,203,45,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(191,210,85,1) 0%,rgba(142,185,42,1) 50%,rgba(114,170,0,1) 51%,rgba(158,203,45,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(191,210,85,1) 0%,rgba(142,185,42,1) 50%,rgba(114,170,0,1) 51%,rgba(158,203,45,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(191,210,85,1) 0%,rgba(142,185,42,1) 50%,rgba(114,170,0,1) 51%,rgba(158,203,45,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(191,210,85,1) 0%,rgba(142,185,42,1) 50%,rgba(114,170,0,1) 51%,rgba(158,203,45,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#bfd255', endColorstr='#9ecb2d',GradientType=0 ); /* IE6-9 */")

			on 47
				return TabMLString("background: rgb(238,238,238); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(238,238,238,1) 0%, rgba(204,204,204,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(238,238,238,1)), color-stop(100%,rgba(204,204,204,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(238,238,238,1) 0%,rgba(204,204,204,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(238,238,238,1) 0%,rgba(204,204,204,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(238,238,238,1) 0%,rgba(204,204,204,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(238,238,238,1) 0%,rgba(204,204,204,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#eeeeee', endColorstr='#cccccc',GradientType=0 ); /* IE6-9 */")

			on 49
				return TabMLString("background: rgb(206,220,231); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(206,220,231,1) 0%, rgba(89,106,114,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(206,220,231,1)), color-stop(100%,rgba(89,106,114,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(206,220,231,1) 0%,rgba(89,106,114,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(206,220,231,1) 0%,rgba(89,106,114,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(206,220,231,1) 0%,rgba(89,106,114,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(206,220,231,1) 0%,rgba(89,106,114,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#cedce7', endColorstr='#596a72',GradientType=0 ); /* IE6-9 */")

			on 50
				return TabMLString("background: rgb(96,108,136); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(96,108,136,1) 0%, rgba(63,76,107,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(96,108,136,1)), color-stop(100%,rgba(63,76,107,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(96,108,136,1) 0%,rgba(63,76,107,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(96,108,136,1) 0%,rgba(63,76,107,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(96,108,136,1) 0%,rgba(63,76,107,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(96,108,136,1) 0%,rgba(63,76,107,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#606c88', endColorstr='#3f4c6b',GradientType=0 ); /* IE6-9 */")

			on 51
				return TabMLString("background: rgb(176,212,227); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(176,212,227,1) 0%, rgba(136,186,207,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(176,212,227,1)), color-stop(100%,rgba(136,186,207,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(176,212,227,1) 0%,rgba(136,186,207,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(176,212,227,1) 0%,rgba(136,186,207,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(176,212,227,1) 0%,rgba(136,186,207,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(176,212,227,1) 0%,rgba(136,186,207,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#b0d4e3', endColorstr='#88bacf',GradientType=0 ); /* IE6-9 */")

			on 52
				return TabMLString("background: rgb(242,245,246); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(242,245,246,1) 0%, rgba(227,234,237,1) 37%, rgba(200,215,220,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(242,245,246,1)), color-stop(37%,rgba(227,234,237,1)), color-stop(100%,rgba(200,215,220,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(242,245,246,1) 0%,rgba(227,234,237,1) 37%,rgba(200,215,220,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(242,245,246,1) 0%,rgba(227,234,237,1) 37%,rgba(200,215,220,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(242,245,246,1) 0%,rgba(227,234,237,1) 37%,rgba(200,215,220,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(242,245,246,1) 0%,rgba(227,234,237,1) 37%,rgba(200,215,220,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#f2f5f6', endColorstr='#c8d7dc',GradientType=0 ); /* IE6-9 */")

			on 53
				return TabMLString("background: rgb(216,224,222); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(216,224,222,1) 0%, rgba(174,191,188,1) 22%, rgba(153,175,171,1) 33%, rgba(142,166,162,1) 50%, rgba(130,157,152,1) 67%, rgba(78,92,90,1) 82%, rgba(14,14,14,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(216,224,222,1)), color-stop(22%,rgba(174,191,188,1)), color-stop(33%,rgba(153,175,171,1)), color-stop(50%,rgba(142,166,162,1)), color-stop(67%,rgba(130,157,152,1)), color-stop(82%,rgba(78,92,90,1)), color-stop(100%,rgba(14,14,14,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(216,224,222,1) 0%,rgba(174,191,188,1) 22%,rgba(153,175,171,1) 33%,rgba(142,166,162,1) 50%,rgba(130,157,152,1) 67%,rgba(78,92,90,1) 82%,rgba(14,14,14,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(216,224,222,1) 0%,rgba(174,191,188,1) 22%,rgba(153,175,171,1) 33%,rgba(142,166,162,1) 50%,rgba(130,157,152,1) 67%,rgba(78,92,90,1) 82%,rgba(14,14,14,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(216,224,222,1) 0%,rgba(174,191,188,1) 22%,rgba(153,175,171,1) 33%,rgba(142,166,162,1) 50%,rgba(130,157,152,1) 67%,rgba(78,92,90,1) 82%,rgba(14,14,14,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(216,224,222,1) 0%,rgba(174,191,188,1) 22%,rgba(153,175,171,1) 33%,rgba(142,166,162,1) 50%,rgba(130,157,152,1) 67%,rgba(78,92,90,1) 82%,rgba(14,14,14,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#d8e0de', endColorstr='#0e0e0e',GradientType=0 ); /* IE6-9 */")

			on 54
				return TabMLString("background: rgb(181,189,200); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(181,189,200,1) 0%, rgba(130,140,149,1) 36%, rgba(40,52,59,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(181,189,200,1)), color-stop(36%,rgba(130,140,149,1)), color-stop(100%,rgba(40,52,59,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(181,189,200,1) 0%,rgba(130,140,149,1) 36%,rgba(40,52,59,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(181,189,200,1) 0%,rgba(130,140,149,1) 36%,rgba(40,52,59,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(181,189,200,1) 0%,rgba(130,140,149,1) 36%,rgba(40,52,59,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(181,189,200,1) 0%,rgba(130,140,149,1) 36%,rgba(40,52,59,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#b5bdc8', endColorstr='#28343b',GradientType=0 ); /* IE6-9 */")

			on 55
				return TabMLString("background: rgb(184,198,223); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(184,198,223,1) 0%, rgba(109,136,183,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(184,198,223,1)), color-stop(100%,rgba(109,136,183,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(184,198,223,1) 0%,rgba(109,136,183,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(184,198,223,1) 0%,rgba(109,136,183,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(184,198,223,1) 0%,rgba(109,136,183,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(184,198,223,1) 0%,rgba(109,136,183,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#b8c6df', endColorstr='#6d88b7',GradientType=0 ); /* IE6-9 */")

			on 56
				return TabMLString("background: rgb(207,231,250); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(207,231,250,1) 0%, rgba(99,147,193,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(207,231,250,1)), color-stop(100%,rgba(99,147,193,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(207,231,250,1) 0%,rgba(99,147,193,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(207,231,250,1) 0%,rgba(99,147,193,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(207,231,250,1) 0%,rgba(99,147,193,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(207,231,250,1) 0%,rgba(99,147,193,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#cfe7fa', endColorstr='#6393c1',GradientType=0 ); /* IE6-9 */")

			on 57
				return TabMLString("background: rgb(210,223,237); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(210,223,237,1) 0%, rgba(200,215,235,1) 26%, rgba(190,208,234,1) 51%, rgba(166,192,227,1) 51%, rgba(175,199,232,1) 62%, rgba(186,208,239,1) 75%, rgba(153,181,219,1) 88%, rgba(121,155,200,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(210,223,237,1)), color-stop(26%,rgba(200,215,235,1)), color-stop(51%,rgba(190,208,234,1)), color-stop(51%,rgba(166,192,227,1)), color-stop(62%,rgba(175,199,232,1)), color-stop(75%,rgba(186,208,239,1)), color-stop(88%,rgba(153,181,219,1)), color-stop(100%,rgba(121,155,200,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(210,223,237,1) 0%,rgba(200,215,235,1) 26%,rgba(190,208,234,1) 51%,rgba(166,192,227,1) 51%,rgba(175,199,232,1) 62%,rgba(186,208,239,1) 75%,rgba(153,181,219,1) 88%,rgba(121,155,200,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(210,223,237,1) 0%,rgba(200,215,235,1) 26%,rgba(190,208,234,1) 51%,rgba(166,192,227,1) 51%,rgba(175,199,232,1) 62%,rgba(186,208,239,1) 75%,rgba(153,181,219,1) 88%,rgba(121,155,200,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(210,223,237,1) 0%,rgba(200,215,235,1) 26%,rgba(190,208,234,1) 51%,rgba(166,192,227,1) 51%,rgba(175,199,232,1) 62%,rgba(186,208,239,1) 75%,rgba(153,181,219,1) 88%,rgba(121,155,200,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(210,223,237,1) 0%,rgba(200,215,235,1) 26%,rgba(190,208,234,1) 51%,rgba(166,192,227,1) 51%,rgba(175,199,232,1) 62%,rgba(186,208,239,1) 75%,rgba(153,181,219,1) 88%,rgba(121,155,200,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#d2dfed', endColorstr='#799bc8',GradientType=0 ); /* IE6-9 */")

			on 58
				return TabMLString("background: rgb(238,238,238); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(238,238,238,1) 0%, rgba(238,238,238,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(238,238,238,1)), color-stop(100%,rgba(238,238,238,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(238,238,238,1) 0%,rgba(238,238,238,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(238,238,238,1) 0%,rgba(238,238,238,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(238,238,238,1) 0%,rgba(238,238,238,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(238,238,238,1) 0%,rgba(238,238,238,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#eeeeee', endColorstr='#eeeeee',GradientType=0 ); /* IE6-9 */")

			on 59
				return TabMLString("background: rgb(226,226,226); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(226,226,226,1) 0%, rgba(219,219,219,1) 50%, rgba(209,209,209,1) 51%, rgba(254,254,254,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(226,226,226,1)), color-stop(50%,rgba(219,219,219,1)), color-stop(51%,rgba(209,209,209,1)), color-stop(100%,rgba(254,254,254,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(226,226,226,1) 0%,rgba(219,219,219,1) 50%,rgba(209,209,209,1) 51%,rgba(254,254,254,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(226,226,226,1) 0%,rgba(219,219,219,1) 50%,rgba(209,209,209,1) 51%,rgba(254,254,254,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(226,226,226,1) 0%,rgba(219,219,219,1) 50%,rgba(209,209,209,1) 51%,rgba(254,254,254,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(226,226,226,1) 0%,rgba(219,219,219,1) 50%,rgba(209,209,209,1) 51%,rgba(254,254,254,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#e2e2e2', endColorstr='#fefefe',GradientType=0 ); /* IE6-9 */")

			on 60
				return TabMLString("background: rgb(242,246,248); /* Old browsers */
background: -moz-linear-gradient(top,  rgba(242,246,248,1) 0%, rgba(216,225,231,1) 50%, rgba(181,198,208,1) 51%, rgba(224,239,249,1) 100%); /* FF3.6+ */
background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(242,246,248,1)), color-stop(50%,rgba(216,225,231,1)), color-stop(51%,rgba(181,198,208,1)), color-stop(100%,rgba(224,239,249,1))); /* Chrome,Safari4+ */
background: -webkit-linear-gradient(top,  rgba(242,246,248,1) 0%,rgba(216,225,231,1) 50%,rgba(181,198,208,1) 51%,rgba(224,239,249,1) 100%); /* Chrome10+,Safari5.1+ */
background: -o-linear-gradient(top,  rgba(242,246,248,1) 0%,rgba(216,225,231,1) 50%,rgba(181,198,208,1) 51%,rgba(224,239,249,1) 100%); /* Opera 11.10+ */
background: -ms-linear-gradient(top,  rgba(242,246,248,1) 0%,rgba(216,225,231,1) 50%,rgba(181,198,208,1) 51%,rgba(224,239,249,1) 100%); /* IE10+ */
background: linear-gradient(to bottom,  rgba(242,246,248,1) 0%,rgba(216,225,231,1) 50%,rgba(181,198,208,1) 51%,rgba(224,239,249,1) 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#f2f6f8', endColorstr='#e0eff9',GradientType=0 ); /* IE6-9 */")

			off

		Func StyleTable
			return "table, th, td { border: 1px solid black; border-collapse: collapse;}"

		Func StyleTableRows id
			return  "table#"+id+" tr:nth-child(even) { background-color: #eee; } " +
				"table#"+id+" tr:nth-child(odd) { background-color: #fff; }"

		Func StyleTableNoBorder
			return " border-style: none;"


	Class PageBuffer from Page
		Func BraceEnd			

	Class HTML2PDF from page
		Func BraceEnd
			HTML2PDF(cOutput)

	Class BootStrapPage from Page
		lBootstrap = True

	Class WebPage from Application

		aObjs = []  

		StartHtml()
		
		Func braceend
			see cCookies + cStart + "<html>" + nl +
			"<header> <title>"+Title+"</title> </header>" + nl + nl +
			"<body> " + nl 
			for x in aObjs
				see x.getdata() + nl
			next
			see nl + "</body>" + nl + "</html>" + nl

		Func Text x
			aObjs + new ObjsBase
			aObjs[len(aObjs)].cOutput = x

		Func styleattribute cName,cValue
			if cName != NULL
				cOutput += cName + ": " + cValue + "; "
			ok

		Func Link
			aObjs + new Link
			return aObjs[len(aObjs)]
		
		Func NewLine
			aObjs + new NewLine

		Func Div
			aObjs + new Div
			return aObjs[len(aObjs)]

	Class ObjsBase  From Application

		cOutput = "" aObjs = []  

		# HTML Elements
		id name align style dir value onclick oncontextmenu
		ondblclick onmousedown onmouseenter onmouseleave
		onmousemove onmouseover onmouseout onmouseup
		onkeydown onkeypress onkeyup onabort onbeforeunload
		onerror onhashchange onload onpageshow onpagehide
		onresize onscroll onunload onblur onchange onfocus
		onfocusin onfocusout oninput oninvalid onreset
      		onsearch onselect onsubmit ondrag ondragend ondragenter
		ondragleave ondragover ondragstart ondrop oncopy oncut
		onpaste onafterprint onbeforeprint onabort oncanplay
		oncanplaythrough ondurationchange onemptied onended
		onerror onloadeddata onloadedmetadata onloadstart
		onpause onplay onplaying onprogress onratechange
		onseeked onseeking onstalled onsuspend ontimeupdate
		onvolumechange onwaiting animationend animationiteration
		animationstart transitionend onmessage onopen
		onmousewheel ononline onoffline onpostate onshow
		onstorage ontoggle onwheel ontouchcancel ontouchend
		ontouchmove ontouchstart 

		# CSS
		color opacity background backgroundattachment 
		backgroundcolor backgroundimage backgroundposition backgroundrepeat backgroundclip 
		backgroundorigin backgroundsize border borderbottom borderbottomcolor 
		borderbottomleftradius borderbottomrightradius borderbottomstyle borderbottomwidth bordercolor 
		borderimage borderimageoutset borderimagerepeat borderimageslice borderimagesource 
		borderimagewidth borderleft borderleftcolor borderleftstyle borderleftwidth 
		borderradius borderright borderrightcolor borderrightstyle borderrightwidth 
		borderstyle bordertop bordertopcolor bordertopleftradius bordertoprightradius 
		bordertopstyle bordertopwidth borderwidth boxdecorationbreak boxshadow 
		bottom clear clip display float 
		height left margin marginbottom marginleft 
		marginright margintop maxheight maxwidth minheight 
		minwidth overflow overflowx overflowy padding 
		paddingbottom paddingleft paddingright paddingtop position 
		right top visibility width verticalalign 
		zindex aligncontent alignitems alignself flex 
		flexbasis flexdirection flexflow flexgrow flexshrink 
		flexwrap justifycontent order hangingpunctuation hyphens 
		letterspacing linebreak lineheight overflowwrap tabsize 
		textalign textalignlast textcombineupright textindent textjustify 
		texttransform whitespace wordbreak wordspacing wordwrap 
		textdecoration textdecorationcolor textdecorationline textdecorationstyle textshadow 
		textunderlineposition @fontface @fontfeaturevalues font fontfamily 
		fontfeaturesettings fontkerning fontlanguageoverride fontsize fontsizeadjust 
		fontstretch fontstyle fontsynthesis fontvariant fontvariantalternates 
		fontvariantcaps fontvarianteastasian fontvariantligatures fontvariantnumeric fontvariantposition 
		fontweight direction textorientation textcombineupright unicodebidi 
		writingmode bordercollapse borderspacing captionside emptycells 
		tablelayout counterincrement counterreset liststyle liststyleimage 
		liststyleposition liststyletype @keyframes animation animationdelay 
		animationdirection animationduration animationfillmode animationiterationcount animationname 
		animationplaystate animationtimingfunction  backfacevisibility perspective 
		perspectiveorigin transform transformorigin transformstyle transition 
		transitionproperty transitionduration transitiontimingfunction transitiondelay boxsizing 
		content cursor imemode navdown navindex 
		navleft navright navup outline outlinecolor 
		outlineoffset outlinestyle outlinewidth resize textoverflow 
		breakafter breakbefore breakinside columncount columnfill 
		columngap columnrule columnrulecolor columnrulestyle columnrulewidth 
		columnspan columnwidth columns widows orphans 
		pagebreakafter pagebreakbefore pagebreakinside marks quotes 
		filter imageorientation imagerendering imageresolution objectfit 
		objectposition mask masktype mark markafter 
		markbefore phonemes rest restafter restbefore 
		voicebalance voiceduration voicepitch voicepitchrange voicerate 
		voicestress voicevolume marqueedirection marqueeplaycount marqueespeed 
		marqueestyle 

		func getdata
			return cOutput

		func getobjsdata
			TabPUSH()
			for x in aObjs
				cOutput += getTabs() + x.getdata() + nl
			next
			TabPOP()

		Func Text x
			aObjs + new ObjsBase
			aObjs[len(aObjs)].cOutput =  NL+GetTabs()+x

		Func addattributes 

			aList = [ :id,:name,:value,:align,:style,:dir,:onclick,:oncontextmenu,
				:ondblclick,:onmousedown,:onmouseenter,:onmouseleave,
				:onmousemove,:onmouseover,:onmouseout,:onmouseup,
				:onkeydown,:onkeypress,:onkeyup,:onabort,:onbeforeunload,
				:onerror,:onhashchange,:onload,:onpageshow,:onpagehide,
				:onresize,:onscroll,:onunload,:onblur,:onchange,:onfocus,
				:onfocusin,:onfocusout,:oninput,:oninvalid,:onreset,
				:onsearch,:onselect,:onsubmit,:ondrag,:ondragend,:ondragenter,
				:ondragleave,:ondragover,:ondragstart,:ondrop,:oncopy,:oncut,
				:onpaste,:onafterprint,:onbeforeprint,:onabort,:oncanplay,
				:oncanplaythrough,:ondurationchange,:onemptied,:onended,
				:onerror,:onloadeddata,:onloadedmetadata,:onloadstart,
				:onpause,:onplay,:onplaying,:onprogress,:onratechange,
				:onseeked,:onseeking,:onstalled,:onsuspend,:ontimeupdate,
				:onvolumechange,:onwaiting,:animationend,:animationiteration,
				:animationstart,:transitionend, :onmessage, :onopen, 
				:onmousewheel, :ononline, :onoffline, :onpostate, :onshow,
				:onstorage, :ontoggle, :onwheel, :ontouchcancel, :ontouchend,
				:ontouchmove, :ontouchstart ]

			for t in aList
				elementattribute(t)
			next

		Func elementattribute cName
			cValue = getattribute(self,cName)
			if cValue != NULL and cValue != "NULL"
				cOutput += ' ' + cName + '="' + cValue + '"'
			ok

		Func styleattribute cName,cValue
			if cName != NULL
				cOutput += cName + " : " + cValue + "; "
			ok

		Func AddStyle
			
			if getattribute(self,"style") = "NULL"
				cOutput += ' style="' 
				aList = ["color","opacity","background","background-attachment",
				"background-color","background-image","background-position","background-repeat","background-clip",
				"background-origin","background-size","border","border-bottom","border-bottom-color",
				"border-bottom-left-radius","border-bottom-right-radius","border-bottom-style","border-bottom-width","border-color",
				"border-image","border-image-outset","border-image-repeat","border-image-slice","border-image-source",
				"border-image-width","border-left","border-left-color","border-left-style","border-left-width",
				"border-radius","border-right","border-right-color","border-right-style","border-right-width",
				"border-style","border-top","border-top-color","border-top-left-radius","border-top-right-radius",
				"border-top-style","border-top-width","border-width","box-decoration-break","box-shadow",
				"bottom","clear","clip","display","float",
				"height","left","margin","margin-bottom","margin-left",
				"margin-right","margin-top","max-height","max-width","min-height",
				"min-width","overflow","overflow-x","overflow-y","padding",
				"padding-bottom","padding-left","padding-right","padding-top","position",
				"right","top","visibility","width","vertical-align",
				"z-index","align-content","align-items","align-self","flex",
				"flex-basis","flex-direction","flex-flow","flex-grow","flex-shrink",
				"flex-wrap","justify-content","order","hanging-punctuation","hyphens",
				"letter-spacing","line-break","line-height","overflow-wrap","tab-size",
				"text-align","text-align-last","text-combine-upright","text-indent","text-justify",
				"text-transform","white-space","word-break","word-spacing","word-wrap",
				"text-decoration","text-decoration-color","text-decoration-line","text-decoration-style","text-shadow",
				"text-underline-position","@font-face","@font-feature-values","font","font-family",
				"font-feature-settings","font-kerning","font-language-override","font-size","font-size-adjust",
				"font-stretch","font-style","font-synthesis","font-variant","font-variant-alternates",
				"font-variant-caps","font-variant-east-asian","font-variant-ligatures","font-variant-numeric","font-variant-position",
				"font-weight","direction","text-orientation","text-combine-upright","unicode-bidi",
				"writing-mode","border-collapse","border-spacing","caption-side","empty-cells",
				"table-layout","counter-increment","counter-reset","list-style","list-style-image",
				"list-style-position","list-style-type","@keyframes","animation","animation-delay",
				"animation-direction","animation-duration","animation-fill-mode","animation-iteration-count","animation-name",
				"animation-play-state","animation-timing-function","","backface-visibility","perspective",
				"perspective-origin","transform","transform-origin","transform-style","transition",
				"transition-property","transition-duration","transition-timing-function","transition-delay","box-sizing",
				"content","cursor","ime-mode","nav-down","nav-index",
				"nav-left","nav-right","nav-up","outline","outline-color",
				"outline-offset","outline-style","outline-width","resize","text-overflow",
				"break-after","break-before","break-inside","column-count","column-fill",
				"column-gap","column-rule","column-rule-color","column-rule-style","column-rule-width",
				"column-span","column-width","columns","widows","orphans",
				"page-break-after","page-break-before","page-break-inside","marks","quotes",
				"filter","image-orientation","image-rendering","image-resolution","object-fit",
				"object-position","mask","mask-type","mark","mark-after",
				"mark-before","phonemes","rest","rest-after","rest-before",
				"voice-balance","voice-duration","voice-pitch","voice-pitch-range","voice-rate",
				"voice-stress","voice-volume","marquee-direction","marquee-play-count","marquee-speed",
				"marquee-style"]
				for t in aList
					cAttr = substr(t,"-","")
					if isattribute(self,cAttr)
						cValue = getattribute(self,cAttr)
						if cValue != "NULL"
							styleattribute(t,cValue)
						ok
					ok
				next
				cOutput += '">' + nl
			else
				cOutput += '>' + nl
			ok

		Func Div
			aObjs + new Div
			return aObjs[len(aObjs)]

		Func Form
			aObjs + new Form
			return aObjs[len(aObjs)]

		Func Input
			aObjs + new Input
			return aObjs[len(aObjs)]

		Func TextArea
			aObjs + new TextArea
			return aObjs[len(aObjs)]

		Func Select
			aObjs + new Select
			return aObjs[len(aObjs)]

		Func Option
			aObjs + new Option
			return aObjs[len(aObjs)]

		Func Image
			aObjs + new Image
			return aObjs[len(aObjs)]

		Func UL
			aObjs + new UL
			return aObjs[len(aObjs)]

		Func LI
			aObjs + new LI
			return aObjs[len(aObjs)]

		Func Table
			aObjs + new Table
			return aObjs[len(aObjs)]

		Func Tr
			aObjs + new TR
			return aObjs[len(aObjs)]

		Func Td
			aObjs + new TD
			return aObjs[len(aObjs)]

		Func Th
			aObjs + new TH
			return aObjs[len(aObjs)]

		Func Audio
			aObjs + new Audio
			return aObjs[len(aObjs)]

		Func Video
			aObjs + new Video
			return aObjs[len(aObjs)]


	Class Link from ObjsBase
		title  link
		Func braceend
			cOutput = nl+GetTabs() + "<a href='" + Link + "'> "+ Title + " </a> " + nl			

	Class NewLine from ObjsBase
		cOutput = GetTabs() + "<br />"

	Class Div from ObjsBase 
		Func braceend
			cOutput += nl+'<div'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</div>" + nl
			cOutput = TabMLString(cOutput)

	Class Form from ObjsBase 
		action method
		Func braceend
			cOutput += nl+'<form'
			addattributes()
			elementattribute(:action)
			elementattribute(:method)
			AddStyle()
			getobjsdata()
			cOutput += nl+"</form>" + nl
			cOutput = TabMLString(cOutput)

	Class Input from ObjsBase 
		type min max checked=false
		Func braceend
			cOutput += nl+'<input'			
			elementattribute(:type)
			addattributes()			
			elementattribute(:min)
			elementattribute(:max)
			if checked
				cOutput += " checked"
			ok
			AddStyle()
			cOutput = TabMLString(cOutput)

	Class TextArea from ObjsBase 
		rows cols
		Func braceend
			cOutput += nl+'<textarea'
			addattributes()
			elementattribute(:rows)
			elementattribute(:cols)
			AddStyle()
			getobjsdata()
			cOutput += nl+"</textarea>" + nl
			cOutput = TabMLString(cOutput)

	Class Select from ObjsBase 
		multiple
		Func braceend
			cOutput += nl+'<select'
			addattributes()
			elementattribute(:multiple)
			AddStyle()
			getobjsdata()
			cOutput += nl+"</select>" + nl
			cOutput = TabMLString(cOutput)

	Class Option from ObjsBase 
		Func braceend
			cOutput += nl+'<option'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</option>" + nl
			cOutput = TabMLString(cOutput)

	Class Image from ObjsBase 
		src alt
		Func braceend
			cOutput += nl+'<img'
			addattributes()
			elementattribute(:src)
			elementattribute(:alt)
			AddStyle()
			getobjsdata()
			cOutput = TabMLString(cOutput)

	Class UL from ObjsBase 
		Func braceend
			cOutput += nl+'<ul'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</ul>" + nl
			cOutput = TabMLString(cOutput)

	Class LI from ObjsBase 
		Func braceend
			cOutput += nl+'<li'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</li>" + nl
			cOutput = TabMLString(cOutput)

	Class Table from ObjsBase 
		Func braceend
			cOutput += nl+'<table'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</table>" + nl
			cOutput = TabMLString(cOutput)

	Class TR from ObjsBase 
		Func braceend
			cOutput += nl+'<tr'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</tr>" + nl
			cOutput = TabMLString(cOutput)

	Class TD from ObjsBase 
		Func braceend
			cOutput += nl+'<td'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</td>" + nl
			cOutput = TabMLString(cOutput)

	Class TH from ObjsBase 
		Func braceend
			cOutput += nl+'<th'
			addattributes()
			AddStyle()
			getobjsdata()
			cOutput += nl+"</th>" + nl
			cOutput = TabMLString(cOutput)

	Class Audio from ObjsBase 
		src type
		Func braceend
			cOutput += nl+'<audio controls'
			addattributes()
			cOutput += '> <source '
			elementattribute(:src)
			elementattribute(:type)
			AddStyle()
			getobjsdata()
			cOutput += nl+"> Your browser does not support the audio element. </audio>" + nl
			cOutput = TabMLString(cOutput)

	Class Video from ObjsBase 
		src type
		Func braceend
			cOutput += nl+'<video controls'
			addattributes()
			elementattribute(:width)
			elementattribute(:height)
			cOutput += '> <source '
			elementattribute(:src)
			elementattribute(:type)
			AddStyle()
			getobjsdata()
			cOutput += nl+"> Your browser does not support the video tag. </video>" + nl
			cOutput = TabMLString(cOutput)
