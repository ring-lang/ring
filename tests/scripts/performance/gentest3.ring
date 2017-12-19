fp = fopen("test3.ring","w+")
for t = 1 to 300000
	fputs(fp, 'x = ' + t + windowsnl())
next
fclose(fp)
