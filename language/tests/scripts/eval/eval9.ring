# Based on a report by isVowel

? "Try ? eval('0+1') - Miss Return command - We expect no output!"
? eval("0+1")
? "Try ? eval('return 0+1') - We expect 1"
? eval("return 0+1")