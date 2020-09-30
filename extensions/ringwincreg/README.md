# Ring_WinCReg

Ring WinCReg extension is a very light, easy, and powerful extension for Ring Programming Language that has been made to bring all means of easiness in the dealing with Windows Registry. It gives you the ability to do from minor registry needs like saving or restoring settings to more superior goals like reaching and manipulating every single key or value in the whole registry tree.

This extension has been made on top of previously created C++ language class called “Registry Wrapper Class(CRegisry Class)” that has been published on CodeProject in [this article](http://www.codeproject.com/Articles/8953/Registry-Wrapper-Class-CRegistry).

## RCRegistry Class Library

RCRegistry class, stands for Ring CRegistry Class or CRegistry Class for Ring, is a Ring Class that has been made to make using ring_wincreg extension functions easier by using the style of using “Registry Wrapper Class” in C++. I found this style is reasonable and readable better than just using the ring_wincreg original functions. It can be used by loading the file that contain it (wincreg.ring).

	Note: RCRegistry Class in Ring_WinCReg Extension is now compatible with Ring 1.1 and above. 
	
	It will show errors if used with Ring 1.0.

## How to use in Ring

1- Go to Ring_WinCReg GitHub project [releases download page](https://github.com/MajdiSobain/ring_wincreg/releases), or Sourceforge [Ring_WinCReg page](https://sourceforge.net/projects/ring-wincreg/).

2- Download the project as a ZIP file.

3- Extract all the files that present in the "bin" folder and copy them into "bin" folder of the binary ring

4- Load the "wincreg.ring" file as it loads all of the extension and its associated library features

5- For more information on how to use the extension and the associated library functions use visit [this documentation website](http://ring-wincreg.sourceforge.net/) or use the documentation attached(Documentation.html)

## Example

This is a simple ring code that use this extension:

    Load "wincreg.ring"
  
    Reg = new RCRegistry
  
    Reg.OpenKey([HKEY_CURRENT_USER, "Software\MyApplication"]) 
    # This will create the Key "MyApplication" if its not present then it will be Opened
  
    Reg["AppVersion"].SetValue("2.3")
	
	See Reg["AppVersion"].GetValue()
  
    Reg.CloseKey()
  

## Other resources

1- [The extension homepage](http://ring-wincreg.sourceforge.net/)

2- [The project SourceForge page](https://sourceforge.net/projects/ring-wincreg/)

3- [The documentation website](http://ring-wincreg.sourceforge.net/docs/)

4- [The Ring Programming Language](http://ring-lang.net/)

5- [The article of the original C++ Class (CRegistry Wrapper)](http://www.codeproject.com/Articles/8953/Registry-Wrapper-Class-CRegistry)
	

## How to Compile

1- Open [Git bash](http://opensourcerer.diy.org/challenge/3) then Navigate to the folder that you want to bring Ring source into it. For example:

	cd c:
	
2- Clone the ring source from GitHub into the opened location (c:)
  
	git clone https://github.com/ring-lang/ring.git
	
3- Optionally, You can create another branch in local repo of ring to use it for extensions development. This will prevent any changes in the master branch of ring if you plan to make some changes in ring away from newly added extensions. This can be done by:
  
	cd ring
	git checkout -b extensions

*This will create a new branch called extensions and will switch to it.

4- Navigate to the extensions folder 

	cd extensions
	
5- Clone the ring_wincreg extension source from GitHub into extensions folder

	git clone https://github.com/MajdiSobain/ring_wincreg.git
	
6- Now Open Command line (cmd) in the extension folder (c:\ring\extensions\ring_wincreg) and compile the extension by run buildvc.bat batch file

	buildvc.bat
	
.

Enjoy ^_^
