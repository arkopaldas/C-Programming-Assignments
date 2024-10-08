#include <iostream>

void swapUsingPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapUsingReferences(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    
    std::cout << "Before swap : x = " << x << ", y = " << y << std::endl;
    swapUsingPointers(&x, &y);
    std::cout << "After swap (using pointers): x = " << x << ", y = " << y << std::endl;
    
    std::cout << "Before swap : x = " << x << ", y = " << y << std::endl;
    swapUsingReferences(x, y);
    std::cout << "After swap (using references): x = " << x << ", y = " << y << std::endl;
    
    return 0;
}
