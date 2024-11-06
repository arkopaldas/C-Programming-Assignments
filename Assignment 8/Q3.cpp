#include<iostream>
using namespace std;

class Char_vec{
	int sz;
	char element[1];
	public:
	static Char_vec* new_char_vec(int s);
	virtual char& operator[](int i){ return element[i]; }
	Char_vec(int s) : sz(s) {}
};
class Char_vec_derived : public Char_vec{
	char *element;
	public:
	Char_vec_derived(int size, char* e) : Char_vec(size), element(e) {}
	char& operator[](int i) override { return element[i]; }
	// Operator [] is overriden to access 'element' of this class making it safe for indexing.
};
Char_vec* Char_vec::new_char_vec(int s){
	char *e = new char[s];
	for(unsigned int i=0;i<s;i++){ e[i] = 'A' + i; }
	Char_vec* c = new Char_vec_derived(s,e); // create a derived class obj and return its ptr
	return c;
}
int main(){
	Char_vec* cobj = Char_vec::new_char_vec(5);
	for(unsigned int i=0;i<5;i++){ cout << cobj->operator[](i) << " "; }
	cout << endl;
} 