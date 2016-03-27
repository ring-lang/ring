f1 = func { see "hello" + nl }

f2 = func { see "how are you?" + nl }

f3 = f1

call f1()
call f2()
call f3()

see (f1 = f2) + nl
see (f2 = f3) + nl
see (f1 = f3) + nl
