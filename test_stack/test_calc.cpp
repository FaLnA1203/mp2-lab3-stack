#include "pch.h"
#include "..\mp2-lab3-stack\calculator.h"


TEST(CalculatorTest, Can_Add_Numbers) {
    Calculator calc;
    calc.SetInfix("2+3");
    calc.ToPostfix();
    EXPECT_DOUBLE_EQ(calc.CalcPostfix(), 5.0);
}

TEST(CalculatorTest, Can_Subtract_Numbers) {
    Calculator calc;
    calc.SetInfix("10-4");
    calc.ToPostfix();
    EXPECT_DOUBLE_EQ(calc.CalcPostfix(), 6.0);
}

TEST(CalculatorTest, Can_Multiply_Numbers) {
    Calculator calc;
    calc.SetInfix("6*7");
    calc.ToPostfix();
    EXPECT_DOUBLE_EQ(calc.CalcPostfix(), 42.0);
}

TEST(CalculatorTest, Can_Divide_Numbers) {
    Calculator calc;
    calc.SetInfix("15/3");
    calc.ToPostfix();
    EXPECT_DOUBLE_EQ(calc.CalcPostfix(), 5.0);
}

TEST(CalculatorTest, Can_Calculate_Power) {
    Calculator calc;
    calc.SetInfix("2^3");
    calc.ToPostfix();
    EXPECT_DOUBLE_EQ(calc.CalcPostfix(), 8.0);
}

TEST(CalculatorTest, Can_Calculate_With_Floating_Point) {
    Calculator calc;
    calc.SetInfix("5.5 + 2.1");
    calc.ToPostfix();
    EXPECT_DOUBLE_EQ(calc.CalcPostfix(), 7.6);
}

TEST(CalculatorTest, Ignores_Spaces) {
    Calculator calc;
    calc.SetInfix("  2   +  3 * 4   ");
    calc.ToPostfix();
    EXPECT_DOUBLE_EQ(calc.CalcPostfix(), 14.0);
}

TEST(CalculatorTest, Respects_Operator_Priority) {
    Calculator calc;
    calc.SetInfix("2+3*4");
    calc.ToPostfix();
    EXPECT_DOUBLE_EQ(calc.CalcPostfix(), 14.0);
}

TEST(CalculatorTest, Respects_Brackets) {
    Calculator calc;
    calc.SetInfix("(2+3)*4");
    calc.ToPostfix();
    EXPECT_DOUBLE_EQ(calc.CalcPostfix(), 20.0);
}

TEST(CalculatorTest, Can_Calculate_Complex_Expression) {
    Calculator calc;
    calc.SetInfix("5*4+(4-1)^2/3");
    calc.ToPostfix();
    EXPECT_DOUBLE_EQ(calc.CalcPostfix(), 23.0);
}

TEST(CalculatorTest, Correctly_Forms_Postfix_String) {
    Calculator calc;
    calc.SetInfix("(2+3)*4");
    calc.ToPostfix();
    EXPECT_EQ(calc.get_postfix(), "2 3 + 4 *");
}

TEST(CalculatorTest, Throws_On_Division_By_Zero) {
    Calculator calc;
    calc.SetInfix("5/0");
    calc.ToPostfix();
    EXPECT_THROW(calc.CalcPostfix(), const char*);
}

TEST(CalculatorTest, Throws_On_Missing_Closing_Bracket) {
    Calculator calc;
    calc.SetInfix("(2+3");
    EXPECT_THROW(calc.ToPostfix(), const char*);
}

TEST(CalculatorTest, Throws_On_Missing_Opening_Bracket) {
    Calculator calc;
    calc.SetInfix("2+3)");
    EXPECT_THROW(calc.ToPostfix(), const char*);
}

TEST(CalculatorTest, Throws_On_Invalid_Expression_Missing_Operand) {
    Calculator calc;
    calc.SetInfix("2+*3");
    calc.ToPostfix();
    EXPECT_THROW(calc.CalcPostfix(), const char*);
}