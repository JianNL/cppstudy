#include <iostream>


using namespace std;



void normalUseOfArray()
{
	/*
	When we define an array, we must specify a type for the array. We cannot use
	auto to deduce the type from a list of initializers. As with vector, arrays hold
	objects. Thus, there are no arrays of references.
	*/
	//int &r[];
	int a[3] = { 1, 2 };
	/*
	If the dimension is greater than the number
	of initializers, the initializers are used for the first elements and any remaining
	elements are value initialized
	*/



	//int a1[3] = { 1, 2, 3, 4 };//error


	int ia[] = { 1, 2, 3, 4 };
	/*
	when we use an array
	as an initializer for a variable defined using auto (§ 2.5.2, p. 68), the deduced type
	is a pointer, not an array
	*/
	auto ia2(ia);//ia2 is an int* that points to the first element in ia
	//auto ia2(&ia[0]);// now it’s clear that ia2 has type int*
	/*
	It is worth noting that this conversion does not happen when we use decltype
	. The type returned by decltype(ia) is array of ten ints
	*/
	// ia3 is an array of ten ints
	//decltype(ia) ia3 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	/*
	We can take the address of the nonexistent element one past
	the last element of an array:
	*/
	//int *e = &ia3[10];
	/*
	The only thing we can
	do with this element is take its address, which we do to initialize e. Like an off-the-
	end iterator , an off-the-end pointer does not point to an element.
	As a result, we may not dereference or increment an off-the-end pointer.
	*/

	int a3[] = { 1, 2, 3 };
	int *p3 = a3;
	decltype(a3) *a4 = &a3;//!!!!这语法

	int *p1 = a3 + 3;
	int *p2 = a3 + 4;
	int *p4 = a3 + 5;


}


void useOfCharacterArray()
{
	char a1[] = { 'c', '+', '+' };//no null
	char a2[] = { 'c', '+', '+', '\0' };//explicit null
	char a3[] = "c++";//null terminator added auto
	
	//const char a4[5] = "hello";
	//error no space for the null
}


void copyOrAssignmentOfArray()
{
	cout << "copyOrAssignmentOfArray" << endl;
	int a[3] = { 1, 2, 3 };
	//a is a pointer bu it can not be modified
	cout << a << endl;

	cout << *a << *(a + 1) << endl;

	int (*parray)[3] = &a;//注意有个&
	cout << "&a is " << a << " " << a + 1 << endl;
	cout <<"parray is "<< parray << " "<<parray+1<<endl;
	

	//int a2[] = a;
	//a2 = a;
}


void beginAndendFunc()
{
	int ia[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *beg = begin(ia);
	int *last = end(ia);
	/*
	begin returns a pointer to the first, and end returns a pointer one past the last
	element in the given array: These functions are defined in the iterator header.
	*/
	cout << *beg << *(last-1)<< endl;
}



void useOfMultidimensionalArray()
{
	int ia[3][4] = { { 1, 2, 3, 4 }, { 1, 2, 3, 4 }, { 1, 2, 3, 4 } };
	/*
	To use a multidimensional array in a range for, the loop control vari-
	able for all but the innermost array must be references.
	*/
	for (const auto &row:ia)
	{
		for (auto col:row)
		{
			cout << col << " ";
		}
		cout << endl;
	}
}