# CMake minimum version
cmake_minimum_required(VERSION 3.15)

# Project name and version
project(Xylor VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set flags for MSVC
if (MSVC)
    add_compile_options(/W4 /WX) # Enable warning level 4 and treat warnings as errors
endif()

# Automatically find all .cpp and .h files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Xylor build complete"
)
