Author : Ahmed Omar
URL : https://github.com/ahmadomar/RingForVS

![Ring](http://ring-lang.sourceforge.net/thering.jpg)

The Ring is an Innovative and practical general-purpose multi-paradigm scripting language that can be embedded in C/C++ projects, extended using C/C++ code and/or used as standalone language. The supported programming paradigms are Imperative, Procedural, Object-Oriented, Functional, Meta programming, Declarative programming using nested structures, and Natural programming. The language is portable (Windows, Linux, Mac OS X, Android, etc.) and can be used to create Console, GUI, Web, Games and Mobile applications. The language is designed to be Simple, Small, Flexible and Fast. Its Dynamic Language (Dynamic Typing and Weakly Typed) that compile the source code to byte code then execute it by the Ring Virtual Machine, which is integrated with the Ring Compiler in one program. The first version of the language (around 100,000 lines of C/C++/Ring code) is released on January 25th, 2016

Check this URL to read more about Ring http://ring-lang.net/

#Visual Studio Extension

![Visual Studio Extension For Ring](http://ring-lang.sourceforge.net/ringvs.png)

List of features:

	1. Add new ring project.
	2. Add new ring item 'Ring File'.
	3. Highlight Ring reserved keywords.
	4. Run the file.
	
Missing features:

	1. Add snippets.
	2. Add new project for web.
	3. Compile the current project.
	
Notes: To run the .ring file you have to do the below steps :

	1. Open Visual Studio -> Tools -> External Tools -> Click Add
	2. Title -> Ring 
	3. Command -> 'Path to RingForVS.bat -> from RingVSIX Project main folder'
	4. Arguments -> $(ItemPath)

#For Developers

To start using the project you must follow the below steps :

(1) Download Microsoft Visual Studio 2013 SDK 
https://www.microsoft.com/en-us/download/details.aspx?id=40758

(2) Download MPF for Projects - Visual Studio 2013
https://mpfproj12.codeplex.com/releases/view/115948

(3) Open file : RingVSIX.csproj modify the path : E:\MyWork\OpenSource\MPFProj12\Dev12\Src\CSharp\ProjectBase.Files to the new path that you have after download from (2)
	
(4) build the solution using visual studio

(5) Run the extensions 

	RingVSIX\bin\Debug\RingVSIX.vsix 
	Ring.VisualStudio.Editor\bin\Debug\Ring.VisualStudio.Editor.vsix
	
