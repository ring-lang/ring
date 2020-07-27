# the program will print numbers from 10 to 1

x = 10                          # x is a global variable.

func main

        for t = 1 to 10         # t is a local variable
                mycounter()     # call function
        next

func mycounter

        see x + nl              # print the global variable value
        x--                     # decrement
