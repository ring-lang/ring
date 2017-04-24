o1 = new Developer
o1.name = "Mahmoud"  see o1.name + nl
o1 { name = "Gal"  see name }
o1 { name = "Bert"  see name }

o1.setname("Marino")
see o1.getname()

Class Developer

        name language = "Ring Programming Language"

        func setname value
                see "Message from SetName() Function!" + nl
                name = value + " - " + language

        func getname
                see "Message from GetName() Function!" + nl + nl
                return "Mr. " + name + nl