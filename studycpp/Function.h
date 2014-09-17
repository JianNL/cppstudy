#include <iostream>

using namespace std;


//the main function cannot be overloaded ,recursived

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



vector<string> useOfReturnValueofListInitializing()
{
	cout << "useOfReturnValueofListInitializing" << endl;
	return{ "sfsdf", "sfdsdfa", "sdfadf" };
}



int (*funOfReturnPointertoArray(int i))[10]
{

}


//trailing return type
/*
A trailing return type follows the parameter list and is preceded
by ->. To signal that the return follows the parameter list, we use auto where the
return type ordinarily appears:
*/
auto func(int i) -> int(*)[10];//this is a function that return a pointer to array


//overloaded function
//It is an error for two functions to differ only in terms of their return types


/*
Local variables may not be used as a default argument. Excepting that restriction,
a default argument can be any expression that has a type that is convertible to the
type of the parameter
*/