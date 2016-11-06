fp = fopen("findcpointer.ring","r")
fp2 = fopen("findcpointer.ring","r")
fp3 = fopen("findcpointer.ring","r")

aList = [["test1",fp],["test2",fp2],["test3",fp3]]

see alist[find(aList,fp,2)][1] + nl
see alist[find(aList,fp3,2)][1] + nl
see alist[find(aList,fp2,2)][1] + nl

fclose(fp)
fclose(fp2)
fclose(fp3)

