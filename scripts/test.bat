@echo off
cd ..

if not exist "build" (
    echo Creating build directory...
    mkdir build
)

cmake -S . -B build
cmake --build build
cd build

echo Running CTest...
ctest

pause
