#include <iostream>
#include <iomanip>  // For setw()
using namespace std;

int main() {
    int start, end;

    cout << "Multiplication Table Generator" << endl << endl;

    cout << "Enter starting number: ";
    cin >> start;

    cout << "Enter ending number: ";
    cin >> end;

    if (start > end) {
        cout << "Error: Starting number must be less than ending number." << endl;
        return 1;
    }

    cout << endl;

    cout << setw(4) << " ";
    for (int column = start; column <= end; column++) {
        cout << setw(4) << column;
    }
    cout << endl;

    cout << "----";
    for (int column = start; column <= end; column++) {
        cout << "----";
    }
    cout << endl;

    for (int row = start; row <= end; row++) {
        cout << setw(4) << row;
        for (int column = start; column <= end; column++) {
            cout << setw(4) << row * column;
        }
        cout << endl;
    }

    return 0;
}