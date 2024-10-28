#include<iostream>
using namespace std;
struct X{
    X(){ cout << "default constructor\n"; };
    X(X&& x){ cout << "move constructor\n"; };
    X(const X&x){ cout << "copy constructor\n"; };
    X& operator = (const X&){ cout << "copy assignment\n"; return *this; };
    ~X(){ cout << "Destructor\n"; };
};
X foo(X x){
    return x;
}
int main(){
    X obj;
    /* This line calls the default constructor of X, so it outputs: default constructor */

    obj = foo(obj);
    /* foo takes its parameter x by value, meaning a copy of obj is made when calling foo.
    Therefore, this invokes the copy constructor to copy obj into x, resulting in: copy constructor */

    /* foo returns x by value, which involves moving x from the local scope of foo to the caller,
    since returning a local variable by value is typically optimized with a move.
    This invokes the move constructor for the returned object: move constructor */

    /* The result of foo(obj), which is now a temporary object of type X, is assigned to obj.
    This invokes the copy assignment operator: copy assignment */

    /* The first temporary object, created as the return value of foo (the result of the move),
    is now out of scope after the assignment. It results in: Destructor */

    /* The second temporary object, which was copied as the argument to foo, also goes out of scope as foo finishes.
    This results in: Destructor */

    /* Finally wshen main finishes, obj goes out of scope and its destructor is called resulting in: Destructor */
}
