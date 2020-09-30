# Clear load command the load stdlibcore.ring in the current directory
# This prevent reloading the same file many times 
# when we use load "stdlib.ring" and load "stdlibcore.ring" in the same project

Load "stdlibcore.ring"