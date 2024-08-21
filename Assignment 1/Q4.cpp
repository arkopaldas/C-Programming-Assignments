#include <iostream>
using namespace std;

void printBinary(int number) {
    const int bits = sizeof(int) * 8;
    cout << number << " in binary: ";

    for (int i = bits - 1; i >= 0; --i) {
        int bit = (number >> i) & 1;
        cout << bit;
    }
    cout << endl;
}

void verifyTwosComplement(int number) {
    int twosComplement = (~(-number)) + 1;
    cout << "Two's complement verification:" << endl;
    cout << "Original negative number: " << number << endl;
    cout << "Computed Two's complement: " << twosComplement << endl;
    cout << "Are they equal? " << (number == twosComplement ? "Yes" : "No") << endl;
}

int main() {
    int positiveNum = 25;
    int negativeNum = -25;
    cout << "Positive number:" << endl;
    printBinary(positiveNum);
    cout << "\nNegative number:" << endl;
    printBinary(negativeNum);
    cout << "\nTwo's Complement Verification:" << endl;
    verifyTwosComplement(negativeNum);
    return 0;
}
