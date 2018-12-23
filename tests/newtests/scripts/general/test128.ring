# Storing binary data inside lists - using the Space() function
B=list(4) 
for k=1 to 4
{ 
	B[k]= Space(4) 
  	for kk=1 to 4 { 
		B[k][kk]= char(60+4*k +kk) 
	}
	? " B" +k +": " +B[k]
}
