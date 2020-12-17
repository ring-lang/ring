# Using CLOC (Count Lines of Code)

Using CLOC and the Ring programming language projects.

## The Tool

We are using cloc version 1.88 

URL: https://github.com/AlDanial/cloc

## Install

	ringpm install cloc from ringpackages

## Usage

	ringcloc <application_folder_path>

## Example

### Ring Notepad

#### Usage

	ringcloc c:\ring\tools\ringnotepad

#### Output

	      47 text files.
	      47 unique files.
	      11 files ignored.
	
	github.com/AlDanial/cloc v 1.88  T=1.18 s (39.0 files/s, 3212.2 lines/s)
	-----------------------------------------------------------------------------------
	Language                         files          blank        comment           code
	-----------------------------------------------------------------------------------
	Ring                                33            273            139           3186
	Bourne Shell                         4             22              9             88
	DOS Batch                            4              3              7             20
	INI                                  1              0              0             15
	C                                    1              0              1             10
	Markdown                             2              4              0              8
	Windows Resource File                1              0              0              1
	-----------------------------------------------------------------------------------
	SUM:                                46            302            156           3328
	-----------------------------------------------------------------------------------

### The Form Designer

#### Usage

	ringcloc c:\ring\tools\formdesigner

#### Output

	      54 text files.
	      54 unique files.
	      13 files ignored.
	
	github.com/AlDanial/cloc v 1.88  T=1.54 s (34.5 files/s, 7122.4 lines/s)
	-------------------------------------------------------------------------------
	Language                     files          blank        comment           code
	-------------------------------------------------------------------------------
	Ring                            52           1306            567           9071
	Markdown                         1              5              0              7
	-------------------------------------------------------------------------------
	SUM:                            53           1311            567           9078
	-------------------------------------------------------------------------------