#include <iostream>
#include <vector>


using namespace std;


void testOfSwap()
{
	cout << "testOfSwap" << endl;
	vector<int> v1 = { 1, 2, 3, 4 };
	vector<int> v2 = { 5, 6, 7, 9 };
	cout << "before" << endl;
	cout << "v1" << " : ";
	for (auto e:v1)
	{
		cout << e;
	}
	cout << endl;
	cout << "v2" << " : ";
	for (auto e:v2)
	{
		cout << e;
	}
	cout << endl;
	v1.swap(v2);
	v2.clear();
	cout << "after" << endl;
	cout << "v1" << " : ";
	for (auto e:v1)
	{
		cout << e;
	}
	cout << endl;
	cout << "v2" << " : ";
	for (auto e:v2)
	{
		cout << e;
	}
	cout << endl;


}
