/*
 * Application : loop (for)
 * Author      : heba atef
 * Date        : 25.12.2017
*/

alist = [ :one, :two, :three ]

for item in alist
    ? item

    switch item 
        on :one 
        on: two 
        on: three
end

? alist

# ================
alist = [ :one, :two, :three ]

for item in alist
    ? item

    switch item 
        case:one 
        case: two
        case: three
    else
end

? alist

# ==================
alist = [:one, :two, :three]

for item in alist   {
    ? item

    switch item {
        on :one 
        on: two 
        on: three
    } 
}

? alist
