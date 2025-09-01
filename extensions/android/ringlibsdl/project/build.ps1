#requires -Version 5.1

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

function Set-PersistentEnvironmentVariable {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Name,
        
        [Parameter(Mandatory=$true)]
        [string]$Value,
        
        [Parameter(Mandatory=$false)]
        [ValidateSet("User", "Machine")]
        [string]$Scope = "User"
    )
    
    try {
        [Environment]::SetEnvironmentVariable($Name, $Value, $Scope)
        Write-LogMessage "Set persistent environment variable '$Name' to '$Value' for $Scope scope." -Level "SUCCESS"
        return $true
    }
    catch {
        Write-LogMessage "Failed to set persistent environment variable '$Name'. Error: $_" -Level "ERROR"
        return $false
    }
}

function Test-Prerequisites {
    param(
        [Parameter(Mandatory=$true)]
        [string]$JavaHome,
        
        [Parameter(Mandatory=$true)]
        [string]$AndroidSdkRoot,
        
        [Parameter(Mandatory=$true)]
        [string]$AndroidNdkRoot,
        
        [Parameter(Mandatory=$true)]
        [string]$GradlewPath
    )
    
    $prerequisitesMet = $true
    
    # Check Java Home
    if (-not (Test-Path $JavaHome -PathType Container)) {
        Write-LogMessage "JAVA_HOME directory not found at '$JavaHome'. Please run the installation script first." -Level "ERROR"
        $prerequisitesMet = $false
    }
    
    # Check Android SDK
    if (-not (Test-Path $AndroidSdkRoot -PathType Container)) {
        Write-LogMessage "Android SDK directory not found at '$AndroidSdkRoot'. Please run the installation script first." -Level "ERROR"
        $prerequisitesMet = $false
    }
    
    # Check Android NDK
    if (-not (Test-Path $AndroidNdkRoot -PathType Container)) {
        Write-LogMessage "Android NDK directory not found at '$AndroidNdkRoot'. Please run the installation script first." -Level "ERROR"
        $prerequisitesMet = $false
    }
    
    # Check Gradle wrapper
    if (-not (Test-Path $GradlewPath -PathType Leaf)) {
        Write-LogMessage "Gradle wrapper ('gradlew.bat') not found in the project directory." -Level "ERROR"
        $prerequisitesMet = $false
    }
    
    return $prerequisitesMet
}

function Set-BuildEnvironment {
    param(
        [Parameter(Mandatory=$true)]
        [string]$JavaHome,
        
        [Parameter(Mandatory=$true)]
        [string]$AndroidSdkRoot,
        
        [Parameter(Mandatory=$true)]
        [string]$AndroidNdkRoot
    )
    
    Write-LogMessage "Setting up the build environment..."
    
    # Set environment variables for the current session
    $env:JAVA_HOME = $JavaHome
    $env:ANDROID_SDK_ROOT = $AndroidSdkRoot
    $env:ANDROID_NDK_ROOT = $AndroidNdkRoot
    $env:ANDROID_HOME = $AndroidSdkRoot
    
    # Set persistent environment variables for the current user
    $persistentSuccess = $true
    $persistentSuccess = $persistentSuccess -and (Set-PersistentEnvironmentVariable -Name "JAVA_HOME" -Value $JavaHome)
    $persistentSuccess = $persistentSuccess -and (Set-PersistentEnvironmentVariable -Name "ANDROID_SDK_ROOT" -Value $AndroidSdkRoot)
    $persistentSuccess = $persistentSuccess -and (Set-PersistentEnvironmentVariable -Name "ANDROID_NDK_ROOT" -Value $AndroidNdkRoot)
    $persistentSuccess = $persistentSuccess -and (Set-PersistentEnvironmentVariable -Name "ANDROID_HOME" -Value $AndroidSdkRoot)
    
    # Display environment variables
    Write-LogMessage "Environment variables set for this session:"
    Write-LogMessage "  JAVA_HOME: $env:JAVA_HOME"
    Write-LogMessage "  ANDROID_SDK_ROOT: $env:ANDROID_SDK_ROOT"
    Write-LogMessage "  ANDROID_NDK_ROOT: $env:ANDROID_NDK_ROOT"
    Write-LogMessage "  ANDROID_HOME: $env:ANDROID_HOME"
    
    return $persistentSuccess
}

function Invoke-GradleBuild {
    param(
        [Parameter(Mandatory=$true)]
        [string]$GradlewPath,
        
        [Parameter(Mandatory=$false)]
        [string]$Task = "assembleDebug"
    )
    
    Write-LogMessage "Starting the Gradle build process ($Task)..."
    Write-LogMessage "Build output will be displayed below:" -Level "INFO"
    Write-Host "--------------------------------------------------" -ForegroundColor Cyan
    
    try {
        # Execute the build command and capture output
        $process = Start-Process -FilePath $GradlewPath -ArgumentList $Task -NoNewWindow -Wait -PassThru -RedirectStandardOutput "$env:TEMP\gradle_stdout.txt" -RedirectStandardError "$env:TEMP\gradle_stderr.txt"
        
        # Display standard output
        if (Test-Path "$env:TEMP\gradle_stdout.txt") {
            Get-Content "$env:TEMP\gradle_stdout.txt" | ForEach-Object {
                Write-Host $_
            }
        }
        
        # Display standard error
        if (Test-Path "$env:TEMP\gradle_stderr.txt") {
            Get-Content "$env:TEMP\gradle_stderr.txt" | ForEach-Object {
                Write-Host $_ -ForegroundColor Red
            }
        }
        
        Write-Host "--------------------------------------------------" -ForegroundColor Cyan
        $exitCode = $process.ExitCode
        
        if ($exitCode -eq 0) {
            Write-LogMessage "Build completed successfully." -Level "SUCCESS"
            return $true
        }
        else {
            Write-LogMessage "Build failed with exit code $exitCode." -Level "ERROR"
            return $false
        }
    }
    catch {
        Write-LogMessage "An exception occurred during the build process. Error: $_" -Level "ERROR"
        return $false
    }
    finally {
        # Clean up temporary files
        Remove-Item "$env:TEMP\gradle_stdout.txt" -ErrorAction SilentlyContinue
        Remove-Item "$env:TEMP\gradle_stderr.txt" -ErrorAction SilentlyContinue
    }
}

# Main script
try {
    # Check if running as administrator
    if (-not (Test-Administrator)) {
        Write-LogMessage "Not running as administrator. This may cause issues if the script needs to modify system files." -Level "WARNING"
    }
    
    # Define the installation paths
    $JavaHome = "C:\open-jdk"
    $AndroidSdkRoot = "C:\android-sdk"
    $AndroidNdkRoot = "C:\android-sdk\ndk\27.0.12077973"
    $GradlewPath = ".\gradlew.bat"
    
    # Check prerequisites
    if (-not (Test-Prerequisites -JavaHome $JavaHome -AndroidSdkRoot $AndroidSdkRoot -AndroidNdkRoot $AndroidNdkRoot -GradlewPath $GradlewPath)) {
        Write-LogMessage "Prerequisites not met. Exiting script." -Level "ERROR"
        exit 1
    }
    
    # Set up environment variables
    $envSetupSuccess = Set-BuildEnvironment -JavaHome $JavaHome -AndroidSdkRoot $AndroidSdkRoot -AndroidNdkRoot $AndroidNdkRoot
    
    # Execute the build command
    $buildSuccess = Invoke-GradleBuild -GradlewPath $GradlewPath -Task "assembleDebug"
    
    # Determine final exit code
    if ($envSetupSuccess -and $buildSuccess) {
        Write-LogMessage "Script completed successfully." -Level "SUCCESS"
        exit 0
    }
    else {
        Write-LogMessage "Script completed with errors." -Level "ERROR"
        exit 1
    }
}
catch {
    Write-LogMessage "An unexpected error occurred. Error: $_" -Level "ERROR"
    exit 1
}