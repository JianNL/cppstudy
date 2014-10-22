#include <iostream>
#include <vector>

using namespace std;

void getLis(int *arr, int size)
{
	int *len = new int[size];
	for (int i = 0; i != size;++i)
	{
		len[i] = 1;
	}
	if (size==0)
	{
		return;
	}
	len[0] = 1;
	for (int i = 0; i != size;++i)
	{
		for (int j = 0; j != i;++j)
		{
			if (arr[i]>=arr[j])
			{
				len[i] = (len[j] + 1 > len[i] ? len[j] + 1 : len[i]);
			}
			else
			{
				if (len[i]!=1)
				{
					continue;
				}
				else
					len[i] = 1;
			}
		}
	}
	int max = 0;
	int maxpos = 0;
	for (int i = 0; i != size;++i)
	{
		if (len[i]>max)
		{
			max = len[i];
			maxpos = i;
		}
	}
	cout << "max is " << max <<" "<<maxpos<< endl;
	delete len;
}

void testOfLis()
{
	cout << "testLis" << endl;
	int input[11] = { 3, 12, 1, 4, 3, 7, 5, 6, 2, 8, 9 };
	getLis(input, 11);
}