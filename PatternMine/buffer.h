
#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

//thread safe buffer
class buffer
{
public:
	bool isEmpty();
	size_t getSize();
	void push(vector<string>);
	vector<string> pop();

private:
	queue<vector<string> > _data;
	mutex _mutex;
	condition_variable _condition;
};

#endif