# Declarative Programming (Nested Structures)

Screen()
{

        point()
        {
                x = 100
                y = 200
                z = 300
        }

        point()
        {
                x = 50
                y = 150
                z = 250
        }
}

# Functions and Classes

Func screen return new screen

Class Screen

        content = []

        func point
                content + new point
                return content[len(content)]

        func braceend
                see "I have " + len(content) + " points!"

Class point

        x=10 y=20 z=30

        func braceend
                see self
