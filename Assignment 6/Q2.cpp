#include <iostream>
using namespace std;
struct foo{
    foo(){ cout << "foo()\n"; };
    ~foo(){ cout << "~foo()\n"; };
    int i {5};
};
struct obj{
    const foo& getFoo(){ return my_foo; };
    foo my_foo;
};
int main(){
    obj *o = new obj();
    /* This line dynamically allocates an instance of obj on the heap.
    During its construction, the foo object my_foo is also created within obj as a member.
    This will call the default constructor of foo, outputting: foo() */
    
    const foo& val = o->getFoo();
    /* This line calls getFoo() on o, which returns a const reference to my_foo.
    The val variable now holds a reference to my_foo within o. */
    
    cout << "val.i=" << val.i << endl;
    /* This outputs the value of i within my_foo, which was initialized to 5.
    So, the output will be: val.i=5 */

    delete o;
    /* This line deletes the obj instance, which in turn destructs its member my_foo,
    calling its destructor and outputting: ~foo() */

    cout << "val.i=" << val.i << endl;
    /* Since val is a reference to my_foo in o, and o has been deleted, val now refers to a deallocated memory area.
    Accessing val.i at this point is undefined behavior, which could lead to various outcomes,
    including a crash, garbage output, or unexpected values. */

    /* Thus the last line of the code results in an unexpected value, known as the garbage value. */
}