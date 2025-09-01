#!/bin/bash
set -euo pipefail

# Script to download SDL2 and related libraries
# Checks if directories exist before cloning to avoid overwriting

# Check if git is installed
if ! command -v git >/dev/null 2>&1; then
    echo -e "\033[0;31mGit not found. Please install git first.\033[0m"
    exit 1
fi

# Define colors
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Define versions
declare -A VERSIONS=(
    ["SDL"]="2.32.8"
    ["SDL_image"]="2.8.8"
    ["SDL_mixer"]="2.8.1"
    ["SDL_net"]="2.2.0"
    ["SDL_ttf"]="2.24.0"
)

BASE_DIR="app/src/main/cpp"

echo -e "${GREEN}Starting download of SDL2 and related libraries...${NC}"
echo -e "Base directory: $BASE_DIR"

# Function to clone if not exists
clone_if_not_exists() {
    local repo=$1
    local version=$2
    local target_dir="$BASE_DIR/$repo"

    if [ -d "$target_dir" ]; then
        echo -e "${YELLOW}$repo already exists at $target_dir, skipping clone.${NC}"
    else
        echo -e "${YELLOW}Progress: [$count/$total] Cloning $repo version $version...${NC}"
        if git clone --filter=blob:none "https://github.com/libsdl-org/$repo.git" "$target_dir" --branch="release-$version" --recursive --depth 1 >/dev/null 2>&1; then
            echo -e "${GREEN}$repo cloned successfully.${NC}"
        else
            echo -e "${RED}Failed to clone $repo${NC}"
            exit 1
        fi
    fi
}

# Clone each library
total=${#VERSIONS[@]}
count=0
for repo in "${!VERSIONS[@]}"; do
    count=$((count + 1))
    clone_if_not_exists "$repo" "${VERSIONS[$repo]}"
done

echo -e "${GREEN}All downloads completed.${NC}"