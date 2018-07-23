# Ring_WINAPI

This Ring Extension brings the power of WIN APIs into Ring Programming Language

## How to use in Ring

1- Download this repo project as zip file from the green button on the upper right corner "Clone or download"

2- Extract all the files that present in the "bin" folder and copy them into "bin" folder of the binary ring

3- Load the "winapi.ring" file as it loads all of the extension and its associated library features

4- For more information on how to use the extension and the associated library functions use the documentations attached(Documentation.txt)

## Example

This is a simple ring code that use this extension:

    Load "WINAPI.ring"

    If rwaIsRunAsAdmin() = False
    	rwaElevate(exefilename(), filename())	
    	#This will elevate ring and open the currently running app as Admin
    Ok


## Other resources

- [The article of this extension in the ring forum](https://groups.google.com/forum/#!topic/ring-lang/4wp4gIoZFm4)
  

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
	
5- Clone the "ring_winapi" extension source from GitHub into extensions folder

    git clone https://github.com/MajdiSobain/ring_winapi.git
	
6- Now Open Command line (cmd) in the extension folder (c:\ring\extensions\ring_winapi) and compile the extension by run buildvc.bat batch file

    buildvc.bat
	
.

Enjoy ^_^
