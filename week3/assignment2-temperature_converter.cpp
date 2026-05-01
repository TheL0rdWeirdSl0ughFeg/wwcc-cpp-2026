#include <iostream>
#include <iomanip>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

using namespace std;

void tempConvert(double temperature, char unit, double& centigrade, double& fahrenheit, double& kelvin);

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif

    double temperature;
    double centigrade, fahrenheit, kelvin;
    char unit;
    char convUnit;

    cout << "Temperature Converter" << "\n" << "Please enter Temperature: ";
    cin >> temperature;

    if (cin.fail()) {
        cout << "Not a valid number, please restart and try again";
        return 0;
    } 

    cout << "Enter unit(C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> unit;

    if (unit == 'C' || unit == 'c') {
        convUnit = 'C';
    } else if (unit == 'F' || unit == 'f') {
        convUnit = 'F';
    } else if (unit == 'K' || unit == 'k') {
        convUnit = 'K';
    } else {
        cout << "Not a valid unit, please restart and try again.";
        return 0;
    }

    if (temperature < -253.15 && convUnit == 'C') {
        cout << "Out of Bounds: Below Absolute Zero";
        return 0;
    } else if (temperature < -459.67 && convUnit == 'F') {
        cout << "Out of Bounds: Below Absolute Zero";
        return 0;
    } else if (temperature < 0 && convUnit == 'K') {
        cout << "Out of Bounds: Below Absolute Zero";
        return 0;
    } 

    tempConvert(temperature, unit, centigrade, fahrenheit, kelvin);

    cout << fixed << setprecision(2);
    cout << "\nTemperature Conversions:\nCelsius: " << centigrade << "°C" << endl;
    cout << "Fahrenheit: " << fahrenheit << "°F" << endl;
    cout << "Kelvin: " << kelvin << "K" << endl;


    return 0;
}

void tempConvert(double temperature, char unit, double& centigrade, double& fahrenheit, double& kelvin) {
    if (unit == 'C' || unit == 'c') {
        centigrade = temperature;
        fahrenheit = (centigrade * 9 / 5) + 32;
        kelvin = centigrade + 273.15;
    }
    else if (unit == 'F' || unit == 'f') {
        fahrenheit = temperature;
        centigrade = (fahrenheit - 32) * 5 / 9;
        kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
    }
    else if (unit == 'K' || unit == 'k') {
        kelvin = temperature;
        centigrade = kelvin - 273.15;
        fahrenheit = (kelvin - 273.15) * 9 / 5 + 32;
    }
}