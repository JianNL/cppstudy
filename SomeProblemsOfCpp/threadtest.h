#include <thread>
#include <iostream>


using namespace std;

void hello()
{
	cout << "thread from hello" << endl;
	cout << "tid is " << this_thread::get_id() << endl;
	int i;
	cin >> i;
}

void testOfThread()
{
	thread t1(hello);
	t1.detach();
	cout << "main thread" << endl;
}
