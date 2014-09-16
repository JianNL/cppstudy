#include <iostream>


using namespace std;




void normalArithmetic()
{
	cout << "normalArithmetic" << endl;
	int i = 4;
	cout << ((i / 3.0) * 3) << endl;
	cout << i / 3 * 3 << endl;
}


void wrappedaround()
{
	cout << "wrappedaround" << endl;
	short short_value = 32767;
	short_value++;
	cout << short_value << endl;
	/*
	1、补码(two's complement) 1、在计算机系统中，数值一律用补码来表示（存储）。 主要原因：使用补码，可以将符号位和其它位统一处理；同时，减法也可按加法来处理。另外，两个用补 码表示的数相加时，如果最高位（符号位）有进位，则进位被舍弃。 2、补码与原码的转换过程几乎是相同的。

	2、原码与补码的转换都是，（1）正数的补码和原码相同。（2）负数的补码是保留符号位，其余取反，再加1。(或者理解为其绝对值的补码，按位取反，再加1) （3）补码的补码就是原码。

	3、-32768的补码为1000,0000,0000,0000。如果按正常的补码运算，转换为源码为，0000,0000,0000,0000。其实是0，但因为+0和-0的补码都是0000,0000,0000,0000，就多出了一个补码，人为规定1000,0000,0000,0000为-32768.
	*/
}


void useOfRelationalOperator()
{
	/*
	The relational operators (<, <=, >, <=) have their ordinary meanings and return
	bool values. These operators are left associative.
	*/
	cout << "chain relational operator" << endl;
	int i = 1;
	int j = 3;
	int k = 2;
	if (i < j < k)//this condition compares k to the bool result of i < j
	{
		cout << "the result of chain relational operator error" << endl;
	}
}