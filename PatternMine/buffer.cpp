#include "buffer.h"


void buffer::push(vector<string> batchInput)
{
	unique_lock<mutex> lock(_mutex);
	_data.push(batchInput);
	cout << this_thread::get_id() << " thread push data " << endl;
	_condition.notify_one();
}


vector<string> buffer::pop()
{
	unique_lock<mutex> lock(_mutex);
	if (_data.empty())
	{
		auto re=_condition.wait_for(lock,chrono::seconds(3));
		if (re==cv_status::timeout)
		{
			return vector<string>();
		}

	}
	vector<string> result = move(_data.front());
	cout << this_thread::get_id() << " thread pop data" << endl;
	_data.pop();
	return result;
}

bool buffer::isEmpty()
{
	_mutex.lock();
	if (_data.empty())
	{
		_mutex.unlock();
		return true;
	}
	else
	{
		_mutex.unlock();
		return false;
	}
}


size_t buffer::getSize()
{
	_mutex.lock();
	size_t size = _data.size();
	_mutex.unlock();
	return size;
}