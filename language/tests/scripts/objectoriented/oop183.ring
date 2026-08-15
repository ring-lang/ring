# Author: Mansour Ayouni

a = [new Vec, new Vec]
o3 = a[1] + a[2]        
? o3.aData[1]           

class Vec
    aData = [1,2,3]
    func operator cOp, Para
        result = self
        if cOp = "+"
            for t = 1 to len(aData)
                result.aData[t] = aData[t] + Para[t]
            next
        but cOp = "[]"
            return &aData[para]
        ok
        return result