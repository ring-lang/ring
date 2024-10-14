/*
	Application	: simple log in form 
	Author  	: Walid Ahmed 
	Date 		: 11/12/2017
*/
data=[]
load "stdlib.ring"
see"         Welcome to our community :) "+nl

see" 1st name "+nl give fname
add(data,fname)
while isnull(fname)=1
 see "required info , enter your name"+nl
give fname
end
 add(data,fname) 

see"family name "+nl  give faname
while isnull(faname)=1
 see "required info , enter your family name"+nl
give faname
end
add(data,faname)
see "enter your age "+nl age= getnumber()
while isnull(age)=1
 see "required info , enter your age"+nl
age= getnumber() end
add(data,age)


see "enter your country"+nl give country 
while isnull(country)=1
 see "required info , enter your country"+nl
end
add(data,country)

see " enter your password"+nl give pass
while isnull(pass)=1
 see "required info , enter your pass"+nl
end
add(data,pass=[])

see "Done *******************"
