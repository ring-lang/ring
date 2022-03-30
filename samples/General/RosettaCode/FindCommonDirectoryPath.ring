# Project : Find common directory path
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
i = 1
o = NULL
path = list(3)
 
path[1] = "/home/user1/tmp/coverage/test"
path[2] = "/home/user1/tmp/covert/operator"
path[3] = "/home/user1/tmp/coven/members"
 
see commonpath(path, "/")
 
func commonpath(p, s)
while i != 0
      o = i
      i = substring(p[1], s, i+1)
      for j = 2 to len(p)
          if left(p[1], i) != left(p[j], i) 
             exit 2
          ok
      next
end
return left(p[1], o-1)
