#include <iostream>
#include "stringStudy.h"
#include "vectorStudy.h"
#include "securityFun.h"
#include "useOfArray.h"
//#include "referenceTest.h"
#include "arithmeticOperate.h"
#include "TypeConversion.h"
#include "Function.h"
#include "sudoku.h"
#include "memoryAlign.h"
#include "AlgorithmOfSTL.h"





//header shouldnot include using declaration
using namespace std;

//The assert macro is often used to check for conditions that “cannot happen.”


/*
typedef的使用
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
	//useOfremove_if();
	initializeOfVector();

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



	/*
	arithmeticOperate
	*/
	//normalArithmetic();
	//wrappedaround();
	//useOfRelationalOperator();
	/*
	arithmeticOperate
	*/



	/*
	typeconversion
	*/
	//useOfconst_cast();
	//useOfNullStatement();

	/*
	typeconversion
	*/


	/*
	function
	*/
	//useOfinitializer_list({ "fsdfsfsdf", "sdfsdfsfddsf", "helloworld" });
	//vector<int> vec1 = { 1, 2, 3, 4, 5 };
	//useOfvectorPara(vec1);
	//for (auto e:vec1)
	//{
	//cout << e << endl;
	//}
	/*
	function
	*/

	/*
	sudoku
	*/
	/*
	vector<vector<int> > s = {
	{ 2, 7, 6, 0, 0, 0, 0, 8, 0 },
	{ 3, 0, 0, 8, 0, 0, 0, 1, 5 },
	{ 5, 0, 0, 2, 0, 9, 7, 0, 0 },
	{ 0, 8, 2, 3, 0, 0, 4, 0, 0 },
	{ 0, 0, 0, 0, 5, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 4, 3, 6, 0 },
	{ 0, 0, 4, 5, 0, 8, 0, 0, 7 },
	{ 1, 6, 0, 0, 0, 3, 0, 0, 4 },
	{ 0, 3, 0, 0, 0, 0, 5, 2, 1 }
	};
	*/
	vector<vector<int> > s1 = {
	{ 8, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 3, 6, 0, 0, 0, 0, 0 },
	{ 0, 7, 0, 0, 9, 0, 2, 0, 0 },
	{ 0, 5, 0, 0, 0, 7, 0, 0, 0 },
	{ 0, 0, 0, 0, 4, 5, 7, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 3, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 6, 8 },
	{ 0, 0, 8, 5, 0, 0, 0, 1, 0 },
	{ 0, 9, 0, 0, 0, 0, 4, 0, 0 }
	};
	//useOfcomplicatedVectorPara(s);
	//printOfcomplicatedVectorPara(s);
	//sudoku solution;
	//solution.printSolution(s);
	//solution.getSolution(s1);
	//cout << "the solution is" << endl;
	//solution.printSolution();

	/*
	memoryAlign
	*/
	//testMemoryPos();

	/*
	memoryAlign
	*/

	/*AlgorithmOfSTL*/
	testOfInsertIterator();



	auto f = [](){cout << "this is fun" << endl;  };//lambda
	f();
	int wait;
	cout << "input any key to exit!" << endl;
	cin >> wait;
	return 0;
}