#include "defaultParameterInDerived.h"
#include "lcs.h"
#include "KSumOfArray.h"
#include "MaxContainArray.h"
#include "testOfSwap.h"
#include "quicksort.h"
#include <iostream>

using namespace std;

int main(char *argv[],int argc)
{
	cout << "some problems in cpp" << endl;
	//lcsTest();
	//testKSumOfArray();
	//testMaxSub();
	//testMaxContainArray();
	//testOfSwap();
	testQuicksort();
	cout << "please input any key to exit the test!" << endl;
	int i;
	cin >> i;
	return 0;
}