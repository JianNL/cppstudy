#include <iostream>


using namespace std;

void useOfswitch()
{
	int i = 2;
	cout << "useOfswitch" << endl;
	cout << "please input the i" << endl;
	switch (i)
	{
	case 1:
		//string str;
		//str = "ffff";
		//cout << str << endl;

		/*
		If we need to define and initialize a variable for a particular case, we can do
		so by defining the variable inside a block, thereby ensuring that the variable is out
		of scope at the point of any subsequent label.
		*/
		int j;
		{
			string str;
		}

		break;
	case 2:
		cout << "test!" << endl;
		break;
	default:
		j = 2;
		cout << j << endl;
		break;
	}
}

void useOfElseif()
{
	cout << "test useOfElseif" << endl;
	if (true)
	{
		cout << "if" << endl;
	}
	else if (true)
	{
		cout << "else if" << endl;
	}
	else
	{
		cout << "else" << endl;
	}

}