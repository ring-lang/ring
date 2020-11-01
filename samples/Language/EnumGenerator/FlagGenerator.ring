# Enum generator 
# Mohammad Hamdy Ghanem
# 1/11/2020


# ====== Usage Sample =========
x = GenerateFlag("FileState", ["ReadOnly", "Hidden", "System"])

? x


# ==============================

func GenerateFlag(FlagName, lstFlags)
	if not isList(lstFlags)
      raise("Bad parameter type!")
   elseif len(lstFlags) = 0
      raise("Flag must contain members")
   end

#================template================================

   FlagTemplate = '
%FlagName% = new %FlagName%Flags

Class %FlagName%Flags
    MaxValue = %MaxValue%
%Flags%
    None = New %FlagName%Type("None", 0)
    All = New %FlagName%Type("All", MaxValue)
    Flags = [%FlagList%]
    FlagNames = [%StrFlagList%]
    FlagValues = [%ValueList%]

Class %FlagName%Type
    Name = "None"
    OnFlags
    OffFlags
    MaxValue = %MaxValue%
    Value = 0
    Text

    func init(flagName, v)
        Name = flagName
        If v > MaxValue 
           Value = v & MaxValue
        else
           Value = v   
        end


    func SetValue()
         raise "Value Is Read Only"

    func GetOnFlags()
       lstFlags = []
       For flag In %FlagName%.Flags
           If (Value & flag.Value) > 0 
              lstFlags + flag
           end
       Next
       Return lstFlags

    func SetOnFlags(lstFlags)
       SetFlags(lstFlags)

    func GetOffFlags()
       lstFlags = []
       For flag In %FlagName%.Flags
           If (Value & flag.Value) = 0 
              lstFlags + flag
           end
       Next
       Return lstFlags

    func SetOffFlags(lstFlags)
       UnsetFlags(lstFlags)

    func GetText()
         return ToString("")

    func SetText()
         raise("Text is read only.")

    Func ToString(Separator)
        If Value = 0 Return %FlagName%.None.Name end
        If Value = MaxValue Return %FlagName%.All.Name end

        If Separator = ""
           Separator = "+"
        End

        sb = ""
        For flag In %FlagName%.Flags
            If (Value & flag.Value) > 0
                If len(sb) > 0
                   sb += Separator
                end
                sb += flag.Name
            End
        Next
        Return sb

    Func ToInteger()
        Return Value

    Func SetFlag(flag)
        if type(flag) = "OBJECT" 
           v = flag.Value
        else
           v = flag
        end
        Return new %FlagName%Type("", Value | v)

    Func SetFlags(flags)
        if type(flags) = "OBJECT" 
           Return new %FlagName%Type("", Value | flags.Value)
        elseIf isNull(flags) Or len(flags) = 0 
           Return new %FlagName%Type("", Value) 
        end

        v = Value
        For flag In Flags
            v = v | flag.Value
        Next
        Return new %FlagName%Type("", v)

    Func SetAllExcxept(flags)
        if type(flags) = "OBJECT" 
           Return new %FlagName%Type("", MaxValue - flags.Value)
        elseIf isNull(flags) Or len(flags) = 0 
           Return new %FlagName%Type("", Value)
        end

        v = MaxValue
        For flag In Flags
            v -= flag.Value
        Next

        Return new %FlagName%Type("", v)

    Func UnsetFlag(flag)
        if type(flag) = "OBJECT" 
           v = flag.Value
        else
           v = flag
        end
        Return new %FlagName%Type("", Value & (Maxvalue - v))

    Func UnsetFlags(flags)
        if type(flags) = "OBJECT" 
           Return new %FlagName%Type("", Value & (MaxValie - flags.Value))
        elseIf isNull(flags) Or len(flags) = 0
           Return new %FlagName%Type("", Value)
        end

        v = Value
        For flag In Flags
            v = v & (MaxValue - flag.Value)
        Next
        Return new %FlagName%Type("", v)

    Func UnsetAllExcxept(flags)
        if type(flags) = "OBJECT" 
           Return flags
        elseIf isNull(flags) Or len(flags) = 0
           Return new %FlagName%Type("", Value)
        end

        v = 0
        For flag In Flags
            v += flag.Value
        Next
        Return new %FlagName%Type("", v)

    Func ToggleFlag(flag)
        if type(flag) = "OBJECT" 
           v = flag.Value
        else
           v = flag
        end
        Return new %FlagName%Type("", Value ^ v)

    Func ToggleFlags(flags)
        if type(flags) = "OBJECT" 
           Return new %FlagName%Type("", Value ^ flags.Value)
        elseIf isNull(flags) Or len(flags) = 0 
           Return new %FlagName%Type("", Value)
        end

        v = Value
        For flag In Flags
            v = v ^ flag.Value
        Next
        Return new %FlagName%Type("", v)

    Func ToggleAll()
        Return new %FlagName%Type("", Value ^ MaxValue)

    Func IsSet(flag)
        if type(flag) = "OBJECT" 
           v = flag.Value
        else
           v = flag
        end
        Return (Value & v) > 0

    Func AreAllSet(flags)
        if type(flags) = "OBJECT" 
           Return (Value & flags.Value) > 0
        elseIf isNull(flags) Or len(flags) = 0 
           Return Value = MaxValue
        end

        For flag In Flags
            If (Value & flag.Value) = 0 Return False end
        Next
        Return True

    Func IsUnset(flag)
        if type(flag) = "OBJECT" 
           v = flag.Value
        else
           v = flag
        end
        Return (Value & v) = 0

    Func AreAllUnset(flags)
        if type(flags) = "OBJECT" 
           Return (Value & flags.Value) = 0
        elseIf isNull(flags) Or len(flags) = 0
           Return Value = 0
        end

        For flag In Flags
            If (Value & flag.Value) > 0 Return False end
        Next
        Return True

    Func IsAnySet(flags)
        if type(flags) = "OBJECT" 
           Return (Value & flags.Value) > 0
        elseIf isNull(flags) Or len(flags) = 0 
           Return Value > 0
        end

        For flag In Flags
            If (Value & flag.Value) > 0 Return True end
        Next
        Return False

    Func IsAnyUnset(flags)
        if type(flags) = "OBJECT" 
           Return (Value & flags.Value) = 0
        elseIf isNull(flags) Or len(flags) = 0 Then 
           Return Value < MaxValue 
        end

        For flag In Flags
            If (Value & flag.Value) = 0 Return True end
        Next
        Return False


	func operator(op, flag)
      v = 0
      if type(flag) = "OBJECT" and ClassName(flag) = lower("%FlagName%type")
         v = flag.Value
      else
         v = flag
      end

	   switch op 
	     case "[]"
           Return (Value & v) > 0
	     case "&"
           Return new %FlagName%Type("", Value & v)
	     case "|"
           Return new %FlagName%Type("", Value | v)
	     case "+"
           Return new %FlagName%Type("", Value | v)
	     case "-"
           Return new %FlagName%Type("", Value & (Maxvalue - v))
	     case "^"
           Return new %FlagName%Type("", Value ^ v)
	     case "~"
           Return new %FlagName%Type("", MaxValue - Value)
	     case "="
           Return Value = v
	     case "!="
           Return Value != v
	     case ">"
           Return Value > v
	     case ">="
           Return Value >= v
	     case "<"
           Return Value < v
	     case "<="
           Return Value <= v
	   end
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

     sFlags += "    " + lstFlags[i] + " = New " + FlagName + "Type(" + flag + ", " + value + ")" + nl
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
