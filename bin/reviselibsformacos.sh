#!/bin/bash
set -e

cd ../lib

CURRENT_USER=$(whoami)
LIB_DIR="$(pwd)"

FILES=( *.dylib )

for LIB in "${FILES[@]}"; do
    echo "Process $LIB ..."

    # Check dependencies that contains /Users/ 
    otool -L "$LIB" | awk 'NR>1 {print $1}' | grep "/Users/" | while read dep; do
        NEW_DEP=$(echo "$dep" | sed -E "s|/Users/[^/]+|/Users/$CURRENT_USER|")
        if [ "$dep" != "$NEW_DEP" ]; then
            echo "Change dependency:"
            echo "From: $dep"
            echo "To: $NEW_DEP"
            install_name_tool -change "$dep" "$NEW_DEP" "$LIB"
        fi
    done

    # Update install_name that contains /Users/
    OLD_ID=$(otool -D "$LIB" | tail -n +2)
    if [[ -n "$OLD_ID" && "$OLD_ID" == *"/Users/"* ]]; then
        NEW_ID=$(echo "$OLD_ID" | sed -E "s|/Users/[^/]+|/Users/$CURRENT_USER|")
        if [ "$OLD_ID" != "$NEW_ID" ]; then
            echo "Update install_name (ID):"
            echo "From: $OLD_ID"
            echo "To: $NEW_ID"
            install_name_tool -id "$NEW_ID" "$LIB"
        fi
    fi

    echo "Updated: $LIB"
    echo
done

cd ../bin

echo "Done.."