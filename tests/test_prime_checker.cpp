#include <gtest/gtest.h>
#include "prime_checker.hpp"

namespace PrimeOrbit {
    PrimeChecker pc;

    TEST(PrimeCheckerTest, EdgeCases) {
        // Negative numbers
        EXPECT_FALSE(pc.isPrime(0));
        EXPECT_FALSE(pc.isPrime(1));
        EXPECT_FALSE(pc.isPrime(-1));
        EXPECT_FALSE(pc.isPrime(-10));

        // Known small primes
        EXPECT_TRUE(pc.isPrime(2));
        EXPECT_TRUE(pc.isPrime(3));
    }

    TEST(PrimeCheckerTest, SmallNumbers) {
        // Non-primes
        EXPECT_FALSE(pc.isPrime(4));
        EXPECT_FALSE(pc.isPrime(6));
        EXPECT_FALSE(pc.isPrime(8));
        EXPECT_FALSE(pc.isPrime(9));
        
        // Additional small primes
        EXPECT_TRUE(pc.isPrime(5));
        EXPECT_TRUE(pc.isPrime(7));
        EXPECT_TRUE(pc.isPrime(11));
        EXPECT_TRUE(pc.isPrime(13));
    }

    TEST(PrimeCheckerTest, LargerNumbers) {
        // Larger primes
        EXPECT_TRUE(pc.isPrime(29));
        EXPECT_TRUE(pc.isPrime(97));
        EXPECT_TRUE(pc.isPrime(7919));     // known prime

        // Larger non-primes
        EXPECT_FALSE(pc.isPrime(100));
        EXPECT_FALSE(pc.isPrime(99998));   // even
    }

    TEST(PrimeCheckerTest, VeryLargeNumber1) {
        EXPECT_FALSE(pc.isPrime(4294967296ULL));  // 2^32
    }

    TEST(PrimeCheckerTest, VeryLargeNumber2) {
        // 4294967291 is known to be prime (largest prime less than 2^32)
        EXPECT_TRUE(pc.isPrime(4294967291ULL)); 
    }
    
    TEST(PrimeCheckerTest, VeryLargeNumber3) {
        // (2^64 - 59) is known to be prime (largest prime less than 2^64)
        EXPECT_TRUE(pc.isPrime(18446744073709551557ULL));
    }

    TEST(PrimeCheckerTest, VeryLargeNumber4) {
        // (2^64 - 1) is not prime
        EXPECT_FALSE(pc.isPrime(18446744073709551615ULL));
    }

}
