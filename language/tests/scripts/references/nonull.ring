try
	ref("")
catch
	? "The ref() function doesn't accept strings"
done

try 
	ref(NULL)
catch
	? "The ref() function doesn't accept NULL"
done

try
	ref(2023)
catch
	? "The ref() function doesn't accept numbers"
done