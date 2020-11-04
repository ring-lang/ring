# Enum generator 
# Mohammad Hamdy Ghanem
# 1/11/2020


# ====== Usage Sample =========
? GenerateFlag("FileState", ["ReadOnly", "Hidden", "System"])
# ==============================

func GenerateFlag(FlagName, lstFlags)
	if not isList(lstFlags)
      raise("Bad parameter type!")
   elseif len(lstFlags) = 0
      raise("Flag must contain members")
   end

#================template================================

   FlagTemplate = '
load "FlagOperations.ring"

%FlagName% = new %FlagName%Flags

Class %FlagName%Flags
    FlagNames = [%StrFlagList%]
    FlagValues = [%ValueList%]
%Flags%
    None = New FlagOperations(0, FlagNames)
    All = New FlagOperations(%MaxValue%, FlagNames)
    Flags = [%FlagList%]

    func FlagFromInt(value)
       return New FlagOperations(value, FlagNames)
'

#============eval=================
  FlagTemplate = SubStr(FlagTemplate, "%FlagName%", FlagName)

  L = len(lstFlags) 
  MaxValue = pow(2, L) - 1
  FlagTemplate = SubStr(FlagTemplate, "%MaxValue%", String(MaxValue))

  sFlags = ""
  sFlagList = ""
  sStrFlagList = ""
  sValueFlagList = ""

  For i = 1 To L 
     flag = '"' + lstFlags[i] + '"'
     value = pow(2, i - 1)

     sFlags += "    " + lstFlags[i] + " = New FlagOperations(" + value + ", FlagNames)" + nl
     If Len(sFlagList) > 0
        sFlagList += ", "
        sStrFlagList += ", "
        sValueFlagList += ", "
     End
     sFlagList += lstFlags[i]
     sStrFlagList += flag
     sValueFlagList += value
  Next
  FlagTemplate = SubStr(FlagTemplate, "%Flags%", sFlags)
  FlagTemplate = SubStr(FlagTemplate, "%FlagList%", sFlagList)
  FlagTemplate = SubStr(FlagTemplate, "%StrFlagList%", sStrFlagList)
  FlagTemplate = SubStr(FlagTemplate, "%ValueList%", sValueFlagList)

  Return FlagTemplate
