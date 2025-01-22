# Disable installation targets for Google Test
set(INSTALL_GTEST OFF CACHE BOOL "Disable Google Test install" FORCE)

# Add Google Test subdir
# This will create targets like gtest and gtest_main
add_subdirectory(googletest)
#########################################################################################################################



#########################################################################################################################
# Create your test executable
add_executable(test_prime_checker test_prime_checker.cpp)

# Link your test executable with:
#   1. the prime checking library
#   2. Google Test libraries
target_link_libraries(test_prime_checker
    PRIVATE
        gtest_main      # from googletest
        primeorbit   # my library target

)

# Set C++ standard for tests
set_target_properties(test_prime_checker PROPERTIES 
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED ON
)

# Tell CTest to run the test executable
add_test(NAME PrimeCheckerTest COMMAND test_prime_checker --gtest_print_time=1 --gtest_output=xml:report_prime_checker.xml)
#########################################################################################################################



#########################################################################################################################
add_executable(test_prime_factorizer test_prime_factorizer.cpp)
target_link_libraries(test_prime_factorizer
    PRIVATE
        gtest_main      # from googletest
        primeorbit      # my library target
)
set_target_properties(test_prime_factorizer PROPERTIES 
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED ON
)
add_test(NAME PrimeFactorizerTest COMMAND test_prime_factorizer --gtest_print_time=1 --gtest_output=xml:report_prime_factorizer.xml)
#########################################################################################################################