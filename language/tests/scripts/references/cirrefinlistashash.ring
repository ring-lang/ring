list = []
current = ref(list)
for t=0 to 9
	current[:value] = t
	current[:next]  = []
	current = ref(current[:next])
next
current[:value] = t
current[:next]  = ref(list)

? list[:value]
? list[:next][:value]
? list[:next][:next][:value]
? list[:next][:next][:next][:value]
? list[:next][:next][:next][:next][:value]
? list[:next][:next][:next][:next][:next][:value]
? list[:next][:next][:next][:next][:next][:next][:next][:next][:next][:next][:value]
? list[:next][:next][:next][:next][:next][:next][:next][:next][:next][:next][:next][:value]
? list[:next][:next][:next][:next][:next][:next][:next][:next][:next][:next][:next][:next][:value]