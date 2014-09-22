#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void lcsWorstMethod(const char *str1, const char *str2)
{
	cout << "lcsWorstMethod" << endl;
	auto len1 = strlen(str1);
	auto len2 = strlen(str2);
	if (len1==0||len2==0)
	{
		cout << "lcs is " << "" << endl;
		return;
	}
	int max = 0;
	int m = 0;
	int n = 0;
	int len = 0;
	int starti = 0;
	int startj = 0;

	for (int i = 0; i != len1;++i)
	{
		for (int j = 0; j != len2;++j)
		{
			len = 0;
			m = i;
			n = j;
			while (str1[m]==str2[n])
			{
				++m;
				++n;
				++len;
			}
			if (len>max)
			{
				max = len;
				starti = i;
				startj = j;
			}
		}
	}
	cout << "the lcs is " << string(&str1[starti],&str1[starti+max]) << endl;
	
}


void lcsDynamicProgMethod(const char *str1, const char *str2)
{
	if (str1==str2)
	{
		cout << "str all the same" << endl;
		return;
	}
	auto len1 = strlen(str1);
	auto len2 = strlen(str2); 
	int pos = 0;
	int max = 0;
	vector<vector<int> > table(len1, vector<int>(len2, 0));
	if (len1==0||len2==0)
	{
		cout << "lcs is" << "" << endl;
		return;
	}
	for (int i = 0; i != len1;++i)
	{
		table[i][0] = (str1[i] == str2[0] ? 1 : 0);
		if (len2==1)
		{
			if (table[i][0]==1)
			{
				cout << "lcs is " << str1[i] << endl;
				return;
			}
		}
	}
	for (int i = 0; i != len2;++i)
	{
		table[0][i] = (str1[0] == str2[i] ? 1 : 0);
		if (len1==1)
		{
			if (table[0][i]==1)
			{
				cout << "lcs is " << str2[i] << endl;
				return;
			}
		}
	}
	
	for (int i = 1; i != len1; ++i)
	{
		for (int j = 1; j != len2;++j)
		{
			table[i][j] = (str1[i] == str2[j] ? table[i - 1][j - 1] + 1 : 0);
			if (table[i][j]>max)
			{
				max = table[i][j];
				pos = i;
			}
		}
	}
	cout << "lcs is " << string(&str1[pos- max], &str1[pos+1]) << endl;
}


string lcsRecursive(const char *str1, const char *str2, int i,int j)
{
	if (i>(strlen(str1)-1))
	{
		return "";
	}
	if (j>(strlen(str2)-1))
	{
		return "";
	}
	if (str1[i]==str2[j])
	{
		return str1[i] + lcsRecursive(str1, str2, i + 1, j + 1);
	}
	else
	{
		return "";
	}
}


void lcsTest()
{
	cout << "lcsTest" << endl;
	const char *str1 = "hello this is a test!";
	const char *str2 = "what are ello thxxx";
	const char *strEmpty = "";
	const char *len1Str1 = "1";
	const char *len1Str2 = "1";
	cout << "str1 is " << str1 << endl;
	cout << "str2 is " << str2 << endl;
	cout << "len1Str1 is " << len1Str1 << endl;
	cout << "len1Str2 is " << len1Str2 << endl;
	//lcsWorstMethod(str1, str2);
	//lcsDynamicProgMethod(str1, str2);
	lcsDynamicProgMethod(len1Str1, len1Str2);
	
}