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
	Base b2 = d;//这个程序的问题是重新定义了继承而来的默认参数。
	b1.foo();//调用b1的动态绑定的foo()，但在C++中，虚函数是动态绑定而在动态绑定中的默认参数是静态绑定的也就是说是基类的默认参数42.
	b2.foo();//调用b2的静态绑定的foo（），默认参数是42 所以输出是base42

}
void test2()
{
	Base *b = new Derived(true);//问题是不要在构造函数中中调用虚函数析构函数
	delete b;
}