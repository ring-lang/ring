Visual Studio Extension
=======================

Author : Ahmed Omar

URL : https://github.com/ahmadomar/RingForVS

Features
========

	1. Add new ring project.
	2. Add new ring item 'Ring File'.
	3. Highlight Ring reserved keywords.
	4. Run the file.
	
Notes: To run the .ring file you have to do the below steps :

	1. Open Visual Studio -> Tools -> External Tools -> Click Add
	2. Title -> Ring 
	3. Command -> 'Path to RingForVS.bat -> from RingVSIX Project main folder'
	4. Arguments -> $(ItemPath)

For Developers
==============

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
	
