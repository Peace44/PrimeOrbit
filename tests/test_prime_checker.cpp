#include <gtest/gtest.h>

TEST(SanityCheck, BasicAssertion) {
    EXPECT_EQ(2 + 2, 4);
}

// Actual tests for prime checker will come later