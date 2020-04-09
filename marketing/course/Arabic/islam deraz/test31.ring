/*
          Application        :Test31
          Author             :Islam Deraz
          Date               :2018.02.28
          Application Number :2
*/

# control structures
# while for if

# 1.statement
# 2.statement
# 3.statement
# .....
# .....

# conditions  ----> true|false

x=6
if x=5
	? "nice number!"
but x=6
	? "six"
but x=7
	? "seven"
else 
	? "another number!"
ok
# ================================

if x=5
	? "nice number!"
elseif x=6
	? "six"
elseif x=7
	? "seven"
else 
	? "another number!"
end

# ================================

if x=5 {

	? "nice number!"
elseif x=6
	? "six"
elseif x=7
	? "seven"
else 
	? "another number!"
	
	}

# FOR
for x=1 to 10
	? x
next			# end or {} may be used instead of next
#==============
for x=1 to 10 step 2

	? x
end
#==============
for x=10 to 1 step -1 {
	? x

        }
