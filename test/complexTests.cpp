#include <gtest/gtest.h>
#include "../complex.cpp"

TEST(ComplexNumberTests, DefaultConstructor) {
    ComplexNumber c;
    EXPECT_EQ(c.to_string(), "0");
}

TEST(ComplexNumberTests, ParameterizedConstructor) {
    ComplexNumber c(3, 4);
    EXPECT_EQ(c.to_string(), "3 + 4i");
}

TEST(ComplexNumberTests, StringConstructorImaginary) {
    ComplexNumber c("5i");
    EXPECT_EQ(c.to_string(), "5i");
}

TEST(ComplexNumberTests, StringConstructorRealAndImaginary) {
    ComplexNumber c("3 + 4i");
    EXPECT_EQ(c.to_string(), "3 + 4i");
}

TEST(ComplexNumberTests, Addition) {
    ComplexNumber c1(3, 4);
    ComplexNumber c2(1, 2);
    ComplexNumber result = c1 + c2;
    EXPECT_EQ(result.to_string(), "4 + 6i");
}

TEST(ComplexNumberTests, Subtraction) {
    ComplexNumber c1(5, 6);
    ComplexNumber c2(3, 2);
    ComplexNumber result = c1 - c2;
    EXPECT_EQ(result.to_string(), "2 + 4i");
}

TEST(ComplexNumberTests, Multiplication) {
    ComplexNumber c1(3, 2);
    ComplexNumber c2(1, 7);
    ComplexNumber result = c1 * c2;
    EXPECT_EQ(result.to_string(), "-11 + 23i");
}

TEST(ComplexNumberTests, Division) {
    ComplexNumber c1(4, 8);
    ComplexNumber c2(3, -2);
    ComplexNumber result = c1 / c2;
    EXPECT_EQ(result.to_string(), "-0.307692 + 2.46154i");
}

TEST(ComplexNumberTests, AssignmentOperatorString) {
    ComplexNumber c;
    c = "4 + 3i";
    EXPECT_EQ(c.to_string(), "4 + 3i");
}

TEST(ComplexNumberTests, AssignmentOperatorPair) {
    ComplexNumber c;
    c = make_pair(4.0, 3.0);
    EXPECT_EQ(c.to_string(), "4 + 3i");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
