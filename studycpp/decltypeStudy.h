#include <iostream>

using namespace std;

/*
When we apply decltype to an expression (other than a variable), the result is
a reference type if the expression yields an lvalue. As an example, assume p is an
int*. Because dereference yields an lvalue, decltype(*p) is int&. On the other
hand, because the address-of operator yields an rvalue, decltype(&p) is int**,
that is, a pointer to a pointer to type int
*/
