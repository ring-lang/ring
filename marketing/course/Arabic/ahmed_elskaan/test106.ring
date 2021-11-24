/*
**  Application Name : Scope
**  Author           : Ahmed Elskaan
**  Date             : 2017-12-31
*/

# Problem: conflict between global and local variables
# Solution 1: use the main function

func main
    x = 10 y = 40
    nSum = x + y
    ? sum(1,2)
    ? nSum


func sum x,y
    nSum = x + y
    return nSum
