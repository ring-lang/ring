#!/bin/sh

echo "Making all '.ring' files executable in this project folder recursively...\n"

echo "$1"

sudo find $1 -name "*.ring" -exec chmod 755 {} \;

echo '\n\n\nYou can run the app now\nPress enter to continue'
read enter

