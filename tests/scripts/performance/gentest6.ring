fp = fopen("test6.ring","w+")
for t = 1 to 500000
	fputs(fp, '? ' + t + windowsnl())
next
fclose(fp)
