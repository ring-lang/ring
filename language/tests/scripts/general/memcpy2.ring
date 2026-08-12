# Author: Mansour Ayouni

# Binary strings that start with a zero byte must not be detected as
# NULL pointers. See ring_vm_api_ispointer() in ringapi.c

cBuf = space(32)
p = varptr(:cBuf, "char *")

# int2bytes(7) starts with 0x07 - this always worked
memcpy(p, int2bytes(7), 4)
? str2hex(ptr2str(p, 0, 4))

# int2bytes(256) starts with 0x00
memcpy(p, int2bytes(256), 4)
? str2hex(ptr2str(p, 0, 4))

# double2bytes() of a small value starts with six zero bytes
memcpy(p, double2bytes(1.5), 8)
? bytes2double(ptr2str(p, 0, 8))

# a single zero byte
memcpy(p, char(0), 1)
? len(ptr2str(p, 0, 1))

# NULL and "" are still C pointers - the existing behaviour
? type(nullptr())
? isnull(NULL)