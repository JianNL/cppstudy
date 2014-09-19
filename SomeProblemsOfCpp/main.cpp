#include <iostream>
using namespace std;
class Base
{
public:
	Base()
	{}
	Base(bool arg)
	{
		foo();
	}
	virtual void foo(int i = 42)
	{
		cout << "base" << i << endl;
	}
};
class Derived :public Base
{
public:
	Derived(){}
	Derived(bool arg) :Base(arg)
	{
		foo();
	}
	virtual void foo(int i = 12)
	{
		cout << "derived" << i << endl;
	}
};
void test1()
{
	Derived d;
	Base &b1 = d;
	Base b2 = d;//�����������������¶����˼̳ж�����Ĭ�ϲ�����
	b1.foo();//����b1�Ķ�̬�󶨵�foo()������C++�У��麯���Ƕ�̬�󶨶��ڶ�̬���е�Ĭ�ϲ����Ǿ�̬�󶨵�Ҳ����˵�ǻ����Ĭ�ϲ���42.
	b2.foo();//����b2�ľ�̬�󶨵�foo������Ĭ�ϲ�����42 ���������base42

}
void test2()
{
	Base *b = new Derived(true);//�Ⱥ���û���̳���Ĺ��캯�����������������캯���ж����Ƕ�̬�����У����Զ���Ĭ��ʵ��
	delete b;
}
int main(int argc, char *argv[])
{
	test2();
	int i;
	cin >> i;
	return 0;
}