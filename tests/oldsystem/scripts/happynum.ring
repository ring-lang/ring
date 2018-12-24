n = 1

found = 0


While found < 8

   If IsHappy(n)

          found += 1

         see string(found) + " : " + string(n) + nl

   ok

   n += 1

End


Func IsHappy n

   cache = []

   While n != 1

       Add(cache,n)

       t = 0

        strn = string(n)

        for e in strn
           t += pow(number(e),2)
        next

       n = t

       If find(cache,n) Return False ok

   End

   Return True
