# Script to download SDL2 and related libraries for Windows (PowerShell)
# Checks if directories exist before cloning to avoid overwriting

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

function Test-GitInstalled {
    try {
        $null = Get-Command git -ErrorAction Stop
        return $true
    }
    catch {
        Write-LogMessage "Git not found. Please install git first." -Level "ERROR"
        return $false
    }
}

function Get-LibraryVersions {
    return @{
        "SDL" = "2.32.8"
        "SDL_image" = "2.8.8"
        "SDL_mixer" = "2.8.1"
        "SDL_net" = "2.2.0"
        "SDL_ttf" = "2.24.0"
    }
}

function Invoke-GitClone {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Repository,
        
        [Parameter(Mandatory=$true)]
        [string]$Version,
        
        [Parameter(Mandatory=$true)]
        [string]$TargetDir
    )
    
    $gitArgs = @(
        "clone",
        "--filter=blob:none",
        "https://github.com/libsdl-org/$Repository.git",
        $TargetDir,
        "--branch=release-$Version",
        "--recursive",
        "--depth", "1"
    )
    
    try {
        $null = & git @gitArgs 2>$null
        return $LASTEXITCODE -eq 0
    }
    catch {
        return $false
    }
}

function Install-Library {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Repository,
        
        [Parameter(Mandatory=$true)]
        [string]$Version,
        
        [Parameter(Mandatory=$true)]
        [string]$BaseDir,
        
        [Parameter(Mandatory=$true)]
        [int]$Current,
        
        [Parameter(Mandatory=$true)]
        [int]$Total
    )
    
    $targetDir = Join-Path $BaseDir $Repository
    $percentComplete = [math]::Round(($Current / $Total) * 100)
    
    Write-Progress -Activity "Downloading SDL libraries" -Status "Cloning $Repository $Version" -PercentComplete $percentComplete
    
    if (Test-Path $targetDir) {
        Write-LogMessage "$Repository already exists at $targetDir, skipping clone." -Level "WARNING"
        return $true
    }
    
    Write-LogMessage "Cloning $Repository $Version..." -Level "INFO"
    
    if (Invoke-GitClone -Repository $Repository -Version $Version -TargetDir $targetDir) {
        Write-LogMessage "$Repository cloned successfully." -Level "SUCCESS"
        return $true
    }
    else {
        Write-LogMessage "Failed to clone $Repository" -Level "ERROR"
        return $false
    }
}

# Main script
try {
    # Check if git is installed
    if (-not (Test-GitInstalled)) {
        exit 1
    }
    
    # Define versions and base directory
    $versions = Get-LibraryVersions
    $baseDir = "app/src/main/cpp"
    $total = $versions.Count
    $current = 0
    $allSuccess = $true
    
    Write-LogMessage "Starting download of SDL2 and related libraries..." -Level "SUCCESS"
    Write-LogMessage "Base directory: $baseDir" -Level "INFO"
    
    # Clone each library
    foreach ($repo in $versions.Keys) {
        $current++
        $success = Install-Library -Repository $repo -Version $versions[$repo] -BaseDir $baseDir -Current $current -Total $total
        $allSuccess = $allSuccess -and $success
    }
    
    Write-Progress -Activity "Downloading SDL libraries" -Completed
    
    if ($allSuccess) {
        Write-LogMessage "All downloads completed successfully." -Level "SUCCESS"
    }
    else {
        Write-LogMessage "Some downloads failed. Please check the messages above." -Level "ERROR"
        exit 1
    }
}
catch {
    Write-LogMessage "An unexpected error occurred: $_" -Level "ERROR"
    exit 1
}