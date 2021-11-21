# Enum generator 
# Mohammad Hamdy Ghanem
# 30/10/2020


# ====== Usage Sample =========
x = GenerateEnum("Alignment", [
	:Left = 1,
	:Right = 2,
	:Center = 3])

? x


# ==============================

func GenerateEnum(Name, lstEnumValues)
	if not isList(lstEnumValues)
      raise("Bad parameter type!")
   elseif len(lstEnumValues) = 0
      raise("Enum must contain members")
   end

# =============== Template ==============================
   enumTemp = "
%EnumName% = new %EnumName%Enum

class %EnumName%Enum
%members%
   func GetName(value)
      switch value
%cases%         else
            return NULL
      end

   func GetValues()
      return [%values%]

   func GetNames()
      return [%names%]

   func GetNamedValues()
      return [%list%]
"

# ============ Eval =================
       members = ""
       cases = ""
       names = ""
       values = ""
       list = ""

       if type(lstEnumValues[1]) != "LIST"
          lstEnumValues = FixEnumList(lstEnumValues)
       end

       For v in lstEnumValues
			  value=""
           if type(v[2]) = "NUMBER"
              value = v[2]
           else
              value = '"' + v[2] + '"'
           end
 
			  member = v[1] + " = " + value
           members += "   " + member + nl

			  cases += "         case " + value + nl + 
						  "            return " + v[1] + nl

           if len(Names) > 0 
              Names += ", "
              values += ", "
              list += ", "       
           end

           Names += V[1]
		     values += value
           list += ":" + member
       Next

       enum = subStr(enumTemp, "%EnumName%", Name)
       enum = subStr(enum, "%members%", members)
       enum = subStr(enum, "%cases%", cases)
       enum = subStr(enum, "%names%", names)
       enum = subStr(enum, "%values%", values)
       enum = subStr(enum, "%list%", list)
       return enum


func FixEnumList(aList)	
	aEnum = []
	nCounter = 1
	for item in aList
		aEnum[item] = nCounter
		nCounter++
	next
	return aEnum
