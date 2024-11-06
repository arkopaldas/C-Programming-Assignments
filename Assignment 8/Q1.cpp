#include <vector>
#include <list>
#include <iostream>
using namespace std;

class base {
	int x;
	vector<double> v;
	public:
	base(int y, vector<double> z) : x{y}, v{z} {}
	int getX() const { return x; }
	const vector<double>& getV() const { return v; }
};
class derived : public base {
	list<bool> l;
	public:
	derived(int y, vector<double> z) : base(y, z), l() {}
	derived(int y, vector<double> z, list<bool> el) : base(y, z), l(el) {}
	void print() {
		cout << "x = " << getX() << endl;
		cout << "v = ";
		for (double value : getV()) { cout << value << " "; }
		cout << endl;
		cout << "l = ";
		for (bool value : l) { cout << (value ? "true" : "false") << " "; }
		cout << endl;
	}
};
int main() {
	derived d{10, {1.5, 2.5, 3.5}, {true, false}};
	d.print();
}