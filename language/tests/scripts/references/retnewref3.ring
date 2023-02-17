# Author: Ilir Liburn

/*
	Description by Fayed
	Here we use Ref() to return a reference to a List Item
	This list item is a List that contains References
	Ring will protect the List item because we used Ref() with it
	But the content (references inside the item) are just weak references
	Ring doesn't protect them.

	I.e. to protect a reference (increase reference count)
	We must use Ref() with this reference, not with it's parent.
*/

x = test()
? "--------------"
? objectid(x)
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

func test
        a = [[ref(a),ref(a),3],[4,5,6]]
        ? a
        return ref(a[1])       
