freopen("myprogoutput.txt","w+",stdout)
see "welcome" + nl
for x = 1 to 10
        see x + nl
next

/*
** Read : https://en.wikipedia.org/wiki/Device_file#Device_files
** The next code is not portable, we can use iswindows() before
** using it and we can write special code for each operating system.
*/

freopen("CON","w",stdout)       # For Microsoft Windows
see "Done" + nl                 # print to stdout again
