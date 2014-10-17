#include "MinerMachine.h"


void MinerMachine::registWithMiner(Miner *miner)
{
	this->_miners.push_back(miner);
}


void MinerMachine::startWork()
{
	if (_miners.size()==0)
	{
		cout << "no miner" << endl;
		exit(0);
	}
	if (_dataSources==nullptr)
	{
		cout << "no datasource" << endl;
		exit(0);
	}
	connectDataSource();
	for (auto iter = _miners.begin(); iter != _miners.end();++iter)
	{

		thread t([&](){
			cout << (*iter)->getMinerName() << " working" << endl;
			while (1)
			{
				vector<string> batchInput = _buffer.pop();
				if (batchInput.size()!=INT_BATCH)
				{
					break;
				}
				(*iter)->inputRawData(batchInput);
				(*iter)->minePatternOnce();
			}
			cout << (*iter)->getMinerName() << " finish" << endl;
		});
		_minerThreads.push_back(&t);
	}
		


}


void MinerMachine::bindDataSource(DataSource *ds)
{
	_dataSources=ds;
}


void MinerMachine::connectDataSource()
{
	if (_dataSources==nullptr)
	{
		cout << "no datasourc" << endl;
		exit(0);
	}
	thread t([&](){
		while (1)
		{
			vector<string> temp = _dataSources->getBatchInput();
			if (temp.size()!=INT_BATCH)
			{
				break;
			}
			else
			{
				_buffer.push(temp);
			}
		}
	});
	this->_dataThreads.push_back(&t);
}



void MinerMachine::waitToFinish()
{
	for (auto t:_dataThreads)
	{
		t->join();
	}
	for (auto t:_minerThreads)
	{
		t->join();
	}
}