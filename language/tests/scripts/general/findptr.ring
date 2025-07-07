fp1 = fopen(filename(),"r")
fp2 = fopen(filename(),"r")
fp3 = fopen(filename(),"r")

aList = [fp3, fp2, fp1]

? find(aList,fp1)
? find(aList,fp2)
? find(aList,fp3)
