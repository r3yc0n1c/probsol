@echo off
setlocal enabledelayedexpansion

:: Define the path as the current directory
set pathToSearch=.

:: Loop through all .exe files in the specified directory
for /r "%pathToSearch%" %%F in (*.exe) do (
    echo Deleting: %%F
    del "%%F"
)

echo Cleanup complete!
