#include <iostream>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <algorithm>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

using namespace std;

int main(){
    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif

    string input = "";
    string longWord = "";
    int wordCount = 0;
    int sentCount = 0;
    int letterCount = 0;
    double average = 0.0;



    cout << "TEXT ANALYZER" << endl;
    cout << "---------------" << endl;
    cout << "Enter a sentence or paragraph:" << endl;
    getline(cin, input);

    int totalChar = input.length();

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?'){
            sentCount++;
        }
    }

    stringstream ss(input);
    string word;

    while(ss >> word){
        string isoWord = word;
        isoWord.erase(remove_if(isoWord.begin(), isoWord.end(), ::ispunct), isoWord.end());

        if (!isoWord.empty()) {
            wordCount++;
            letterCount += isoWord.length();

            if (isoWord.length() > longWord.length()){
                longWord = isoWord;
            }
        }
    }

    if (wordCount > 0) {
        average = (double) letterCount / wordCount;
    }

    string upper = input;
    string lower = input;

    for (int i = 0; i < upper.length(); i++) {
        upper[i] = toupper(upper[i]);
    }

    for (int i = 0; i < lower.length(); i++) {
        lower[i] = tolower(lower[i]);
    }

    cout << "\nAnalysis:" << endl;
    cout << "Characters (with spaces): " << totalChar << endl;
    cout << "Word count: " << wordCount << endl;
    cout << "Sentence count: " << sentCount << endl;
    cout << "Longest word: " << longWord << endl;
    cout << fixed << setprecision(1);
    cout << "Average word length: " << average << " characters" << endl;

    cout << "\nUppercase:" << endl;
    cout << upper << endl;

    cout << "\nLowercase:" << endl;
    cout << lower << endl;

    return 0;
}