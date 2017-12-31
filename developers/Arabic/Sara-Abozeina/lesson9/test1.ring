/*
**	Application:security keys
**	Author	   :Sara Abozeina
**	Date       :2017.12.31
*/
load "openssllib.ring"

while true
	? "Enter password: " Give passwd
	tab=char(9)+char(9)
	? tab + "
		(1) MD5
		(2) SHA1
		(3) SHA256
		(4) SHA512
		"Give nchoice
		switch nchoice
			case 1 ? "Md5= "   + MD5(passwd)
			case 2 ? "SHA1= "   + SHA1(passwd)
			case 3 ? "SHA256= " + SHA256(passwd)
			case 4 ? "SHA512= " + SHA512(passwd)
			other  ? "Bad Option,try again,...."
		end
end
