# ring_state_findvar() folds the name, like the rest of the language.
# Ring stores identifiers in lower case, so a caller passing the name as
# written in their own source must still find the variable.

st = ring_state_init()
ring_state_runcode(st, "nTotal = 7")

for cName in ["nTotal", "ntotal", "NTOTAL", "nTOTAL"]
    v = ring_state_findvar(st, cName)
    if isnumber(v)
        ? cName + " : not found"
    else
        ? cName + " : " + v[3]
    ok
next

# a name that really is absent must still report absence
v = ring_state_findvar(st, "notdefined")
? "notdefined : " + isnumber(v)

ring_state_delete(st)
