![Ring](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/graphics/thering.jpg)

# Ring Programming Language

## Simple and flexible programming language for applications development

| |*Resources*|
|---|---|
|Download |[![Download](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/graphics/binaryrelease.svg)](https://ring-lang.github.io/download.html)|
|Help |[![Help](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/graphics/documentation.svg)](https://ring-lang.github.io/doc1.18/index.html)|
|Try |[![Try](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/graphics//interactive%20ring-use%20online-green.svg)](https://tio.run/#Ring)|
|Extra |[![Resources](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/graphics/resources-orange.svg)](https://ring-lang.github.io/resources.html)|

# Contents:

- [Welcome to Ring](#welcome-to-ring)
- [Get Excited!](#get-excited)
- [Batteries Included!](#batteries-included)
- [Practical](#practical)
  * [Custom Styles And Modern Programming Paradigms](#custom-styles-and-modern-programming-paradigms)
  * [GUI Applications Development And RAD Tools](#gui-applications-development-and-rad-tools)
  * [First Class Support For Game Development](#first-class-support-for-game-development)
  * [WebAssembly (Front-End Web Development)](#webassembly-front-end-web-development)
  * [Back-End Web Development](#back-end-web-development)
  * [Mobile Development](#mobile-development)
  * [Building Tools (Command Line)](#building-tools-command-line)
- [Why Ring?](#why-ring)
  * [Designed for a Clear Goal](#designed-for-a-clear-goal)
  * [Simple](#simple)
  * [Trying to be natural](#trying-to-be-natural)
  * [Encourage Organization](#encourage-organization)
  * [Data Representation](#data-representation)
  * [Compact Syntax](#compact-syntax)
  * [Syntax Flexibility](#syntax-flexibility)
  * [Define Natural Statements based on Object-Oriented](#define-natural-statements-based-on-object-oriented)
  * [Define Declarative Languages using Nested Structures based on Object-Oriented](#define-declarative-languages-using-nested-structures-based-on-object-oriented)
- [Implementation](#implementation)
  * [Transparent Implementation](#transparent-implementation)
  * [Visual Implementation](#visual-implementation)
  * [Smart Garbage Collector](#smart-garbage-collector)
  * [No Global Interpreter (VM) Lock - No GIL](#no-global-interpreter-vm-lock---no-gil)
  * [Fast Enough For Many Applications](#fast-enough-for-many-applications)
- [Features](#features)
  * [Syntax](#syntax)
  * [Powerful Implementation](#powerful-implementation)
  * [Simple](#simple-1)
  * [Dynamic](#dynamic)
  * [Object-Oriented Programming (OOP)](#object-oriented-programming-oop)
  * [Standard Library](#standard-library)
  * [Web Development](#web-development)
  * [Extensions](#extensions)
  * [More](#more)
- [Building from source code](#building-from-source-code)
- [License](#license)


# Welcome to Ring

Ring is a practical general-purpose multi-paradigm language.
The supported programming paradigms are Imperative, Procedural, Object-Oriented, Functional,
Metaprogramming, Declarative programming using nested structures, and Natural programming.

The language is portable (MS-DOS, Windows, Linux, macOS, Android, WebAssembly, etc.) and can be used to create
Console, GUI, Web, Games, and Mobile applications. 

The language is designed to be Simple, Small, and Flexible. 

# Get Excited

Ring comes with better support for Natural Language Programming and Declarative Programming. 

The language support these paradigms with new practical techniques on top of Object-Oriented Programming and Functional Programming. No need to know anything about (Compilers and Parsing). 

You get the language constructs ready for use to create domain-specific languages in a fraction of time. 

* [Ring Article](https://www.codeproject.com/Articles/1089887/The-Ring-Programming-Language)

* [Syntax Flexibility](https://www.codeproject.com/Articles/1137388/Syntax-Flexibility-in-the-Ring-Programming-Languag)

* [The Declarative Approach](https://www.codeproject.com/Articles/1222105/The-declarative-approach-of-the-Ring-programming-l)

* [Natural Language Programming](https://www.codeproject.com/Articles/1138605/Natural-Language-Programming-in-the-Ring-Programmi)

* [Natural Language Programming Library](https://www.codeproject.com/Articles/1200766/Using-the-Natural-Language-Programming-Library-NLP)

* [Programming Without Coding Technology](https://github.com/ring-lang/ring/tree/master/marketing/pwct)

# Batteries Included

Ring comes with many high quality bindings for popular libraries 

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/libs.png)

# Practical

Many of the Ring libraries (StdLib, WebLib, Natural Library, Games Engine, etc.) and the Ring IDE (Ring Notepad, Form Designer, etc.) are written in the Ring language itself. Ring is ready for use in production and increases the developers productivity. 

## Custom Styles And Modern Programming Paradigms

Using Ring you will feel that the language is yours! A lot of modern programming paradigms are ready for use in production and using Natural Language Programming you can quickly integrate natural interfaces to your programs. 

Also, you can start your software development by writing natural descriptions, then adding the implementation later. 

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/newringdemo1.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/newringdemo2.png)


## GUI Applications Development And RAD Tools

Many developers reported that using Ring we can develop many GUI applications in a few hours. 
Ring comes with Rapid Application Development (RAD) tools that we can use to quickly develop GUI applications using the MVC design pattern. 
Also, using the same source code we can distribute our applications for Desktop, Web, and Mobile platforms. 

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/newringdemo6.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/newringdemo5.png)

## First Class Support For Game Development

We believe in Games as a nice way to encourage people to learn to program.
Ring comes with many game programming libraries in the standard library.
Ring provides native support for Allegro, LibSDL, RayLib, OpenGL, FreeGLUT, Tilengine and Qt3D libraries.
Also, Ring comes with a simple game engine for 2D game development using Declarative Programming.

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/ringdemo13.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/goldmagic800.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/newringdemo3.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/snakegamecode.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/sokobangamecode.png)


## WebAssembly (Front-End Web Development)

Using Ring we can quickly develop web applications using WebAssembly (Binary format that allows sand-boxed executable code in web pages. This format is nearly as fast as native machine code and is now supported by all major web browsers) 

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/wasm_demo4.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/wasm_demo1.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/wasm_demo2.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/wasm_demo3.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/wasm_demo5.png)

## Back-End Web Development

Using Ring we can quickly develop web applications using the MVC design pattern. 
We can easily use HTML templates with embedded Ring code. 
Also, we can generate HTML code from Ring programs using Declarative Programming.

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/newringdemo9.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/newringdemo12.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/mycoffee.png)

## Mobile Development

Using Ring we can distribute our applications for mobile platforms (Android, iOS, etc.)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/android_demo1.png)

## Building Tools (Command Line)

Using Ring we can whip up a CLI tool quickly and distribute it with ease. 
The Ring Package Manager is an example of a powerful tool that we developed using Ring in a few hours. 
We recorded the development time (21 hours of development includes explaining each step) 

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/cmddemo2.png)

# Why Ring?

The language is simple, trying to be natural, encourage organization, and comes with transparent and visual implementation. 
It comes with compact syntax and a group of features that enable the programmer to create natural interfaces and declarative domain-specific languages in a fraction of time. 
It is very small, flexible, and comes with a smart garbage collector that puts the memory under the programmer's control. 
It supports many programming paradigms, comes with useful and practical libraries. 
The language is designed for productivity and developing high-quality solutions that can scale.

## Designed for a Clear Goal


* Applications programming language.

* Productivity and developing high-quality solutions that can scale.

* Small and flexible language that can be embedded in C/C++ projects.

* Simple language that can be used in education and introducing Compiler/VM concepts.

* General-Purpose language that can be used for creating domain-specific libraries, frameworks, and tools.

* Practical language designed for creating the next version of the Programming Without Coding Technology software.

## Simple 

Ring is a very simple language and has a very straightforward syntax. 
It encourages programmers to program without boilerplate code.
To print something using the standard output, We can use the 'See' command.

```ring
see "Hello, World!" 
```		

The Main function is optional and will be executed after the statements, and is useful for using the local scope.

```ring
func main
  see "Hello, World!" 
```					

Uses Dynamic Typing and Lexical scoping.
Also, we can use the '+' operator for string concatenation.

```ring
nCount = 10	# Global variable
func main
  nID = 1	# Local variable
  see "Count = " + nCount + nl + " ID = " + nID
```

## Trying to be natural 

Ring is not case-sensitive

```ring
see "Enter your name ? " 
give name
see "Hello " + Name	# Name is the same as name 
```			

The list index starts from 1

```ring
aList = ["one","two","three"]
see aList[1]	# print one
```			

Call functions before the definition

```ring
one() 
two() 
three()
func one 
  see "One" 
func two 
  see "two" 
func three 
  see "three" 
```			

The assignment operator uses Deep copy (no references in this operation)

```ring
aList = ["one","two","three"]
aList2 = aList
aList[1] = 1
see alist[1]	# print 1
see aList2[1]	# print one
```			

Pass numbers and strings by value, but pass lists and objects by reference.
The for-in loop can update the list items.

```ring
func main
  aList = [1,2,3]
  update(aList)
  see aList	# print one two three

func update aList
  for x in aList
    switch x
    on 1 x = "one"
    on 2 x = "two"
    on 3 x = "three"
    off
  next
```			

Using Lists during definition

```ring
aList = [ [1,2,3,4,5] , aList[1] , aList[1] ]
see aList       # print 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
```			

Exit from more than one loop

```ring
for x = 1 to 10
  for y = 1 to 10
    see "x=" + x + " y=" + y + nl
    if x = 3 and y = 5
      exit 2     # exit from 2 loops
    ok
  next
next
```
			
## Encourage Organization 			

The language encourage organization, Forget bad days using languages where the programmer start with function then class then function and a strange mix between things!

Each source file follow the next structure

    Load Files
    Statements and Global Variables
    Functions
    Packages and Classes

This enables us to use Packages, Classes, and Functions without the need to use a keyword to end these components.

We can write one line comments and multi-line comments

The comment starts with # or //

Multi-line comments are written between /* and */

```ring
/* 
	Program Name : My first program using Ring
	Author       : Ring Team 
*/

see "What is your name? " 	# print message on screen
give cName 			# get input from the user
see "Hello " + cName		# say hello!

// See "End of Program!"
```

## Data Representation

Ring contains only 4 types that represent the program data

These types are (String, Number, List & Object)

The idea is to have many use cases for each type which increase the flexibility and the ability
to write functions that are more usable in different situations.

The String type is used to represent:
* One character
* A string of many characters
* Multi-line string
* Binary Data 

```ring
cStr1 = "a"			# One character
cStr2 = "Hello, World!" 	# A string of many characters
cStr3 = "Hello
Welcome to the Ring language!
"				# Multi-line string
cStr4 = read(EXEFileName())	# Read executable file (Binary Data)
```

The Number type is used to represent
* Boolean Values 
* Signed/Unsigned Integers
* Float/Double 

```ring
nNum1 = True		# Boolean Value (1) 
nNum2 = False		# Boolean Value (0)
nNum3 = 10		# Integer
nNum4 = -10		# Signed Integer
nNum5 = 1250.11		# Float/Double
```

The List type is used instead of
* One Dimension Arrays
* Multi-Dimension Arrays
* Lists of multiple types
* Nested Lists
* Hash Tables (Key & Value)
* Tree
* Wrapper around a C Pointer

```ring
aList1 = ["one","two","three"]				# Strings
aList2 = [1,2,3,4,5,6,7,8,9,10]				# Numbers
aList3 = ["Ring",1234]					# Multiple types
aList4 = [["Fayed","Egypt"],["Mansour","Tunisia"]]  	# Nested Lists
aList5 = [ :name = "Fayed", :country = "Egypt"]		# Hash Table
```
The Object type is used to represent objects created from classes

Using classes and operator overloading we can create custom types 
			
## Compact Syntax 

The language is not line-sensitive, you don't need to write ; after statements, also you don't need to press ENTER or TAB, so we can write the next code

```ring
see "The First Message"	see " Another message in the same line! " + nl
see "Enter your name?" give Name see "Hello " + Name
```			

The next code creates a class called Point contains three attributes X,Y, and Z. No keywords is used to end the package/class/function definition. Also, we can write the attributes' names directly below the class name.

```ring
class Point X Y Z
```			

We can use classes and functions before their definition, In this example, we will create a new object, set the object attributes then print the object values.

```ring
o1 = new point	o1.x=10    o1.y=20   o1.z=30	see O1	class Point X Y Z
```			

Instead of using the dot '.' operator to access the object attributes and methods, we can use braces { } to access the object, then we can use the object attributes and methods.
 
```ring
o1 = new point { x=10 y=20 z=30 } see O1  class Point X Y Z
```

Now we will call a method after accessing the object using { }
 
```ring
oPerson = new Person
{
  Name = "Somebody"
  Address = "Somewhere"
  Phone = "0000000"
  Print()			# here we call the Print() method
}
class Person Name Address Phone
  func Print
    see "Name :" + name + nl +
        "Address :" + Address + nl +
        "Phone : " + phone + nl
```

When we use { } to access the object then write any attribute name, the language will check the class for any setter/getter methods that will be called automatically.

```ring
new Number {
  see one    # Execute GetOne()
  see two    # Execute GetTwo()
  see three  # Execute GetThree()
}
class Number one two three
  func GetOne
    see "Number : One" + nl
    return 1
  func GetTwo
    see "Number : Two" + nl
    return 2
  func GetThree
    see "Number : Three" + nl
    return 3	
```

## Syntax Flexibility

Ring comes with many styles for writing your source code!

Also, You can change the language keywords and operators and create your custom style!

### The First Style

```ring
? "Welcome to Ring! "
new test { start() }

class Test
	x=10  y=20
	func start 
		? "x+y=" + (x+y)
		for t=1 to 10 
			? "t = " + t
			if t=3 
				? "Three" 
			ok 
		next
```

### The Second Style

```ring
def main
	put "Welcome to Ring! " + nl
	new test { start() }
end

class Test
	x = 10
	y = 20
	def start 
		put "x+y=" + (x+y) + nl
		for t=1 to 10 
			put "t = " + t + nl
			if t=3 
				put "Three" + nl
			end
		end
	end
end
```

### The Third Style

```ring
load "stdlib.ring"

func main() {
	print("Welcome to Ring! \n")
	new test { start() }
}

class Test {
	x = 10
	y = 20
	func start {
		print("x+y=" + (x+y) + "\n")
		for t=1 to 10 {
			print("t = " + t + " \n")
			if t=3 {
				print("Three \n")
			}
		}
	}
}
```

### Change Keywords

```ring
ChangeRingKeyword See Print
Print "Hello, World!"
ChangeRingKeyword Print See
See "Hello, World!"
ChangeRingKeyword See Show
Show "Hello, World!"
```


## Define Natural Statements based on Object-Oriented 

After the object access using { } if the class contains a method called BraceEnd() it will be executed!

```ring
TimeForFun = new journey
# The first surprise!
TimeForFun {
  Hello it is me  # What a beautiful programming world!
}
# Our Class
class journey
  hello=0 it=0 is=0 me=0
  func GetHello
    See "Hello" + nl
  func braceEnd
    See "Goodbye!" + nl	
```

We can execute code written in strings using the Eval() function

```ring
cCode = "See 'Code that will be executed later!' "
Eval(cCode)	# execute the code to print the message
```

We can create a list then execute code generated from that list

```ring
aWords = ["hello","it","is","me"]
for word in aWords cCode=word+"=0" eval(cCode) next
```

We can read text files using the Read(cFileName) function and we can write files using the Write(cFileName,cString) function.

```ring
see "Enter File Name:" give cFileName see read(cFileName) # Print the file content
```

The next example presents how to create a class that defines two instructions

The first instruction is : I want window

The second instruction is : Window title = Expression

Also, keywords that can be ignored like the **the** keyword

```ring
new App
{
  I want window
  The window title = "hello world"
}

class App

  # Attributes for the instruction I want window
    i want window
    nIwantwindow = 0
  # Attributes for the instruction Window title
  # Here we don't define the window attribute again
    title
    nWindowTitle = 0
  # Keywords to ignore, just give them any value
    the=0

  func geti
    if nIwantwindow = 0
      nIwantwindow++
    ok

  func getwant
    if nIwantwindow = 1
      nIwantwindow++
    ok

  func getwindow
    if nIwantwindow = 2
      nIwantwindow= 0
      see "Instruction : I want window" + nl
    ok
    if nWindowTitle = 0
      nWindowTitle++
    ok

  func settitle cValue
    if nWindowTitle = 1
      nWindowTitle=0
      see "Instruction : Window Title = " + cValue + nl
    ok
  
```

To complete the previous example, use read() to get the content of a file that contains

```ring
I want window
The window title = "hello world"
```

Then use eval() to execute the content of that file!.
Also, you can update the methods GetWindow() and SetTitle() to create Real windows using the GUI Library
			
## Define Declarative Languages using Nested Structures based on Object-Oriented 

We learned how to use Natural statements to execute our code and using the same features we can use nested structures to execute our code.

The next example from the Web library, generate an HTML document using the Bootstrap library. No HTML code is written directly in this example, we created a similar language (just as an example) Then using this declarative language that uses nested structures, we generated the HTML Document.

The idea in this example is that the GetDiv() and GetH1() methods return an object that we can access using {} and after each object access, the method BraceEnd() will be executed to send the generated HTML to the parent object until we reach to the root where BraceEnd() will print the output.

```ring
load "weblib.ring"
import System.Web

func Main

BootStrapWebPage()
{
  div
  {
    classname = :container
    div
    {
      classname = :jumbotron
      H1 {   text("Bootstrap Page")   }
    }
    div
    {
      classname = :row
        for x = 1 to 3
          div
          {
            classname = "col-sm-4"
            H3 { html("Welcome to the Ring programming language") }
            P  { html("Using a scripting language is very fun!") }
          }
        next
    }
  }
}
```

The classes that power the declarative interface looks like this

```ring
class Link from ObjsBase
  title  link
  func braceend			
    cOutput = nl+GetTabs() + "<a href='" + 
              Link + "'> "+ Title + " </a> " + nl			

class Div from ObjsBase 
  func braceend
    cOutput += nl+'<div'
    addAttributes()
    addStyle()
    getObjsData()
    cOutput += nl+"</div>" + nl
    cOutput = TabMLString(cOutput)
```

# Implementation

## Transparent Implementation 

Ring comes with transparent implementation. We can know what is happening in each compiler stage and what is going on during the run-time by the Virtual Machine Example : ring helloworld.ring -tokens -rules -ic -norun

```ring
see "Hello, World!" 
```			

Output

```
==================================================================
Tokens - Generated by the Scanner
==================================================================

Keyword : SEE
Literal : Hello, World!
EndLine

==================================================================

==================================================================
Grammar Rules Used by The Parser
==================================================================

Rule : Program --> {Statement}

Line 1
Rule : Factor --> Literal
Rule : Range --> Factor
Rule : Term --> Range
Rule : Arithmetic --> Term
Rule : BitShift --> Arithmetic
Rule : BitAnd --> BitShift
Rule : BitOrXOR -->  BitAnd
Rule : Compare --> BitOrXOR
Rule : EqualOrNot --> Compare
Rule : LogicNot -> EqualOrNot
Rule : Expr --> LogicNot
Rule : Statement  --> 'See' Expr

==================================================================

==================================================================
Byte Code - Before Execution by the VM
==================================================================

PC     OPCode   Data
1     FuncExE
2       PushC   Hello, World!
3       Print
4  ReturnNull

==================================================================
```			

## Visual Implementation

The Ring programming language is designed using the PWCT visual programming tool 

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/ringvisualsrc1.jpg)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/ringvisualsrc2.jpg)

## Smart Garbage Collector

Avoid memory problems:-

    Invalid Memory Access
    Memory leaks
    Uninitialized Memory Access
    Dangling pointer

Rules:-

* Global variables always stay in the memory, until you delete these variables using the assignment statement.

* Local variables always deleted after the end of the function.

* The programmer has full control over when to delete the variable from the memory using the Assignment statement.

Example:

```ring
aList = [1,2,3,4,5]
aList = "nice"
```    			

After the second line directly, The list [1,2,3,4,5] will be deleted from the memory and we will have a string "nice"

The programmer can call the function callgc() to force running the garbage collector.

If we have a reference to a variable (when we pass objects and lists to functions), then deleting variables will be based on reference counting, if no references everything will be deleted, but if we have a reference, the data will stay in memory.

## No Global Interpreter (VM) Lock - No GIL

When we use threads in Ring applications, We don't have a global interpreter (VM) lock (No GIL)

So threads can work in parallel and execute Ring instructions at the same time

This is better for threads and concurrency (More Faster!) 

## Fast Enough For Many Applications

Ring is designed to be a simple, small, and flexible language in the first place, but also it is fast enough for many applications.

Ring can do each of the next tasks in around 1 second

Tested using Victus Laptop [13th Gen Intel(R) Core(TM) i7-13700H, Windows 11]

(1) Compiling 100,000 lines of code

(2) Executing empty loop that count from 1 to 100,000,000

(3) Creating list contains 7,000,000 items then summing all of the list items

(4) Printing numbers from 1 to 30,000 using command prompt

(5) Printing numbers from 1 to 400,000 using output redirection and Ring Notepad

(6) Adding 50,000 nodes to the TreeWidget in GUI applications

(7) Adding 60,000 items to the ListWidget in GUI applications

(8) Executing 3000 search operations using linear search in a list contains 100,000 items, trying to find the last item (The worst case)

Also, when we need more speed we can use C/C++ extensions! 

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/ringdemo1_speed.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/ringdemo2_speed.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/ringdemo3_speed.png)

![ScreenShot](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/website/ringdemo4_speed.png)


# Features


## Syntax

* Compact Syntax

* Three Styles for writing the source code

* Syntax Flexibility support customization, translation and porting old code

* Declarative Programming

* Natural Language Programming

* Clear program structure (Statements then functions then packages & classes)

* using { } to access objects and use attributes/methods as variables/functions

* No explicit end for statements (No ; or ENTER is required)

* Use exit to go outside from more than one loop

* No keyword to end Functions, Classes, and Packages

## Powerful Implementation

* Free Open Source (MIT License)

* Hybrid Implementation (Compiler+VM)

* The compiler + The Virtual Machine are 20,000 lines of C code

* The other 500,000 lines of code are related to libraries!

* Transparent Implementation provides optional printing for Tokens/Grammar/Byte-Code during execution

* Written in ANSI C (The code is generated)

* Developed using Visual Programming (PWCT)

* Smart Garbage Collector suitable for Games (Automatic Memory Management using Escape Analysis and Reference Counting)

* No Global Interpreter Lock (No GIL)

* Portable (MS-DOS, Windows, Linux, macOS, Android, WebAssembly, etc.)

## Simple

* Comments (One line & Multi-line)

* Multi-line literals

* Not Case-Sensitive

* The list index starts from 1

* Rich control structures & Operators

* Range operator ex: 1:10

* Main Function (optional)

* Call Function before the definition

* Recursion

* Access (read/write) string letter by index

* For in get item by reference not value

* First Class Variables, Lists, Objects and Functions

* Store/Copy Lists/Objects by value (Deep Copy)

* Pass Lists/Objects by reference

* 8-bit clean, work on binary data directly

## Dynamic

* Dynamic Typing

* Lexical Scoping (Global, Local & Object State)

* Default scope for variables inside functions (Local)

* Default scope for variables outside functions (global)

* Optional loading for modules in a separate global scope

* Exception Handling

* Eval() to execute code during run-time

## Object-Oriented Programming (OOP)

* Encapsulation

* Setter/Getter (optional)

* private state (optional)

* Instantiation

* Polymorphism

* Composition

* Inheritance (Single Inheritance)

* Operator Overloading

* Packages

* Reflection and Meta-programming

## Standard Library 

* I/O commands

* Math functions

* String functions

* List functions

* File processing functions

* System functions

* Database support (ODBC, MySQL, PostgreSQL and SQLite)

* Security Functions (OpenSSL)

* Internet Functions (LibCurl)

* Powerful GUI Framework (Qt)

* Web Development Library

* Many Game Programming Libraries

## Web Development 

* HTTP Get

* HTTP Post

* File upload

* Cookies

* URL Encode

* Templates

* HTML Special Characters

* HTML Generation using Functions

* HTML Generation using Classes

* CRUD Example (using MVC)

* Users Example (Register, Login, and Check)

* Deploy web applications in the Cloud

## Extensions

* Extension using C/C++ (Simple API)

* Embedding in C/C++ projects

* Comes with a binding generator to quickly wrap C/C++ Libraries

* Network Programming (SDLNet, Libuv, etc.)

* Create 2D Games (Allegro & LibSDL)

* Create 3D Games (OpenGL, FreeGLUT, RayLib, Qt3D, etc.)

* Tilengine Extension (2D retro graphics engine with raster effects)

* Create GUI Applications for Desktop, WebAssembly, and Mobile platforms (Using the Qt Framework)

* Libui Extension (lightweight GUI Applications)

## More 

* Very Stable

* Good Performance

* Complete Documentation

* Many Libraries (Batteries Included)

* Many Samples (Easy to Learn)

* Many Applications

* Hundreds of YouTube Videos

* Powerful RAD tools (Code Editor, Form Designer, REPL, Debugger, Ring2EXE, Package Manager, etc.)
			
# Building from source code

We provide instructions for building on the next platforms:-

(1) [Microsoft Windows](language/README_Windows.md)

(2) [Ubuntu Linux](language/README_UbuntuLinux.md)

(3) [macOS](language/README_macOS.md)

# License 

The Ring programming language is distributed under the MIT License.
