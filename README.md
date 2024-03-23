![Ring](https://ring-lang.github.io/theringlogo.jpg)

# Ring Programming Language

## Simple and flexible programming language for applications development

| |*Resources*|
|---|---|
|Download |[![Download](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/graphics/binaryrelease.svg)](https://ring-lang.github.io/download.html)|
|Help |[![Help](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/graphics/documentation.svg)](https://ring-lang.github.io/doc1.19/index.html)|
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
- [Implementation](#implementation)
  * [Transparent Implementation](#transparent-implementation)
  * [Visual Implementation](#visual-implementation)
  * [Smart Garbage Collector](#smart-garbage-collector)
  * [No Global Interpreter (VM) Lock - No GIL](#no-global-interpreter-vm-lock---no-gil)
  * [Fast Enough For Many Applications](#fast-enough-for-many-applications)
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

* [Ring Article](https://ring-lang.github.io/doc1.19/languagedesign.html)

* [Syntax Flexibility](https://ring-lang.github.io/doc1.19/syntaxflexibility.html)

* [The Declarative Approach](https://ring-lang.github.io/doc1.19/declarative.html)

* [Natural Language Programming](https://ring-lang.github.io/doc1.19/natural.html)

* [Natural Language Programming Library](https://ring-lang.github.io/doc1.19/naturallibrary.html)

* [Programming Without Coding Technology](https://github.com/ring-lang/ring/tree/master/marketing/pwct)

# Batteries Included

Ring comes with many high quality bindings for popular libraries 

![ScreenShot](https://ring-lang.github.io/libs.png)

# Practical

Many of the Ring libraries (StdLib, WebLib, Natural Library, Games Engine, etc.) and the Ring IDE (Ring Notepad, Form Designer, etc.) are written in the Ring language itself. Ring is ready for use in production and increases the developers productivity. 

## Custom Styles And Modern Programming Paradigms

Using Ring you will feel that the language is yours! A lot of modern programming paradigms are ready for use in production and using Natural Language Programming you can quickly integrate natural interfaces to your programs. 

Also, you can start your software development by writing natural descriptions, then adding the implementation later. 

![ScreenShot](https://ring-lang.github.io/newringdemo1.png)

![ScreenShot](https://ring-lang.github.io/newringdemo2.png)


## GUI Applications Development And RAD Tools

Many developers reported that using Ring we can develop many GUI applications in a few hours. 
Ring comes with Rapid Application Development (RAD) tools that we can use to quickly develop GUI applications using the MVC design pattern. 
Also, using the same source code we can distribute our applications for Desktop, Web, and Mobile platforms. 

![ScreenShot](https://ring-lang.github.io/newringdemo6.png)

![ScreenShot](https://ring-lang.github.io/newringdemo5.png)

## First Class Support For Game Development

We believe in Games as a nice way to encourage people to learn to program.
Ring comes with many game programming libraries in the standard library.
Ring provides native support for Allegro, LibSDL, RayLib, OpenGL, FreeGLUT, Tilengine and Qt3D libraries.
Also, Ring comes with a simple game engine for 2D game development using Declarative Programming.

![ScreenShot](https://ring-lang.github.io/ringdemo13.png)

![ScreenShot](https://ring-lang.github.io/goldmagic800.png)

![ScreenShot](https://ring-lang.github.io/newringdemo3.png)

![ScreenShot](https://ring-lang.github.io/snakegamecode.png)

![ScreenShot](https://ring-lang.github.io/sokobangamecode.png)


## WebAssembly (Front-End Web Development)

Using Ring we can quickly develop web applications using WebAssembly (Binary format that allows sand-boxed executable code in web pages. This format is nearly as fast as native machine code and is now supported by all major web browsers) 

![ScreenShot](https://ring-lang.github.io/wasm_demo4.png)

![ScreenShot](https://ring-lang.github.io/wasm_demo1.png)

![ScreenShot](https://ring-lang.github.io/wasm_demo2.png)

![ScreenShot](https://ring-lang.github.io/wasm_demo3.png)

![ScreenShot](https://ring-lang.github.io/wasm_demo5.png)

## Back-End Web Development

Using Ring we can quickly develop web applications using the MVC design pattern. 
We can easily use HTML templates with embedded Ring code. 
Also, we can generate HTML code from Ring programs using Declarative Programming.

![ScreenShot](https://ring-lang.github.io/newringdemo9.png)

![ScreenShot](https://ring-lang.github.io/newringdemo12.png)

![ScreenShot](https://ring-lang.github.io/mycoffee.png)

## Mobile Development

Using Ring we can distribute our applications for mobile platforms (Android, iOS, etc.)

![ScreenShot](https://ring-lang.github.io/android_demo1.png)

## Building Tools (Command Line)

Using Ring we can whip up a CLI tool quickly and distribute it with ease. 
The Ring Package Manager is an example of a powerful tool that we developed using Ring in a few hours. 
We recorded the development time (21 hours of development includes explaining each step) 

![ScreenShot](https://ring-lang.github.io/cmddemo2.png)

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

![ScreenShot](https://ring-lang.github.io/ringvisualsrc1.jpg)

![ScreenShot](https://ring-lang.github.io/ringvisualsrc2.jpg)

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

Ring can do each of the following tasks in around one second.

Tested using Victus Laptop [13th Gen Intel(R) Core(TM) i7-13700H, Windows 11, Ring 1.19]

(1) Compiling 100,000 lines of code

(2) Executing an empty loop that count from 1 to 100,000,000

(3) Creating list contains 7,000,000 items then summing all of the list items

(4) Printing numbers from 1 to 40,000 using command prompt

(5) Printing numbers from 1 to 500,000 using output redirection and Ring Notepad

(6) Adding 50,000 nodes to the TreeWidget in GUI applications

(7) Adding 60,000 items to the ListWidget in GUI applications

(8) Executing 3000 search operations using linear search in a list contains 100,000 items, trying to find the last item (The worst case)

Also, when we need more speed we can use C/C++ extensions! 

![ScreenShot](https://ring-lang.github.io/ringdemo1_speed.png)

![ScreenShot](https://ring-lang.github.io/ringdemo2_speed.png)

![ScreenShot](https://ring-lang.github.io/ringdemo3_speed.png)

![ScreenShot](https://ring-lang.github.io/ringdemo4_speed.png)

# Building from source code

We provide instructions for building on the next platforms:-

-  [Microsoft Windows](language/README_Windows.md)

-  [Ubuntu Linux](language/README_UbuntuLinux.md)

-  [macOS](language/README_macOS.md)

# License 

The Ring programming language is distributed under the MIT License.
