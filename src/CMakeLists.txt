add_library(primeorbit
    prime_checker.cpp
    prime_factorizer.cpp
)

# Making the library's header files available
target_include_directories(primeorbit
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/../include
)

# setting C++ standard
set_target_properties(primeorbit PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# creating the main executable
add_executable(prime_app main.cpp)

# Linking the executable with the library
target_link_libraries(prime_app primeorbit
)

# setting C++ standard for the executable
set_target_properties(prime_app PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)