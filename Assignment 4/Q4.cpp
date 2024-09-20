#include<iostream>
using namespace std;

int main()
{
    /*String literals in C++ are stored in read-only memory. Attempting to modify a string literal str[7] causes the problem.
    Using a mutable array of characters instead of a string literal fixes the problem*/
    char str[] = "India vs Pakistan, Asia Cup 2023";
    str[7] = 'V';
    
    /*The array darr only has 3 elements. The statement *(darr + 3) = 6.5; attempts to write to darr[3], which is out of bounds, results in undefined behavior.
    Allocating more space in the array or ensuring access within bounds solves the problem.*/
    double darr[] = {2.3, 4.5, 5.5, 0.0};  // Add an extra element
    *(darr + 3) = 6.5;

    /*The extern declaration means f is declared elsewhere, but in this program, f has not been initialized.
    This leads to undefined behavior when f is used in the expression g = f * 100.5;.
    Initializing f in the program or providing a definition for f fixes the problem.*/
    float f = 5.0f;  // Example initialization
    float g = f * 100.5;

    /*v is a void* pointing to a short int, but it is being cast to an int*.
    This results in incorrect interpretation of the data, leading to undefined behavior.
    Either casting void* to short int* or declare i as an int solves the problem.*/
    short int i = 89;
    void *v = &i;
    short int *ip = static_cast<short int*>(v);  // Correct typecasting
    cout << "integer = " << *ip;

    return 0;
}
