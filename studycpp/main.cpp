#include <iostream>
#include "stringStudy.h"
#include "vectorStudy.h"
#include "securityFun.h"
#include "useOfArray.h"
#include "referenceTest.h"
//header shouldnot include using declaration
using namespace std;



/*
typedef��ʹ��
*/
typedef double wage;
typedef wage base, *p;//base is double p is *double;
using type_double = double;//type_double is double

int global_i = 1;

















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
	vs2013�в�֧�� constexpr
	�������
	http://msdn.microsoft.com/en-us/library/vstudio/hh567368.aspx
	*/
	//constexpr int conexpr = 2;
	//constexpr int *const_p = &global_i;// constexpr������ε���ָ����ָ�뱾��ĵ�ַΪconst��ע����ֵ�ĵ�ַ����Ϊfixed��
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
	//useOfc_strString();
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