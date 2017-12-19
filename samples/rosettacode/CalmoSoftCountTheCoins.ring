# Project : Count the coins
# Date    : 2017/09/09
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

penny = 1 
nickel = 1
dime = 1 
quarter = 1
count = 0
 
for penny = 0 to 100
    for nickel = 0 to 20
        for dime = 0 to 10
            for quarter = 0 to 4
                if (penny + nickel * 5 + dime * 10 + quarter * 25) = 100
                   see "" + penny + " pennies " + nickel + " nickels " + dime + " dimes " + quarter + " quarters" + nl
                   count = count + 1 
                ok
            next
        next
    next
next
see  "" + count + " ways to make a dollar" + nl
