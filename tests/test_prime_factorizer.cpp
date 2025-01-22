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

    TEST(PrimeFactorizerTest, NegativeInput) {
        // Simulate behavior for invalid input (< 2)
        testing::internal::CaptureStderr();
        PrimeFactorizer pf4(1);
        auto output = testing::internal::GetCapturedStderr();
        EXPECT_EQ(output, "WARNING: Factorization is only defined for integers >= 2!\n");
        auto factors = pf4.getFactors();
        EXPECT_TRUE(factors.empty());
    }

    TEST(PrimeFactorizerTest, FactorizationReset) {
        PrimeFactorizer pf5(90);
        auto factors = pf5.getFactors();
        ASSERT_EQ(factors.size(), 3);
        EXPECT_EQ(factors[0], std::make_pair(2ULL, 1));
        EXPECT_EQ(factors[1], std::make_pair(3ULL, 2));
        EXPECT_EQ(factors[2], std::make_pair(5ULL, 1));

        pf5.reset();
        EXPECT_TRUE(pf5.getFactors().empty());
        EXPECT_EQ(pf5.getNumber(), 0);
    }

    TEST(PrimeFactorizerTest, VeryLargeCompositeNumber) {
        PrimeFactorizer pf6(1000000016000000063ULL); // 1000000007 * 1000000009
        auto factors = pf6.getFactors();
        ASSERT_EQ(factors.size(), 2);
        EXPECT_EQ(factors[0], std::make_pair(1000000007ULL, 1));
        EXPECT_EQ(factors[1], std::make_pair(1000000009ULL, 1));
    }
}
