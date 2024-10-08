// A pointer to a character
char c = 'A';
char *charPtr = &c;

// An array of 10 integers
int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// A reference to an array of 10 integers
int (&arrRef)[10] = arr;

// A pointer to an array of character strings (array of pointers to characters)
const char *charStrArr[] = {"Hello", "World", "C++", "Programming"};
const char **ptrToCharStrArr = charStrArr;

// A pointer to a pointer to a character
char ch = 'X';
char *ptrToChar = &ch;
char **ptrToPtr = &ptrToChar;

// A constant integer
const int constantInt = 42;

// A pointer to a constant integer
const int *ptrToConstInt = &constantInt;

// A constant pointer to an integer
int num = 100;
int *const constPtrToInt = &num;

// A constant pointer to a constant double
const double pi = 3.14159;
const double *const constPtrToConstDouble = &pi;