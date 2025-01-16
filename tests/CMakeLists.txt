# tests/CMakeLists.txt

# Disable installation targets for Google Test
set(INSTALL_GTEST OFF CACHE BOOL "Disable Google Test install" FORCE)

# Add Google Test subdir
# This will create targets like gtest and gtest_main
add_subdirectory(googletest)

# Now create your test executable
add_executable(test_prime_checker test_prime_checker.cpp)

# Link your test executable with:
#   1. the prime checking library
#   2. Google Test libraries
target_link_libraries(test_prime_checker
    PRIVATE
        gtest_main
        # prime_checker (I'll add this once the library is created)
)

# Set C++ standard for tests
set_target_properties(test_prime_checker PROPERTIES 
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED ON
)

# Tell CTest to run the test executable
add_test(NAME PrimeCheckerTest COMMAND test_prime_checker)
