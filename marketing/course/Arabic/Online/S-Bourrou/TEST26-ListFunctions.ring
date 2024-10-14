# بسم الله الرحمن الرحيم
// this is Lesson4 -  thanks to Mr.MAHMOUD Fayed
/*
  Application: list Functions 
  Author     :  S.BOURROU
  Date       :  13.12.2017  
*/

aList =  1:10
? alist 
 del(aList,9) # delete 9 
 ? alist 

aList + "Products"
aList + "shipping"
aList + "Address"

? "Products Position :" + find(aList,"Products")  # 10

aList = [
       ["Laptop"  ,"1.00  BTC"   ],
       ["Books"   ,"0.001 BTC"  ],
       ["Cars"    ,"6.08  BTC"   ],
       ["Bike"    ,"0.01  BTC"   ]
      ]

? aList[ find(aList,"Books",1)][2] # get Books value 
? aList[find(alist,"Cars",1)] # Get Cars and value 



