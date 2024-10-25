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

# Find all source and header files in src/
file(GLOB_RECURSE XYLOR_SOURCES "src/*.cpp" "src/*.h")

# Define the main executable (Xylor)
add_executable(${PROJECT_NAME} ${XYLOR_SOURCES})

# Set output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Custom build message for Xylor
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Xylor build complete"
)

# Enable testing
enable_testing()

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Find all test source files in tests/
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

# Define the test executable
add_executable(testing ${TEST_SOURCES} ${XYLOR_SOURCES}) # Link Xylor sources to testing
target_compile_definitions(testing PRIVATE XY_TESTING)

target_include_directories(testing PRIVATE "${PROJECT_SOURCE_DIR}/src")

# Link GoogleTest to the testing executable
target_link_libraries(testing PRIVATE GTest::gtest_main)

# Register tests with CTest
include(GoogleTest)
gtest_discover_tests(testing)
