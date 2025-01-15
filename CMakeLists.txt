cmake_minimum_required(VERSION 3.10)
project(PrimeOrbit VERSION 1.0 LANGUAGES CXX)

# Enable testing globally
enable_testing()

# Include subdirectories
add_subdirectory(src)   # for the main code
add_subdirectory(tests) # for the test code