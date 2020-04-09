# بسم الله الرحمن الرحيم
// this is Lesson4 -  thanks to Mr.MAHMOUD Fayed
/*
  Application: Conversion Between Lists and strings 
  Author     :  S.BOURROU
  Date       :  13.12.2017  

*/
 
aList = [ :A,:B,:C,:D,:E]

? aList 
? "N°:" + len(aList) #  5!
 
# list to string
cString = list2str(aList)
? len(cString) # 9 !
? cString  

# string to list

aList2 = str2list(cString)
? "N°:" + len(aList2) # 5 !
