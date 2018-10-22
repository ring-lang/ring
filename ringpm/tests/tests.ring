/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

aTests = [
	[ :name = "Test Printing the Program Name" ,
	  :Command = "ringpm" ],
	[ :name = "Test Installing the First Package" ,
	  :Command = "ringpm install firstpackage" ] ,
	[ :name = "Test Listing the Packages after installing the first package" ,
	  :Command = "ringpm list" ],
	[ :name = "Test Installing the Second Package" ,
	  :Command = "ringpm install secondpackage" ] ,
	[ :name = "Test Listing the Packages after installing the second package" ,
	  :Command = "ringpm list" ],
	[ :name = "Test Installing the Third Package" ,
	  :Command = "ringpm install thirdpackage" ] ,
	[ :name = "Test Listing the Packages after installing the third package" ,
	  :Command = "ringpm list" ],
	[ :name = "Test Removing the First Package" ,
	  :Command = "ringpm remove firstpackage" ] ,
	[ :name = "Test Listing the Packages after removing the first package" ,
	  :Command = "ringpm list" ],
	[ :name = "Test Removing the Second Package" ,
	  :Command = "ringpm remove secondpackage" ] ,
	[ :name = "Test Listing the Packages after removing the second package" ,
	  :Command = "ringpm list" ],
	[ :name = "Test Removing the Third Package" ,
	  :Command = "ringpm remove thirdpackage" ] ,
	[ :name = "Test Listing the Packages after removing the third package" ,
	  :Command = "ringpm list" ]
]
