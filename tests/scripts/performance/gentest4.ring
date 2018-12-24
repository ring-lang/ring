fp = fopen("test4.ring","w+")
for t = 1 to 20000
	fputs(fp, 'myfunc(' + t + ')' + windowsnl())
next
fputs(fp,"func myfunc x x++ ")
fclose(fp)
