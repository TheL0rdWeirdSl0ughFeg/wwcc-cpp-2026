#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
#include <string>
using namespace std;

int main() {
    srand(time(0));

    int flips;
    int heads = 0;
    int tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;

    cout << "Simulating " << flips << " coin flips...\n\n";

    for (int i = 0; i < flips; i++) {
        int result = rand() % 2;

        if (result == 0){
            heads++;
        }
        if (result == 1){
            tails++;
        }
    }

    double headsPercent = (double)heads/flips * 100;
    double tailsPercent = (double)tails/flips * 100;

    printf("Results:\nHeads: %d (%.2f%)\nTails: %d (%.2f%)", heads, headsPercent, tails, tailsPercent);

    return 0;
}