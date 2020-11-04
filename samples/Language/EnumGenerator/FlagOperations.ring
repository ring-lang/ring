# Enum generator 
# Mohammad Hamdy Ghanem
# 1/11/2020

# Don't forget to copy This file to the folder Ring\Bin

Class FlagOperations
    Value
    MaxValue
    Text
    AllNames
    OnFlags
    OffFlags


    func init(flagValue, names)
        AllNames = names
        MaxValue = pow(2, len(names)) -1
        If flagValue > MaxValue 
           Value = flagValue & MaxValue
        else
           Value = flagValue   
        end

    func SetValue()
         raise "Value Is Read Only"

    func SetAllNames()
        Raise("Readonly Property")

    func GetOnFlags()
       lstFlags = []
       n = len(AllNames)
       For i = 1 to n
           flag = pow(2, i - 1)
           If (Value & flag) > 0 
              lstFlags + new FlagOperations(flag, AllNames)
           end
       Next
       Return lstFlags

    func SetOnFlags(lstFlags)
       SetFlags(lstFlags)

    func GetOffFlags()
       lstFlags = []
       n = len(AllNames)
       For i = 1 to n
           flag = pow(2, i - 1)
           If (Value & flag) = 0 
              lstFlags + new FlagOperations(flag, AllNames)
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
        If Value = 0 Return "None" end
        If Value = MaxValue Return "All" end

        If Separator = ""
           Separator = "+"
        End

        sb = ""
        n = len(AllNames)
        For i = 1 to n
            flag = pow(2, i -1)
            If (Value & flag) > 0
                If len(sb) > 0
                   sb += Separator
                end
                sb += AllNames[i]
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
        Return new FlagOperations(Value | v, AllNames)

    Func SetFlags(flags)
        if type(flags) = "OBJECT" 
           Return new FlagOperations(Value | flags.Value, AllNames)
        elseIf isNull(flags) Or len(flags) = 0 
           Return new FlagOperations(Value, AllNames) 
        end

        v = Value
        For flag In Flags
            v = v | flag.Value
        Next
        Return new FlagOperations(v, AllNames)

    Func SetAllExcxept(flags)
        if type(flags) = "OBJECT" 
           Return new FlagOperations(MaxValue - flags.Value, AllNames)
        elseIf isNull(flags) Or len(flags) = 0 
           Return new FlagOperations(Value, AllNames)
        end

        v = MaxValue
        For flag In Flags
            v -= flag.Value
        Next

        Return new FlagOperations(v, AllNames)

    Func UnsetFlag(flag)
        if type(flag) = "OBJECT" 
           v = flag.Value
        else
           v = flag
        end
        Return new FlagOperations(Value & (Maxvalue - v) , AllNames)

    Func UnsetFlags(flags)
        if type(flags) = "OBJECT" 
           Return new FlagOperations(Value & (MaxValie - flags.Value) , AllNames)
        elseIf isNull(flags) Or len(flags) = 0
           Return new FlagOperations(Value, AllNames)
        end

        v = Value
        For flag In Flags
            v = v & (MaxValue - flag.Value)
        Next
        Return new FlagOperations(v, AllNames)

    Func UnsetAllExcxept(flags)
        if type(flags) = "OBJECT" 
           Return flags
        elseIf isNull(flags) Or len(flags) = 0
           Return new FlagOperations(Value, AllNames)
        end

        v = 0
        For flag In Flags
            v += flag.Value
        Next
        Return new FlagOperations(v, AllNames)

    Func ToggleFlag(flag)
        if type(flag) = "OBJECT" 
           v = flag.Value
        else
           v = flag
        end
        Return new FlagOperations(Value ^ v, AllNames)

    Func ToggleFlags(flags)
        if type(flags) = "OBJECT" 
           Return new FlagOperations(Value ^ flags.Value, AllNames)
        elseIf isNull(flags) Or len(flags) = 0 
           Return new FlagOperations(Value, AllNames)
        end

        v = Value
        For flag In Flags
            v = v ^ flag.Value
        Next
        Return new FlagOperations(v, AllNames)

    Func ToggleAll()
        Return new FlagOperations(Value ^ MaxValue, AllNames)

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
      if type(flag) = "OBJECT" and ClassName(flag) = lower("FlagOperations")
         v = flag.Value
      else
         v = flag
      end

	   switch op 
	     case "[]"
           Return (Value & v) > 0
	     case "&"
           Return new FlagOperations(Value & v, AllNames)
	     case "|"
           Return new FlagOperations(Value | v, AllNames)
	     case "+"
           Return new FlagOperations(Value | v, AllNames)
	     case "-"
           Return new FlagOperations(Value & (Maxvalue - v) , AllNames)
	     case "^"
           Return new FlagOperations(Value ^ v, AllNames)
	     case "~"
           Return new FlagOperations(MaxValue - Value, AllNames)
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
end
