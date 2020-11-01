# Ring Enum and Flag Generators

# Enum Generator:
Ring programming language doesn't have a special structure for `Enum`. We can just define an enum as a list like this:
```ring
Alignment = [
   :Left = 0,
   :Right = 1,
   :Center = 2
]
```

and use it like this:
`a = Alignment[:Left]`

But I wanted to use the familiar enum syntax:
`a = Alignment.Left`
So, I created this class:
```ring
class AlignmentEnum
   left = 0
   right = 1
   center = 2
   
   func GetName(value)
      switch value
         case 0
            return left
         case 1
            return right
         case 2
            return center
         else
            return NULL
       end

   func GetValues()
      return [0, 1, 2]

   func GetNames()
      return [left, right, center]

   func GetNamedValues()
      return [:left = 0, :right = 1, :center = 2]
```

and created a global variable of it:
`Alignment = new AlignmentEnum`

now, I can use the enum as I prefer:
```ring
x = Alignment.Center
? Alignment.GetName(x)
```

The additional methods, returns lists that contain the names, values, and named values:
```ring
names = Alignment.GetNames()
values = Alignment.GetValues()
list = Alignment.GetNamedValues()
```

I found this useful, but it will be hard to write such a class every time I need a 2-value enum!
So, I decided to auto-generate it. I crated the `GenerateEnum` function in the file `EnumGenerator.ring`, to return a string containing the definition of the enum class and the global variable. You can output this string to the output window, copy it to a ring project, or save it in a file. It's up to you.

# Sample code:
The `GenerateEnum` function can be used like this:
```ring
x = GenerateEnum("Alignment", [
   :Left = 0,
   :Right = 1,
   :Center = 2])

? x
```

the output window will show the generated class.

If the enum values start from 1 and increment by 1 `(1, 2, 3, 4,...)`, you can use this shorter syntax:
```ring
x = GenerateEnum("Alignment", [:Left, :Right,:Center])

? x
```

You can also use string values (but don't use double qutes `"` in the string. Use single quotes instead `'`) like this:
```ring
x = GenerateEnum("Alignment", [
   :Left = "Left align",
   :Right = "Right align",
   :Center = "Center align"])

? x
```

# Flag Generator:
A flag is an enum with values of power of 2 (1, 2, 4, ....) represinting boolean flags that can be can be used to efficiently store a collection of boolean values. This requires some methods to set, unset and get the value of any individual flag in the collection, besides some overloaded operators to do the same tasks using the language operators like `+, -, &, |, ^, ~, =, !=, > ... etc`.
I created a function named `GenerateFlag` in the file `FlagGenerator.ring`, to generate the flag and its methods for you. You can use it like this:
```ring
? GenerateFlag("FileState", ["ReadOnly", "Hidden", "System"])
```
 This will show the Generated FileState flag in the output window, where you can caopy and paste it anywhere you like.
 
This is the generated code:

```ring

FileState = new FileStateFlags

Class FileStateFlags
    MaxValue = 7
    ReadOnly = New FileStateType("ReadOnly", 1)
    Hidden = New FileStateType("Hidden", 2)
    System = New FileStateType("System", 4)

    None = New FileStateType("None", 0)
    All = New FileStateType("All", MaxValue)
    Flags = [ReadOnly, Hidden, System]
    FlagNames = ["ReadOnly", "Hidden", "System"]
    FlagValues = [1, 2, 4]

Class FileStateType
    Name = "None"
    OnFlags
    OffFlags
    MaxValue = 7
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
       For flag In FileState.Flags
           If (Value & flag.Value) > 0 
              lstFlags + flag
           end
       Next
       Return lstFlags

    func SetOnFlags(lstFlags)
       SetFlags(lstFlags)

    func GetOffFlags()
       lstFlags = []
       For flag In FileState.Flags
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
        If Value = 0 Return FileState.None.Name end
        If Value = MaxValue Return FileState.All.Name end

        If Separator = ""
           Separator = "+"
        End

        sb = ""
        For flag In FileState.Flags
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
        Return new FileStateType("", Value | v)

    Func SetFlags(flags)
        if type(flags) = "OBJECT" 
           Return new FileStateType("", Value | flags.Value)
        elseIf isNull(flags) Or len(flags) = 0 
           Return new FileStateType("", Value) 
        end

        v = Value
        For flag In Flags
            v = v | flag.Value
        Next
        Return new FileStateType("", v)

    Func SetAllExcxept(flags)
        if type(flags) = "OBJECT" 
           Return new FileStateType("", MaxValue - flags.Value)
        elseIf isNull(flags) Or len(flags) = 0 
           Return new FileStateType("", Value)
        end

        v = MaxValue
        For flag In Flags
            v -= flag.Value
        Next

        Return new FileStateType("", v)

    Func UnsetFlag(flag)
        if type(flag) = "OBJECT" 
           v = flag.Value
        else
           v = flag
        end
        Return new FileStateType("", Value & (Maxvalue - v))

    Func UnsetFlags(flags)
        if type(flags) = "OBJECT" 
           Return new FileStateType("", Value & (MaxValie - flags.Value))
        elseIf isNull(flags) Or len(flags) = 0
           Return new FileStateType("", Value)
        end

        v = Value
        For flag In Flags
            v = v & (MaxValue - flag.Value)
        Next
        Return new FileStateType("", v)

    Func UnsetAllExcxept(flags)
        if type(flags) = "OBJECT" 
           Return flags
        elseIf isNull(flags) Or len(flags) = 0
           Return new FileStateType("", Value)
        end

        v = 0
        For flag In Flags
            v += flag.Value
        Next
        Return new FileStateType("", v)

    Func ToggleFlag(flag)
        if type(flag) = "OBJECT" 
           v = flag.Value
        else
           v = flag
        end
        Return new FileStateType("", Value ^ v)

    Func ToggleFlags(flags)
        if type(flags) = "OBJECT" 
           Return new FileStateType("", Value ^ flags.Value)
        elseIf isNull(flags) Or len(flags) = 0 
           Return new FileStateType("", Value)
        end

        v = Value
        For flag In Flags
            v = v ^ flag.Value
        Next
        Return new FileStateType("", v)

    Func ToggleAll()
        Return new FileStateType("", Value ^ MaxValue)

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
      if type(flag) = "OBJECT" and ClassName(flag) = lower("FileStatetype")
         v = flag.Value
      else
         v = flag
      end

	   switch op 
	     case "[]"
           Return (Value & v) > 0
	     case "&"
           Return new FileStateType("", Value & v)
	     case "|"
           Return new FileStateType("", Value | v)
	     case "+"
           Return new FileStateType("", Value | v)
	     case "-"
           Return new FileStateType("", Value & (Maxvalue - v))
	     case "^"
           Return new FileStateType("", Value ^ v)
	     case "~"
           Return new FileStateType("", MaxValue - Value)
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
```

You can use it like this:
```ring
x = FileState.ReadOnly
? x.Text #ReadOnly 
X = x + FileState.Hidden
? x.ToString(" | ") #ReadOnly | Hidden
x = X.ToggleFlag(FileState.ReadOnly) + FileState.System
? x.Text #Hidden+System
if x = FileState.ReadOnly 
   ? "ReadOnly"
end

if x.AreAllSet([FileState.Hidden, FileState.System])
   ? "Hidden+System"
end

# Alternative syntax
if x.IsSet(FileState.Hidden + FileState.System)
   ? "Hidden+System"
end

x = x  - FileState.System
# Alternative syntax 
x = x.UnsetFlag(FileState.System)
```

Note that the flag is immutable, and all methods and operator return a new Flag holding the result, without affecting the original Flag.


# To Do:
Personally, I wish someone can add a command in the Ring Notepad that shows a window with a textbox (to enter the enum name) , a table grid with two columns to enter names and values, and an OK button that calls the ` GenerateEnum` function to generate the class and show a save file dialogue to let the user choose the name and the location to save the class. Finally, the editor should add a `Load "[enumfile].ring" ` statement at the beginning of the current file opened in ring. Ot maybe we can let this option up to the user (by adding a check box to the enum generation window).

