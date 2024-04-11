![Ring](https://ring-lang.github.io/theringlogo.jpg)

# Ring Programming Language

## Simple and flexible programming language for applications development

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

* [Aim](https://ring-lang.github.io/doc1.20/introduction.html#motivation-1)

* [Ring Article](https://ring-lang.github.io/doc1.20/languagedesign.html)

* [Syntax Flexibility](https://ring-lang.github.io/doc1.20/syntaxflexibility.html)

* [The Declarative Approach](https://ring-lang.github.io/doc1.20/declarative.html)

* [Natural Language Programming](https://ring-lang.github.io/doc1.20/natural.html)

* [Natural Language Programming Library](https://ring-lang.github.io/doc1.20/naturallibrary.html)

* [Programming Without Coding Technology](https://github.com/ring-lang/ring/tree/master/marketing/pwct)

# Batteries Included

Ring comes with many high quality bindings for popular libraries 

![ScreenShot](https://ring-lang.github.io/libs.png)

# Practical

Many of the Ring libraries (StdLib, WebLib, Natural Library, Games Engine, etc.) and the Ring IDE (Ring Notepad, Form Designer, etc.) are written in the Ring language itself. Ring is ready for use in production and increases the developers productivity. 

## Custom Styles And Modern Programming Paradigms

Using Ring you will feel that the language is yours! A lot of modern programming paradigms are ready for use in production and using Natural Language Programming you can quickly integrate natural interfaces to your programs. 

Also, you can start your software development by writing natural descriptions, then adding the implementation later. 

## GUI Applications Development And RAD Tools

Many developers reported that using Ring we can develop many GUI applications in a few hours. 
Ring comes with Rapid Application Development (RAD) tools that we can use to quickly develop GUI applications using the MVC design pattern. 
Also, using the same source code we can distribute our applications for Desktop, Web, and Mobile platforms. 

![ScreenShot](https://ring-lang.github.io/newringdemo6.png)

## First Class Support For Game Development

We believe in Games as a nice way to encourage people to learn to program.
Ring comes with many game programming libraries in the standard library.
Ring provides native support for Allegro, LibSDL, RayLib, OpenGL, FreeGLUT, Tilengine and Qt3D libraries.
Also, Ring comes with a simple game engine for 2D game development using Declarative Programming.

![ScreenShot](https://ring-lang.github.io/ringdemo13.png)

## WebAssembly (Front-End Web Development)

Using Ring we can quickly develop web applications using WebAssembly (Binary format that allows sand-boxed executable code in web pages. This format is nearly as fast as native machine code and is now supported by all major web browsers) 

![ScreenShot](https://ring-lang.github.io/wasm_demo4.png)

## Back-End Web Development

Using Ring we can quickly develop web applications using the MVC design pattern. 
We can easily use HTML templates with embedded Ring code. 
Also, we can generate HTML code from Ring programs using Declarative Programming.

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

Ring comes with transparent implementation. We can know what is happening in each compiler stage and what is going on during the run-time by the Virtual Machine 

Example: 

	ring helloworld.ring -tokens -rules -ic -norun

## Visual Implementation

The Ring programming language is designed using the PWCT visual programming tool 

## Smart Garbage Collector

Avoid memory problems:-

    Invalid Memory Access
    Memory leaks
    Uninitialized Memory Access
    Dangling pointer

## No Global Interpreter (VM) Lock - No GIL

When we use threads in Ring applications, We don't have a global interpreter (VM) lock (No GIL)

So threads can work in parallel and execute Ring instructions at the same time

This is better for threads and concurrency (More Faster!) 

## Fast Enough For Many Applications

Ring is designed to be a simple, small, and flexible language in the first place, but also it is fast enough for many applications.

Also, when we need more speed we can use C/C++ extensions! 

![ScreenShot](https://ring-lang.github.io/ringdemo4_speed.png)

# Building from source code

We provide instructions for building on the next platforms:-

-  [Microsoft Windows](language/README_Windows.md)

-  [Ubuntu Linux](language/README_UbuntuLinux.md)

-  [macOS](language/README_macOS.md)

# License 

The Ring programming language is distributed under the MIT License.
