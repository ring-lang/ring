New container { 
    aList = [ New myclass]

    aList[1] += ["test1", 2025, :nice]
    aList[1] -= ["test2", 2025, :nice]
    aList[1] *= ["test3", 2025, :nice]
    aList[1] /= ["test4", 2025, :nice]
    aList[1] %= ["test5", 2025, :nice]
    aList[1] <<= ["test6", 2025, :nice]
    aList[1] >>= ["test7", 2025, :nice]
    aList[1] &= ["test8", 2025, :nice]
    aList[1] |= ["test9", 2025, :nice]
    aList[1] ^= ["test10", 2025, :nice]
    aList[1]**=["test11", 2025, :nice]

    v = aList[1] = ["test12", 2025, :nice]
    aList[1] != ["test13", 2025, :nice]
    aList[1] <= ["test14", 2025, :nice]
    aList[1] >= ["test15", 2025, :nice]

    ? copy("=", 70)

    o = New myclass 

    o += ["test1", 2025, :nice]
    o -= ["test2", 2025, :nice]
    o *= ["test3", 2025, :nice]
    o /= ["test4", 2025, :nice]
    o %= ["test5", 2025, :nice]
    o <<= ["test6", 2025, :nice]
    o >>= ["test7", 2025, :nice]
    o &= ["test8", 2025, :nice]
    o |= ["test9", 2025, :nice]
    o ^= ["test10", 2025, :nice]
    o**=["test11", 2025, :nice]

    v = o = ["test12", 2025, :nice]
    o != ["test13", 2025, :nice]
    o <= ["test14", 2025, :nice]
    o >= ["test15", 2025, :nice]

    Try 
        o = New myclass2 
        o += ["test1", 2025, :nice]
    Catch 
        ? "Pass Error"
        ? cCatchError 
    Done 
}

? "End of test program!"


Class container 

    aList 

    
    Func getaList 

        ? "aList Getter"
        Return aList 

        
Class myclass 

    
    Func operator cop, vvalue 

        ? "oo"
        ? cop 
        ? vvalue 
        Return self 

        
Class myclass2 From myclass 

    Private 

    
    Func operator cop, vvalue 

        ? "oo"
        ? cop 
        ? vvalue 
        Return self 
        