#include <iostream>

using namespace std;


struct data
{
	char ch1 = '1';
	int i = 4;
	char ch = '1';
	int j = 56;
};

void testSize()
{
	cout << "memoryAlign" << " " << "testSize" << endl;
	cout << sizeof(data) << endl;
}


void testMemoryPos()
{
	cout << "memoryAlign" << " " << "testMemoryPos" << endl;
	data d1;
	d1.i = 5;
	d1.ch = 'a';
	cout << &d1 << endl;
	cout << "the pos of i is " << (int)&(d1.i) << endl;
	cout << "the pos of ch is " << (int)&(d1.ch) << endl;
	cout << "the pos of j is" << (int)&(d1.j) << endl;

}