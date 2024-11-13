#include <iostream>
#include <fstream>
#include <stdexcept>

class fileRA;
class fileRADescriptor {
	private:
	std::fstream& file;
	unsigned int position;
	public:
	fileRADescriptor(std::fstream& file, unsigned int pos) : file(file), position(pos) {
		file.seekg(position, std::ios::beg);
		file.seekp(position, std::ios::beg);
	}
	operator char() const {
		file.seekg(position, std::ios::beg);
		char c;
		file.get(c);
		return c;
	}
	fileRADescriptor& operator=(char c) {
		file.seekp(position, std::ios::beg);
		file.put(c);
		return *this;
	}
};
class fileRA {
	private:
		std::fstream file;
		unsigned int size;
	public:
		fileRA(const std::string& filename) {
			file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
			if (!file) {
				throw std::runtime_error("Could not open file.");
			}
			file.seekg(0, std::ios::end);
			size = file.tellg();
			file.seekg(0, std::ios::beg);
		}
		~fileRA() {
			if (file.is_open()) {
				file.close();
			}
		}
		unsigned int get_size() const {
			return size;
		}
		fileRADescriptor operator[](unsigned int index) {
			if (index >= size) {
				throw std::out_of_range("Index out of range");
			}
			return fileRADescriptor(file, index);
	}
};
int main() {
	try {
		fileRA fobj("Test.txt");
		fobj[4] = 'A';
		for (unsigned int i = 0; i < fobj.get_size(); i++) {
			std::cout << fobj[i];
		}
		std::cout << std::endl;
		char c = fobj[1];
		std::cout << "Char is = " << c << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
