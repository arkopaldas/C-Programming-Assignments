#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter the number of days: ";
    cin >> num;
    cout << (num/365) << " years ";
    cout << ((num%365)/7) << " weeks ";
    cout << ((num%365)%7) << " days" << endl;
    return 0;
}
