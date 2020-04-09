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

alist = [:one, :two, :three]

for item in alist 		# item by reference
	 ? item
	switch item 
	case :one 	item=1
	case :two		item=2
	case :three  	item=3
	else		item=0
	end


end
? alist


alist = [:one, :two, :three]

for item in alist {		# item by reference
	 ? item
	switch item {
	case :one 	item=1
	case :two		item=2
	case :three  	item=3
	else		item=0
	}


}
? alist
