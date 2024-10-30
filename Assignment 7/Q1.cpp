#include <iostream>
using namespace std;
struct X{
	int i;
	X(int n) : i(n) {};
	X operator+(int n){return X(n+i);};
};
struct Y{
	int i;
	Y operator+(X x){Y y; y.i = x.i+i; return y;};
	operator int(){return i;};
};
ostream& operator<<(ostream& os, X x){
	os << x.i;
	return os;
}
extern X operator*(X x, Y y){return X(x.i*y.i);};
extern int f(X x){return x.i;};
X x = 1;
Y y = y+x;
int i = 2;
int main() {
	cout << i + 10 << endl;
	cout << y + X(10) << endl;
	cout << y + X(10) * y << endl;
	cout << x + y + i << endl;
	cout << f(x) * f(x) + i << endl;
	cout << f(7) << endl;
	cout << f(int(y)) << endl;
	cout << y + y << endl;
	cout << 106 + int(y) << endl;
}
