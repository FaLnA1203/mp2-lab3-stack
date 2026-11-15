#include <iostream>
#include "calculator.h"
using namespace std;

void main() {
    Calculator calc;
    calc.SetInfix("2 + 3");
    calc.ToPostfix();
    cout<<calc.CalcPostfix();
}