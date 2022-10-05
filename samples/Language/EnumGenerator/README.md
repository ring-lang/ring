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

You can also use string values (but don't use double quotes `"` in the string. Use single quotes instead `'`) like this:
```ring
x = GenerateEnum("Alignment", [
   :Left = "Left align",
   :Right = "Right align",
   :Center = "Center align"])

? x
```

# Flag Generator:
A flag is an enum which members values are of power of 2 (1, 2, 4, ....), representing binary flags that can be used to efficiently store a collection of boolean values. This requires some methods to set, unset and get the value of any individual flag in the collection, besides some overloaded operators to do the same tasks using the language operators like `+, -, &, |, ^, ~, =, !=, > ... etc`. I created the [FlagType class](FlagType.bin) that contains all these methods and operators. In fact you will not directly use this class, and will not deal with it unless you want to modify it.
I also created a function named [GenerateFlag](FlagGenerator.ring) to generate the required flag values as objects of the FlagType Class. Use this function like this:
```ring
? GenerateFlag("FileState", ["ReadOnly", "Hidden", "System"])
```
 This will show the Generated FileState flag in the output window, which will be: 

```ring

load "FlagOperations.ring"

FileState = new FileStateFlags

Class FileStateFlags
    FlagNames = ["ReadOnly", "Hidden", "System"]
    FlagValues = [1, 2, 4]
    ReadOnly = New FlagOperations(1, FlagNames)
    Hidden = New FlagOperations(2, FlagNames)
    System = New FlagOperations(4, FlagNames)

    None = New FlagOperations(0, FlagNames)
    All = New FlagOperations(7, FlagNames)
    Flags = [ReadOnly, Hidden, System]

    func FlagFromInt(value)
       return New FlagOperations(value, FlagNames)
```

You can copy this code to a new file and name it `FileState.ring` for example. 
Note that for the `load "FlagType.ring"` statement to work, you need to copy the file `Flagtype.ring` to the folder `ring\bin`. This will make it available to use in all your ring projects. 
Now you can use the FileState false like this:
```ring
load "FileState.ring"
x = FileState.ReadOnly
? x.Text                                #ReadOnly 
X = x + FileState.Hidden
? x.ToString(" | ")                     #ReadOnly | Hidden
x = X.ToggleFlag(FileState.ReadOnly) + FileState.System
? x.Text                                #Hidden+System
if x = FileState.ReadOnly               #False
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
x = FileState.FlagFromInt(3) 
? x.Text                                 # ReadOnly+Hidden
```

Note that the flag is immutable, and all methods and operator return a new Flag holding the result, without affecting the original Flag.

Note also that if you will use the flag members multiple times on three same code block, you can use this simple trick to shorten the name of the flag:
```ring
FileState {
   x = ReadOnly
   ? x.Text                             #ReadOnly 
   X = x + Hidden
   ? x.ToString(" | ")                  #ReadOnly | Hidden
   x = X.ToggleFlag(ReadOnly) + System
   ? x.Text                             #Hidden+System
   if x = ReadOnly {? "ReadOnly"}
   if x.AreAllSet([Hidden, System]) {? "Hidden+System"}
   # Alternative syntax
   if x.IsSet(Hidden + System) {? "Hidden+System"}
   x = x  - System
   # Alternative syntax 
   x = x.UnsetFlag(System)
   x = FlagFromInt(3) 
   ? x.Text                              #ReadOnly+Hidden   
}
```

# To Do:
Personally, I wish someone can add a command in the Ring Notepad that shows a window with a textbox (to enter the enum name) , a table grid with two columns to enter names and values, and an OK button that calls the ` GenerateEnum` function to generate the class and show a save file dialogue to let the user choose the name and the location to save the class. Finally, the editor should add a `Load "[enumfile].ring" ` statement at the beginning of the current file opened in ring. Qt maybe we can let this option up to the user (by adding a check box to the enum generation window).

