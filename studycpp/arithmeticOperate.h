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
	1������(two's complement) 1���ڼ����ϵͳ�У���ֵһ���ò�������ʾ���洢���� ��Ҫԭ��ʹ�ò��룬���Խ�����λ������λͳһ����ͬʱ������Ҳ�ɰ��ӷ����������⣬�����ò� ���ʾ�������ʱ��������λ������λ���н�λ�����λ�������� 2��������ԭ���ת�����̼�������ͬ�ġ�

	2��ԭ���벹���ת�����ǣ���1�������Ĳ����ԭ����ͬ����2�������Ĳ����Ǳ�������λ������ȡ�����ټ�1��(�������Ϊ�����ֵ�Ĳ��룬��λȡ�����ټ�1) ��3������Ĳ������ԭ�롣

	3��-32768�Ĳ���Ϊ1000,0000,0000,0000������������Ĳ������㣬ת��ΪԴ��Ϊ��0000,0000,0000,0000����ʵ��0������Ϊ+0��-0�Ĳ��붼��0000,0000,0000,0000���Ͷ����һ�����룬��Ϊ�涨1000,0000,0000,0000Ϊ-32768.
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