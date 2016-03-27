fp = fopen("tests\s65.nova","r")

see fp
fp2 = fp
see fp2

fclose(fp)
see fp
see fp2
r = fgetc(fp2)
see r

fclose(fp2)
see "done..." + nl

