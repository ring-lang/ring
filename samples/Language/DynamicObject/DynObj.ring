# Mohammad Hamdy Ghanem
# 04/11/2020

_Dynamic_Class_id = 1


func defObj(lstAttrs)
    _class = "o = new DynamicClass_" + _Dynamic_Class_id + nl + 
				  "Class DynamicClass_" + _Dynamic_Class_id + nl + "end" 
 
    eval(_class)
    for attr in lstAttrs
      if isList(attr)   
        if isstring(attr[2]) and isFunction(attr[2])
           AddMethod(o, attr[1], attr[2])
        else
           AddAttribute(o, attr[1])
           SetAttribute(o, attr[1], attr[2])
        end
      else
        AddAttribute(o, attr)
      end
    next
    _Dynamic_Class_id += 1
    return o
end


func NewObj(obj)
    if not IsObject(obj) return Null end

    eval("o = new " + className(obj))

    for attr in Attributes(obj)  
        if ! isAttribute(o, attr)      
            AddAttribute(o, attr)
        ok
    next

    for m in Methods(obj)        
        if ! isAttribute(o, m)      
            AddAttribute(o, m)
        ok
    next

    return o
end
