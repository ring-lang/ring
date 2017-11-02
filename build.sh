#! /bin/sh

####################################
##      Set global variables      ##
####################################
VERSION=1.4.5
BASE_DIR="/usr/local/lib/ring"
LIB_DIR="$BASE_DIR/lib/"
EXT_DIR="$BASE_DIR/extensions/"

## AT_* : autotools variables
AT_BIN=autoreconf
AT_FLAGS=-i

####################################
##   Make required directories    ##
####################################
if [ ! -d $BASE_DIR ]; then
    mkdir $BASE_DIR || exit
    echo "$BASE_DIR Directory created successfully"
fi

if [ ! -d $LIB_DIR ]; then
    mkdir $LIB_DIR || exit
    echo "$LIB_DIR Directory created successfully"
fi

if [ ! -d $EXT_DIR ]; then
    mkdir $EXT_DIR || exit
    echo "$EXT_DIR Directory created successfully"
fi


#####################################
## Build the configuration files  ##
####################################
$AT_BIN $AT_FLAGS || exit
