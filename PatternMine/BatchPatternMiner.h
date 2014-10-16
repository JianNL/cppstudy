#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include "common.h"
#include "Miner.h"

using namespace std;




class BatchPatternMiner:public Miner
{
public:
	struct table
	{
	public:
		table() :count(0), data(vector<vector<int> >(INT_BATCH))
		{
		}
		int count;
		vector<vector<int> > data;
	};
	typedef map<char, table> MMap;

	struct currentCharInfo
	{
	public:
		currentCharInfo() :currentChar(0), usedNum(0), masks(vector<bool>(INT_BATCH,true))
		{
		}
		char currentChar;
		int usedNum;
		vector<bool> masks;
	};
	
	BatchPatternMiner() :Miner(),IsOutputToScreen(true)
	{
	}

	void minePatternOnce(bool noOrderMode=false);
	void minePatternLasting(bool noOrderMode = false);
	void inputRawData(const vector<string> &input);
	void inputRawData(const string &file);
	void setIsOutputToScreen(bool b)
	{
		this->IsOutputToScreen = b;
	}
	void reset();

	
private:
	
	bool IsOutputToScreen;
	vector<string> _batchInput;

	queue<vector<string> > _bufferInput;
	
	MMap _inMap;

	void getPattern(string prefix, vector<int> positions);
	void getPatterNoOrder(string prefix, currentCharInfo info);

	void processResult(const string &result);
	void preProcessRawData();

	map<char, vector<int> > getAllNext(vector<int> positions);
	map<char, currentCharInfo> getAllNextNoOrder(currentCharInfo info);

	bool getInputFromDatasource();

};
