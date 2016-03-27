doors = list(100)
for i = 1 to 100
doors[i] = false
next

For pass = 1 To 100
         For door = pass To 100
             if doors[door] doors[door] = false else doors[door] = true ok
	     door += pass-1
         Next
Next

For door = 1 To 100
     see "Door (" + door + ") is "
     If doors[door] see "Open" else see "Closed" ok
     see nl
Next
