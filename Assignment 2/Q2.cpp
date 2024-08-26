/*
The line typedef int (&rifii)(int, int); defines a type alias named rifii for a reference 
to a function that takes two int arguments and returns an int.

int specifies the return type of the function.
& indicates that rifii is a reference to a function.
(int, int) specifies the parameters of the function: two integers.

*/

/*
It is good for the following purposes.
Type Abstraction: It provides a convenient way to refer to a reference to a function with a specific 
signature, making it easier to declare variables or parameters of this type 
in the code without repeating the full function signature.

Function References: This can be used to pass around references to functions (not pointers) as arguments 
to other functions, ensuring that the reference cannot be null (unlike function pointers).

A sample program is given below which best suits its purpose.
*/

#include <iostream>
using namespace std;

typedef int (&rifii)(int, int);

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// Function that takes a reference to a function
int operate(rifii operation, int x, int y) {
    return operation(x, y);
}

int main() {
    cout << "Add: " << operate(add, 3, 4) << endl;
    cout << "Multiply: " << operate(multiply, 3, 4) << endl;
    return 0;
}
