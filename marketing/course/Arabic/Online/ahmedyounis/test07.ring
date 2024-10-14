/*
 * Application : Variables (Strings)
 * Author      : Ahmed Younis
 * Date        : 2017.12.11
 */

# VARIABLES TYPES (STRING, NUMBER, LIST, OBJECT, C OBJECT)

# STRINGS  TYPES	
# علامات التنصيص تكون للجمل
mystring = " welcome to the ring programming lang   " 
# علامة التنصيص المفردة  يمكن التعبير بها عن النصوص 
mystring02= ' another string  ' 
# العلامة اسفل حرف الذال نعبر ها عن النصوص
mystrings03=` another string` 
#النقطتان نعبر بها عن كلمة واحدة
mystring04 = :welcome
# لو محتاج يكون حرف واحد بيكون ب علامات التنصيص 
mycharacter= "a"
#يمكن بعلامات التنصيص الكتابة على اكثر من سطر
 mymultistring=" one two
 	 three four
			 five six 		
								"
/*
لطباعة جميع السطور وبنفس الوقت يضع السطر الاخر على سطر 
جديد وليس بجانب بعض يكون من خلال علامة الاستفهام هكذا 
*/
? mystring             # تعادل   see ---------- + nl   
? mystring02
? mystrings03
? mystring04 ? mycharacter ?mymultistring    
