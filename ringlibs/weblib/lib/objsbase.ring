# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web

	Class ObjsBase  From Application

		cOutput = "" aObjs = []  

		cAttrOutput = "" cStyleOutput = ""

		AddAttribute(self,htmlcssattributes)
		AddAttribute(self,aObjsAttributes)

		func getdata
			return cOutput

		func getobjsdata
			TabPUSH()
			for x in aObjs
				cOutput += getTabs() + x.getdata() + nl
			next
			TabPOP()

		Func addattributes 

			cOutput += cAttrOutput

		Func elementattribute cName
			cValue = getattribute(self,cName)
			if cValue != NULL and cValue != "NULL"
				cOutput += ' ' + cName + '="' + cValue + '"'
			ok

		Func elementattribute2 cName,cName2
			cValue = getattribute(self,cName)
			if cValue != NULL and cValue != "NULL"
				cOutput += ' ' + lower(cName2) + '="' + cValue + '"'
			ok

		Func AddStyle
			
			if getattribute(self,"style") = "NULL"
				cOutput += ' style="' 
				cOutput += cStyleOutput	
				cOutput += '">' + nl
			else
				cOutput += '>' + nl
			ok

		# Generated setter functions 

		func setclassname  cValue
			cAttrOutput += ' class = "' + cValue + '"'

		func setid  cValue
			cAttrOutput += ' id  = "' + cValue + '"'

		func setname  cValue
			cAttrOutput += ' name  = "' + cValue + '"'

		func setalign cValue
			cAttrOutput += ' align = "' + cValue + '"'

		func setstyle cValue
			cAttrOutput += ' style = "' + cValue + '"'

		func setdir  cValue
			cAttrOutput += ' dir  = "' + cValue + '"'

		func setvalue  cValue
			cAttrOutput += ' value  = "' + cValue + '"'

		func setonclick cValue
			cAttrOutput += ' onclick = "' + cValue + '"'

		func setoncontextmenu cValue
			cAttrOutput += ' oncontextmenu = "' + cValue + '"'

		func setondblclick cValue
			cAttrOutput += ' ondblclick = "' + cValue + '"'

		func setonmousedown cValue
			cAttrOutput += ' onmousedown = "' + cValue + '"'

		func setonmouseenter cValue
			cAttrOutput += ' onmouseenter = "' + cValue + '"'

		func setonmouseleave cValue
			cAttrOutput += ' onmouseleave = "' + cValue + '"'

		func setonmousemove cValue
			cAttrOutput += ' onmousemove = "' + cValue + '"'

		func setonmouseover cValue
			cAttrOutput += ' onmouseover = "' + cValue + '"'

		func setonmouseout cValue
			cAttrOutput += ' onmouseout = "' + cValue + '"'

		func setonmouseup cValue
			cAttrOutput += ' onmouseup = "' + cValue + '"'

		func setonkeydown cValue
			cAttrOutput += ' onkeydown = "' + cValue + '"'

		func setonkeypress cValue
			cAttrOutput += ' onkeypress = "' + cValue + '"'

		func setonkeyup cValue
			cAttrOutput += ' onkeyup = "' + cValue + '"'

		func setonabort cValue
			cAttrOutput += ' onabort = "' + cValue + '"'

		func setonbeforeunload cValue
			cAttrOutput += ' onbeforeunload = "' + cValue + '"'

		func setonerror cValue
			cAttrOutput += ' onerror = "' + cValue + '"'

		func setonhashchange  cValue
			cAttrOutput += ' onhashchange  = "' + cValue + '"'

		func setonload cValue
			cAttrOutput += ' onload = "' + cValue + '"'

		func setonpageshow cValue
			cAttrOutput += ' onpageshow = "' + cValue + '"'

		func setonpagehide cValue
			cAttrOutput += ' onpagehide = "' + cValue + '"'

		func setonresize cValue
			cAttrOutput += ' onresize = "' + cValue + '"'

		func setonscroll  cValue
			cAttrOutput += ' onscroll  = "' + cValue + '"'

		func setonunload cValue
			cAttrOutput += ' onunload = "' + cValue + '"'

		func setonblur cValue
			cAttrOutput += ' onblur = "' + cValue + '"'

		func setonchange cValue
			cAttrOutput += ' onchange = "' + cValue + '"'

		func setonfocus cValue
			cAttrOutput += ' onfocus = "' + cValue + '"'

		func setonfocusin cValue
			cAttrOutput += ' onfocusin = "' + cValue + '"'

		func setonfocusout cValue
			cAttrOutput += ' onfocusout = "' + cValue + '"'

		func setoninput  cValue
			cAttrOutput += ' oninput  = "' + cValue + '"'

		func setoninvalid  cValue
			cAttrOutput += ' oninvalid  = "' + cValue + '"'

		func setonreset cValue
			cAttrOutput += ' onreset = "' + cValue + '"'

		func setonsearch  cValue
			cAttrOutput += ' onsearch  = "' + cValue + '"'

		func setonselect  cValue
			cAttrOutput += ' onselect  = "' + cValue + '"'

		func setonsubmit cValue
			cAttrOutput += ' onsubmit = "' + cValue + '"'

		func setondrag  cValue
			cAttrOutput += ' ondrag  = "' + cValue + '"'

		func setondragend cValue
			cAttrOutput += ' ondragend = "' + cValue + '"'

		func setondragenter cValue
			cAttrOutput += ' ondragenter = "' + cValue + '"'

		func setondragleave cValue
			cAttrOutput += ' ondragleave = "' + cValue + '"'

		func setondragover  cValue
			cAttrOutput += ' ondragover  = "' + cValue + '"'

		func setondragstart cValue
			cAttrOutput += ' ondragstart = "' + cValue + '"'

		func setondrop  cValue
			cAttrOutput += ' ondrop  = "' + cValue + '"'

		func setoncopy  cValue
			cAttrOutput += ' oncopy  = "' + cValue + '"'

		func setoncut cValue
			cAttrOutput += ' oncut = "' + cValue + '"'

		func setonpaste  cValue
			cAttrOutput += ' onpaste  = "' + cValue + '"'

		func setonafterprint cValue
			cAttrOutput += ' onafterprint = "' + cValue + '"'

		func setonbeforeprint cValue
			cAttrOutput += ' onbeforeprint = "' + cValue + '"'

		func setoncanplay cValue
			cAttrOutput += ' oncanplay = "' + cValue + '"'

		func setoncanplaythrough  cValue
			cAttrOutput += ' oncanplaythrough  = "' + cValue + '"'

		func setondurationchange cValue
			cAttrOutput += ' ondurationchange = "' + cValue + '"'

		func setonemptied  cValue
			cAttrOutput += ' onemptied  = "' + cValue + '"'

		func setonended cValue
			cAttrOutput += ' onended = "' + cValue + '"'

		func setonloadeddata cValue
			cAttrOutput += ' onloadeddata = "' + cValue + '"'

		func setonloadedmetadata cValue
			cAttrOutput += ' onloadedmetadata = "' + cValue + '"'

		func setonloadstart cValue
			cAttrOutput += ' onloadstart = "' + cValue + '"'

		func setonpause  cValue
			cAttrOutput += ' onpause  = "' + cValue + '"'

		func setonplay cValue
			cAttrOutput += ' onplay = "' + cValue + '"'

		func setonplaying  cValue
			cAttrOutput += ' onplaying  = "' + cValue + '"'

		func setonprogress cValue
			cAttrOutput += ' onprogress = "' + cValue + '"'

		func setonratechange cValue
			cAttrOutput += ' onratechange = "' + cValue + '"'

		func setonseeked cValue
			cAttrOutput += ' onseeked = "' + cValue + '"'

		func setonseeking cValue
			cAttrOutput += ' onseeking = "' + cValue + '"'

		func setonstalled  cValue
			cAttrOutput += ' onstalled  = "' + cValue + '"'

		func setonsuspend cValue
			cAttrOutput += ' onsuspend = "' + cValue + '"'

		func setontimeupdate cValue
			cAttrOutput += ' ontimeupdate = "' + cValue + '"'

		func setonvolumechange cValue
			cAttrOutput += ' onvolumechange = "' + cValue + '"'

		func setonwaiting  cValue
			cAttrOutput += ' onwaiting  = "' + cValue + '"'

		func setanimationend cValue
			cAttrOutput += ' animationend = "' + cValue + '"'

		func setanimationiteration cValue
			cAttrOutput += ' animationiteration = "' + cValue + '"'

		func setanimationstart cValue
			cAttrOutput += ' animationstart = "' + cValue + '"'

		func settransitionend cValue
			cAttrOutput += ' transitionend = "' + cValue + '"'

		func setonmessage  cValue
			cAttrOutput += ' onmessage  = "' + cValue + '"'

		func setonopen cValue
			cAttrOutput += ' onopen = "' + cValue + '"'

		func setonmousewheel  cValue
			cAttrOutput += ' onmousewheel  = "' + cValue + '"'

		func setononline cValue
			cAttrOutput += ' ononline = "' + cValue + '"'

		func setonoffline cValue
			cAttrOutput += ' onoffline = "' + cValue + '"'

		func setonpostate cValue
			cAttrOutput += ' onpostate = "' + cValue + '"'

		func setonshow cValue
			cAttrOutput += ' onshow = "' + cValue + '"'

		func setonstorage cValue
			cAttrOutput += ' onstorage = "' + cValue + '"'

		func setontoggle cValue
			cAttrOutput += ' ontoggle = "' + cValue + '"'

		func setonwheel  cValue
			cAttrOutput += ' onwheel  = "' + cValue + '"'

		func setontouchcancel cValue
			cAttrOutput += ' ontouchcancel = "' + cValue + '"'

		func setontouchend cValue
			cAttrOutput += ' ontouchend = "' + cValue + '"'

		func setontouchmove cValue
			cAttrOutput += ' ontouchmove = "' + cValue + '"'

		func setontouchstart  cValue
			cAttrOutput += ' ontouchstart  = "' + cValue + '"'

		# bootstrap 
		func setdatatoggle cValue
			cAttrOutput += ' data-toggle = "' + cValue + '"'

		func setdataride cValue
			cAttrOutput += ' data-ride = "' + cValue + '"'

		func setdatatarget cValue
			cAttrOutput += ' data-target = "' + cValue + '"'

		func setdataslideto cValue
			cAttrOutput += ' data-slide-to = "' + cValue + '"'

		func setdataslide cValue
			cAttrOutput += ' data-slide = "' + cValue + '"'

		func setdatadismiss cValue
			cAttrOutput += ' data-dismiss = "' + cValue + '"'

		func setdataplacement cValue
			cAttrOutput += ' data-placement = "' + cValue + '"'

		func setdatacontent cValue
			cAttrOutput += ' data-content = "' + cValue + '"'

		func setdatatrigger cValue
			cAttrOutput += ' data-trigger = "' + cValue + '"'

		func setdataspy cValue
			cAttrOutput += ' data-spy = "' + cValue + '"'

		func setdataoffset cValue
			cAttrOutput += ' data-offset = "' + cValue + '"'

		func setdataoffsettop cValue
			cAttrOutput += ' data-offset-top = "' + cValue + '"'

		# css
		func setcolor cValue
			cStyleOutput += 'color : ' + cValue + '; '

		func setopacity cValue
			cStyleOutput += 'opacity : ' + cValue + '; '

		func setbackground cValue
			cStyleOutput += 'background : ' + cValue + '; '

		func setbackgroundattachment cValue
			cStyleOutput += 'background-attachment : ' + cValue + '; '

		func setbackgroundcolor cValue
			cStyleOutput += 'background-color : ' + cValue + '; '

		func setbackgroundimage cValue
			cStyleOutput += 'background-image : ' + cValue + '; '

		func setbackgroundposition cValue
			cStyleOutput += 'background-position : ' + cValue + '; '

		func setbackgroundrepeat cValue
			cStyleOutput += 'background-repeat : ' + cValue + '; '

		func setbackgroundclip cValue
			cStyleOutput += 'background-clip : ' + cValue + '; '

		func setbackgroundorigin cValue
			cStyleOutput += 'background-origin : ' + cValue + '; '

		func setbackgroundsize cValue
			cStyleOutput += 'background-size : ' + cValue + '; '

		func setborder cValue
			cStyleOutput += 'border : ' + cValue + '; '

		func setborderbottom cValue
			cStyleOutput += 'border-bottom : ' + cValue + '; '

		func setborderbottomcolor cValue
			cStyleOutput += 'border-bottom-color : ' + cValue + '; '

		func setborderbottomleftradius cValue
			cStyleOutput += 'border-bottom-left-radius : ' + cValue + '; '

		func setborderbottomrightradius cValue
			cStyleOutput += 'border-bottom-right-radius : ' + cValue + '; '

		func setborderbottomstyle cValue
			cStyleOutput += 'border-bottom-style : ' + cValue + '; '

		func setborderbottomwidth cValue
			cStyleOutput += 'border-bottom-width : ' + cValue + '; '

		func setbordercolor cValue
			cStyleOutput += 'border-color : ' + cValue + '; '

		func setborderimage cValue
			cStyleOutput += 'border-image : ' + cValue + '; '

		func setborderimageoutset cValue
			cStyleOutput += 'border-image-outset : ' + cValue + '; '

		func setborderimagerepeat cValue
			cStyleOutput += 'border-image-repeat : ' + cValue + '; '

		func setborderimageslice cValue
			cStyleOutput += 'border-image-slice : ' + cValue + '; '

		func setborderimagesource cValue
			cStyleOutput += 'border-image-source : ' + cValue + '; '

		func setborderimagewidth cValue
			cStyleOutput += 'border-image-width : ' + cValue + '; '

		func setborderleft cValue
			cStyleOutput += 'border-left : ' + cValue + '; '

		func setborderleftcolor cValue
			cStyleOutput += 'border-left-color : ' + cValue + '; '

		func setborderleftstyle cValue
			cStyleOutput += 'border-left-style : ' + cValue + '; '

		func setborderleftwidth cValue
			cStyleOutput += 'border-left-width : ' + cValue + '; '

		func setborderradius cValue
			cStyleOutput += 'border-radius : ' + cValue + '; '

		func setborderright cValue
			cStyleOutput += 'border-right : ' + cValue + '; '

		func setborderrightcolor cValue
			cStyleOutput += 'border-right-color : ' + cValue + '; '

		func setborderrightstyle cValue
			cStyleOutput += 'border-right-style : ' + cValue + '; '

		func setborderrightwidth cValue
			cStyleOutput += 'border-right-width : ' + cValue + '; '

		func setborderstyle cValue
			cStyleOutput += 'border-style : ' + cValue + '; '

		func setbordertop cValue
			cStyleOutput += 'border-top : ' + cValue + '; '

		func setbordertopcolor cValue
			cStyleOutput += 'border-top-color : ' + cValue + '; '

		func setbordertopleftradius cValue
			cStyleOutput += 'border-top-left-radius : ' + cValue + '; '

		func setbordertoprightradius cValue
			cStyleOutput += 'border-top-right-radius : ' + cValue + '; '

		func setbordertopstyle cValue
			cStyleOutput += 'border-top-style : ' + cValue + '; '

		func setbordertopwidth cValue
			cStyleOutput += 'border-top-width : ' + cValue + '; '

		func setborderwidth cValue
			cStyleOutput += 'border-width : ' + cValue + '; '

		func setboxdecorationbreak cValue
			cStyleOutput += 'box-decoration-break : ' + cValue + '; '

		func setboxshadow cValue
			cStyleOutput += 'box-shadow : ' + cValue + '; '

		func setbottom cValue
			cStyleOutput += 'bottom : ' + cValue + '; '

		func setclear cValue
			cStyleOutput += 'clear : ' + cValue + '; '

		func setclip cValue
			cStyleOutput += 'clip : ' + cValue + '; '

		func setdisplay cValue
			cStyleOutput += 'display : ' + cValue + '; '

		func setfloat cValue
			cStyleOutput += 'float : ' + cValue + '; '

		func setheight cValue
			cStyleOutput += 'height : ' + cValue + '; '

		func setleft cValue
			cStyleOutput += 'left : ' + cValue + '; '

		func setmargin cValue
			cStyleOutput += 'margin : ' + cValue + '; '

		func setmarginbottom cValue
			cStyleOutput += 'margin-bottom : ' + cValue + '; '

		func setmarginleft cValue
			cStyleOutput += 'margin-left : ' + cValue + '; '

		func setmarginright cValue
			cStyleOutput += 'margin-right : ' + cValue + '; '

		func setmargintop cValue
			cStyleOutput += 'margin-top : ' + cValue + '; '

		func setmaxheight cValue
			cStyleOutput += 'max-height : ' + cValue + '; '

		func setmaxwidth cValue
			cStyleOutput += 'max-width : ' + cValue + '; '

		func setminheight cValue
			cStyleOutput += 'min-height : ' + cValue + '; '

		func setminwidth cValue
			cStyleOutput += 'min-width : ' + cValue + '; '

		func setoverflow cValue
			cStyleOutput += 'overflow : ' + cValue + '; '

		func setoverflowx cValue
			cStyleOutput += 'overflow-x : ' + cValue + '; '

		func setoverflowy cValue
			cStyleOutput += 'overflow-y : ' + cValue + '; '

		func setpadding cValue
			cStyleOutput += 'padding : ' + cValue + '; '

		func setpaddingbottom cValue
			cStyleOutput += 'padding-bottom : ' + cValue + '; '

		func setpaddingleft cValue
			cStyleOutput += 'padding-left : ' + cValue + '; '

		func setpaddingright cValue
			cStyleOutput += 'padding-right : ' + cValue + '; '

		func setpaddingtop cValue
			cStyleOutput += 'padding-top : ' + cValue + '; '

		func setposition cValue
			cStyleOutput += 'position : ' + cValue + '; '

		func setright cValue
			cStyleOutput += 'right : ' + cValue + '; '

		func settop cValue
			cStyleOutput += 'top : ' + cValue + '; '

		func setvisibility cValue
			cStyleOutput += 'visibility : ' + cValue + '; '

		func setwidth cValue
			cStyleOutput += 'width : ' + cValue + '; '

		func setverticalalign cValue
			cStyleOutput += 'vertical-align : ' + cValue + '; '

		func setzindex cValue
			cStyleOutput += 'z-index : ' + cValue + '; '

		func setaligncontent cValue
			cStyleOutput += 'align-content : ' + cValue + '; '

		func setalignitems cValue
			cStyleOutput += 'align-items : ' + cValue + '; '

		func setalignself cValue
			cStyleOutput += 'align-self : ' + cValue + '; '

		func setflex cValue
			cStyleOutput += 'flex : ' + cValue + '; '

		func setflexbasis cValue
			cStyleOutput += 'flex-basis : ' + cValue + '; '

		func setflexdirection cValue
			cStyleOutput += 'flex-direction : ' + cValue + '; '

		func setflexflow cValue
			cStyleOutput += 'flex-flow : ' + cValue + '; '

		func setflexgrow cValue
			cStyleOutput += 'flex-grow : ' + cValue + '; '

		func setflexshrink cValue
			cStyleOutput += 'flex-shrink : ' + cValue + '; '

		func setflexwrap cValue
			cStyleOutput += 'flex-wrap : ' + cValue + '; '

		func setjustifycontent cValue
			cStyleOutput += 'justify-content : ' + cValue + '; '

		func setorder cValue
			cStyleOutput += 'order : ' + cValue + '; '

		func sethangingpunctuation cValue
			cStyleOutput += 'hanging-punctuation : ' + cValue + '; '

		func sethyphens cValue
			cStyleOutput += 'hyphens : ' + cValue + '; '

		func setletterspacing cValue
			cStyleOutput += 'letter-spacing : ' + cValue + '; '

		func setlinebreak cValue
			cStyleOutput += 'line-break : ' + cValue + '; '

		func setlineheight cValue
			cStyleOutput += 'line-height : ' + cValue + '; '

		func setoverflowwrap cValue
			cStyleOutput += 'overflow-wrap : ' + cValue + '; '

		func settabsize cValue
			cStyleOutput += 'tab-size : ' + cValue + '; '

		func settextalign cValue
			cStyleOutput += 'text-align : ' + cValue + '; '

		func settextalignlast cValue
			cStyleOutput += 'text-align-last : ' + cValue + '; '

		func settextcombineupright cValue
			cStyleOutput += 'text-combine-upright : ' + cValue + '; '

		func settextindent cValue
			cStyleOutput += 'text-indent : ' + cValue + '; '

		func settextjustify cValue
			cStyleOutput += 'text-justify : ' + cValue + '; '

		func settexttransform cValue
			cStyleOutput += 'text-transform : ' + cValue + '; '

		func setwhitespace cValue
			cStyleOutput += 'white-space : ' + cValue + '; '

		func setwordbreak cValue
			cStyleOutput += 'word-break : ' + cValue + '; '

		func setwordspacing cValue
			cStyleOutput += 'word-spacing : ' + cValue + '; '

		func setwordwrap cValue
			cStyleOutput += 'word-wrap : ' + cValue + '; '

		func settextdecoration cValue
			cStyleOutput += 'text-decoration : ' + cValue + '; '

		func settextdecorationcolor cValue
			cStyleOutput += 'text-decoration-color : ' + cValue + '; '

		func settextdecorationline cValue
			cStyleOutput += 'text-decoration-line : ' + cValue + '; '

		func settextdecorationstyle cValue
			cStyleOutput += 'text-decoration-style : ' + cValue + '; '

		func settextshadow cValue
			cStyleOutput += 'text-shadow : ' + cValue + '; '

		func settextunderlineposition cValue
			cStyleOutput += 'text-underline-position : ' + cValue + '; '

		func set@fontface cValue
			cStyleOutput += '@font-face : ' + cValue + '; '

		func set@fontfeaturevalues cValue
			cStyleOutput += '@font-feature-values : ' + cValue + '; '

		func setfont cValue
			cStyleOutput += 'font : ' + cValue + '; '

		func setfontfamily cValue
			cStyleOutput += 'font-family : ' + cValue + '; '

		func setfontfeaturesettings cValue
			cStyleOutput += 'font-feature-settings : ' + cValue + '; '

		func setfontkerning cValue
			cStyleOutput += 'font-kerning : ' + cValue + '; '

		func setfontlanguageoverride cValue
			cStyleOutput += 'font-language-override : ' + cValue + '; '

		func setfontsize cValue
			cStyleOutput += 'font-size : ' + cValue + '; '

		func setfontsizeadjust cValue
			cStyleOutput += 'font-size-adjust : ' + cValue + '; '

		func setfontstretch cValue
			cStyleOutput += 'font-stretch : ' + cValue + '; '

		func setfontstyle cValue
			cStyleOutput += 'font-style : ' + cValue + '; '

		func setfontsynthesis cValue
			cStyleOutput += 'font-synthesis : ' + cValue + '; '

		func setfontvariant cValue
			cStyleOutput += 'font-variant : ' + cValue + '; '

		func setfontvariantalternates cValue
			cStyleOutput += 'font-variant-alternates : ' + cValue + '; '

		func setfontvariantcaps cValue
			cStyleOutput += 'font-variant-caps : ' + cValue + '; '

		func setfontvarianteastasian cValue
			cStyleOutput += 'font-variant-east-asian : ' + cValue + '; '

		func setfontvariantligatures cValue
			cStyleOutput += 'font-variant-ligatures : ' + cValue + '; '

		func setfontvariantnumeric cValue
			cStyleOutput += 'font-variant-numeric : ' + cValue + '; '

		func setfontvariantposition cValue
			cStyleOutput += 'font-variant-position : ' + cValue + '; '

		func setfontweight cValue
			cStyleOutput += 'font-weight : ' + cValue + '; '

		func setdirection cValue
			cStyleOutput += 'direction : ' + cValue + '; '

		func settextorientation cValue
			cStyleOutput += 'text-orientation : ' + cValue + '; '

		func setunicodebidi cValue
			cStyleOutput += 'unicode-bidi : ' + cValue + '; '

		func setwritingmode cValue
			cStyleOutput += 'writing-mode : ' + cValue + '; '

		func setbordercollapse cValue
			cStyleOutput += 'border-collapse : ' + cValue + '; '

		func setborderspacing cValue
			cStyleOutput += 'border-spacing : ' + cValue + '; '

		func setcaptionside cValue
			cStyleOutput += 'caption-side : ' + cValue + '; '

		func setemptycells cValue
			cStyleOutput += 'empty-cells : ' + cValue + '; '

		func settablelayout cValue
			cStyleOutput += 'table-layout : ' + cValue + '; '

		func setcounterincrement cValue
			cStyleOutput += 'counter-increment : ' + cValue + '; '

		func setcounterreset cValue
			cStyleOutput += 'counter-reset : ' + cValue + '; '

		func setliststyle cValue
			cStyleOutput += 'list-style : ' + cValue + '; '

		func setliststyleimage cValue
			cStyleOutput += 'list-style-image : ' + cValue + '; '

		func setliststyleposition cValue
			cStyleOutput += 'list-style-position : ' + cValue + '; '

		func setliststyletype cValue
			cStyleOutput += 'list-style-type : ' + cValue + '; '

		func set@keyframes cValue
			cStyleOutput += '@keyframes : ' + cValue + '; '

		func setanimation cValue
			cStyleOutput += 'animation : ' + cValue + '; '

		func setanimationdelay cValue
			cStyleOutput += 'animation-delay : ' + cValue + '; '

		func setanimationdirection cValue
			cStyleOutput += 'animation-direction : ' + cValue + '; '

		func setanimationduration cValue
			cStyleOutput += 'animation-duration : ' + cValue + '; '

		func setanimationfillmode cValue
			cStyleOutput += 'animation-fill-mode : ' + cValue + '; '

		func setanimationiterationcount cValue
			cStyleOutput += 'animation-iteration-count : ' + cValue + '; '

		func setanimationname cValue
			cStyleOutput += 'animation-name : ' + cValue + '; '

		func setanimationplaystate cValue
			cStyleOutput += 'animation-play-state : ' + cValue + '; '

		func setanimationtimingfunction cValue
			cStyleOutput += 'animation-timing-function : ' + cValue + '; '

		func setbackfacevisibility cValue
			cStyleOutput += 'backface-visibility : ' + cValue + '; '

		func setperspective cValue
			cStyleOutput += 'perspective : ' + cValue + '; '

		func setperspectiveorigin cValue
			cStyleOutput += 'perspective-origin : ' + cValue + '; '

		func settransform cValue
			cStyleOutput += 'transform : ' + cValue + '; '

		func settransformorigin cValue
			cStyleOutput += 'transform-origin : ' + cValue + '; '

		func settransformstyle cValue
			cStyleOutput += 'transform-style : ' + cValue + '; '

		func settransition cValue
			cStyleOutput += 'transition : ' + cValue + '; '

		func settransitionproperty cValue
			cStyleOutput += 'transition-property : ' + cValue + '; '

		func settransitionduration cValue
			cStyleOutput += 'transition-duration : ' + cValue + '; '

		func settransitiontimingfunction cValue
			cStyleOutput += 'transition-timing-function : ' + cValue + '; '

		func settransitiondelay cValue
			cStyleOutput += 'transition-delay : ' + cValue + '; '

		func setboxsizing cValue
			cStyleOutput += 'box-sizing : ' + cValue + '; '

		func setcontent cValue
			cStyleOutput += 'content : ' + cValue + '; '

		func setcursor cValue
			cStyleOutput += 'cursor : ' + cValue + '; '

		func setimemode cValue
			cStyleOutput += 'ime-mode : ' + cValue + '; '

		func setnavdown cValue
			cStyleOutput += 'nav-down : ' + cValue + '; '

		func setnavindex cValue
			cStyleOutput += 'nav-index : ' + cValue + '; '

		func setnavleft cValue
			cStyleOutput += 'nav-left : ' + cValue + '; '

		func setnavright cValue
			cStyleOutput += 'nav-right : ' + cValue + '; '

		func setnavup cValue
			cStyleOutput += 'nav-up : ' + cValue + '; '

		func setoutline cValue
			cStyleOutput += 'outline : ' + cValue + '; '

		func setoutlinecolor cValue
			cStyleOutput += 'outline-color : ' + cValue + '; '

		func setoutlineoffset cValue
			cStyleOutput += 'outline-offset : ' + cValue + '; '

		func setoutlinestyle cValue
			cStyleOutput += 'outline-style : ' + cValue + '; '

		func setoutlinewidth cValue
			cStyleOutput += 'outline-width : ' + cValue + '; '

		func setresize cValue
			cStyleOutput += 'resize : ' + cValue + '; '

		func settextoverflow cValue
			cStyleOutput += 'text-overflow : ' + cValue + '; '

		func setbreakafter cValue
			cStyleOutput += 'break-after : ' + cValue + '; '

		func setbreakbefore cValue
			cStyleOutput += 'break-before : ' + cValue + '; '

		func setbreakinside cValue
			cStyleOutput += 'break-inside : ' + cValue + '; '

		func setcolumncount cValue
			cStyleOutput += 'column-count : ' + cValue + '; '

		func setcolumnfill cValue
			cStyleOutput += 'column-fill : ' + cValue + '; '

		func setcolumngap cValue
			cStyleOutput += 'column-gap : ' + cValue + '; '

		func setcolumnrule cValue
			cStyleOutput += 'column-rule : ' + cValue + '; '

		func setcolumnrulecolor cValue
			cStyleOutput += 'column-rule-color : ' + cValue + '; '

		func setcolumnrulestyle cValue
			cStyleOutput += 'column-rule-style : ' + cValue + '; '

		func setcolumnrulewidth cValue
			cStyleOutput += 'column-rule-width : ' + cValue + '; '

		func setcolumnspan cValue
			cStyleOutput += 'column-span : ' + cValue + '; '

		func setcolumnwidth cValue
			cStyleOutput += 'column-width : ' + cValue + '; '

		func setcolumns cValue
			cStyleOutput += 'columns : ' + cValue + '; '

		func setwidows cValue
			cStyleOutput += 'widows : ' + cValue + '; '

		func setorphans cValue
			cStyleOutput += 'orphans : ' + cValue + '; '

		func setpagebreakafter cValue
			cStyleOutput += 'page-break-after : ' + cValue + '; '

		func setpagebreakbefore cValue
			cStyleOutput += 'page-break-before : ' + cValue + '; '

		func setpagebreakinside cValue
			cStyleOutput += 'page-break-inside : ' + cValue + '; '

		func setmarks cValue
			cStyleOutput += 'marks : ' + cValue + '; '

		func setquotes cValue
			cStyleOutput += 'quotes : ' + cValue + '; '

		func setfilter cValue
			cStyleOutput += 'filter : ' + cValue + '; '

		func setimageorientation cValue
			cStyleOutput += 'image-orientation : ' + cValue + '; '

		func setimagerendering cValue
			cStyleOutput += 'image-rendering : ' + cValue + '; '

		func setimageresolution cValue
			cStyleOutput += 'image-resolution : ' + cValue + '; '

		func setobjectfit cValue
			cStyleOutput += 'object-fit : ' + cValue + '; '

		func setobjectposition cValue
			cStyleOutput += 'object-position : ' + cValue + '; '

		func setmask cValue
			cStyleOutput += 'mask : ' + cValue + '; '

		func setmasktype cValue
			cStyleOutput += 'mask-type : ' + cValue + '; '

		func setmark cValue
			cStyleOutput += 'mark : ' + cValue + '; '

		func setmarkafter cValue
			cStyleOutput += 'mark-after : ' + cValue + '; '

		func setmarkbefore cValue
			cStyleOutput += 'mark-before : ' + cValue + '; '

		func setphonemes cValue
			cStyleOutput += 'phonemes : ' + cValue + '; '

		func setrest cValue
			cStyleOutput += 'rest : ' + cValue + '; '

		func setrestafter cValue
			cStyleOutput += 'rest-after : ' + cValue + '; '

		func setrestbefore cValue
			cStyleOutput += 'rest-before : ' + cValue + '; '

		func setvoicebalance cValue
			cStyleOutput += 'voice-balance : ' + cValue + '; '

		func setvoiceduration cValue
			cStyleOutput += 'voice-duration : ' + cValue + '; '

		func setvoicepitch cValue
			cStyleOutput += 'voice-pitch : ' + cValue + '; '

		func setvoicepitchrange cValue
			cStyleOutput += 'voice-pitch-range : ' + cValue + '; '

		func setvoicerate cValue
			cStyleOutput += 'voice-rate : ' + cValue + '; '

		func setvoicestress cValue
			cStyleOutput += 'voice-stress : ' + cValue + '; '

		func setvoicevolume cValue
			cStyleOutput += 'voice-volume : ' + cValue + '; '

		func setmarqueedirection cValue
			cStyleOutput += 'marquee-direction : ' + cValue + '; '

		func setmarqueeplaycount cValue
			cStyleOutput += 'marquee-play-count : ' + cValue + '; '

		func setmarqueespeed cValue
			cStyleOutput += 'marquee-speed : ' + cValue + '; '

		func setmarqueestyle cValue
			cStyleOutput += 'marquee-style : ' + cValue + '; '
