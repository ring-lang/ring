# Demo Program

while true

        see "

        Main Menu
        ===========
        [1] Say Hello
        [2] Sum two numbers
        [3] Stars
        [4] Fact
        [5] Exit

        " give nMenu see nl

        # we can use Switch-ON-Other-OFF instead of IF-BUT-ELSE-OK

        if nMenu = 1 sayhello()
        but nMenu = 2 Sum()
        but nMenu = 3 Stars()
        but nMenu = 4
                see "Enter Number : " give x
                see "Output : "

                Try
                        see Fact(number(x))
                Catch
                        see "Error in parameters!" + nl
                Done

        but nMenu = "5" return
        else see "bad option" + nl
        ok

end

func sayhello
        see "Enter your name ? " give fname
        see "Hello " + fname + nl

func sum
        see "number 1 : " give num1 see "number 2 : " give num2
        see "Sum : " see 0 + num1 + num2

func stars
        for x = 1 to 10
                see space(8)
                for y = 1 to x see "*" next see nl
        next

func fact x if x = 1 return 1 else return x * fact(x-1) ok

func space x y = "" for t=1 to x y += " " next return y
