#include <iostream>

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
	const pstring *ps;
}



int main()
{
	int i = 1;
	int &r = i;
	int *p1 = &i;
	cout << *p1 << endl;
	int *p2 = &r;
	cout << *p2 << endl;
	cout << &i << " " << p1 << " " << &r << endl;
	//int &r1 = 3;
	constexpr int *const_p = &global_i;// constexpr如果修饰的是指针则指针本身的地址为const，注意右值的地址必须为fixed。
	//int null = 0, *p_null = null;
	cout << "testReference!" << endl;
	auto f = [](){cout << "this is fun";  };
	f();
	int wait;
	cin >> wait;
}