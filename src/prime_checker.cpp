#include "prime_checker.hpp"
#include "prime_factorizer.hpp"

namespace PrimeOrbit {

    bool PrimeChecker::isPrime(unsigned long long int number) {
        if (number < 2) return false;  // Numbers less than 2 aren't prime!
        
        return PrimeFactorizer::getFirstPrimeFactor(number) == number; // If the 1st prime factor is the number itself, then the number is prime!
    }
}