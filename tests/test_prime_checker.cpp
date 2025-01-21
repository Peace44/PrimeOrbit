#include <gtest/gtest.h>
#include "prime_checker.hpp"

namespace PrimeOrbit {
    PrimeChecker pc;

    TEST(PrimeCheckerTest, NegativeNumbers) {
        EXPECT_FALSE(pc.isPrime(-1));
        EXPECT_FALSE(pc.isPrime(-2));
        EXPECT_FALSE(pc.isPrime(-3));
        EXPECT_FALSE(pc.isPrime(-4));

        EXPECT_FALSE(pc.isPrime(-5));
        EXPECT_FALSE(pc.isPrime(-6));
        EXPECT_FALSE(pc.isPrime(-7));
        EXPECT_FALSE(pc.isPrime(-8));

        EXPECT_FALSE(pc.isPrime(-9));
        EXPECT_FALSE(pc.isPrime(-10));
        EXPECT_FALSE(pc.isPrime(-11));
        EXPECT_FALSE(pc.isPrime(-12));

        EXPECT_FALSE(pc.isPrime(-13));
        EXPECT_FALSE(pc.isPrime(-14));
        EXPECT_FALSE(pc.isPrime(-15));
        EXPECT_FALSE(pc.isPrime(-16));

        EXPECT_FALSE(pc.isPrime(-17));
        EXPECT_FALSE(pc.isPrime(-18));
        EXPECT_FALSE(pc.isPrime(-19));
        EXPECT_FALSE(pc.isPrime(-20));
    }

    TEST(PrimeCheckerTest, EdgeCases) {
        EXPECT_FALSE(pc.isPrime(0));
        EXPECT_FALSE(pc.isPrime(1));
        EXPECT_TRUE(pc.isPrime(2));
        EXPECT_TRUE(pc.isPrime(3));

        EXPECT_FALSE(pc.isPrime(4));
        EXPECT_TRUE(pc.isPrime(5));
        EXPECT_FALSE(pc.isPrime(6));
        EXPECT_TRUE(pc.isPrime(7));
    }

    TEST(PrimeCheckerTest, SmallNonPrimes) {
        EXPECT_FALSE(pc.isPrime(15));
        EXPECT_FALSE(pc.isPrime(35));
        EXPECT_FALSE(pc.isPrime(143));
        EXPECT_FALSE(pc.isPrime(323));

        EXPECT_FALSE(pc.isPrime(899));
        EXPECT_FALSE(pc.isPrime(1763));
        EXPECT_FALSE(pc.isPrime(3599));
        EXPECT_FALSE(pc.isPrime(5183));

        EXPECT_FALSE(pc.isPrime(10403));
        EXPECT_FALSE(pc.isPrime(11663));
        EXPECT_FALSE(pc.isPrime(19043));
        EXPECT_FALSE(pc.isPrime(22499));

        EXPECT_FALSE(pc.isPrime(32399));
        EXPECT_FALSE(pc.isPrime(36863));
        EXPECT_FALSE(pc.isPrime(39203));
        EXPECT_FALSE(pc.isPrime(51983));

        EXPECT_FALSE(pc.isPrime(57599));
        EXPECT_FALSE(pc.isPrime(72899));
        EXPECT_FALSE(pc.isPrime(79523));
        EXPECT_FALSE(pc.isPrime(97343));
    }

    TEST(PrimeCheckerTest, SmallPrimes) {
        EXPECT_TRUE(pc.isPrime(11));
        EXPECT_TRUE(pc.isPrime(13));
        EXPECT_TRUE(pc.isPrime(17));
        EXPECT_TRUE(pc.isPrime(31));

        EXPECT_TRUE(pc.isPrime(37));
        EXPECT_TRUE(pc.isPrime(71));
        EXPECT_TRUE(pc.isPrime(73));
        EXPECT_TRUE(pc.isPrime(79));

        EXPECT_TRUE(pc.isPrime(97));
        EXPECT_TRUE(pc.isPrime(101));
        EXPECT_TRUE(pc.isPrime(107));
        EXPECT_TRUE(pc.isPrime(113));

        EXPECT_TRUE(pc.isPrime(131));
        EXPECT_TRUE(pc.isPrime(149));
        EXPECT_TRUE(pc.isPrime(151));
        EXPECT_TRUE(pc.isPrime(157));

        EXPECT_TRUE(pc.isPrime(167));
        EXPECT_TRUE(pc.isPrime(179));
        EXPECT_TRUE(pc.isPrime(181));
        EXPECT_TRUE(pc.isPrime(191));

        EXPECT_TRUE(pc.isPrime(199));
        EXPECT_TRUE(pc.isPrime(311));
        EXPECT_TRUE(pc.isPrime(313));
        EXPECT_TRUE(pc.isPrime(337));

        EXPECT_TRUE(pc.isPrime(347));
        EXPECT_TRUE(pc.isPrime(353));
        EXPECT_TRUE(pc.isPrime(359)); 
        EXPECT_TRUE(pc.isPrime(373));

        EXPECT_TRUE(pc.isPrime(383));
        EXPECT_TRUE(pc.isPrime(389));
        EXPECT_TRUE(pc.isPrime(701));
        EXPECT_TRUE(pc.isPrime(709));

        EXPECT_TRUE(pc.isPrime(727));
        EXPECT_TRUE(pc.isPrime(733));
        EXPECT_TRUE(pc.isPrime(739));
        EXPECT_TRUE(pc.isPrime(743));

        EXPECT_TRUE(pc.isPrime(751));
        EXPECT_TRUE(pc.isPrime(757));
        EXPECT_TRUE(pc.isPrime(761));
        EXPECT_TRUE(pc.isPrime(769));
        
        EXPECT_TRUE(pc.isPrime(787));
        EXPECT_TRUE(pc.isPrime(797));
        EXPECT_TRUE(pc.isPrime(907));
        EXPECT_TRUE(pc.isPrime(919));

        EXPECT_TRUE(pc.isPrime(929));
        EXPECT_TRUE(pc.isPrime(937));
        EXPECT_TRUE(pc.isPrime(941));
        EXPECT_TRUE(pc.isPrime(953));

        EXPECT_TRUE(pc.isPrime(967));
        EXPECT_TRUE(pc.isPrime(983));
        EXPECT_TRUE(pc.isPrime(991));
        EXPECT_TRUE(pc.isPrime(1009));
    }

    TEST(PrimeCheckerTest, LargerNonPrimes) {
        EXPECT_FALSE(pc.isPrime(121103));
        EXPECT_FALSE(pc.isPrime(176399));
        EXPECT_FALSE(pc.isPrime(186623));
        EXPECT_FALSE(pc.isPrime(213443));

        EXPECT_FALSE(pc.isPrime(272483));
        EXPECT_FALSE(pc.isPrime(324899));
        EXPECT_FALSE(pc.isPrime(359999));
        EXPECT_FALSE(pc.isPrime(381923));

        EXPECT_FALSE(pc.isPrime(412163));
        EXPECT_FALSE(pc.isPrime(435599));
        EXPECT_FALSE(pc.isPrime(656099));
        EXPECT_FALSE(pc.isPrime(675683));

        EXPECT_FALSE(pc.isPrime(685583));
        EXPECT_FALSE(pc.isPrime(736163));
        EXPECT_FALSE(pc.isPrime(777923));
        EXPECT_FALSE(pc.isPrime(1040399));

        EXPECT_FALSE(pc.isPrime(1065023));
        EXPECT_FALSE(pc.isPrime(1102499));
        EXPECT_FALSE(pc.isPrime(1127843));
        EXPECT_FALSE(pc.isPrime(1192463));
    }

    TEST(PrimeCheckerTest, LargerPrimes) {
        EXPECT_TRUE(pc.isPrime(1279));
        EXPECT_TRUE(pc.isPrime(2203));
        EXPECT_TRUE(pc.isPrime(2281));
        EXPECT_TRUE(pc.isPrime(3217));

        EXPECT_TRUE(pc.isPrime(4253));
        EXPECT_TRUE(pc.isPrime(4423));
        EXPECT_TRUE(pc.isPrime(8191));
        EXPECT_TRUE(pc.isPrime(9689));

        EXPECT_TRUE(pc.isPrime(9941));
        EXPECT_TRUE(pc.isPrime(11213));
        EXPECT_TRUE(pc.isPrime(19937));
        EXPECT_TRUE(pc.isPrime(21701));

        EXPECT_TRUE(pc.isPrime(23209));
        EXPECT_TRUE(pc.isPrime(44497));
        EXPECT_TRUE(pc.isPrime(86243));
        EXPECT_TRUE(pc.isPrime(110503));

        EXPECT_TRUE(pc.isPrime(131071));
        EXPECT_TRUE(pc.isPrime(132049));
        EXPECT_TRUE(pc.isPrime(216091));
        EXPECT_TRUE(pc.isPrime(524287));

        EXPECT_TRUE(pc.isPrime(756839));
        EXPECT_TRUE(pc.isPrime(859433));
        EXPECT_TRUE(pc.isPrime(1257787));
        EXPECT_TRUE(pc.isPrime(1398269));

        EXPECT_TRUE(pc.isPrime(2976221));
        EXPECT_TRUE(pc.isPrime(3021377));
        EXPECT_TRUE(pc.isPrime(6972593));
        EXPECT_TRUE(pc.isPrime(13466917));

        EXPECT_TRUE(pc.isPrime(20996011));
        EXPECT_TRUE(pc.isPrime(24036583));
        EXPECT_TRUE(pc.isPrime(25964951));
        EXPECT_TRUE(pc.isPrime(2147483647));
    }

    TEST(PrimeCheckerTest, VeryLargeNonPrime1) {
        EXPECT_FALSE(pc.isPrime(1125897758834689ULL));  // 2147483647 * 524287
    }

    TEST(PrimeCheckerTest, VeryLargePrime1) {
        EXPECT_TRUE(pc.isPrime(2305843009213693951ULL)); // This is the 9th Mersenne prime
    }
    
    TEST(PrimeCheckerTest, VeryLargePrime2) {
        EXPECT_TRUE(pc.isPrime(18446744073709551557ULL)); // (2^64 - 59) is known to be prime (largest prime less than 2^64)
    }

    TEST(PrimeCheckerTest, VeryLargeNonPrime2) {
        EXPECT_FALSE(pc.isPrime(1000000016000000063ULL)); // 1000000007 * 1000000009
    }
}