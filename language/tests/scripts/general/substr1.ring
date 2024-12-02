 
cStr = "ONE TEST TWO"

? between("ONE","TWO")
? between("",`TEST`)
? between("",`TWO`)

func between(cFirst,cSecond)

    nPos1   = substr(cStr,cFirst)
    nStart1 = nPos1 + len(cFirst)

    nPos2   = substr(cStr,cSecond)

    return substr(cStr, nStart1, nPos2-nStart1)

