load "stdlib.ring"

table = newlist(32, 2)
dividend = 580
divisor = 34
 
i = 1
table[i][1] = 1
table[i][2] = divisor
 
while table[i][2] < dividend
      i = i + 1
      table[i][1] = table[i-1][1] * 2
      table[i][2] = table[i-1][2] * 2
end 
i = i - 1
answer = table[i][1]
accumulator = table[i][2]
 
while i > 1
      i = i - 1
      if table[i][2]+ accumulator <= dividend 
         answer = answer + table[i][1]
         accumulator = accumulator + table[i][2]
      ok
end
 
see string(dividend)  + " divided by " + string(divisor) + " using egyptian division" + nl
see " returns " + string(answer) + " mod(ulus) " + string(dividend-accumulator)
