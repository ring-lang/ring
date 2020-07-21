companyList = []
aList = [
            ["SPY",   "SP500",    0],
            ["SDYL",  "SPDivs",   1],
            ["FB",    "Facebook", 2],
            ["AMZN",  "Amazon",   3],
            ["NVDA",  "Nvidia",   4],
            ["GOOGL", "Google",   5]
        ]
        
    for aItem in aList
        
        CurTicker = aItem[1]
        CurName   = aItem[2]
        Pos       = aItem[3]
    
            ###------------------------
            ### ADD to Company List
            
            Add(companyList,  new Company { Symbol=CurTicker  CmpName=CurName  Position=Pos  } )
            
    next
        
        for i = 1 to len(companyList)   
            See " "+ companyList[i].Symbol +" "+  companyList[i].CmpName +" "+  companyList[i].Position  +nl                
        next
        
        #See nl + "COMPANYLIST" +nl +nl
        #See companyList
        
        See nl +"SORT: "+nl+nl
        see sort(companyList,1,"Symbol")
    
    
###----------------------------------

Class Company 
   Symbol
   CmpName 
   Position 