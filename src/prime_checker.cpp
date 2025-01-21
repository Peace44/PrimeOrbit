#include <cmath>
#include "prime_checker.hpp"

namespace PrimeOrbit {
    bool PrimeChecker::isPrime(unsigned long long int number) const {
        if (number < 2) return false;
        if (number == 2 || number == 3) return true;
        if (number % 2 == 0 || number % 3 == 0) return false;

        // Every prime number >= 5 fits the form 6k±1 for some k >= 1
        for (unsigned long long int i = 5; i <= number / i; i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) return false; 
        }

        return true;
    }
}