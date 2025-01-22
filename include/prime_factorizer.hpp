#ifndef PRIMEORBIT_PRIME_FACTORIZER_HPP
#define PRIMEORBIT_PRIME_FACTORIZER_HPP

#include <vector>
#include <utility>

namespace PrimeOrbit {

    /**
     * @class PrimeFactorizer
     * @brief A class to compute the prime factorization of a given number.
     */
    class PrimeFactorizer {
        
        public:

            /**
             * @brief Default constructor.
             * Initializes the object with no number.
             */
            PrimeFactorizer();

            /**
             * @brief Parameterized constructor.
             * @param num The number to be factorized.
             */
            explicit PrimeFactorizer(unsigned long long int num);
            
            /**
             * @brief Gets the number being factorized.
             * @return The number.
             */
            unsigned long long int getNumber() const;

            /**
             * @brief Gets the prime factors of the number.
             * @return A vector of pairs, where each pair contains a prime factor and its multiplicity.
             */
            const std::vector<std::pair<unsigned long long int, int>>& getFactors() const;

            /**
             * @brief Static method to get the first prime factor of a number.
             * @param num The number to analyze.
             * @return The first prime factor, or the number itself if it's prime.
             */
            static unsigned long long int getFirstPrimeFactor(unsigned long long int num);

            /**
             * @brief Resets the current factorization.
             * Clears the factors and resets the number.
             */
            void reset();
        
        private:
            unsigned long long int number; ///< The number to be factorized.
            std::vector<std::pair<unsigned long long int, int>> factors; ///< The prime factors of the number.

            /**
             * @brief Computes the prime factorization of a given number.
             * @param num The number to factorize.
             */
            void factorize(unsigned long long int num);
    };
}

#endif