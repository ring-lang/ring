# Based on code from MatrixLib by Bert Mariani

L = [-2,-1]

L = PolyMultiply(L,[-1])

? L

Func PolyMultiply(A,B)

   Alen = len(A)
   Blen = len(B)

   Prod = List(Alen + Blen -1)

   for i=1 to Alen
      for j=1 to Blen
         Prod[i+j-1] += A[i] * B[j]
      next
   next
   
return Prod   //   Flat Matrix [1,2,3] Pwr 0,1,2,3 etc
  
