# PowerShell script to install GCC (MinGW-w64) and add to PATH
# Run this script as Administrator

# Check if running as Administrator
$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)

if (-not $isAdmin) {
    Write-Host "This script requires Administrator privileges. Please run PowerShell as Administrator." -ForegroundColor Red
    exit 1
}

Write-Host "Installing GCC via MinGW-w64..." -ForegroundColor Green

# Define installation directory
$installDir = "C:\mingw64"
$binPath = "$installDir\bin"

# Download URL for MinGW-w64 (x86_64-posix-seh version)
$downloadUrl = "https://github.com/niXman/mingw-builds-binaries/releases/download/14.2.0-rt_v12-rev0/x86_64-14.2.0-release-posix-seh-msvcrt-rt_v12-rev0.7z"
$downloadPath = "$env:TEMP\mingw64.7z"

# Check if 7-Zip is available
$sevenZipPath = "C:\Program Files\7-Zip\7z.exe"
if (-not (Test-Path $sevenZipPath)) {
    Write-Host "7-Zip not found. Installing 7-Zip first..." -ForegroundColor Yellow
    $sevenZipInstaller = "$env:TEMP\7z-installer.exe"
    Invoke-WebRequest -Uri "https://www.7-zip.org/a/7z2408-x64.exe" -OutFile $sevenZipInstaller
    Start-Process -FilePath $sevenZipInstaller -Args "/S" -Wait
    Start-Sleep -Seconds 3
}

# Download MinGW-w64
Write-Host "Downloading MinGW-w64..." -ForegroundColor Cyan
Invoke-WebRequest -Uri $downloadUrl -OutFile $downloadPath

# Extract archive
Write-Host "Extracting MinGW-w64 to $installDir..." -ForegroundColor Cyan
if (Test-Path $installDir) {
    Remove-Item -Path $installDir -Recurse -Force
}
& $sevenZipPath x $downloadPath -o"C:\" -y

# Rename extracted folder to mingw64 if needed
$extractedFolder = Get-ChildItem "C:\" -Directory | Where-Object { $_.Name -like "mingw*" } | Select-Object -First 1
if ($extractedFolder -and $extractedFolder.FullName -ne $installDir) {
    Rename-Item -Path $extractedFolder.FullName -NewName "mingw64"
}

# Add to System PATH
Write-Host "Adding MinGW-w64 to System PATH..." -ForegroundColor Cyan
$currentPath = [Environment]::GetEnvironmentVariable("Path", "Machine")

if ($currentPath -notlike "*$binPath*") {
    [Environment]::SetEnvironmentVariable("Path", "$currentPath;$binPath", "Machine")
    Write-Host "MinGW-w64 bin directory added to System PATH." -ForegroundColor Green
} else {
    Write-Host "MinGW-w64 bin directory already in System PATH." -ForegroundColor Yellow
}

# Update current session PATH
$env:Path = [Environment]::GetEnvironmentVariable("Path", "Machine")

# Clean up
Remove-Item -Path $downloadPath -Force

# Verify installation
Write-Host "`nVerifying GCC installation..." -ForegroundColor Cyan
$gccVersion = & gcc --version 2>&1
if ($LASTEXITCODE -eq 0) {
    Write-Host "GCC installed successfully!" -ForegroundColor Green
    Write-Host $gccVersion
} else {
    Write-Host "GCC installation verification failed. You may need to restart your terminal." -ForegroundColor Yellow
}

Write-Host "`nInstallation complete! You may need to restart your terminal or IDE for PATH changes to take effect." -ForegroundColor Green