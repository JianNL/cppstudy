#include <iostream>

using namespace std;



void useOfconst_cast()
{
	cout << "useOfconst_cast" << endl;
	const char *str = "helloworld";
	cout << "str is" << " " << str << endl;
	char *casted = const_cast<char *>(str);
	cout << "casted is " << casted << endl;
	//casted[0] = '1';//windows��vs����ʱ����
	cout << "after change casted[0] " << "," << "casted is " << casted << endl;
	//int a = ('fdfdf', 2);//error 
	int a = (1, 2);
	int b = { (1,2,3) };

	cout << a << endl;
	
}


void useOfNullStatement()
{
	cout << "useOfNullStatement" << endl;
	string s;
	cout << "please input the string ,the loop will end until you input the 'hello'" << endl;
	while (cin >> s&&s != "hello");
	/*
	����Ӹ�{}Ҳ���ԡ�
	*/
	cout << "end" << endl;
}

