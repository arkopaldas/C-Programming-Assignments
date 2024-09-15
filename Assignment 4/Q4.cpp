#include <iostream>
using namespace std;

int main() {
    /* In C++, string literals are read-only. When declared char *str,
    it points to a constant string literal stored in read-only memory.
    Trying to modify the string literal causes a runtime error,
    typically leading to a segmentation fault. */
    
    // This statement is replaced with the following to resolve issues.
    // char *str = "India vs Pakistan, Asia Cup 2023";
    
    // To modify the string, it is allocated to a array of characters which is modifiable.
    char str[] = "India vs Pakistan, Asia Cup 2023";
    str[7] = 'V';
    
    double darr[] = {2.3, 4.5, 5.5};
    
    *(darr + 3) = 6.5;
    
    extern float f;
    float g = f * 100.5;
    
    short int i = 89;
    void *v = &i;
    short int *ip = static_cast<short int*>(v);  // Corrected casting to 'short int*'
    
    cout << "integer = " << *ip;  // Now prints 89 correctly
}