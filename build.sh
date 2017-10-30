#! /bin/sh

## rights


VERSION=1.4.5
BASE_DIR="/usr/lib/ring"
# BASE_DIR="/var/hassan/ir"
MOD_DIR="$BASE_DIR/modules/"

if [ ! -d $BASE_DIR ]; then
    mkdir $BASE_DIR || exit
    echo "$BASE_DIR Directory created successfully"
fi

if [ ! -d $MOD_DIR ]; then
    mkdir $MOD_DIR || exit
    echo "$MOD_DIR Directory created successfully"
fi
