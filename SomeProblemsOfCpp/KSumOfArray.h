#include <iostream>
#include <vector>

using namespace std;

void KSumOfArray(bool *map, int len, int k, int sum, int current)
{
	if (k>=len)
	{
		return;
	}
	if (current==sum)
	{
		for (int i = 0; i != len; ++i)
		{
			if (map[i])
			{
				cout << (i + 1) << " ";
			}
		}
		cout << endl;
		return;
	}
	if (current<sum)
	{
		map[k] = true;
		KSumOfArray(map, len, k + 1, sum, current + k + 1);
		map[k] = false;
		KSumOfArray(map, len, k + 1, sum, current);
	}
}

vector<int> vec;
void KSumOfArray(int sum, int n)
{
	if (sum<=0||n<=0)
	{
		return;
	}
	if (sum==n)
	{
		for (auto e:vec)
		{
			cout << e << " ";
		}
		cout << n << endl;
	}
	vec.push_back(n);
	KSumOfArray(sum - n, n - 1);
	vec.pop_back();
	KSumOfArray(sum, n - 1);
}

vector<int> data = { 5, 2, 1, 2, 3, 2, 6, 5, 4 };
void KSumOfArray_C(int sum, int n)
{
	if (sum < 0 || n >= data.size())
	{
		return;
	}
	if (sum==data[n])
	{
		for (auto e:vec)
		{
			cout << e << " ";
		}
		cout << data[n] << endl;
		return;
	}
	vec.push_back(data[n]);
	KSumOfArray_C(sum - data[n], n + 1);
	vec.pop_back();
	KSumOfArray_C(sum, n + 1);

}

void testKSumOfArray()
{
	bool map[10] = { false };
	KSumOfArray(map, 10, 0, 20, 0);
	cout << "-------------------------------------------" << endl;
	KSumOfArray(20, 9);
	//KSumOfArray_C(15, 0);
}