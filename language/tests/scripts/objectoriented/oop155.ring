# Posted by Shadi in Ring Group
# Description by Fayed

/*

The rule in the class region (after the class name) is 
(Any identifier which is not already defined will be defined as an attribute in the class)

So, we can write 

	class point x y z

And all of these identifiers will become attributes 

Using x y z means expr expr expr where expr --> identifier 

In the same context, Using (x = y) means (identifier = expr) where expr --> identifier

Summary: writing code in the class region requires attention because of this rule.

*/

o = new myclass

? o

class myclass

            x = y