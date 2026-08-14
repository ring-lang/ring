# Ring stores identifiers in lower case. The functions that take a variable
# name as a string must fold it too, so a caller writing the name the way
# their own source writes it still reaches the variable.

# 1. ring_state_findvar()

st = ring_state_init()
ring_state_runcode(st, "nTotal = 7")

for cName in ["nTotal", "ntotal", "NTOTAL", "nTOTAL"]
    v = ring_state_findvar(st, cName)
    if isnumber(v)
        ? "findvar " + cName + " : not found"
    else
        ? "findvar " + cName + " : " + v[3]
    ok
next

# a name that really is absent must still report absence
v = ring_state_findvar(st, "notdefined")
? "findvar notdefined : " + isnumber(v)

# 2. ring_state_setvar()

ring_state_setvar(st, "nTotal", 11)
ring_state_runcode(st, "? 'setvar cased : ' + nTotal")
ring_state_setvar(st, "ntotal", 12)
ring_state_runcode(st, "? 'setvar lower : ' + nTotal")

ring_state_delete(st)

# 3. ring_state_newvar() - the stored name must be folded, so that Ring
#    code running inside the state can reach the variable

st2 = ring_state_init()
ring_state_newvar(st2, "cRegion")
ring_state_setvar(st2, "cRegion", "Tillaberi")
ring_state_runcode(st2, "? 'newvar cRegion : ' + cRegion")
ring_state_runcode(st2, "? 'newvar cregion : ' + cregion")
ring_state_delete(st2)

# 4. varptr()

nCount = 3
for cName in ["nCount", "ncount", "NCOUNT"]
    try
        p = varptr(cName, "int")
        ? "varptr " + cName + " : ok"
    catch
        ? "varptr " + cName + " : error"
    done
next
