#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define UNUSE -2
#define INT_BATCH 4
#define INT_SUPPORTRATE INT_BATCH/2



class BatchPatternMiner
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

	void minePattern(bool noOrderMode=false);
	void getInput(const vector<string> &input);
	void getInput(const string &file);

	
private:
	

	vector<string> _batchInput;
	MMap _inMap;

	void getPattern(const MMap &inMap,string prefix, vector<int> positions);
	void getPatterNoOrder(const MMap &inMap, string prefix, currentCharInfo info);

	void processResult(string result);
	MMap preProcessRawData(const vector<string> &input);
	map<char, vector<int> > getAllNext(const MMap &inMap, vector<int> positions);
	map<char, currentCharInfo> getAllNextNoOrder(const MMap &inMap, currentCharInfo info);
};
