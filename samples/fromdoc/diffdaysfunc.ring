cDate1 = date()
see cDate1 + nl                                         # 24/05/2015
cDate2 = adddays(cDate1,10)
see cDate2 + nl                                         # 03/06/2015
see "DiffDays = " + diffdays(cDate1,cDate2) + nl        # -10
see "DiffDays = " + diffdays(cDate2,cDate1) + nl        # 10
