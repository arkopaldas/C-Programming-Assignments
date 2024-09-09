#include <ctype.h>
#include <string.h>
#include <iostream>
#include "reverse.h"
#include "revword.cpp"

using namespace std;

int main() {
    char str[] = "University of Cambridge!";
    reverse_words(str);
    cout << str << endl;
    return 0;
}
