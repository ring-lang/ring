# Author: Mansour Ayouni
# An empty Catch block must not grow the VM stack

? :start

for i = 1 to 2000
    try  raise("x")  catch  done
next

? :done