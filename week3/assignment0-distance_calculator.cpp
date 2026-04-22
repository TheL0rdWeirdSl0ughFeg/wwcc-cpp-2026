#include <iostream>
#include <cmath>
#include<string>

using namespace std;


double calculateDistance(double x1, double y1, double x2, double y2) {
    double distance = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
    return distance;
}

void calculateMidpoint(double x1, double y1, double x2, double y2) {
    double midpointX = (x1+x2)/2;
    double midpointY = (y1+y2)/2;
    printf("The midpoint between (%.2f,%.2f) and (%.2f,%.2f) is: (%.2f,%.2f)\n", x1, y1, x2, y2, midpointX, midpointY);
}


int main(){
    double x1, y1, x2, y2;

    cout << "Enter the coordinates of the first point:\n";
    cout << "x1: ";
    cin >> x1;
    cout << "y1: ";
    cin >> y1;

    cout << "Enter the coordinates of the second point:\n";
    cout << "x2: ";
    cin >> x2;
    cout << "y2: ";
    cin >> y2;

    double distanceResult = calculateDistance(x1, y1, x2, y2);

    printf("The distance between (%.2f,%.2f) and (%.2f,%.2f) is: %.2f\n", x1, y1, x2, y2, distanceResult);
    calculateMidpoint(x1, y1, x2, y2);

    return 0;
}