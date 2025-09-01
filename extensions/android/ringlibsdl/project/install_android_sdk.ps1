#requires -RunAsAdministrator

function Write-LogMessage {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Message,
        
        [Parameter(Mandatory=$false)]
        [ValidateSet("INFO", "WARNING", "ERROR", "SUCCESS")]
        [string]$Level = "INFO"
    )
    
    $color = switch ($Level) {
        "INFO"    { "White" }
        "WARNING" { "Yellow" }
        "ERROR"   { "Red" }
        "SUCCESS" { "Green" }
        default   { "White" }
    }
    
    Write-Host "$Level`: $Message" -ForegroundColor $color
}

function Test-Administrator {
    $currentUser = [Security.Principal.WindowsIdentity]::GetCurrent()
    $principal = New-Object Security.Principal.WindowsPrincipal($currentUser)
    return $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
}

function Set-EnvironmentVariables {
    param(
        [Parameter(Mandatory=$true)]
        [string]$JdkPath,
        
        [Parameter(Mandatory=$true)]
        [string]$SdkPath
    )
    
    $env:JAVA_HOME = $JdkPath
    $env:ANDROID_SDK_ROOT = $SdkPath
    $env:Path = "$JdkPath\bin;$SdkPath\cmdline-tools\latest\bin;$env:Path"
}

function Accept-SdkLicenses {
    param(
        [Parameter(Mandatory=$true)]
        [string]$SdkPath
    )
    
    try {
        Write-LogMessage "Accepting Android SDK licenses..."
        $sdkManagerPath = Join-Path $SdkPath "cmdline-tools\latest\bin\sdkmanager.bat"
        $input = "y`n" * 20
        $input | & $sdkManagerPath --licenses
        Write-LogMessage "SDK licenses accepted successfully." -Level "SUCCESS"
        return $true
    }
    catch {
        Write-LogMessage "Failed to accept SDK licenses. Error: $_" -Level "ERROR"
        return $false
    }
}

function Install-OpenJDK {
    param(
        [Parameter(Mandatory=$true)]
        [string]$InstallDrive
    )
    
    $JdkPath = Join-Path $InstallDrive "open-jdk"
    if (Test-Path $JdkPath) {
        Write-LogMessage "OpenJDK already found at $JdkPath. Skipping installation." -Level "SUCCESS"
        return $true
    }
    
    try {
        Write-LogMessage "Installing Azul Zulu JDK 21 LTS at $JdkPath..."
        $jdkZip = "zulu21.44.17-ca-jdk21.0.8-win_x64.zip"
        $jdkUrl = "https://cdn.azul.com/zulu/bin/zulu21.44.17-ca-jdk21.0.8-win_x64.zip"
        
        Invoke-WebRequest -Uri $jdkUrl -OutFile $jdkZip -UseBasicParsing
        Expand-Archive -Path $jdkZip -DestinationPath . -Force
        Remove-Item -Force $jdkZip
        
        $extractedFolder = Join-Path $InstallDrive "zulu21.44.17-ca-jdk21.0.8-win_x64"
        if (Test-Path $extractedFolder) {
            Rename-Item -Path $extractedFolder -NewName "open-jdk"
        }
        
        Write-LogMessage "OpenJDK installed successfully." -Level "SUCCESS"
        return $true
    }
    catch {
        Write-LogMessage "Failed to install OpenJDK. Error: $_" -Level "ERROR"
        return $false
    }
}

function Install-AndroidNDK {
    param(
        [Parameter(Mandatory=$true)]
        [string]$InstallDrive,
        
        [Parameter(Mandatory=$true)]
        [string]$SdkPath
    )
    
    $NdkPath = Join-Path $SdkPath "ndk\27.0.12077973"
    if (Test-Path $NdkPath) {
        Write-LogMessage "Android NDK already found at $NdkPath. Skipping installation." -Level "SUCCESS"
        return $true
    }
    
    try {
        Write-LogMessage "Installing latest Android NDK LTS at $NdkPath..."
        $ndkZip = "android-ndk-r27-windows.zip"
        $ndkUrl = "https://dl.google.com/android/repository/android-ndk-r27d-windows.zip"
        
        Invoke-WebRequest -Uri $ndkUrl -OutFile $ndkZip -UseBasicParsing
        New-Item -ItemType Directory -Path (Join-Path $SdkPath "ndk") -Force | Out-Null
        Expand-Archive -Path $ndkZip -DestinationPath (Join-Path $SdkPath "ndk") -Force
        Remove-Item -Force $ndkZip
        
        Rename-Item (Join-Path $SdkPath "ndk\android-ndk-r27d") (Join-Path $SdkPath "ndk\27.0.12077973")
        
        Write-LogMessage "Android NDK installed successfully." -Level "SUCCESS"
        return $true
    }
    catch {
        Write-LogMessage "Failed to install Android NDK. Error: $_" -Level "ERROR"
        return $false
    }
}

function Install-AndroidSDK {
    param(
        [Parameter(Mandatory=$true)]
        [string]$InstallDrive,
        
        [Parameter(Mandatory=$true)]
        [string]$SdkPath
    )
    
    Write-LogMessage "Installing/Updating Android SDK components at $SdkPath..."
    New-Item -ItemType Directory -Path $SdkPath -Force | Out-Null
    
    $success = $true
    
    # SDK: command-line tools
    $CmdlineToolsPath = Join-Path $SdkPath "cmdline-tools\latest"
    if (Test-Path $CmdlineToolsPath) {
        Write-LogMessage "Command-line tools already found. Skipping installation." -Level "SUCCESS"
    }
    else {
        try {
            Write-LogMessage "Installing command-line tools..."
            $cmdZip = "commandlinetools-win-11076708_latest.zip"
            $cmdUrl = "https://dl.google.com/android/repository/$cmdZip"
            
            Invoke-WebRequest -Uri $cmdUrl -OutFile $cmdZip -UseBasicParsing
            New-Item -ItemType Directory -Path (Join-Path $SdkPath "cmdline-tools") -Force | Out-Null
            Expand-Archive -Path $cmdZip -DestinationPath (Join-Path $SdkPath "cmdline-tools") -Force
            Remove-Item -Force $cmdZip
            
            Rename-Item (Join-Path $SdkPath "cmdline-tools\cmdline-tools") (Join-Path $SdkPath "cmdline-tools\latest")
            
            Write-LogMessage "Command-line tools installed successfully." -Level "SUCCESS"
        }
        catch {
            Write-LogMessage "Failed to install command-line tools. Error: $_" -Level "ERROR"
            $success = $false
        }
    }
    
    # SDK: platform-tools
    $PtPath = Join-Path $SdkPath "platform-tools"
    if (Test-Path $PtPath) {
        Write-LogMessage "Platform-tools already found. Skipping installation." -Level "SUCCESS"
    }
    else {
        try {
            Write-LogMessage "Installing platform-tools..."
            $ptZip = "platform-tools-latest-windows.zip"
            $ptUrl = "https://dl.google.com/android/repository/$ptZip"
            
            Invoke-WebRequest -Uri $ptUrl -OutFile $ptZip -UseBasicParsing
            Expand-Archive -Path $ptZip -DestinationPath $SdkPath -Force
            Remove-Item -Force $ptZip
            
            Write-LogMessage "Platform-tools installed successfully." -Level "SUCCESS"
        }
        catch {
            Write-LogMessage "Failed to install platform-tools. Error: $_" -Level "ERROR"
            $success = $false
        }
    }
    
    # SDK: build-tools
    $btVersion = "36.0.0"
    $btPath = Join-Path $SdkPath "build-tools\$btVersion"
    if (Test-Path $btPath) {
        Write-LogMessage "Build-Tools $btVersion already found. Skipping installation." -Level "SUCCESS"
    }
    else {
        try {
            Write-LogMessage "Installing build-tools $btVersion..."
            New-Item -ItemType Directory -Path (Join-Path $SdkPath "build-tools") -Force | Out-Null
            $btZip = "build-tools_r36_windows.zip"
            $btUrl = "https://dl.google.com/android/repository/$btZip"
            
            Invoke-WebRequest -Uri $btUrl -OutFile $btZip -UseBasicParsing
            Expand-Archive -Path $btZip -DestinationPath (Join-Path $SdkPath "build-tools") -Force
            Remove-Item -Force $btZip
            
            # Rename the extracted folder from android-15 to the version number
            $extractedPath = Join-Path $SdkPath "build-tools\android-16"
            if (Test-Path $extractedPath) {
                Rename-Item -Path $extractedPath -NewName $btVersion -Force
            }
            
            # Verify the correct path exists
            if (-not (Test-Path $btPath)) {
                throw "Expected build-tools folder not found at $btPath after extraction"
            }
            
            Write-LogMessage "Build-tools $btVersion installed successfully." -Level "SUCCESS"
        }
        catch {
            Write-LogMessage "Failed to install build-tools $btVersion. Error: $_" -Level "ERROR"
            $success = $false
        }
    }
    
    # SDK: platform
    $platformId = "android-36"
    $platformPath = Join-Path $SdkPath "platforms\$platformId"
    if (Test-Path $platformPath) {
        Write-LogMessage "Platform $platformId already found. Skipping installation." -Level "SUCCESS"
    }
    else {
        try {
            Write-LogMessage "Installing platform $platformId..."
            New-Item -ItemType Directory -Path (Join-Path $SdkPath "platforms") -Force | Out-Null
            $platformZip = "platform-36_r02.zip"
            $platformUrl = "https://dl.google.com/android/repository/$platformZip"
            
            Invoke-WebRequest -Uri $platformUrl -OutFile $platformZip -UseBasicParsing
            Expand-Archive -Path $platformZip -DestinationPath (Join-Path $SdkPath "platforms") -Force
            Remove-Item -Force $platformZip
            
            Write-LogMessage "Platform $platformId installed successfully." -Level "SUCCESS"
        }
        catch {
            Write-LogMessage "Failed to install platform $platformId. Error: $_" -Level "ERROR"
            $success = $false
        }
    }
    
    # CMake: Android
    $cmakeId = "3.22.1"
    $platformPath = Join-Path $SdkPath "cmake\$cmakeId"
    if (Test-Path $platformPath) {
        Write-LogMessage "CMake $cmakeId already found. Skipping installation." -Level "SUCCESS"
    }
    else {
        try {
            Write-LogMessage "Installing CMake $cmakeId..."
            New-Item -ItemType Directory -Path (Join-Path $SdkPath "cmake") -Force | Out-Null
            $platformZip = "cmake-3.22.1-windows.zip"
            $platformUrl = "https://dl.google.com/android/repository/$platformZip"
            
            Invoke-WebRequest -Uri $platformUrl -OutFile $platformZip -UseBasicParsing
            Expand-Archive -Path $platformZip -DestinationPath (Join-Path $SdkPath "cmake\$cmakeId") -Force
            Remove-Item -Force $platformZip
            
            Write-LogMessage "CMake $cmakeId installed successfully." -Level "SUCCESS"
        }
        catch {
            Write-LogMessage "Failed to install CMake $cmakeId. Error: $_" -Level "ERROR"
            $success = $false
        }
    }
    return $success
}

# Main script
try {
    # Check if running as administrator
    if (-not (Test-Administrator)) {
        Write-LogMessage "Please run as administrator." -Level "ERROR"
        exit 1
    }
    
    # Set the root location for all installations
    $InstallDrive = "C:\"
    $SdkPath = Join-Path $InstallDrive "android-sdk"
    
    pushd $InstallDrive
    
    # OpenJDK Installation
    $jdkSuccess = Install-OpenJDK -InstallDrive $InstallDrive
    
    # Android NDK Installation
    $ndkSuccess = Install-AndroidNDK -InstallDrive $InstallDrive -SdkPath $SdkPath
    
    # Android SDK Installation
    $sdkSuccess = Install-AndroidSDK -InstallDrive $InstallDrive -SdkPath $SdkPath
    
    # Accept SDK licenses
    if ($jdkSuccess -and $sdkSuccess) {
        $JdkPath = Join-Path $InstallDrive "open-jdk"
        Set-EnvironmentVariables -JdkPath $JdkPath -SdkPath $SdkPath
        $licenseSuccess = Accept-SdkLicenses -SdkPath $SdkPath
    }
    else {
        Write-LogMessage "Skipping license acceptance due to previous installation failures." -Level "WARNING"
        $licenseSuccess = $false
    }
    
    # Check overall success
    if ($jdkSuccess -and $ndkSuccess -and $sdkSuccess -and $licenseSuccess) {
        Write-LogMessage "Script finished successfully." -Level "SUCCESS"
    }
    else {
        Write-LogMessage "Script finished with errors. Please check the log messages above." -Level "WARNING"
        exit 1
    }
}
finally {
    popd
}