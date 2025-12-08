# Using keywords like Again, Done, On, Off, Catch, From, To, etc.

import Again.Done		

new on
new off

Catch = func from,to {	
	for x=from to to 
		? x
	next
}

call Catch(1,10)

package Again.Done

class on
	? :start

class off
	? :end
