# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web

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
				  :onpaste,:onafterprint,:onbeforeprint,:oncanplay,
				  :oncanplaythrough,:ondurationchange,:onemptied,:onended,
				  :onloadeddata,:onloadedmetadata,:onloadstart,
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

		Func navstart aPara
			html( nl + GetTabs() + '<nav ' )
			addattributes(aPara)
			html( '>' + nl )
			TabPush()

		Func spanstart aPara
			html( nl + GetTabs() + '<span ' )
			addattributes(aPara)
			html( '>' + nl )
			TabPush()


		Func boxstart 
			html( nl + GetTabs() +'<div style="width:100% ; height:30px ; color: yellow ; background-color:black">' + nl)
			TabPush()

		Func divend
			TabPOP()
			html( nl + GetTabs() +'</div>' + nl )

		Func navend
			TabPOP()
			html( nl + GetTabs() +'</nav>' + nl )

		Func spanend
			TabPOP()
			html( nl + GetTabs() +'</span>' + nl )


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

		Func theadstart aPara
			cOutput += nl+GetTabs()+'<thead '
			addattributes(aPara)
			cOutput += '>'
			TabPush()

		Func theadend
			TabPOP()
			cOutput += nl+GetTabs()+"</thead>" + nl

		Func tbodystart aPara
			cOutput += nl+GetTabs()+'<tbody '
			addattributes(aPara)
			cOutput += '>'
			TabPush()

		Func tbodyend
			TabPOP()
			cOutput += nl+GetTabs()+"</tbody>" + nl

		Func tfootstart aPara
			cOutput += nl+GetTabs()+'<tfoot '
			addattributes(aPara)
			cOutput += '>'
			TabPush()

		Func tfootend
			TabPOP()
			cOutput += nl+GetTabs()+"</tfoot>" + nl

		Func braceend 
			print() 
