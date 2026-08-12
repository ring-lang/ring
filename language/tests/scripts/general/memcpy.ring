# Written by Mansour Ayouni

cBuf = space(64)
p = varptr(:cBuf, "char *")
memcpy(p, int2bytes(7),   4)     # 07000000  -> fine
? bytes2int(left(cBuf,4))
memcpy(p, int2bytes(256), 4)     # 00010000  -> process aborts
? bytes2int(left(cBuf,4))
memcpy(p, double2bytes(1.5), 8)  # -> aborts
? bytes2double(left(cBuf,8))
memcpy(p, char(0), 1)            # -> aborts, copying one byte
? :done