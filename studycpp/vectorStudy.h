#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void VectorOfVector()
{
	vector<vector<int> > vecofvec;//注意有个空格。
	
}

void initializeOfVector()
{
	vector<int> vec;
	vector<int> vec1 = { 0 };
}

void normaluseOfVector()
{
	vector<int> vec;
	vec.push_back(12);
	cout << vec[0] << endl;
	vec[0] = 1;
	cout << vec[0] << endl;
	vector<int> v1{ 10, 2, 3 };
	v1.resize(9);
	cout << "vector.resize()" << endl;
	for (auto &c : v1)
	{
		cout << c << endl;
		c = 1;
	}
	for (auto c:v1)
	{
		cout << c << endl;
	}
}

void useOfremove_if()
{
	cout << "useOfremove_if" << endl;
	vector<int> v1 = { 1, 2, 3, 2, 1, 2 };
	vector<int> v2 = { 12, 3, 2, 1, 4, 55, 22, 211 };
	vector<int> v3 = { 3423, 123123, 12312, 2, 5 };
	vector<int> vec = { 1, 2, 3, 4, 52, 11, 2, 3, 2, 3 };
	auto p = remove_if(vec.begin(), vec.end(), [v1,v2](int n){
		if (find(v1.begin(),v1.end(),n)!=v1.end())
		{
			return true;
		}
		if (find(v2.begin(),v2.end(),n)!=v2.end())
		{
			return true;
		}
		return false;
	});
	for (auto i = vec.begin(); i != p;++i)
	{
		cout << *i << endl;
	}

}

