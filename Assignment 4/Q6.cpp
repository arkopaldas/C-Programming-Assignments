#include <iostream>
using namespace std;

struct Month {
    char* name;
    int days;
};

int main() {
    const char* monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    cout << "Month Table using Array of Months and Days" << endl;
    cout << "Month\t\t\tDays" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < 12; i++) {
        cout << monthNames[i] << "\t\t\t" << monthDays[i] << endl;
    }
    
    Month months[] = {
        {"January", 31}, {"February", 28}, {"March", 31}, {"April", 30},
        {"May", 31}, {"June", 30}, {"July", 31}, {"August", 31},
        {"September", 30}, {"October", 31}, {"November", 30}, {"December", 31}
    };
    
    cout << "\nMonth Table using Array of Structure of Months" << endl;
    cout << "Month\t\t\tDays" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < 12; i++) {
        cout << months[i].name << "\t\t\t" << months[i].days << endl;
    }

    return 0;
}