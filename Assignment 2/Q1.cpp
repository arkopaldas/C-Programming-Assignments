/* A function that takes a pointer to a character and a reference to an integer, returning no value */
void func(char *ptr, int &ref);

/* A pointer to such a function */
typedef void (*FuncPtr)(char *, int &);

/* A function that takes such a pointer as an argument */
void funcTakingFuncPtr(FuncPtr ptr);

/* A function that returns such a pointer */
FuncPtr funcReturningFuncPtr();

/* A function that takes such a pointer as an argument and returns its argument as the return value */
FuncPtr funcReturningArgument(FuncPtr ptr) {
    return ptr;
}