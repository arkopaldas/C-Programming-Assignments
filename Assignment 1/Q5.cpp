#include <iostream>
#include <cmath>
using namespace std;

double roundToNearestK(double number, int k) {
    double factor = 1.0;
    for (int i = 0; i < k; ++i) {
        factor *= 10.0;
    }
    double shiftedNumber = number * factor;
    double roundedShiftedNumber;
    if (shiftedNumber >= 0) {
        roundedShiftedNumber = static_cast<int>(shiftedNumber + 0.5);
    } else {
        roundedShiftedNumber = static_cast<int>(shiftedNumber - 0.5);
    }
    return roundedShiftedNumber / factor;
}

int main() {
    double number;
    int k;
    cout << "Enter a real number: ";
    cin >> number;
    cout << "Enter the place to round off to (k): ";
    cin >> k;
    if (k <= 0) {
        cerr << "The value of k must be a positive integer." << endl;
        return 1;
    }
    double roundedNumber = roundToNearestK(number, k);
    cout.precision(k);
    cout << "The rounded number is: " << fixed << roundedNumber << endl;
    return 0;
}
