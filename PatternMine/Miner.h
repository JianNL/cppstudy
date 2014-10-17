#ifndef MINER_H
#define MINER_H

#include <iostream>
#include <vector>

using namespace std;


class Miner
{
public:
	Miner() :_minerName("default"), IsOutputToScreen(true)
	{}
	Miner(const string &name) :_minerName(name), IsOutputToScreen(true)
	{}
	virtual void minePatternOnce(bool noOrderMode = false)
	{
	}
	virtual void minePatternLasting(bool noOrderMode = false)
	{}
	virtual void inputRawData(const vector<string> &input)
	{}
	virtual void inputRawData(const string &file)
	{}
	const string &getMinerName()
	{
		return this->_minerName;
	}
	void setIsOutputToScreen(bool b)
	{
		this->IsOutputToScreen = b;
	}
	bool IsOutputToScreen;
private:
	string _minerName;
		
};


#endif