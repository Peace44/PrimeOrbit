#ifndef PRIMEORBIT_PRIME_FACTORIZER_HPP
#define PRIMEORBIT_PRIME_FACTORIZER_HPP

#include <vector>
#include <utility>

namespace PrimeOrbit {
    class PrimeFactorizer {
        public:
            // Constructor that accepts a number
            explicit PrimeFactorizer(unsigned long long int num);
            
            // Getters
            unsigned long long int getNumber() const;
            const std::vector<std::pair<unsigned long long int, int>>& getFactors() const;
        
        private:
            unsigned long long int number;
            std::vector<std::pair<unsigned long long int, int>> factors;

            void factorize(unsigned long long int num);
            unsigned long long int getFirstPrimeFactor(unsigned long long int num);
    };
}

#endif