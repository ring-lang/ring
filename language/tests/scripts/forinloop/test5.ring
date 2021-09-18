for i=1 to 4 next
? i

for i=1 to 4 if i=3 exit ok next
? i

for x in "test" next
? x

cStr = "test"
for x in cStr next
? x

for x in "test" if x="t" exit ok next
? x

for x in 1:5 next
? x

for x in 1:5 if x=3 exit ok next
? x

for sublist in [1:5,6:10] next
? sublist

for sublist in [1:5,6:10] if len(sublist)=5 exit ok next
? sublist