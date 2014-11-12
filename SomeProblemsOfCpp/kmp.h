#include <iostream>
#include <string>


using namespace std;


void getNexts(const string &p, int *next, int len)
{
	if (len == 0)
	{
		return;
	}
	next[0] = -1;
	int i = 0;
	int k = -1;
	for (; i != len;++i)
	{
		if (k==-1||p[i]==p[k])
		{
			k++;
			i++;
			next[i] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int kmpsearch(const string &str, const string &pattern, int *nexts)
{
	int lenStr = str.length();
	int lenPattern = pattern.length();
	int j = 0;
	int i = 0;
	while (i<lenStr&&j<lenPattern)
	{
		if (j==-1||str[i]==pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			j = nexts[j];
		}
	}
	if (j>=lenPattern)
	{
		return i - lenPattern;
	}

}

void testKMP()
{
	string str = "abcdeabacabdaefa";
	string pattern = "abac";
	int nexts[4] = { 0 };
	getNexts(pattern, nexts, 4);
	int re=kmpsearch(str, pattern, nexts);
	cout << " str is " << str << endl;
	cout << " pattern is " << pattern << endl;
	cout << " the result is " << re << endl;
}
