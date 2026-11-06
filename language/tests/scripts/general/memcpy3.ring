? "Start"

cDest = space(16)

memcpy(varptr(:cDest,:char), "RINGLANG", 8)

? cDest

try
	memcpy(cDest, "RINGLANG", 8)
catch
	? :error
done


cBuf = space(32)

p = varptr(:cBuf, "char *")
memcpy(p, int2bytes(1),   4)    
? :one
memcpy(p, int2bytes(256), 4)    
? :Two
memcpy(p, double2bytes(1.2), 8) 
? :three

try
	memcpy(p, "NULL", 4)           
catch
	? :error
done

? :four
? len(char(0))
MEMCPY(p, "* I Love Programming", 20)
? cBuf
memcpy(p, CHAR(0), 1)
? cBuf
? len(cBuf)

? "Done"