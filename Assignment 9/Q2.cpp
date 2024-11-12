#include <iostream>
#include <fstream>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file.\n";
        return 1;
    }
    unsigned long long sum = 0;
    char c;
    while (file.get(c)) { sum += static_cast<unsigned char>(c); }
    file.close();\
    std::cout << "The total of all characters is: " << sum << std::endl;
    return 0;
}
