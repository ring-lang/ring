doors = list(100)

for pass = 1 to 100
    for door = pass to 100 step pass
        doors[door] = not doors[door]
    next
next

for door = 1 to 100
    if doors[door] = true
       see "Door " + door + " is open" + nl
    ok
next