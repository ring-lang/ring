/*
 * Application       : variables string,Date & Time
 * Author            : Hany Ibrahim Ahmed
 * Date              : 22/12/2017
 */
# Variables types (string, number, list, object, c object) 
# Project----> Files(*.ring)
# Control structures-----> while ,for ,if
 
#=============================================
x = 10
if x = 5
? "nice number"
but x = 6
? "six"
but x = 7
? "seven"
else
? "another number"
ok
#===================
if x = 5
? "nice number"
elseif x = 6
? "six"
elseif x = 7
? "seven"
else
? "another number"
end
#==================
if x = 5{
? "nice number"
elseif x = 6
? "six"
elseif x = 7
? "seven"
else
? "another number"
}
#=========================
for x = 1 to 10
? x
next
for x = 1 to 10 step 2
? x
next
for x = 10 to 1 step -1
? x
next
#========
for x = 1 to 10
? x
end
for x = 1 to 10 step 2
? x
end
for x=10 to 1 step -1
? x
end
#==========
for x = 1 to 10 {
? x
}
for x = 1 to 10 step 2 {
? x
}
for x = 10 to 1 step -1 {
? x
}
