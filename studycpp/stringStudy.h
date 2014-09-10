#include <string>
#include <iostream>

using namespace std;
void sizeAndLength()
{
	const char *str_const = "helloworld";
	std::cout << sizeof(str_const) << std::endl;
	std::cout << strlen(str_const) << std::endl;
	string str = "helloworld";
	cout << str.size() << endl;
	auto size = str.size();
	/*
	For example, if n is an int that holds a negative value, then s.size() < n will
	almost surely evaluate as true. It yields true because the negative value in n will
	convert to a large unsigned value.
	You can avoid problems due to conversion between unsigned and
	int by not using ints in expressions that use size().
	*/

}

void NormalUseOfString()
{
	string s;
	cout << "NormalUseOfString input string" << endl;
	cin >> s;
	cout << "the input is " << s << endl;
	cout << s[0] << endl;
	s[0] = '1';
	cout << s << endl;
}


void UseOfGetLine()
{
	string line;
	while (getline(cin,line))
	{
		//the line doesnot contain the newline(discard)
		cout << line << endl;
	}
}