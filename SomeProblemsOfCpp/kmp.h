#include <iostream>


using namespace std;


void getNextArrays(const char *str, int *t, int len)
{
	if (len==0)
	{
		return;
	}
	t[0] = -1;
	for (int i = 0; i != len;++i)
	{
		if (t[i-1]==-1)
		{
			t[i] = 0;
		}

	}
}