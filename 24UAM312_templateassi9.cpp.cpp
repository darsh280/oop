#include <iostream>
using namespace std;

// Template function to find the maximum of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Template class for a generic calculator
template <typename T>
class Calculator {
    T num1, num2;

public:
    Calculator(T a, T b) : num1(a), num2(b) {}

    T add() { return num1 + num2; }
    T subtract() { return num1 - num2; }
    T multiply() { return num1 * num2; }
    T divide() {
        if (num2 != 0) return num1 / num2;
        else {
            cout << "Division by zero!" << endl;
            return 0;
        }
    }
};

int main() {
    // Using findMax
    cout << "Max of 5 and 10 is: " << findMax(5, 10) << endl;

    // Integer operations
    Calculator<int> intCalc(5, 10);
    cout << "Integer Operations:" << endl;
    cout << "5 + 10 = " << intCalc.add() << endl;
    cout << "5 - 10 = " << intCalc.subtract() << endl;
    cout << "5 * 10 = " << intCalc.multiply() << endl;
    cout << "5 / 10 = " << intCalc.divide() << endl;

    // Float operations
    Calculator<float> floatCalc(3.5f, 2.0f);
    cout << "Float Operations:" << endl;
    cout << "3.5 + 2.0 = " << floatCalc.add() << endl;
    cout << "3.5 - 2.0 = " << floatCalc.subtract() << endl;
    cout << "3.5 * 2.0 = " << floatCalc.multiply() << endl;
    cout << "3.5 / 2.0 = " << floatCalc.divide() << endl;

    // Double operations
    Calculator<double> doubleCalc(7.25, 2.5);
    cout << "Double Operations:" << endl;
    cout << "7.25 + 2.5 = " << doubleCalc.add() << endl;
    cout << "7.25 - 2.5 = " << doubleCalc.subtract() << endl;
    cout << "7.25 * 2.5 = " << doubleCalc.multiply() << endl;
    cout << "7.25 / 2.5 = " << doubleCalc.divide() << endl;

    return 0;
}
