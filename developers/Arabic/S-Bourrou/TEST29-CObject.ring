# بسم الله الرحمن الرحيم
// this is Lesson4 -  thanks to Mr.MAHMOUD Fayed
/*
  Application:  Object
  Author     :  S.BOURROU
  Date       :  14.12.2017  
*/

  filePointer = fopen("TEST29-COBject.ring","r")
  for x=1 to 5  
  ? fgets(filePointer,100)
  next  ? filePointer

  fclose(filePointer)   // close
  
 ? type(filePointer) // type :file !

