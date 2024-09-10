#!/bin/bash

# CLear terminal
clear

# Function to get the Linux distro name
get_distro_name() {
    if command -v lsb_release &> /dev/null; then
        lsb_release -d | awk -F'\t' '{print $2}'
        elif [ -f /etc/os-release ]; then
        . /etc/os-release
        echo "$NAME"
    else
        echo "Unknown Linux Distro"
    fi
}

# Get the Linux distro name
distro_name=$(get_distro_name)

# Get the directory of the current script
DIR="$(dirname "$(realpath "$0")")"

build_header() {
    local name="$1"
    echo -e "\033[1;33mBuilding \033[1;34m$name\033[1;33m on $distro_name...\033[0m"
    sleep 2
}

install() {
    local name="$1"
    
    cd $DIR/../bin || exit 1
    echo -e "\033[0;32mInstalling...\033[0m"
    ./install.sh || exit 1
    echo -e "\033[1;34m$name\033[1;33m has been successfully compiled and installed!\033[0m"
}

# Initialize and set DEBUG to false by default
DEBUG=false

# Check for -debug argument
if [[ "$@" == *"-debug"* ]]; then
    DEBUG=true
fi

# Function to build a compiler/extension/tool
build() {
    local path="$DIR/$1"
    local gencode_script="$2"
    local build_script="$3"
    local name="$4"
    
    echo -e "\033[0;32mBuilding $name...\033[0m"

    cd "$path" || exit 1

    if [ -n "$gencode_script" ]; then
        if $DEBUG; then
            ./"$gencode_script"
        else
            ./"$gencode_script" > /dev/null 2>&1
        fi
        if [ $? -ne 0 ]; then
            echo -e "\033[0;31mError: Failed to run gencode for $name.\033[0m"
            cd - > /dev/null || exit 1
            return 1
        fi
    fi

    if $DEBUG; then
        ./"$build_script"
    else
        ./"$build_script" > /dev/null 2>&1
    fi
    if [ $? -ne 0 ]; then
        echo -e "\033[0;31mError: Failed to build $name.\033[0m"
        cd - > /dev/null || exit 1
        return 1
    fi

    cd - > /dev/null || exit 1
}

# Check if no arguments are provided or if only -debug is provided
if [ $# -eq 0 ] || { [ $# -eq 1 ] && [[ "$1" == "-debug" ]]; }; then
    build_header                                             "Ring"
    # Compile ring with all extensions
    build "../language/build"                   ""                  "buildgcc.sh"       "Ring Compiler/VM"      || exit 1
    build "../extensions/ringallegro"           "gencode.sh"        "buildgcc.sh"       "RingAllegro"           || exit 1
    build "../extensions/ringfreeglut"          "gencode.sh"        "buildgcc.sh"       "RingFreeGLUT"          || exit 1
    build "../extensions/ringmurmurhash"        ""                  "buildgcc.sh"       "RingMurmurHash"        || exit 1
    build "../extensions/ringqt"                "gencode_core.sh"   "buildgcc_core.sh"  "RingQt (Core)"         || exit 1
    build "../extensions/ringqt"                "gencode_light.sh"  "buildgcc_light.sh" "RingQt (Light)"        || exit 1
    build "../extensions/ringqt"                "gencode.sh"        "buildgcc.sh"       "RingQt"                || exit 1
    build "../extensions/ringstbimage"          "gencode.sh"        "buildgcc.sh"       "RingStbImage"          || exit 1
    build "../extensions/ringzip"               "gencode.sh"        "buildgcc.sh"       "RingZip"               || exit 1
    build "../extensions/ringhttplib"           "gencode.sh"        "buildgcc.sh"       "RingHTTPLib"           || exit 1
    build "../extensions/ringmysql"             ""                  "buildgcc.sh"       "RingMySQL"             || exit 1
    build "../extensions/ringraylib5/src"       "gencode.sh"        "buildgcc.sh"       "RingRayLib"            || exit 1
    build "../extensions/ringtilengine"         "gencode.sh"        "buildgcc.sh"       "RingTilengine"         || exit 1
    build "../extensions/ringthreads"           "gencode.sh"        "buildgcc.sh"       "RingThreads"           || exit 1
    build "../extensions/ringcjson"             "gencode.sh"        "buildgcc.sh"       "RingCJSON"             || exit 1
    build "../extensions/ringinternet"          ""                  "buildgcc.sh"       "RingInternet"          || exit 1
    build "../extensions/ringodbc"              ""                  "buildgcc.sh"       "RingODBC"              || exit 1
    build "../extensions/ringrogueutil"         "gencode.sh"        "buildgcc.sh"       "RingRogueUtil"         || exit 1
    build "../extensions/ringpdfgen"            "gencode.sh"        "buildgcc.sh"       "RingPDFGen"            || exit 1
    build "../extensions/ringconsolecolors"     "gencode.sh"        "buildgcc.sh"       "RingConsoleColors"     || exit 1
    build "../extensions/ringlibui"             "gencode.sh"        "buildgcc.sh"       "RingLibUI"             || exit 1
    build "../extensions/ringopengl/opengl21"   "gencode.sh"        "buildgcc.sh"       "RingOpenGL"            || exit 1
    build "../extensions/ringsdl"               "gencode.sh"        "buildgcc.sh"       "RingSDL"               || exit 1
    build "../extensions/ringcurl"              "gencode.sh"        "buildgcc.sh"       "RingCurl"              || exit 1
    build "../extensions/ringlibuv"             "gencode.sh"        "buildgcc.sh"       "RingLibuv"             || exit 1
    build "../extensions/ringopenssl"           ""                  "buildgcc.sh"       "RingOpenSSL"           || exit 1
    build "../extensions/ringsockets"           ""                  "buildgcc.sh"       "RingSockets"           || exit 1
    build "../extensions/ringfastpro"           ""                  "buildgcc.sh"       "RingFastPro"           || exit 1
    build "../extensions/ringpostgresql"        "gencode.sh"        "buildgcc.sh"       "RingPostgreSQL"        || exit 1
    build "../extensions/ringsqlite"            ""                  "buildgcc.sh"       "RingSQLite"            || exit 1
    build "../tools/ring2exe"                   ""                  "build.sh"          "Ring2EXE"              || exit 1
    build "../tools/ringpm"                     ""                  "build.sh"          "RingPM"                || exit 1
    build "../tools/ringrepl"                   ""                  "build.sh"          "RingREPL"              || exit 1
    build "../tools/folder2qrc"                 ""                  "build.sh"          "Folder2QRC"            || exit 1
    build "../language/tests"                   ""                  "build.sh"          "Tests"                 || exit 1
    install                                                  "Ring"
fi

## Check for specific args
for arg in "$@"; do
    case "$arg" in
        -light)
            build_header                                             "Ring"
            # Compile light build
            build "../language/build"                   ""                  "buildgcc.sh"       "Ring Compiler/VM"      || exit 1
            build "../extensions/ringconsolecolors"     "gencode.sh"        "buildgcc.sh"       "RingConsoleColors"     || exit 1
            build "../extensions/ringinternet"          ""                  "buildgcc.sh"       "RingInternet"          || exit 1
            build "../extensions/ringzip"               "gencode.sh"        "buildgcc.sh"       "RingZip"               || exit 1
            build "../tools/ring2exe"                   ""                  "build.sh"          "Ring2EXE"              || exit 1
            build "../tools/ringpm"                     ""                  "build.sh"          "RingPM"                || exit 1
            build "../tools/ringrepl"                   ""                  "build.sh"          "RingREPL"              || exit 1
            build "../tools/folder2qrc"                 ""                  "build.sh"          "Folder2QRC"            || exit 1
            build "../language/tests"                   ""                  "build.sh"          "Tests"                 || exit 1
            install                                                  "Ring"
        ;;
        -ring)
            build_header "Ring Compiler/VM"
            build "../language/build"                   ""                  "buildgcc.sh"       "Ring Compiler/VM"      || exit 1
            install      "Ring Compiler/VM"
        ;;
        -ringallegro)
            build_header "RingAllegro"
            build "../extensions/ringallegro"           "gencode.sh"        "buildgcc.sh"       "RingAllegro"           || exit 1
            install      "RingAllegro"
        ;;
        -ringfreeglut)
            build_header "RingFreeGLUT"
            build "../extensions/ringfreeglut"          "gencode.sh"        "buildgcc.sh"       "RingFreeGLUT"          || exit 1
            install      "RingFreeGLUT"
        ;;
        -ringmurmurhash)
            build_header "RingMurmurHash"
            build "../extensions/ringmurmurhash"        ""                  "buildgcc.sh"       "RingMurmurHash"        || exit 1
            install      "RingMurmurHash"
        ;;
        -ringqt-core)
            build_header "RingQt (Core)"
            build "../extensions/ringqt"                "gencode_core.sh"   "buildgcc_core.sh"  "RingQt (Core)"        || exit 1
            install      "RingQt (Core)"
        ;;
        -ringqt-light)
            build_header "RingQt (Light)"
            build "../extensions/ringqt"                "gencode_light.sh"  "buildgcc_light.sh" "RingQt (Light)"        || exit 1
            install      "RingQt (Light)"
        ;;
        -ringqt)
            build_header "RingQt"
            build "../extensions/ringqt"                "gencode.sh"        "buildgcc.sh"       "RingQt"                || exit 1
            install      "RingQt"
        ;;
        -ringstbimage)
            build_header "RingStbImage"
            build "../extensions/ringstbimage"          "gencode.sh"        "buildgcc.sh"       "RingStbImage"          || exit 1
            install      "RingStbImage"
        ;;
        -ringzip)
            build_header "RingZip"
            build "../extensions/ringzip"               "gencode.sh"        "buildgcc.sh"       "RingZip"               || exit 1
            install      "RingZip"
        ;;
        -ringhttplib)
            build_header "RingHTTPLib"
            build "../extensions/ringhttplib"           "gencode.sh"        "buildgcc.sh"       "RingHTTPLib"           || exit 1
            install      "RingHTTPLib"
        ;;
        -ringmysql)
            build_header "RingMySQL"
            build "../extensions/ringmysql"             ""                  "buildgcc.sh"       "RingMySQL"             || exit 1
            install      "RingMySQL"
        ;;
        -ringraylib)
            build_header "RingRayLib"
            build "../extensions/ringraylib5/src"       "gencode.sh"        "buildgcc.sh"       "RingRayLib"            || exit 1
            install      "RingRayLib"
        ;;
        -ringtilengine)
            build_header "RingTilengine"
            build "../extensions/ringtilengine"         "gencode.sh"        "buildgcc.sh"       "RingTilengine"            || exit 1
            install      "RingTilengine"
        ;;
        -ringthreads)
            build_header "RingThreads"
            build "../extensions/ringthreads"           "gencode.sh"        "buildgcc.sh"       "RingThreads"           || exit 1
            install      "RingThreads"
        ;;
        -ringcjson)
            build_header "RingCJSON"
            build "../extensions/ringcjson"             "gencode.sh"        "buildgcc.sh"       "RingCJSON"             || exit 1
            install      "RingCJSON"
        ;;
        -ringinternet)
            build_header "RingInternet"
            build "../extensions/ringinternet"          ""                  "buildgcc.sh"       "RingInternet"          || exit 1
            install      "RingInternet"
        ;;
        -ringodbc)
            build_header "RingODBC"
            build "../extensions/ringodbc"              ""                  "buildgcc.sh"       "RingODBC"              || exit 1
            install      "RingODBC"
        ;;
        -ringrogueutil)
            build_header "RingRogueUtil"
            build "../extensions/ringrogueutil"         "gencode.sh"        "buildgcc.sh"       "RingRogueUtil"         || exit 1
            install      "RingRogueUtil"
        ;;
        -ringpdfgen)
            build_header "RingPDFGen"
            build "../extensions/ringpdfgen"            "gencode.sh"        "buildgcc.sh"       "RingPDFGen"            || exit 1
            install      "RingPDFGen"
        ;;
        -ringconsolecolors)
            build_header "RingConsoleColors"
            build "../extensions/ringconsolecolors"     "gencode.sh"        "buildgcc.sh"       "RingConsoleColors"     || exit 1
            install      "RingConsoleColors"
        ;;
        -ringlibui)
            build_header "RingLibUI"
            build "../extensions/ringlibui"             "gencode.sh"        "buildgcc.sh"       "RingLibUI"             || exit 1
            install      "RingLibUI"
        ;;
        -ringopengl)
            build_header "RingOpenGL"
            build "../extensions/ringopengl/opengl21"   "gencode.sh"        "buildgcc.sh"       "RingOpenGL"            || exit 1
            install      "RingOpenGL"
        ;;
        -ringsdl)
            build_header "RingSDL"
            build "../extensions/ringsdl"               "gencode.sh"        "buildgcc.sh"       "RingSDL"               || exit 1
            install      "RingSDL"
        ;;
        -ringcurl)
            build_header "RingCurl"
            build "../extensions/ringcurl"              "gencode.sh"        "buildgcc.sh"       "RingCurl"              || exit 1
            install      "RingCurl"
        ;;
        -ringlibuv)
            build_header "RingLibuv"
            build "../extensions/ringlibuv"             "gencode.sh"        "buildgcc.sh"       "RingLibuv"             || exit 1
            install      "RingLibuv"
        ;;
        -ringopenssl)
            build_header "RingOpenSSL"
            build "../extensions/ringopenssl"           ""                  "buildgcc.sh"       "RingOpenSSL"           || exit 1
            install      "RingOpenSSL"
        ;;
        -ringsockets)
            build_header "RingSockets"
            build "../extensions/ringsockets"           ""                  "buildgcc.sh"       "RingSockets"           || exit 1
            install      "RingSockets"
        ;;
        -ringfastpro)
            build_header "RingFastPro"
            build "../extensions/ringfastpro"           ""                  "buildgcc.sh"       "RingFastPro"           || exit 1
            install      "RingFastPro"
        ;;
        -ringpostgresql)
            build_header "RingPostgreSQL"               
            build "../extensions/ringpostgresql"        "gencode.sh"        "buildgcc.sh"       "RingPostgreSQL"        || exit 1
            install      "RingPostgreSQL"
        ;;
        -ringsqlite)
            build_header "RingSQLite"
            build "../extensions/ringsqlite"            ""                  "buildgcc.sh"       "RingSQLite"            || exit 1
            install      "RingSQLite"
        ;;
        -ring2exe)
            build_header "Ring2EXE"
            build "../tools/ring2exe"                   ""                  "build.sh"          "Ring2EXE"              || exit 1
            install      "Ring2EXE"
        ;;
        -ringpm)
            build_header "RingPM"
            build "../tools/ringpm"                     ""                  "build.sh"          "RingPM"                || exit 1
            install      "RingPM"
        ;;
        -ringrepl)
            build_header "RingREPL"
            build "../tools/ringrepl"                   ""                  "build.sh"          "RingREPL"              || exit 1
            install      "RingREPL"
        ;;
        -folder2qrc)
            build_header "Folder2QRC"
            build "../tools/folder2qrc"                 ""                  "build.sh"          "Folder2QRC"            || exit 1
            install      "Folder2QRC"
        ;;
        -tests)
            build_header "Tests"
            build "../language/tests"                   ""                  "build.sh"          "Tests"                 || exit 1
            install      "Tests"
        ;;
    esac
done
