#!/bin/bash
set -euo pipefail

# Define colors
readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly CYAN='\033[0;36m'
readonly NC='\033[0m'

# Logging function with levels
log() {
    local level=$1
    shift
    local message=$*
    
    local color
    case "$level" in
        INFO)    color="$BLUE" ;;
        WARNING) color="$YELLOW" ;;
        ERROR)   color="$RED" ;;
        SUCCESS) color="$GREEN" ;;
        *)       color="$NC" ;;
    esac
    
    echo -e "${color}${level}: ${message}${NC}"
}

# Test prerequisites
test_prerequisites() {
    local java_home=$1
    local android_sdk_root=$2
    local android_ndk_root=$3
    local gradlew_path=$4
    
    local prerequisites_met=0
    
    # Check Java Home
    if [[ ! -d "$java_home" ]]; then
        log "ERROR" "JAVA_HOME directory not found at '$java_home'. Please run the installation script first."
        prerequisites_met=1
    fi
    
    # Check Android SDK
    if [[ ! -d "$android_sdk_root" ]]; then
        log "ERROR" "Android SDK directory not found at '$android_sdk_root'. Please run the installation script first."
        prerequisites_met=1
    fi
    
    # Check Android NDK
    if [[ ! -d "$android_ndk_root" ]]; then
        log "ERROR" "Android NDK directory not found at '$android_ndk_root'. Please run the installation script first."
        prerequisites_met=1
    fi
    
    # Check Gradle wrapper
    if [[ ! -f "$gradlew_path" ]]; then
        log "ERROR" "Gradle wrapper ('gradlew') not found in the project directory."
        prerequisites_met=1
    fi
    
    return $prerequisites_met
}

# Set build environment
set_build_environment() {
    local java_home=$1
    local android_sdk_root=$2
    local android_ndk_root=$3
    
    log "INFO" "Setting up the build environment..."
    
    # Set environment variables for the current session
    export JAVA_HOME="$java_home"
    export ANDROID_SDK_ROOT="$android_sdk_root"
    export ANDROID_NDK_ROOT="$android_ndk_root"
    export ANDROID_HOME="$android_sdk_root"
    
    # Update PATH
    export PATH="$java_home/bin:$android_sdk_root/cmdline-tools/latest/bin:$android_sdk_root/platform-tools:$PATH"
    
    # Set persistent environment variables
    local persistent_success=0  # 0 = true, 1 = false
    
    # Determine scope based on whether we're running as root
    local scope="user"
    if [[ $EUID -eq 0 ]]; then
        scope="system"
    fi
        
    # Update PATH in the appropriate file
    if [[ "$scope" == "system" ]]; then
        # For system-wide PATH, we need to update /etc/environment or create a script in /etc/profile.d/
        local path_entry="PATH=\"$java_home/bin:$android_sdk_root/cmdline-tools/latest/bin:$android_sdk_root/platform-tools:\$PATH\""
        if ! grep -q "$path_entry" /etc/environment; then
            echo "$path_entry" >> /etc/environment
        fi
    else
        # For user-specific PATH, update .bashrc
        local path_entry="export PATH=\"$java_home/bin:$android_sdk_root/cmdline-tools/latest/bin:$android_sdk_root/platform-tools:\$PATH\""
        if ! grep -q "$path_entry" "$HOME/.bashrc"; then
            echo "$path_entry" >> "$HOME/.bashrc"
        fi
    fi
    
    # Display environment variables
    log "INFO" "Environment variables set for this session:"
    log "INFO" "  JAVA_HOME: $JAVA_HOME"
    log "INFO" "  ANDROID_SDK_ROOT: $ANDROID_SDK_ROOT"
    log "INFO" "  ANDROID_NDK_ROOT: $ANDROID_NDK_ROOT"
    log "INFO" "  ANDROID_HOME: $ANDROID_HOME"
    
    return $persistent_success
}

# Main script
main() {
    # Define the installation paths
    local java_home="$HOME/open-jdk"
    local android_sdk_root="$HOME/android-sdk"
    local android_ndk_root="$HOME/android-sdk/ndk/27.0.12077973"
    local gradlew_path="./gradlew"
    
    # Ensure gradlew is executable
    chmod +x "$gradlew_path"

    # Check prerequisites
    if ! test_prerequisites "$java_home" "$android_sdk_root" "$android_ndk_root" "$gradlew_path"; then
        log "ERROR" "Prerequisites not met. Exiting script."
        exit 1
    fi
    
    # Set up environment variables
    local env_setup_success=false
    if set_build_environment "$java_home" "$android_sdk_root" "$android_ndk_root"; then
        env_setup_success=true
    fi
    
    # Execute the build command
    local build_success=false
    if "$gradlew_path" assembleDebug; then
        build_success=true
    fi
    
    # Determine final exit code
    if [[ "$env_setup_success" == true && "$build_success" == true ]]; then
        log "SUCCESS" "Script completed successfully."
        exit 0
    else
        log "ERROR" "Script completed with errors."
        exit 1
    fi
}

# Run main function
main "$@"