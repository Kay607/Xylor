@echo off
cd /d "%~dp0"

cd ..

if not exist "build" (
    echo Creating build directory...
    mkdir build
)

cd build

echo Running CMake...
cmake ..

echo CMake configuration complete

pause
