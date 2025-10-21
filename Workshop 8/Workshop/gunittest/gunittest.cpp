#include <gtest/gtest.h>
#include "myapp.hpp"

using namespace myApp;  // to avoid repeating myApp::

//
// ---------- Free Function Tests ----------
//
TEST(MyAppFreeFunctionTests, Add_PositiveNumbers)
{
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MyAppFreeFunctionTests, Add_NegativeNumbers)
{
    EXPECT_EQ(add(-2, -3), -5);
}

TEST(MyAppFreeFunctionTests, Add_WithZero)
{
    EXPECT_EQ(add(10, 0), 10);
}

TEST(MyAppFreeFunctionTests, Subtract_PositiveNumbers)
{
    EXPECT_EQ(subtract(10, 4), 6);
}

TEST(MyAppFreeFunctionTests, Subtract_NegativeNumbers)
{
    EXPECT_EQ(subtract(-2, -3), 1);
}

TEST(MyAppFreeFunctionTests, Subtract_WithZero)
{
    EXPECT_EQ(subtract(5, 0), 5);
}

TEST(MyAppFreeFunctionTests, Multiply_PositiveNumbers)
{
    EXPECT_EQ(multiply(3, 4), 12);
}

TEST(MyAppFreeFunctionTests, Multiply_NegativeNumbers)
{
    EXPECT_EQ(multiply(-3, 4), -12);
}

TEST(MyAppFreeFunctionTests, Multiply_ByZero)
{
    EXPECT_EQ(multiply(7, 0), 0);
}

TEST(MyAppFreeFunctionTests, Divide_ValidNumbers)
{
    EXPECT_EQ(divide(8, 2), 4);
}

TEST(MyAppFreeFunctionTests, Divide_NegativeNumbers)
{
    EXPECT_EQ(divide(-10, 5), -2);
}

TEST(MyAppFreeFunctionTests, Divide_ByZero_Throws)
{
    EXPECT_THROW(divide(5, 0), std::invalid_argument);
}

TEST(MyAppFreeFunctionTests, Modulus_ValidNumbers)
{
    EXPECT_EQ(modulus(10, 3), 1);
}

TEST(MyAppFreeFunctionTests, Modulus_NegativeNumbers)
{
    EXPECT_EQ(modulus(-10, 3), -1);
}

TEST(MyAppFreeFunctionTests, Modulus_ByZero_Throws)
{
    EXPECT_THROW(modulus(10, 0), std::invalid_argument);
}

//
// ---------- Class Method Tests ----------
//

class MyAppClassMethodTests : public ::testing::Test {
protected:
    MathFunctions math;  // available in all TEST_F cases
};

TEST_F(MyAppClassMethodTests, Add_UsingClass)
{
    EXPECT_EQ(math.add(5, 5), 10);
}

TEST_F(MyAppClassMethodTests, Subtract_UsingClass)
{
    EXPECT_EQ(math.subtract(10, 8), 2);
}

TEST_F(MyAppClassMethodTests, Multiply_UsingClass)
{
    EXPECT_EQ(math.multiply(3, 5), 15);
}

TEST_F(MyAppClassMethodTests, Divide_UsingClass)
{
    EXPECT_EQ(math.divide(9, 3), 3);
}

TEST_F(MyAppClassMethodTests, Divide_ByZero_UsingClass_Throws)
{
    EXPECT_THROW(math.divide(1, 0), std::invalid_argument);
}

TEST_F(MyAppClassMethodTests, Modulus_UsingClass)
{
    EXPECT_EQ(math.modulus(10, 3), 1);
}

TEST_F(MyAppClassMethodTests, Modulus_ByZero_UsingClass_Throws)
{
    EXPECT_THROW(math.modulus(10, 0), std::invalid_argument);
}
