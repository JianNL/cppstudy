#include <cstring>
#include <iostream>

using namespace std;
void useOfstrcpy_s()
{
	char str[10];
	strcpy_s(str, 10, "hhelosd11");
	cout << str << endl;
}