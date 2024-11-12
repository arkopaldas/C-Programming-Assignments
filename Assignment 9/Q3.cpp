#include <iostream>
#include <fstream>
#include <bitset>

/* This function opens a binary file, reads each byte, and prints its binary representation.
Opens the file filename in binary read mode. Reads each byte into char c, casts it to std::bitset<8>(c)
to get an 8-bit binary string representation, and prints it with a space between each byte.
Closes the file after reading. */
void printBitSequenceFromFile(std::string filename)
{
    std::fstream fhand(filename, fhand.binary | fhand.in);
    char c;
    while (fhand.read(reinterpret_cast<char*>(&c), sizeof(c)))
    {
        if (!fhand.eof())
        {
            std::cout << std::bitset<8>(c) << " ";
        }
    }
    std::cout << std::endl;
    fhand.close();
}

/* The main function prints a, b, and c to the console to show the initial values being written to the file.
Opens the file data.bin in binary write mode with trunc flag to clear any existing contents.
Writes the binary representation of a, b, and c to the file using fhand.write and reinterpret_cast<char*>
to interpret each variable as a sequence of bytes. Closes the file after writing.

Calls printBitSequenceFromFile(<filename>), which reads each byte from data.bin and prints its binary representation.
This provides a bit-level view of the file contents. Declares variables d, e, and f to store the values read back from the file.
Opens data.bin in binary read mode.

Reads each variable back from the file in the same order they were written, storing the results in d, e, and f.
Closes the file after reading.
Prints the values of d, e, and f to verify that the original values were written and read correctly from the binary file. */
int main()
{
    std::string filename = "data.bin";
    signed int a = -10000;
    unsigned short b = 100;
    const char c[] = "WE";
    const size_t str_size = sizeof(c);
    std::cout << "Encoding values:" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::fstream fhand;
    fhand.open(filename, fhand.binary | fhand.trunc | fhand.out);
    fhand.write(reinterpret_cast<char*>(&a), sizeof(a));
    fhand.write(reinterpret_cast<char*>(&b), sizeof(b));
    fhand.write(c, str_size);
    fhand.close();
    std::cout << "Bit sequence in the file: " << std::endl;
    printBitSequenceFromFile(filename);
    signed int d;
    unsigned short e;
    char f[str_size];
    fhand.open(filename, fhand.binary | fhand.in);
    fhand.read(reinterpret_cast<char*>(&d), sizeof(d));
    fhand.read(reinterpret_cast<char*>(&e), sizeof(e));
    fhand.read(f, str_size);
    std::cout << "Decoded values:" << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    fhand.close();
}