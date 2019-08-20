# Project : Dijkstra's algorithm
# Date    : 2018/02/13
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
graph = [["a", "b", 7],
              ["a", "c", 9],
              ["a", "f", 14],
              ["b", "c", 10],
              ["b", "d", 15],
              ["c", "d", 11],
              ["c", "f", 2],
              ["d", "e", 6],
              ["e", "f", 9]]
 
dbegin = "a"
dend = "e"
powlen = pow(2,len(graph)) - 1
dgraph = list(powlen)
dtemp = list(powlen)
lenold = 10
lennew = 0
sumold = 30
sumnew = 0
 
powerset(graph)
 
for n = 1 to len(dgraph)
      dtemp[n] = str2list(substr(dgraph[n], " ", nl))
next
 
for n = 1 to len(dtemp)
     if len(dtemp[n]) > 3 and dtemp[n][1] = dbegin  and dtemp[n][len(dtemp[n])-1] = dend        
        flag = 1
        for m = 1 to len(dtemp[n])/3-1
              if dtemp[n][m*3-1] != dtemp[n][m*3+1]
                 flag = 0
              ok
        next
        if flag = 1
           lennew = len(dtemp[n])
           if lennew <= lenold
              lenold = lennew
              sumnew = 0
              for m = 1 to len(dtemp[n])/3
                    sumnew = sumnew + dtemp[n][m*3]
              next
              if sumnew < sumold
                 sumold = sumnew
                 gend = dtemp[n]
              ok
           ok
        ok
     ok
next
str = ""
see dbegin + " " + dend + " : " 
for m = 1 to len(gend)/3
     str = str + gend[(m-1)*3 + 1] + " " + gend[(m-1)*3 + 2] + " " + gend[(m-1)*3 + 3] + " -> " 
next
str = left(str,len(str)-4)
str = str + " cost : " + sumold + nl
see str + nl
 
func powerset(list)
        s = "{"
        p = 0
        for i = 2 to (2 << len(list)) - 1 step 2
             s = ""
             for j = 1 to len(list) 
                  if i & (1 << j)
                     s = s + list[j][1] + " " + list[j][2] + " " + list[j][3] + " "
                  ok
             next
             if right(s,1) = " "
                s = left(s,len(s)-1)
             ok
             p = p + 1
             dgraph[p] = s
        next
/*       
Output:
a e : a c 9 -> c d 11 -> d e 6 cost : 26
*/
