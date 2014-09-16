#include <iostream>

using namespace std;



void useOfinitializer_list(initializer_list<string> l)
{
	cout << "useOfinitializer_list" << endl;
	for (auto beg = l.begin(); beg != l.end();beg++)
	{
		cout << *beg << endl;
	}
}


void useOfvectorPara(vector<int> vec)
{
	cout << "useOfvectorPara" << endl;
	for (auto c : vec)
	{
		cout << c << endl;
		c = 1;
	}
}


void useOfcomplicatedVectorPara(vector<vector<int> > comVec)
{
	cout << "useOfcomplicatedVectorPara" << endl;
	for (auto iter = comVec.begin(); iter != comVec.end();++iter)
	{
		for (auto iter_iner = (*iter).begin(); iter_iner != (*iter).end();++iter_iner)
		{
			*iter_iner = 1;
		}
	}
}


void printOfcomplicatedVectorPara(vector<vector<int> > comVec)
{
	cout << "printOfcomplicatedVectorPara" << endl;
	for (auto iter = comVec.begin(); iter != comVec.end();++iter)
	{
		for (auto iter_iner = (*iter).begin(); iter_iner != (*iter).end();++iter_iner)
		{
			cout << *iter_iner ;
		}
		cout << endl;
	}

}
