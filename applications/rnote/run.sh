# Simple script to execute Ring applications in the application folder
# So the application can find files using relative path 
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

cd $(dirname "$1")
ring $1

