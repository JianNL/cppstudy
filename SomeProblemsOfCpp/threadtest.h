#include <thread>
#include <iostream>


using namespace std;

void hello()
{
	cout << "thread from hello" << endl;
	cout << "tid is " << this_thread::get_id() << endl;
	int i=20000;
	while (i>10000)
	{
		cout << i << endl;
		i--;
	}

}

void testOfThread()
{
	thread t1(hello);
	thread t2([](){
		int i = 10000;
		while (i--)
		{
			cout << i << endl;
		}
	});
	cout << "main thread" << endl;
}
