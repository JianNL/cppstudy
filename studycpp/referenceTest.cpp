#include <iostream>
#include "stringStudy.h"
#include "vectorStudy.h"
#include "securityFun.h"
#include "useOfArray.h"
//header shouldnot include using declaration
using namespace std;



/*
typedef的使用
*/
typedef double wage;
typedef wage base, *p;//base is double p is *double;
using type_double = double;//type_double is double

int global_i = 1;


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
	for which decltype returns a reference.As we’ve seen, when we dereference a
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


int main()
{
	const int &n1 = 1;
	const auto &n2 = 1;
	int &&n = 1;
	//int &n = 1;
	int i = 1;
	// reference must be initialized
	//int &rr;
	int &r = i;
	int *p1 = &i;
	cout << *p1 << endl;
	int *p2 = &r;
	cout << *p2 << endl;
	cout << &i << " " << p1 << " " << &r << endl;
	//int &r1 = 3;
	/*
	vs2013中不支持 constexpr
	详情参阅
	http://msdn.microsoft.com/en-us/library/vstudio/hh567368.aspx
	*/
	//constexpr int conexpr = 2;
	//constexpr int *const_p = &global_i;// constexpr如果修饰的是指针则指针本身的地址为const，注意右值的地址必须为fixed。
	//const int *p = nullptr;// p is a pointer to a const int
	//constexpr int *q = nullptr; // q is a const pointer to int

	//int null = 0, *p_null = null;
	cout << "testReference!" << endl;



	/*
	string test!
	*/
	//sizeAndLength();
	//NormalUseOfString();
	//UseOfGetLine();
	//newFor();
	useOfc_strString();
	/*
	string test!
	*/



	/*
	vector test!
	*/
	//normaluseOfVector();
	
	/*
	vector test!
	*/


	/*
	security function
	*/
	//cout << "use of strcpy_s()" << endl;
	//useOfstrcpy_s();
	/*
	security function
	*/

	/*
	array
	*/
	//cout << "test array" << endl;
	//copyOrAssignmentOfArray();
	//beginAndendFunc();
	/*
	array
	*/



	auto f = [](){cout << "this is fun" << endl;  };//lambda
	f();
	int wait;
	cout << "input any key to exit!" << endl;
	cin >> wait;
	return 0;
}