#include <iostream>
#include <fstream>
#include <string>

void copyFile(const std::string& sourceFile, const std::string& destinationFile){
    std::ifstream src(sourceFile, std::ios::binary);
    if (!src.is_open()) {
        std::cerr << "Error: Cannot open source file '" << sourceFile << "' for reading." << std::endl;
        return;
    }
    std::ofstream dest(destinationFile, std::ios::binary | std::ios::trunc);
    if (!dest.is_open()) {
        std::cerr << "Error: Cannot open destination file '" << destinationFile << "' for writing." << std::endl;
        src.close();
        return;
    }
    dest << src.rdbuf();
    std::cout << "File copied successfully from '" << sourceFile << "' to '" << destinationFile << "'." << std::endl;
    src.close();
    dest.close();
}
int main(){
    std::string sourceFile, destinationFile;
    std::cout << "Enter the source file name: ";
    std::cin >> sourceFile;
    std::cout << "Enter the destination file name: ";
    std::cin >> destinationFile;
    copyFile(sourceFile, destinationFile);
    return 0;
}