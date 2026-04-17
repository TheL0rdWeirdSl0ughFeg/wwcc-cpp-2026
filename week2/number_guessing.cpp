#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
#include <string>
using namespace std;

int main() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Number Guessing Game" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl << endl;


    cout << "Enter your guess: ";
    cin >> guess;
    attempts ++;

    
    if (guess == secretNumber) {
        printf("Congratulations! You guessed the number %d correctly! \n It took you %d guesses.", guess, attempts);
    }
    else {
        while (true) {
        if (guess > secretNumber){
            cout << "Too high! Try again.\nEnter your guess: ";
            cin >> guess;
            attempts ++;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\nEnter your guess: ";
            cin >> guess;
            attempts ++;
        } else {
            printf("Congratulations! You guessed the number %d correctly!\nIt took you %d guesses.", guess, attempts);
            break;
        }
    }
    }


    return 0;
}