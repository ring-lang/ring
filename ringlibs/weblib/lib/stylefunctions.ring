# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web

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
