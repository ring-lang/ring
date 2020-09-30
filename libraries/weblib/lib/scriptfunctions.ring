# The Ring Standard Library
# Web Library
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

Package System.Web

	Class ScriptFunctions
		
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
