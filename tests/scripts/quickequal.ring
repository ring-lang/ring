x = 10
x += 5
see x + nl

x -= 2
see x + nl

x *= 3
see x + nl

x /= 2
see x + nl

x += 1.5
see x + nl

x %= 2
see x + nl

x = 4
x &= 5
see x + nl

x = 8
x |= 5
see x + nl

x ^= 5
see x + nl

x <<= 1
see x + nl

x >>= 2
see x + nl

mylist = [1,2,3,4,5]

mylist[1] += 5
see mylist[1] + nl

mylist[2] -= 5
see mylist[2] + nl

mylist[3] *= 5
see mylist[3] + nl

mylist[4] /= 2
see mylist[4] + nl

mylist[5] %= 2
see mylist[5] + nl

mylist[5] <<= 4
see mylist[5] + nl

mylist[5] >>= 2
see mylist[5] + nl

mylist[5] &= 5
see mylist[5] + nl

mylist[5] |= 8
see mylist[5] + nl

mylist[5] ^= 2
see mylist[5] + nl

mylist[5] ^= 14
see mylist[5] + nl

o1 = new test

o1.value += 10
see o1.value + nl

o1.list[3] += 7
see o1.list[3] + nl

try
x = 1
x += "2"
catch
see "Error 1 " + nl
done

x = "1"
x += 1
see x + nl

name = "Mahmoud "
name += "Fayed"
see name + nl

x = 10
x += "5"
see x + nl

mylist = [1,2,"3",4,5]
mylist[3] += 5
see mylist[3] + nl

mylist[1] += "4"
see mylist[1] + nl

mylist[3] += "nice"
see mylist[3] + nl

Class Test
	value = 10
	list = [1,2,3]