fp = fopen("test2.ring","w+")
for t = 1 to 500000
	fputs(fp, 'x = ' + t + windowsnl())
next
fclose(fp)
