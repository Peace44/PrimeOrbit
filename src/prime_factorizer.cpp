#include "prime_factorizer.hpp"
#include "prime_checker.hpp"
#include <iostream>

namespace PrimeOrbit {
    // Constructor
    PrimeFactorizer::PrimeFactorizer(unsigned long long int num) : number(num) {
        factorize(number); // Start the recursive factorization with the smallest prime (2)
    }

    PrimeChecker pc;

    unsigned long long int PrimeFactorizer::getFirstPrimeFactor(unsigned long long int num) {
        if (num <= 1) return 1;
        if (num <= 3) return num;

        if (num % 2 == 0) return 2;
        if (num % 3 == 0) return 3;

        // Every prime number >= 5 fits the form 6k±1 for some k >= 1
        for (unsigned long long int i = 5; i <= num / i; i += 6) {
            if (num % i == 0) return i;
            if (num % (i + 2) == 0) return (i + 2); 
        }

        return num;
    }

    void PrimeFactorizer::factorize(unsigned long long int num) {
        unsigned long long int nextFactor = getFirstPrimeFactor(num);
        if (nextFactor < 2) return;
        
        if (!factors.empty() && factors.back().first == nextFactor) factors.back().second++; // if the divisor is already in the factors list, increment the count of the current prime nextFactor
        else factors.emplace_back(nextFactor, 1); // Else add a new prime factor with count 1

        factorize(num / nextFactor);
    }

    const std::vector<std::pair<unsigned long long int, int>>& PrimeFactorizer::getFactors() const {
        return factors;
    }
}