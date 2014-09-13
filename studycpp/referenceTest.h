#include <iostream>

//header shouldnot include using declaration
using namespace std;





void func_typedefAndconst()
{
	typedef char *pstring;
	const pstring cstr = 0;
	const pstring *ps;//ps is pointer to a constant pointer to char
}


void func_theUseOfauto()
{
	//auto sz = 0, pi = 3.14;//
}


void func_theUseOfdecltype()
{
	/*
	Generally speaking, decltype returns
	a reference type for expressions that yield objects that can stand on the left-hand
	side of the assignment
	*/
	
	int i = 42, *p = &i, &r = i;
	decltype(r + 0) b; // ok: addition yields an int; b is an (uninitialized) int
	//decltype(*p) c;
	// error: c is int& and must be initialized
	/*
	Here r is a reference, so decltype(r) is a reference type.If we want the type to
	which r refers, we can use r in an expression, such as r + 0, which is an expression
	that yields a value that has a nonreference type.
	On the other hand, the dereference operator is an example of an expression
	for which decltype returns a reference.As we¡¯ve seen, when we dereference a
	pointer, we get the object to which the pointer points.Moreover, we can assign to
	that object.Thus, the type deduced by decltype(*p) is int&, not plain int.
	*/
	/*
	Remember that decltype((variable)) (note, double parentheses) is al-
	ways a reference type, but decltype(variable) is a reference type only
	if variable is a reference.
	*/
	
	int a = 1;
	int b1 = 2;
	//decltype(a = b) c;
	//error decltype(a=b) is the type: int &
	//so it must be initialized
	
}

