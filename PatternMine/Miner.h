#ifndef MINER_H
#define MINER_H

#include <iostream>
#include <vector>

using namespace std;


class Miner
{
public:
	virtual void minePatternOnce(bool noOrderMode = false)
	{
	}
	virtual void minePatternLasting(bool noOrderMode = false)
	{}
	virtual void inputRawData(const vector<string> &input)
	{}
	virtual void inputRawData(const string &file)
	{}
	virtual void setIsOutputToScreen(bool b)
	{}
private:
		

};


#endif