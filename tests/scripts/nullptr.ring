fp = fopen("scripts/nullptr.ring","r")
fp2 = fopen("scripts/nullptr.ring","r")
fp3 = fp
see fp = fp2
see nl
see fp = fp3
see nl
fclose(fp)
fclose(fp2)
try
	fclose(fp3)
catch
	? "Wow, we get error here!"
end
