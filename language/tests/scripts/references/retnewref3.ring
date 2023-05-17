# Author: Ilir Liburn
# Updated by Fayed

/*
	Description by Fayed
	Here we use Ref() to return a reference to a List Item
	This list item is a List that contains References
	Ring will protect the List item because we used Ref() with it
	Also the content (references inside the item) will be protected
	This protection happens because RETURN create a temp. variable
*/

cnd = 0		# Tested using (cnd=1) - No Memory Leak
do
	x = test()
	? "--------------"
	? refcount(x)
	? type(x)
	? len(x)
	? x
	? "--------------"
	for y in x
	        ? type(y)
	        ? y
	        ? refcount(y)
	        y = 0
	next
	? "--------------"
	? x
	? refcount(x)
	? :done
again cnd

func test
        a = [[ref(a),ref(a),3],[4,5,6]]
        ? a
        return ref(a[1])       
