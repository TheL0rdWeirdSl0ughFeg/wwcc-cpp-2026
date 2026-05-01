#include <iostream>
#include <iomanip>
#include <cctype>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

using namespace std;

int main(){
    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif

    int grades[5];
    char letterGrade[5];
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    int dCount = 0;
    int fCount = 0;
    char overall;

    cout << "QUIZ GRADE TRACKER" << endl;
    cout << "--------------------" << endl;
    
    for (int i = 0; i < 5; i++){
        cout << "Enter score for Quiz " << i + 1 << " (0-100): ";
        cin >> grades[i];

        while (cin.fail() || grades[i] < 0 || grades[i] > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Grade must be a number between 0 and 100: ";
            cin >> grades[i];
        }
    }

    for (int i = 0; i < 5; i++){
        if (grades[i] <= 60){
            letterGrade[i] = 'F';
            fCount++;
        } else if (grades[i] <= 69) {
            letterGrade[i] = 'D';
            dCount++;
        }else if (grades[i] <= 79) {
            letterGrade[i] = 'C';
            cCount++;
        }else if (grades[i] <= 89) {
            letterGrade[i] = 'B';
            bCount++;
        } else {
            letterGrade[i] = 'A';
            aCount++;
        }
    }

    int high = grades[0];
    int quizHigh = 1;
    int low = grades[0];
    int quizLow = 1;

    for (int i = 1; i < 5; i++){
        if (grades[i] > high){
            high = grades[i];
            quizHigh = i + 1;
        }

        if (grades[i] < low){
            low = grades[i];
            quizLow = i + 1;
        }
    }

    double average = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4])/5.0;

    if (average <= 60){
            overall = 'F';
        } else if (average <= 69) {
            overall = 'D';
        }else if (average <= 79) {
            overall = 'C';
        }else if (average <= 89) {
            overall = 'B';
        } else {
            overall = 'A';
        }


    cout << "Quiz Results: " << endl;
    cout << "Quiz 1: " << grades[0] << " (" << letterGrade[0] << ")" << endl;
    cout << "Quiz 2: " << grades[1] << " (" << letterGrade[1] << ")" << endl;
    cout << "Quiz 3: " << grades[2] << " (" << letterGrade[2] << ")" << endl;
    cout << "Quiz 4: " << grades[3] << " (" << letterGrade[3] << ")" << endl;
    cout << "Quiz 5: " << grades[4] << " (" << letterGrade[4] << ")" << endl;

    cout << "Statistics:" << endl;
    cout << fixed << setprecision(1);
    cout << "Average score: " << average << endl;
    cout << "Highest score: " << high << " (Quiz " << quizHigh << ")" << endl;
    cout << "Lowest score: " << low << " (Quiz " << quizLow << ")" << endl;
    cout << "Overall grade: " << overall << endl;

    cout << "Grade Distribution:" << endl;
    cout << "A: " << aCount << endl;
    cout << "B: " << bCount << endl;
    cout << "C: " << cCount << endl;
    cout << "D: " << dCount << endl;
    cout << "F: " << fCount << endl;

    return 0;
}