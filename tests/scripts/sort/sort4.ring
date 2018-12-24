myList1 = [new Company {position=3 name="Mahmoud" symbol="MHD"},

                new Company {position=2 name="Bert" symbol="BRT"},

                new Company {position=1 name="Ring" symbol="RNG"}
          ]

see sort(mylist1,1,"position")
see copy("*",60) + nl
see sort(mylist1,1,"name")

class company position name symbol