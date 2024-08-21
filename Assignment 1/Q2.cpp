#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "x+1/(x+1/(x+1/x)) : " << (x+1/(x+1/(x+1/x))) << endl;
    return 0;
}
