#include <gtest/gtest.h>
#include "../Mod/inc/Mod_000.hpp"

// Test Implementation_1
TEST(ImplementationTests, TestImplementation1) {
    int result = Implementation_1();
    // Assert that the result is within a valid range
    ASSERT_GE(result, 0);  // Ensure result is non-negative
    ASSERT_LE(result, 255); // Ensure result is within an expected range
}

// Test Implementation_2
TEST(ImplementationTests, TestImplementation2) {
    int data = 50;
    Implementation_2(&data);
    // Assert that data is modified and within a valid range
    ASSERT_NE(data, 50);  // Ensure the data is modified
    ASSERT_GE(data, -100); // Ensure data is not too small
    ASSERT_LE(data, 500);  // Ensure data is not too large
}

// Test Implementation_3
TEST(ImplementationTests, TestImplementation3) {
    int input = 100;
    char result = Implementation_3(input);
    // Assert that the result is a valid uppercase character
    ASSERT_TRUE(result >= 'A' && result <= 'Z'); // Ensure result is within A-Z
}

// Test Implementation_2 with edge cases
TEST(ImplementationTests, TestImplementation2EdgeCases) {
    int data = 0;
    Implementation_2(&data);
    ASSERT_NE(data, 0);  // Ensure data is modified

    data = -10;
    Implementation_2(&data);
    ASSERT_NE(data, -10);  // Ensure data is modified even for negative input
}

// Test Implementation_3 with edge cases
TEST(ImplementationTests, TestImplementation3EdgeCases) {
    int input = 0;
    char result = Implementation_3(input);
    ASSERT_TRUE(result >= 'A' && result <= 'Z'); // Ensure result is within A-Z

    input = -100;
    result = Implementation_3(input);
    ASSERT_TRUE(result >= 'A' && result <= 'Z'); // Ensure result is within A-Z
}

//Change to check