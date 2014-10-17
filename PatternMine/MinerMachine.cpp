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
	thread t_data([&](){
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
	vector<thread> minerThreads(_miners.size());
	int i = 0;
	for (auto iter = _miners.begin(); iter != _miners.end();++iter)
	{
		thread t([iter,this](){
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
		minerThreads[i] = move(t);
		i++;
		
	}

	t_data.join();
	for (auto &t:minerThreads)
	{
		t.join();
	}

}


void MinerMachine::bindDataSource(DataSource *ds)
{
	_dataSources=ds;
}





