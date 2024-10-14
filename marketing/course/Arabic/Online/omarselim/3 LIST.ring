alist =[]


while true
	see"
	(1)add number
	(2) sum number
	(3) exit
	
"give coption 
	switch coption 
		on "1" see "enter number : " give cnumber alist+cnumber 
		on "2" nsum=0 for nnum in alist nsum =nsum +nnum next
? "sum:" +nsum
		on "3"	bye 
		other 
off 
end
