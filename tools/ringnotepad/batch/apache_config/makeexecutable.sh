#!/usr/bin/env bash

printf "Making all '.ring' files executable in this project folder recursively...\n\n"

printf "$1\n"

sudo find $1 -name "*.ring" -exec chmod 755 {} \;

printf '\n\n\nYou can run the app now\nPress enter to continue'
read enter

