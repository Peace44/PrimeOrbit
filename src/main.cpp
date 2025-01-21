#include <iostream>
#include <string>
#include <stdexcept>
#include "prime_checker.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <non-negative 64-bit integer> [<non-negative 64-bit integer> ...]\n";
        return 1;
    }

    PrimeOrbit::PrimeChecker primeChecker;

    for (int i = 1; i < argc; ++i) {
        try {
            if (argv[i][0] == '-') throw std::out_of_range("Negative input encountered!"); // Negative numbers aren't allowed!!!
            unsigned long long int number = std::stoull(argv[i]); // stoull() throws an exception if the input is invalid or out of range
            bool isNumberPrime = primeChecker.isPrime(number);
            std::cout << number << (isNumberPrime ? " is prime!" : " is not prime!") << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << "ERROR: Invalid input \"" << argv[i] << "\"!\n";
        } catch (const std::out_of_range& e) {
            std::cerr << "ERROR: Input \"" << argv[i] << "\" is out of range for a 64-bit unsigned integer!\n";
        } catch (...) {
            std::cerr << "ERROR: Unexpected error while processing argument \"" << argv[i] << "\"\n";
        }    
    }

    return 0;
}