#include <iostream>

/*
The following program increments each element of the 2D array m by 2.
*/

/*
Yes, it is valid to pass a 2d array to a function without passing the first dimension in C++.
The second dimension must be specified to ensure the compiler can correctly access the array elements.
*/

/*
In C++, when you pass a 2D array to a function, you must specify the size of the columns
(the second dimension) because the compiler needs to know how to calculate the memory offset
for each element in the array.

The first dimension (number of rows) can be left unspecified because the compiler uses
the second dimension (number of columns) to correctly calculate the position of each element.
*/

void f1(int m[][5], int dim1) {
    for (unsigned int i = 0; i < dim1; i++)
        for (unsigned int j = 0; j < 5; j++)
            m[i][j] = m[i][j] + 2;
}

int main() {
    int m[3][5] = {{1, 2, 3, 4, 5},{11, 12, 13, 14, 15},{21, 22, 23, 34, 25}};
    f1(m, 3);
    for (unsigned int i = 0; i < 3; i++){
        for (unsigned int j = 0; j < 5; j++)
            std::cout << m[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
}
