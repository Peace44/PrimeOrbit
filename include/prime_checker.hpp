#ifndef PRIMEORBIT_PRIME_CHECKER_HPP
#define PRIMEORBIT_PRIME_CHECKER_HPP

namespace PrimeOrbit {
    class PrimeChecker {
        public:
            PrimeChecker() = default;
            bool isPrime(unsigned long long int number) const;
    };
}

#endif