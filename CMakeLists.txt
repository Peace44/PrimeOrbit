cmake_minimum_required(VERSION 3.10)

# Name of the project
project(PrimeOrbit VERSION 1.0 LANGUAGES CXX)

# Enable testing globally (needed for CTest)
enable_testing()

# Include subdirectories
add_subdirectory(src)   # for the main code
add_subdirectory(tests) # for the test code