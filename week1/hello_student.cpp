#include <iostream>
#include <string>

using namespace std;
//absolutely no reason to use std:: for something like this

int main() {
    string name;
    string answer;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "What was the most popular optical storage medium before DVD?";
    getline(cin, answer);

    cout << "CDs nuts haha gotteem";

    return 0;
}