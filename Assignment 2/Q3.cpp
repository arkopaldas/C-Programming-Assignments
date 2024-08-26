#include <iostream>
using namespace std;

int globalCallCount = 0;


/*
This method is less desirable because the global variable can be accidentally
modified or used by other parts of the program, leading to potential bugs.
*/
void displayGlobalCallCount() {
    globalCallCount++;
    cout << "I have been called " << globalCallCount << " times (Global variable)." << endl;
}

/*
This method is more appropriate because the variable is only accessible within the function
where it’s used, reducing the risk of unintended interference from other parts of the program.
*/
void displayCallCount() {
    static int callCount = 0;
    callCount++;
    cout << "I have been called " << callCount << " times (Static Variable)." << endl;
}

/*
A regular local variable would be reinitialized every time the function is called,
which means it would always start at 0 and the function would always print "I have been called 1 time."
To maintain a count across multiple function calls, the variable needs to persist between calls,
which is why a static local variable is appropriate.
*/
int main() {
    for (int i = 0; i < 10; i++) {
        displayCallCount();
        displayGlobalCallCount();
    }
    return 0;
}