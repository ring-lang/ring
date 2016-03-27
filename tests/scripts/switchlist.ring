aList = [:apple,:google,:Ibm]
see aList
for x in aList
switch x
on :google x="one"
on :apple x ="two"
on :ibm x = "three"
off
next
see aList