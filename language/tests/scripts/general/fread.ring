fp = fopen(filename(),"rb")

cData = fread(fp,1000)
cData = substr(cData,WindowsNL(),NL)
? "Size: " + len(cData)
? cData

fclose(fp)	# Not necessary in Ring