#include <ctype.h>
#include <string.h>
#include <iostream>
#include "revwords.h"
#include "revwords.cpp"

using namespace std;

int main() {
    char str[] = "University of Cambridge!";
    cout << "Original String : " << str << endl;
    reverse_words(str);
    cout << "Reverse String : " << str << endl;
    return 0;
}
