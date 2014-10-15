#include "pattern.h"

void BatchPatternMiner::preProcessRawData()
{
	if (_batchInput.size()!=INT_BATCH)
	{
		cout << "the input's " << endl;
	}
	set<char> lineSet;
	int tid = 0;
	int pos = 0;
	for (const auto &line:_batchInput)
	{
		if (line.length()==0)
		{
			cout << "occur a empty input line" << endl;
		}
		pos = 0;
		for (const auto &c:line)
		{
			if (!lineSet.count(c))
			{
				lineSet.insert(c);
				_inMap[c].count++;
			}
			_inMap[c].data[tid].push_back(pos);
			pos++;
		}
		lineSet.clear();
		tid++;
	}
	for (auto iter = _inMap.begin(); iter != _inMap.end();)
	{
		if (iter->second.count<INT_SUPPORTRATE)
		{
			_inMap.erase(iter++);
		}
		else
		{
			iter++;
		}
	}
}




map<char,vector<int> > BatchPatternMiner::getAllNext(vector<int> positions)
{
	map<char, vector<int>> result;
	int count = 0;
	for (auto iter = _inMap.begin(); iter != _inMap.end();++iter)
	{
		vector<int> re_positions(positions);
		count = 0;
		for (int i = 0; i != INT_BATCH;++i)
		{
			if (re_positions[i] == UNUSE)
			{
				continue;
			}
			for (auto e:iter->second.data[i])//
			{
				if (e>re_positions[i])
				{
					re_positions[i] = e;
					count++;
					break;
				}
			}
			if (positions[i] == re_positions[i])
			{
				re_positions[i] = UNUSE;
			}
		}
		if (count>=INT_SUPPORTRATE)
		{
			result[iter->first] = re_positions;
		}
	}
	return result;
}





map<char, BatchPatternMiner::currentCharInfo> BatchPatternMiner::getAllNextNoOrder(currentCharInfo info)
{
	int count = 0;
	map<char, currentCharInfo> result;
	for (auto iter = _inMap.begin(); iter != _inMap.end();++iter)
	{
		currentCharInfo newinfo = info;
		if (iter->first==info.currentChar)
		{
			for (int tid = 0; tid != INT_BATCH;++tid)
			{
				if (info.masks[tid]==false)
				{
					continue;
				}
				if (iter->second.data[tid].size() < info.usedNum + 1)
				{
					newinfo.masks[tid] = false;
					continue;
				}
				else
				{
					count++;
				}
			}
			if (count>=INT_SUPPORTRATE)
			{
				newinfo.usedNum++;
				result[iter->first] = newinfo;
			}
		}
		if (iter->first>info.currentChar)
		{
			for (int tid = 0; tid != INT_BATCH;++tid)
			{
				if (iter->second.data[tid].size()>0)
				{
					count++;
				}
				else
				{
					newinfo.masks[tid] = false;
				}
			}
			if (count>=INT_SUPPORTRATE)
			{
				newinfo.currentChar = iter->first;
				newinfo.usedNum = 1;
				result[iter->first] = newinfo;
			}
		}
	}
	return result;
	
}


void BatchPatternMiner::processResult(const string& result)
{
	if (IsOutputToScreen)
	{
		cout << result << endl;
	}
}



void BatchPatternMiner::getPattern(string prefix, vector<int> positions)
{
	auto allNexts = getAllNext(positions);
	if (allNexts.size() == 0)
	{
		return;
	}
	else
	{
		for (auto iter = allNexts.begin(); iter != allNexts.end(); ++iter)
		{
			processResult(prefix + (iter->first));
			getPattern(prefix + (iter->first), iter->second);
		}
	}
}



void BatchPatternMiner::getPatterNoOrder(string prefix, currentCharInfo info)
{
	auto allNexts = getAllNextNoOrder(info);
	if (allNexts.size()==0)
	{
		return;
	}
	else
	{
		for (auto iter = allNexts.begin(); iter != allNexts.end();++iter)
		{
			processResult(prefix + (iter->first));
			getPatterNoOrder(prefix + (iter->first), iter->second);
		}
	}
}


void BatchPatternMiner::minePatternOnce(bool noOrderMode)
{
	preProcessRawData();
	if (_inMap.size() == 0)
	{
		cout << "no result" << endl;
	}
	if (noOrderMode)
	{
		currentCharInfo info;
		info.currentChar = 'a' - 1;
		getPatterNoOrder( "", info);
	}
	else
	{
		getPattern( "", vector<int>(INT_BATCH,-1));
	}
}


void BatchPatternMiner::minePatternLasting(bool noOrderMode)
{
	int count = 0;
	while (!_bufferInput.empty())
	{
		this->_batchInput = std::move(this->_bufferInput.front());
		//this->_batchInput = this->_bufferInput.front();
		cout << "mining " << ++count << " batch number" << endl;
		this->minePatternOnce();
		this->_bufferInput.pop();
		this->reset();
	}
}


void BatchPatternMiner::inputRawData(const vector<string> &input)
{
	if (input.size()!=INT_BATCH)
	{
		cout << "input raw data size error" << endl;
		exit(0);
	}
	this->_batchInput = input;
}


void BatchPatternMiner::inputRawData(const string &file)
{
	ifstream infile(file.c_str());
	if (!infile)
	{
		cout << "open file " << file << " error" << endl;
		infile.close();
		exit(0);
	}
	string temp;
	while (getline(infile,temp))
	{
		this->_batchInput.push_back(temp);
		if (_batchInput.size()==INT_BATCH)
		{
			this->_bufferInput.push(_batchInput);
			this->_batchInput.clear();
		}
	}
	infile.close();
	this->_batchInput.clear();
	/*
	if (_batchInput.size()!=INT_BATCH)
	{
		cout << "input raw data size error" << endl;
		exit(0);
	}
	*/


}

void BatchPatternMiner::reset()
{
	this->_batchInput.clear();
	this->_inMap.clear();
}