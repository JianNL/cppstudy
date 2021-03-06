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


void mixString()
{
	/*
	When we mix strings and string or character literals, at least one operand to each
	+ operator must be of string type:
	*/
	string s1 = "hello";
	string s4 = s1 + ", ";// ok: adding a string and a literal
	//string s5 = "hello" + ", ";// error: no string operand
	string s6 = s1 + ", " + "world"; // ok: each + has a string operand
	//string s7 = "hello" + ", " + s2; // error: can��t add string literals

}


void newFor()
{

	string str("hello world!");
	for (auto c : str)
	{
		cout << c << endl;
	}
	for (auto &c : str)
	{
		c = toupper(c);
	}
	cout << str << endl;
}


void SubscriptOfString()
{
	string str = "helloworld";
	cout << str[0] << endl;
	str[1] = '1';//the subscript operator return a reference
}




void useOfc_strString()
{
	/*
	The array returned by c_str is not guaranteed to be valid indefinitely. Any
	subsequent use of s that might change the value of s can invalidate this array.
	*/
	cout << "useOfc_strString" << endl;
	string str("helloworld");
	const char *cstr = str.c_str();
	cout << "const char *cstr" << " " << cstr << endl;
	str[0] = '0';
	cout << "after is" << endl;
	cout << cstr << endl;

}
