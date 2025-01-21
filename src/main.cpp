#include <iostream>
#include <string>
#include <stdexcept>
#include "prime_checker.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " 
                  << argv[0] 
                  << " <non-negative 64-bit integer> [<non-negative 64-bit integer> ...]"
                  << std::endl;
        return 1;
    }

    PrimeOrbit::PrimeChecker primeChecker;

    for (int i = 1; i < argc; ++i) {
        try {
            if (argv[i][0] == '-') throw std::out_of_range("Negative input encountered!");
            unsigned long long int number = std::stoull(argv[i]); // stoull() throws an exception if the input is invalid or out of range
            bool isNumberPrime = primeChecker.isPrime(number);
            std::cout << number 
                      << (isNumberPrime ? " is prime!" : " is not prime!") 
                      << std::endl;
        } catch (...) {
            std::cerr << "Error: Invalid or Out-Of-Range input for argument \"" 
                      << argv[i] 
                      << "\""
                      << std::endl;
        }
    }

    return 0;
}