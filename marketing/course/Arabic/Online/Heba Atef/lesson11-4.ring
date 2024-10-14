/*
 * Application : Object Oriented programming (OOP)
 * Author      : heba atef
 * Date        : 3.1.2018
*/

new point {
    x=10 y=20 
    print() 
}

new point { 
    x=30 y=40 
    print()
}

class point x y 
    func print
        ? " x : " +  x +
           " y : " + y

    func getx 
        ? "message from getx()"
        return x

    func setx value 
        x =  value +  10
        ? "message from setx()"
