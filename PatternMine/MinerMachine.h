#ifndef MINERMACHINE_H
#define MINERMACHINE_H
#include <thread>
#include "BatchPatternMiner.h"
#include "buffer.h"
#include "datasource.h"



class MinerMachine
{
public:
	MinerMachine() :name("default")
	{
		cout << name << "start" << endl;
	}
	MinerMachine(const string &argname) :name(argname)
	{
		cout << name << "start" << endl;
	}
	void registWithMiner(Miner *miner);
	void bindDataSource(DataSource *ds);
	void startWork();
	void waitToFinish();
private:
	string name;
	void connectDataSource();
	buffer _buffer;
	DataSource * _dataSources;
	vector<Miner *> _miners;
	vector<thread *> _minerThreads;
	vector<thread *> _dataThreads;

};


#endif