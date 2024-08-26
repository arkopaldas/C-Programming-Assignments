#include <iostream>
using namespace std;

/*
Yes, this is a valid function declaration in C++.
The parameters in the function have default values assigned.
If no argument is provided, the char parameter defaults to * and int to 45.
*/

void func(char='*', int=45);

/*
When you call the function without any arguments, both parameters will use their default values.
When you provide only one argument, it will be used for the first parameter (char),
and the second parameter (int) will use its default value.
When you provide both arguments, the default values are ignored, and the provided arguments are used.
*/
void func(char c, int num) {
    cout << "Character: " << c << " Number: " << num << endl;
}

int main() {
    func();         // Uses both default values: '*', 45
    func('#');      // Uses '#' for char, and 45 as default for int
    func('#',99);   // Uses '#' for char, and 99 for int
    return 0;
}
