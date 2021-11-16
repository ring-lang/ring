/*    Application: Objects  (for statement)
 *    Author     : heba atef 
 *    Date       : 27.12.2017 
*/

for x = 1 to 10
    ? x
next

for x = 1 to 10 step 2
    ? x
next


# ===========================

for x = 1 to 10
    ? x
end

for x=1 to 10 step 2
    ? x
end


# ===========================

for x = 1 to 10
{
    ? x
}

for  x=1  to  10 step 2
{
    ? x
}


# ===========================
alist = [:one, :two, :three ]

for item in alist
    ? item
next

