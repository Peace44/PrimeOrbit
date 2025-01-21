add_library(prime_checker
    prime_checker.cpp
)

# Making the library's header files available
target_include_directories(prime_checker
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/../include
)

# setting C++ standard
set_target_properties(prime_checker PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# creating the main executable
add_executable(prime_app main.cpp)

# Linking the executable with the library
target_link_libraries(prime_app
    PRIVATE
        prime_checker
)

# setting C++ standard for the executable
set_target_properties(prime_app PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)