tokenize("one^|uno||three^^^^|four^^^|^cuatro|", "|", "^")

func tokenize(src, sep, esc)
field = 1
escaping = false
see "" + field + " "
for i = 1 to len(src)
    char = substr(src, i, 1)
    if escaping 
       see char
       escaping = false
    else
       switch char 
              on sep
                 see nl
                 field = field + 1
                 see "" + field + " "
              on esc
                 escaping = true
              other
                 see char 
       off
     ok
next
see nl
