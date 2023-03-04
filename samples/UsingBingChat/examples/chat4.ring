#================================================#
# Author: Bing Chat 
# Questions by Fayed
# Note: It's not the perfect code (It just works!)
#================================================#

p = new Person("Alice" , 25)

? p.name # prints Alice
? p.age # prints 25

class Person

    name = ""
    age = 0

    func init(name , age)
        self.name = name
        self.age = age
    end

end