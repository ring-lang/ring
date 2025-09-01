#!/bin/bash
set -euo pipefail

# Script to install Android development tools on Ubuntu

# Define colors
readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
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

# Set environment variables
set_environment_variables() {
    local jdk_path=$1
    local sdk_path=$2
    
    export JAVA_HOME="$jdk_path"
    export ANDROID_SDK_ROOT="$sdk_path"
    export ANDROID_NDK_ROOT="$sdk_path/ndk/27.0.12077973"
    export PATH="$jdk_path/bin:$sdk_path/cmdline-tools/latest/bin:$sdk_path/platform-tools:$PATH"
    
    # Add to ~/.bashrc for persistence
    {
        echo "export JAVA_HOME=\"$jdk_path\""
        echo "export ANDROID_SDK_ROOT=\"$sdk_path\""
        echo "export ANDROID_NDK_ROOT=\"$sdk_path/ndk/27.0.12077973\""
        echo "export PATH=\"\$JAVA_HOME/bin:\$ANDROID_SDK_ROOT/cmdline-tools/latest/bin:\$ANDROID_SDK_ROOT/platform-tools:\$PATH\""
    } >> $HOME/.bashrc
    
    log "INFO" "Environment variables set for this session and added to $HOME/.bashrc"
}

# Accept SDK licenses
accept_sdk_licenses() {
    local sdk_path=$1
    
    log "INFO" "Accepting Android SDK licenses..."
    local output
    output=$(yes | "$sdk_path/cmdline-tools/latest/bin/sdkmanager" --licenses 2>&1)
    
    if echo "$output" | grep -q "All SDK package licenses accepted"; then
        log "SUCCESS" "SDK licenses accepted successfully."
        return 0
    else
        log "ERROR" "Failed to accept SDK licenses."
        log "ERROR" "Output: $output"
        return 1
    fi
}

# Install OpenJDK
install_openjdk() {
    local install_dir=$1
    local jdk_path="$install_dir/open-jdk"
    
    if [[ -d "$jdk_path" ]]; then
        log "SUCCESS" "OpenJDK already found at $jdk_path. Skipping installation."
        return 0
    fi
    
    log "INFO" "Installing Azul Zulu JDK 21 LTS at $jdk_path..."
    
    # Download and extract JDK
    local jdk_tar="zulu21.44.17-ca-jdk21.0.8-linux_x64.tar.gz"
    local jdk_url="https://cdn.azul.com/zulu/bin/$jdk_tar"
    
    if ! wget -q "$jdk_url"; then
        log "ERROR" "Failed to download JDK from $jdk_url."
        return 1
    fi
    
    if ! tar -xzf "$jdk_tar" -C "$install_dir"; then
        log "ERROR" "Failed to extract JDK archive."
        rm -f "$jdk_tar"
        return 1
    fi
    
    rm -f "$jdk_tar"
    
    # Rename extracted folder
    local extracted_folder="$install_dir/zulu21.44.17-ca-jdk21.0.8-linux_x64"
    if [[ -d "$extracted_folder" ]]; then
        if ! mv "$extracted_folder" "$jdk_path"; then
            log "ERROR" "Failed to rename JDK folder."
            return 1
        fi
    fi
    
    log "SUCCESS" "OpenJDK installed successfully."
    return 0
}

# Install Android NDK
install_android_ndk() {
    local install_dir=$1
    local sdk_path=$2
    local ndk_path="$sdk_path/ndk/27.0.12077973"
    
    if [[ -d "$ndk_path" ]]; then
        log "SUCCESS" "Android NDK already found at $ndk_path. Skipping installation."
        return 0
    fi
    
    log "INFO" "Installing latest Android NDK LTS at $ndk_path..."
    
    # Download and extract NDK
    local ndk_zip="android-ndk-r27-linux.zip"
    local ndk_url="https://dl.google.com/android/repository/$ndk_zip"
    
    if ! wget -q "$ndk_url"; then
        log "ERROR" "Failed to download NDK from $ndk_url."
        return 1
    fi
    
    if ! mkdir -p "$sdk_path/ndk"; then
        log "ERROR" "Failed to create NDK directory."
        rm -f "$ndk_zip"
        return 1
    fi
    
    if ! unzip -q "$ndk_zip" -d "$sdk_path/ndk"; then
        log "ERROR" "Failed to extract NDK archive."
        rm -f "$ndk_zip"
        return 1
    fi
    
    rm -f "$ndk_zip"
    
    # Rename extracted folder
    if ! mv "$sdk_path/ndk/android-ndk-r27" "$ndk_path"; then
        log "ERROR" "Failed to rename NDK folder."
        return 1
    fi
    
    log "SUCCESS" "Android NDK installed successfully."
    return 0
}

# Install Android SDK
install_android_sdk() {
    local install_dir=$1
    local sdk_path=$2
    
    log "INFO" "Installing/Updating Android SDK components at $sdk_path..."
    if ! mkdir -p "$sdk_path"; then
        log "ERROR" "Failed to create SDK directory."
        return 1
    fi
    
    local success=true
    
    # SDK: command-line tools
    local cmdline_tools_path="$sdk_path/cmdline-tools/latest"
    if [[ -d "$cmdline_tools_path" ]]; then
        log "SUCCESS" "Command-line tools already found. Skipping installation."
    else
        log "INFO" "Installing command-line tools..."
        
        # Download and extract command-line tools
        local cmd_zip="commandlinetools-linux-11076708_latest.zip"
        local cmd_url="https://dl.google.com/android/repository/$cmd_zip"
        
        if ! wget -q "$cmd_url"; then
            log "ERROR" "Failed to download command-line tools from $cmd_url."
            success=false
        else
            if ! mkdir -p "$sdk_path/cmdline-tools"; then
                log "ERROR" "Failed to create command-line tools directory."
                rm -f "$cmd_zip"
                success=false
            else
                if ! unzip -q "$cmd_zip" -d "$sdk_path/cmdline-tools"; then
                    log "ERROR" "Failed to extract command-line tools archive."
                    rm -f "$cmd_zip"
                    success=false
                else
                    rm -f "$cmd_zip"
                    
                    # Rename extracted folder
                    if ! mv "$sdk_path/cmdline-tools/cmdline-tools" "$sdk_path/cmdline-tools/latest"; then
                        log "ERROR" "Failed to rename command-line tools folder."
                        success=false
                    else
                        log "SUCCESS" "Command-line tools installed successfully."
                    fi
                fi
            fi
        fi
    fi
    
    # SDK: platform-tools
    local pt_path="$sdk_path/platform-tools"
    if [[ -d "$pt_path" ]]; then
        log "SUCCESS" "Platform-tools already found. Skipping installation."
    else
        log "INFO" "Installing platform-tools..."
        
        # Download and extract platform-tools
        local pt_zip="platform-tools-latest-linux.zip"
        local pt_url="https://dl.google.com/android/repository/$pt_zip"
        
        if ! wget -q "$pt_url"; then
            log "ERROR" "Failed to download platform-tools from $pt_url."
            success=false
        else
            if ! unzip -q "$pt_zip" -d "$sdk_path"; then
                log "ERROR" "Failed to extract platform-tools archive."
                rm -f "$pt_zip"
                success=false
            else
                rm -f "$pt_zip"
                log "SUCCESS" "Platform-tools installed successfully."
            fi
        fi
    fi
    
    # SDK: build-tools
    local bt_version="36.0.0"
    local bt_path="$sdk_path/build-tools/$bt_version"
    if [[ -d "$bt_path" ]]; then
        log "SUCCESS" "Build-Tools $bt_version already found. Skipping installation."
    else
        log "INFO" "Installing build-tools $bt_version..."
        if ! mkdir -p "$sdk_path/build-tools"; then
            log "ERROR" "Failed to create build-tools directory."
            success=false
        else
            # Download and extract build-tools
            local bt_zip="build-tools_r36_linux.zip"
            local bt_url="https://dl.google.com/android/repository/$bt_zip"
            
            if ! wget -q "$bt_url"; then
                log "ERROR" "Failed to download build-tools from $bt_url."
                success=false
            else
                if ! unzip -q "$bt_zip" -d "$sdk_path/build-tools"; then
                    log "ERROR" "Failed to extract build-tools archive."
                    rm -f "$bt_zip"
                    success=false
                else
                    rm -f "$bt_zip"
                    
                    # Rename the extracted folder from android-16 to the version number
                    local extracted_path="$sdk_path/build-tools/android-16"
                    if [[ -d "$extracted_path" ]]; then
                        if ! mv "$extracted_path" "$bt_path"; then
                            log "ERROR" "Failed to rename build-tools folder."
                            success=false
                        else
                            # Verify the correct path exists
                            if [[ ! -d "$bt_path" ]]; then
                                log "ERROR" "Expected build-tools folder not found at $bt_path after extraction"
                                success=false
                            else
                                log "SUCCESS" "Build-tools $bt_version installed successfully."
                            fi
                        fi
                    else
                        log "ERROR" "Expected extracted folder not found at $extracted_path"
                        success=false
                    fi
                fi
            fi
        fi
    fi
    
    # SDK: platform
    local platform_id="android-36"
    local platform_path="$sdk_path/platforms/$platform_id"
    if [[ -d "$platform_path" ]]; then
        log "SUCCESS" "Platform $platform_id already found. Skipping installation."
    else
        log "INFO" "Installing platform $platform_id..."
        if ! mkdir -p "$sdk_path/platforms"; then
            log "ERROR" "Failed to create platforms directory."
            success=false
        else
            # Download and extract platform
            local platform_zip="platform-36_r02.zip"
            local platform_url="https://dl.google.com/android/repository/$platform_zip"
            
            if ! wget -q "$platform_url"; then
                log "ERROR" "Failed to download platform from $platform_url."
                success=false
            else
                if ! unzip -q "$platform_zip" -d "$sdk_path/platforms"; then
                    log "ERROR" "Failed to extract platform archive."
                    rm -f "$platform_zip"
                    success=false
                else
                    rm -f "$platform_zip"
                    log "SUCCESS" "Platform $platform_id installed successfully."
                fi
            fi
        fi
    fi
    
    # CMake: Android
    local cmake_id="3.22.1"
    local cmake_path="$sdk_path/cmake/$cmake_id"
    if [[ -d "$cmake_path" ]]; then
        log "SUCCESS" "CMake $cmake_id already found. Skipping installation."
    else
        log "INFO" "Installing CMake $cmake_id..."
        if ! mkdir -p "$sdk_path/cmake"; then
            log "ERROR" "Failed to create cmake directory."
            success=false
        else
            # Download and extract CMake
            local cmake_zip="cmake-3.22.1-linux.zip"
            local cmake_url="https://dl.google.com/android/repository/$cmake_zip"
            
            if ! wget -q "$cmake_url"; then
                log "ERROR" "Failed to download CMake from $cmake_url."
                success=false
            else
                if ! unzip -q "$cmake_zip" -d "$sdk_path/cmake/$cmake_id"; then
                    log "ERROR" "Failed to extract CMake archive."
                    rm -f "$cmake_zip"
                    success=false
                else
                    rm -f "$cmake_zip"
                    log "SUCCESS" "CMake $cmake_id installed successfully."
                fi
            fi
        fi
    fi
    
    if [[ "$success" == true ]]; then
        return 0
    else
        return 1
    fi
}

# Main script
main() { 
    # Set the root location for all installations
    local install_dir=$HOME
    local sdk_path="$install_dir/android-sdk"
    
    # Change to installation directory
    pushd "$install_dir" > /dev/null || exit 1
    
    # OpenJDK Installation
    local jdk_success=false
    if install_openjdk "$install_dir"; then
        jdk_success=true
    fi
    
    # Android NDK Installation
    local ndk_success=false
    if install_android_ndk "$install_dir" "$sdk_path"; then
        ndk_success=true
    fi
    
    # Android SDK Installation
    local sdk_success=false
    if install_android_sdk "$install_dir" "$sdk_path"; then
        sdk_success=true
    fi
    
    # Accept SDK licenses
    local license_success=false
    if [[ "$jdk_success" == true && "$sdk_success" == true ]]; then
        local jdk_path="$install_dir/open-jdk"
        set_environment_variables "$jdk_path" "$sdk_path"
        
        if accept_sdk_licenses "$sdk_path"; then
            license_success=true
        fi
    else
        log "WARNING" "Skipping license acceptance due to previous installation failures."
    fi
    
    # Return to original directory
    popd > /dev/null || exit 1
    
    # Check overall success
    if [[ "$jdk_success" == true && "$ndk_success" == true && "$sdk_success" == true && "$license_success" == true ]]; then
        log "SUCCESS" "Script finished successfully."
        exit 0
    else
        log "WARNING" "Script finished with errors. Please check the log messages above."
        exit 1
    fi
}

# Run main function
main "$@"