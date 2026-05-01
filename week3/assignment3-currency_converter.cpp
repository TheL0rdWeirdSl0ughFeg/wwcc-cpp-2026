#include <iostream>
#include <iomanip>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

using namespace std;

double dollarToEuro(double amount);
double dollarToPound(double amount);
double dollarToYen(double amount);
int getConversionCount();

static int conversionCount = 0;

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif
    
    int select;
    double value, conValue;
    char cont;

    do {
        cout << "CURRENCY CONVERTER" << endl;
        cout << "------------------" << endl;
        cout << "1. Convert USD to Euro (EUR)" << endl;
        cout << "2. Convert USD to British Pound (GBP)" << endl;
        cout << "3. Convert USD to Japanese Yen (JPY)" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Enter your choice (1-4): ";
        cin >> select;

        if (select == 4) {
            break;
        }

        if (select < 1 || select > 4) {
            cout << "Invalid choice. Please try again." << endl << endl;
            cont = 'y';
            continue;
        }

        cout << "Enter amount in USD: ";
        cin >> value;

        if (cin.fail() || value < 0) {
            cout << "Invalid amount. Please restart and enter a valid non-negative number." << endl;
            cont = 'y';
            continue;
        }

        cout << fixed << setprecision(2);
        if (select == 1) {
            conValue = dollarToEuro(value);
            cout << value << " USD = " << conValue << " EUR" << endl << endl;
        }
        else if (select == 2) {
            conValue = dollarToPound(value);
            cout << value << " USD = " << conValue << " GBP" << endl << endl;
        }
        else if (select == 3) {
            conValue = dollarToYen(value);
            cout << value << " USD = " << conValue << " JPY" << endl << endl;
        }

        cout << "Number of conversions performed: " << getConversionCount() << endl << endl;
        cout << "Would you like to perform another conversion? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    cout << "Thank you for using the Currency Converter!" << endl;

    return 0;
}

double dollarToEuro(double amount) {
    conversionCount++;
    return amount * 0.85;
}

double dollarToPound(double amount) {
    conversionCount++;
    return amount * 0.74;
}

double dollarToYen(double amount) {
    conversionCount++;
    return amount * 110.33;
}

int getConversionCount() {
    return conversionCount;
}