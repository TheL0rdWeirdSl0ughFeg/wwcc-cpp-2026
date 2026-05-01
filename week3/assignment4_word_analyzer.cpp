#include <iostream>
#include <cctype>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

using namespace std;

int countVowels(string word);
int countConsonants(string word);
bool isPalindrome(string word);
char firstLetter(string word);
string reverse(string word);
string getStats(string word);


int main(){
    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif

    char again;

    do{

    string word;
    bool valid = false;

    while (!valid) {
        cout << "Enter a word: ";
        cin >> word;

        valid = true;

        for (int i = 0; i < word.length(); i++) {
            if (!isalpha(word[i])) {
                cout << "Invalid input. Letters only." << endl;
                valid = false;
                break;
            }
        }
    }

    cout << "Word Analysis:" << endl;
    cout << "--------------------" << endl;
    cout << "Original word: " << word << endl;
    cout << "Number of vowels: " << countVowels(word) << endl;
    cout << "Number of consonants: " << countConsonants(word) << endl;
    cout << "First letter: " << firstLetter(word) << endl;
    cout << "Reversed: " << reverse(word) << endl;
    cout << "Palindrome: ";
        if (isPalindrome(word)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    cout << "Overview: " << getStats(word) << endl;
    
    cout << "Would you like to enter another word? (y/n) : ";
    cin >> again;
    cout << endl;
    } while (again =='y' || again == 'Y');

    cout << "Goodbye." << endl;

    return 0;
}

int countVowels(string word) {
    int vowelCount = 0;
    for (int i = 0; i < word.length(); i++){
        if (toupper(word[i]) == 'A' || toupper(word[i]) == 'E' || toupper(word[i]) == 'I' || toupper(word[i]) == 'O' || toupper(word[i]) == 'U' || toupper(word[i]) == 'Y'){
            vowelCount++;
        }
    }

    return vowelCount;
}

int countConsonants(string word) {
    int consCount = 0;
    for (int i = 0; i < word.length(); i++){
        if (toupper(word[i]) != 'A' && toupper(word[i]) != 'E' && toupper(word[i]) != 'I' && toupper(word[i]) != 'O' && toupper(word[i]) != 'U' && toupper(word[i]) != 'Y'){
            consCount++;
        }
    }

    return consCount;
}

bool isPalindrome(string word) {
    string palindromeCheck;

    for (int i = word.length() - 1; i >= 0; i--){
        palindromeCheck += word[i];
    }

    return word == palindromeCheck;
}

char firstLetter(string word) {
    char firstChar = word[0];

    return firstChar;
}

string reverse(string word) {
    string reversed = "";

    for (int i = word.length() -1; i >= 0; i--){
        reversed += word[i];
    }
    return reversed;
}

string getStats(string word){
    int length = word.length();
    int vowelCount = countVowels(word);
    int consCount = countConsonants(word);
    string palindromeStatus;

    if (isPalindrome(word)) {
        palindromeStatus = "is a palindrome";
    } else {
        palindromeStatus = "is not a palindrome";
    }

    return word + " has " + to_string(length) + " characters, " + to_string(vowelCount) + " vowels, " + to_string(consCount) + " consonants, and " + palindromeStatus + ".";
}