#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    string input1, input2;

    cout << "Enter the first number: ";
    cin >> input1;
    cout << "Enter the second number: ";
    cin >> input2;

    num1 = stod(input1);
    num2 = stod(input2);

    double sum = num1 + num2;
    double difference = num1 - num2;
    double product = num1 * num2;
    double quotient;

    cout << "Results: " << "\n" "Sum: " << sum << "\n" << "Difference: " << difference << "\n" << "Product: " << product << "\n";

    if (num2 == 0) {
        cout << "Quotient: Undefined - Cannot divide by zero.";
    } else {
    quotient = num1 / num2;
    cout << "Quotient: " << quotient;
    };


    return 0;
}