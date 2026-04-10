#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double temperature;
    double tempConv;
    char unit;
    char convUnit;

    cout << "Temperature Converter" << "\n" << "Please enter Temperature: ";
    cin >> temperature;

    if (cin.fail()) {
        cout << "Not a valid unit, please restart and try again";
        return 0;
    } 

    cout << "Enter unit(C for Celsius, F for Fahrenheit): ";
    cin >> unit;

    if (unit == 'C' || unit == 'c') {
        tempConv = (temperature * 9/5) + 32;
        convUnit = 'F';
    } else if (unit == 'F' || unit == 'f') {
        tempConv = (temperature - 32) * 5/9;
        convUnit = 'C';
    } else {
        cout << "Not a valid unit, please restart and try again.";
        return 0;
    }

    cout << temperature << "°" << (char)toupper(unit) << " is equal to " << tempConv << "°" << convUnit << "." << endl;

    return 0;
}