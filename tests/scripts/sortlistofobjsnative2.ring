myList1 = [
            new Company {position=3 name="Mahmoud" symbol="MHD"},
            new Company {position=2 name="Bert" symbol="BRT"},
            new Company {position=8 name="Charlie" symbol="CHR"},
            new Company {position=6 name="Easy" symbol="FEAS"},
            new Company {position=7 name="Fox" symbol="EFOX"},
            new Company {position=5 name="Dog" symbol="GDOG"},
            new Company {position=4 name="George" symbol="DGRG"},
            new Company {position=1 name="Ring" symbol="RNG"}
          ]

see sort(mylist1,1,"name")
see copy("*",70) + nl
see sort(mylist1,1,"symbol")
see copy("*",70) + nl
see sort(mylist1,1,"position")


class company position name symbol