fp = fopen("findcpointer.ring","r")
fp2 = fopen("findcpointer.ring","r")
fp3 = fopen("findcpointer.ring","r")

aList = [fp,fp2,fp3]

see find(aList,fp) + nl
see find(aList,fp3) + nl
see find(aList,fp2) + nl

fclose(fp)
fclose(fp2)
fclose(fp3)

