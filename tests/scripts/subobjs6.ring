mergemethods("objsbase","mymethods")

	Screen() 
	{

		point() 
		{ 			# access the object using reference 
			/*one = 1
			two = 2
			three = 3
			x = 100 
			y = 200
			z = 300		
*/
			link()
			{
				title = "great"
				nono = 0
				habal = "what"
			}
		}

		point() 
		{ 			# access the object using reference 
			x = 50 
			y = 150
			z = 250		
		}
	}

Func screen return new screen

Class Screen from base
	content = []

	func braceend
		see "I have " + len(content) + " points!"

class base
	good test

	func point
		content + new point
		return content[len(content)]	# return the object by reference

	private
		ohno

Class ObjsBase from base
	r t y myobjs = []
	myattr cOutput
	for m = 1 to 10000
		myattr + ("prop"+m)
	next
/*
*/
	addattribute(self,["one","two","three"])
	addattribute(self,myattr)
AddAttribute(self,["classname","id","name","align",
"style","dir","value","onclick","oncontextmenu",
"ondblclick","onmousedown","onmouseenter","onmouseleave","onmousemove",
"onmouseover","onmouseout","onmouseup","onkeydown","onkeypress",
"onkeyup","onabort","onbeforeunload","onerror","onhashchange",
"onload","onpageshow","onpagehide","onresize","onscroll",
"onunload","onblur","onchange","onfocus","onfocusin",
"onfocusout","oninput","oninvalid","onreset","onsearch",
"onselect","onsubmit","ondrag","ondragend","ondragenter",
"ondragleave","ondragover","ondragstart","ondrop","oncopy",
"oncut","onpaste","onafterprint","onbeforeprint","oncanplay",
"oncanplaythrough","ondurationchange","onemptied","onended","onloadeddata",
"onloadedmetadata","onloadstart","onpause","onplay","onplaying",
"onprogress","onratechange","onseeked","onseeking","onstalled",
"onsuspend","ontimeupdate","onvolumechange","onwaiting","animationend",
"animationiteration","animationstart","transitionend","onmessage","onopen",
"onmousewheel","ononline","onoffline","onpostate","onshow",
"onstorage","ontoggle","onwheel","ontouchcancel","ontouchend",
"ontouchmove","ontouchstart","color","opacity","background","backgroundattachment",
"backgroundcolor","backgroundimage","backgroundposition","backgroundrepeat","backgroundclip",
"backgroundorigin","backgroundsize","border","borderbottom","borderbottomcolor",
"borderbottomleftradius","borderbottomrightradius","borderbottomstyle","borderbottomwidth","bordercolor",
"borderimage","borderimageoutset","borderimagerepeat","borderimageslice","borderimagesource",
"borderimagewidth","borderleft","borderleftcolor","borderleftstyle","borderleftwidth",
"borderradius","borderright","borderrightcolor","borderrightstyle","borderrightwidth",
"borderstyle","bordertop","bordertopcolor","bordertopleftradius","bordertoprightradius",
"bordertopstyle","bordertopwidth","borderwidth","boxdecorationbreak","boxshadow",
"bottom","clear","clip","display","float",
"height","left","margin","marginbottom","marginleft",
"marginright","margintop","maxheight","maxwidth","minheight",
"minwidth","overflow","overflowx","overflowy","padding",
"paddingbottom","paddingleft","paddingright","paddingtop","position",
"right","top","visibility","width","verticalalign",
"zindex","aligncontent","alignitems","alignself","flex",
"flexbasis","flexdirection","flexflow","flexgrow","flexshrink",
"flexwrap","justifycontent","order","hangingpunctuation","hyphens",
"letterspacing","linebreak","lineheight","overflowwrap","tabsize",
"textalign","textalignlast","textcombineupright","textindent","textjustify",
"texttransform","whitespace","wordbreak","wordspacing","wordwrap",
"textdecoration","textdecorationcolor","textdecorationline","textdecorationstyle","textshadow",
"textunderlineposition","@fontface","@fontfeaturevalues","font","fontfamily",
"fontfeaturesettings","fontkerning","fontlanguageoverride","fontsize","fontsizeadjust",
"fontstretch","fontstyle","fontsynthesis","fontvariant","fontvariantalternates",
"fontvariantcaps","fontvarianteastasian","fontvariantligatures","fontvariantnumeric","fontvariantposition",
"fontweight","direction","textorientation","unicodebidi","writingmode",
"bordercollapse","borderspacing","captionside","emptycells","tablelayout",
"counterincrement","counterreset","liststyle","liststyleimage","liststyleposition",
"liststyletype","@keyframes","animation","animationdelay","animationdirection",
"animationduration","animationfillmode","animationiterationcount","animationname","animationplaystate",
"animationtimingfunction","backfacevisibility","perspective","perspectiveorigin","transform",
"transformorigin","transformstyle","transition","transitionproperty","transitionduration",
"transitiontimingfunction","transitiondelay","boxsizing","content","cursor",
"imemode","navdown","navindex","navleft","navright",
"navup","outline","outlinecolor","outlineoffset","outlinestyle",
"outlinewidth","resize","textoverflow","breakafter","breakbefore",
"breakinside","columncount","columnfill","columngap","columnrule",
"columnrulecolor","columnrulestyle","columnrulewidth","columnspan","columnwidth",
"columns","widows","orphans","pagebreakafter","pagebreakbefore",
"pagebreakinside","marks","quotes","filter","imageorientation",
"imagerendering","imageresolution","objectfit","objectposition","mask",
"masktype","mark","markafter","markbefore","phonemes",
"rest","restafter","restbefore","voicebalance","voiceduration",
"voicepitch","voicepitchrange","voicerate","voicestress","voicevolume",
"marqueedirection","marqueeplaycount","marqueespeed","marqueestyle",
"datatoggle","dataride","datatarget",
"dataslideto","dataslide","datadismiss", "dataplacement",
"datacontent","datatrigger","dataspy","dataoffset","dataoffsettop"])

/*
*/
	private
		sowhat

class mymethods
	func link
		myobjs + new link
		return myobjs[len(myobjs)]

Class point from ObjsBase
	x=10 y=20 z=30
	func braceend				# will be executed after the end of object access using { }
		see self			# print the object state

class link from objsbase
	title name
	func settitle value
		#title = value
		cOutput += value
	func braceend
		
		see "title " + title + nl