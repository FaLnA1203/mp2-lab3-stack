#include <iostream>

#include "calculator.h"
using namespace std;

void main() {

    string infix;
    int user;
    bool fl = true;
    Calculator calc;
    while (fl) {
        system("cls");
        cout << "1. calculate expression\n";
        cout << "2. exit\n";
        cout << "enter number: ";
        cin >> user;
        switch (user) {
            case 1:
                system("cls");
                cout << "enter expression: ";
                cin >> infix;
                calc.SetInfix(infix);
                try {
                    calc.ToPostfix();
                }
                catch (const char* err) {
                    cerr << "expression typed incorrectly";
                }
                cout << "expression equaks: "<<floor(calc.CalcPostfix()) << "\n";
                system("pause");
                break;
            case 2:
                fl = false;
                break;
            default:
                system("cls");
                cout << "There no such point\n";
                system("pause");
        }
    }

}