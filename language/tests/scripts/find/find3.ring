myList1 = [new Company {position=3 name="Mahmoud" symbol="MHD"},

                new Company {position=2 name="Bert" symbol="BRT"},

                new Company {position=1 name="Ring" symbol="RNG"}
          ]

see find(mylist1,"Bert",1,"name") + nl
see find(mylist1,"Ring",1,"name") + nl
see find(mylist1,"Mahmoud",1,"name") + nl
see find(mylist1,"RNG",1,"symbol") + nl
see find(mylist1,"MHD",1,"symbol") + nl
see find(mylist1,"BRT",1,"symbol") + nl
see find(mylist1,3,1,"position") + nl
see find(mylist1,1,1,"position") + nl
see "Other" + nl
see find(mylist1,"test",1,"name") + nl
see find(mylist1,"test",0,"name") + nl
see find(mylist1,"test",5,"name") + nl

try
see find(mylist1,"RNG",1,"ASYMBOL") + nl
catch  
	see "catch error!" + nl
done

see "end of test" + nl
class company position name symbol