#!ring -cgi

Load "weblib.ring"
Load "openssllib.ring"
Import System.Web

New Page 
{
	boxstart()
		text( "Hash Result" )
		newline()
	boxend()
	divstart([:style = styleFloatLeft() + styleWidth("100%") ])
		newline()
		text( "Value : " + aPageVars["Value"] )  	
		newline()
		text( "MD5 : " + md5(aPageVars["Value"]) )  	
		newline()
		text( "SHA1 : " + SHA1(aPageVars["Value"]) )
		newline()
		text( "SHA256 : " + SHA256(aPageVars["Value"]) )
		newline()
		text( "SHA224 : " + SHA224(aPageVars["Value"]) )
		newline()
		text( "SHA384 : " + SHA384(aPageVars["Value"]) )
		newline()
		text( "SHA512 : " + SHA512(aPageVars["Value"]) )
		newline()
	divend()
}	
