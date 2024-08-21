
#include <iostream>
#include <cmath>

int main() {
    // Input variables
    double number;
    int k;

    // Reading the number and k from the user
    std::cout << "Enter the real number: ";
    std::cin >> number;
    std::cout << "Enter the positive integer k: ";
    std::cin >> k;

    // Calculating the multiplier as 10^k
    double multiplier = pow(10, k);

    // Rounding off the number to the nearest k-th place
    double roundedNumber = std::round(number * multiplier) / multiplier;

    // Displaying the result
    std::cout << "The rounded off number is: " << roundedNumber << std::endl;

    return 0;
}
