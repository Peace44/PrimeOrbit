#ifndef PRIMEORBIT_PRIME_CHECKER_HPP
#define PRIMEORBIT_PRIME_CHECKER_HPP

namespace PrimeOrbit {
    
    /**
     * @class PrimeChecker
     * @brief A utility class to check if a number is prime.
     */
    class PrimeChecker {
        public:

            /**
             * @brief Checks whether a given number is prime.
             * 
             * @param number The number to be checked. Must be a non-negative 64-bit unsigned integer.
             * @return True if the number is prime, false otherwise.
             * 
             * @note Numbers less than 2 are not considered prime.
             *       Behavior is undefined for negative inputs.
             */
            static bool isPrime(unsigned long long int number);
    };
}

#endif