List = Zero([1,2,3])
List.add(4)
List.add(5)
List.insert(2,6)
see "item0 = " + List[0] + nl
see "item1 = " + List[1] + nl
see "item2 = " + List[2] + " - insert" + nl
see "item3 = " + List[3] + nl
see "item4 = " + List[4] + " - add" + nl
see "item5 = " + List[5] + " - add" + nl
fnd = List.find(2)
see "find 2 = " + fnd + nl
List.del(0)
see "After deleting item0:" + nl
see "item0 = " + List[0] + nl
String = Zero("Welcome")
see String[0]
see String[1]
see String[2]

func Zero(vValue)
     if isString(vValue)
        return new ZeroBasedString(vValue)
     but isList(vValue)
         return new ZeroBasedList(vValue)
     ok

func ZeroBased_Add(List,Value) 
     add(List,Value)

func ZeroBased_Insert(List,nPos,Value)
     insert(List,nPos,Value)

func ZeroBased_Find(List,Value)
     return find(List,Value)

func ZeroBased_Del(List,ind)
     del(List,ind)

class ZeroBasedList
      ZB_aItems = []
      func init(aList) 
           ZB_aItems = aList 
      func operator(cOperator,cValue)
           switch cOperator
                  on "[]"  
                     return &ZB_aItems[cValue+1]
                  on "len"
                     return len(ZB_aItems)
      off

      func add(Value)
           ZeroBased_Add(ZB_aItems,Value)

      func insert(nPos,Value)
           ZeroBased_Insert(ZB_aItems,nPos,Value)

      func find(Value)
           return ZeroBased_Find(ZB_aItems,Value)-1

      func del(ind)
           ZeroBased_Del(ZB_aItems,ind+1)

class ZeroBasedString
      ZB_cString = ""
      func init(cValue)
           ZB_cString = cValue
      func operator(cOperator,cValue) 
           switch cOperator
                  on "[]"
                     return ZB_cString[cValue+1]
                  on "len"
                     return len(ZB_cString)
           off
