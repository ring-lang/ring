func main
        o1 = New Screen  {
                point() {               # access the object using reference
                        x = 100
                        y = 200
                        z = 300
                }
                point() {               # access the object using reference
                        x = 50
                        y = 150
                        z = 250
                }
        }
        see o1.content[1]
        see o1.content[2]

Class Screen
        content = []
        func point
                content + new point
                return content[len(content)]    # return the object by reference

Class point x=10 y=20 z=30
