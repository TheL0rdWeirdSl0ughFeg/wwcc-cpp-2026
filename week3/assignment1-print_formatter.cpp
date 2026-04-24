#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

string format(int number);
string format(double number);
string format(double number, int precise);
string format(string input);

int main() {
    int value = -1234567;
    double decimal = -12.34567;
    int precision = 3;
    string text = "welcome to the world of c++ programming";

    cout << "Integer formatting:\nOriginal: " << value << endl;
    cout << "Formatted: " << format(value) << endl << endl;

    cout << "Double formatting (default 2 decimal places):\nOriginal: " << decimal << endl;
    cout << "Formatted: " << format(decimal)<< endl << endl ;

    cout << "Double formatting (custom decimal places):\nOriginal: " << decimal << " with precision " << precision << endl;
    cout << "Formatted: " << format(decimal, precision) << endl << endl;

    cout << "String formatting:\nOriginal: \"" << text << "\"" << endl;
    cout << "Formatted: \"" << format(text) << "\"" << endl;


    return 0;
}

string format(int number) {
    string intString = to_string(number);

    if (number < 0) {
        intString = intString.substr(1);
        for (int i = intString.length() - 3; i > 0; i -= 3) {
            intString.insert(i, ",");
        }
        return "-" + intString;
    } else {
        for (int i = intString.length() - 3; i > 0; i -= 3) {
            intString.insert(i, ",");
        }
        return intString;
    }
}

string format(double number) {
    stringstream ss;
    ss << fixed << setprecision(2) << number;
    return ss.str();
}

string format(double number, int precise) {
    stringstream ss;
    ss << fixed << setprecision(precise) << number;
    return ss.str();
}

string format(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (i == 0 || text[i - 1] == ' ') {
            text[i] = toupper(text[i]);
        }
    }
    return text;
}