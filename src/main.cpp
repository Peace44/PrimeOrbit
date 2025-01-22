#include <iostream>
#include <string>
#include <stdexcept>
#include "prime_checker.hpp"
#include "prime_factorizer.hpp"

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " <non-negative 64-bit integer> [<non-negative 64-bit integer> ...]\n";
    std::cout << "Options:\n";
    std::cout << "  --help      Show this help message and exit.\n";
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    if (std::string(argv[1]) == "--help") {
        printUsage(argv[0]);
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        try {
            if (argv[i][0] == '-') throw std::out_of_range("Negative input encountered!"); // Negative numbers aren't allowed!!!
            
            unsigned long long int number = std::stoull(argv[i]); // stoull() throws an exception if the input is invalid or out of range
            bool isNumberPrime = PrimeOrbit::PrimeChecker::isPrime(number);
            std::cout << number << (isNumberPrime ? " is prime!" : " is not prime!") << " <==> ";

            PrimeOrbit::PrimeFactorizer factorizer(number);
            const auto& factors = factorizer.getFactors();

            std::cout << number;
            if (factors.empty()) std::cout << " doesn't have prime factors!\n";
            else {
                std::cout << " = ";
                for (const auto& factor: factors) std::cout << "(" << factor.first << " ^ " << factor.second << ") ";
                std::cout << std::endl;
            }
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