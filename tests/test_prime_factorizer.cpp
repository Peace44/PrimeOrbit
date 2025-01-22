#include <gtest/gtest.h>
#include "prime_factorizer.hpp"

namespace PrimeOrbit {
    TEST(PrimeFactorizerTest, SimpleFactorization) {
        PrimeFactorizer pf1(60);
        auto factors = pf1.getFactors();
        ASSERT_EQ(factors.size(), 3);
        EXPECT_EQ(factors[0], std::make_pair(2ULL, 2));
        EXPECT_EQ(factors[1], std::make_pair(3ULL, 1));
        EXPECT_EQ(factors[2], std::make_pair(5ULL, 1));
    }

    TEST(PrimeFactorizerTest, PrimeNumber) {
        PrimeFactorizer pf2(997);
        auto factors = pf2.getFactors();
        ASSERT_EQ(factors.size(), 1);
        EXPECT_EQ(factors[0], std::make_pair(997ULL, 1));
    }

    TEST(PrimeFactorizerTest, LargeNumber) {
        PrimeFactorizer pf3(18446744073709551557ULL);
        auto factors = pf3.getFactors();
        ASSERT_EQ(factors.size(), 1);
        EXPECT_EQ(factors[0], std::make_pair(18446744073709551557ULL, 1));
    }
}
