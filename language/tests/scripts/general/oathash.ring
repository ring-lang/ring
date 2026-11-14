see oat_hash("hello") + nl

# Jenkins hash function - https://en.wikipedia.org/wiki/Jenkins_hash_function
func oat_hash cKey
        h = 0
        for x in cKey
                h = unsigned(h,ascii(x),"+")
                h = unsigned(h,unsigned(h,10,"<<"),"+")
                r = unsigned(h,6,">>")
                h = unsigned(h, r,"^")
        next
        h = unsigned(h,unsigned(h,3,"<<"),"+")
        h = unsigned(h,unsigned(h,11,">>"),"^")
        h = unsigned(h,unsigned(h,15,"<<"),"+")
        return h
