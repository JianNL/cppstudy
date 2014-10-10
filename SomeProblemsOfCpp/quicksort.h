#include <iostream>


using namespace std;

int quicksort(int *data, int begin, int end)
{
	if (begin>=end)
	{
		return begin;
	}
	int p = data[begin];
	int last_small = begin;
	int e = end;
	while (last_small<e)
	{
		if (data[e] <= p)
		{
			last_small++;
			int temp = data[e];
			data[e] = data[last_small];
			data[last_small] = temp;
		}
		else
			e--;
	}
	int temp = data[last_small];
	data[last_small] = p;
	data[begin] = temp;
	quicksort(data, begin, last_small - 1);
	quicksort(data, last_small + 1, end);
	return last_small;
}


void quicksort_2(int *data, int begin, int end)
{
	if (begin>=end)
	{
		return;
	}
	int last_small = begin - 1;
	int p = data[end];
	int i = begin;
	for (; i <= end - 1;++i)
	{
		if (data[i] <= p)
		{
			last_small++;
			int temp = data[last_small];
			data[last_small] = data[i];
			data[i] = temp;
		}
	}
	int temp = data[last_small + 1];
	data[last_small+1] = p;
	data[end] = temp;
	quicksort_2(data, begin, last_small );
	quicksort_2(data, last_small + 2, end);
}


void testQuicksort()
{
	int data[9] = { 5, 1, 3, 6, 3, 2, 6, 8, 4 };
	int data1[23] = { 2, 3, 2, 6, 4, 6, 4, 5, 6, 7, 3, 78, 5, 43, 32, 45, 665, 33, 567, 32, 2, 566, 98 };
	vector<int> v2 = { 5, 1, 3, 6, 3, 2, 6, 8, 4 };
	quicksort_2(data1, 0, 22);
	for (int i = 0; i !=23;++i)
	{
		cout << data1[i] << " ";
	}
	cout << endl;
}
