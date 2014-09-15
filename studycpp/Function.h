#include <iostream>

using namespace std;



void useOfinitializer_list(initializer_list<string> l)
{
	cout << "useOfinitializer_list" << endl;
	for (auto beg = l.begin(); beg != l.end();beg++)
	{
		cout << *beg << endl;
	}
}