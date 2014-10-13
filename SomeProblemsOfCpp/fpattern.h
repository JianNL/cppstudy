#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define UNUSE -2
#define INT_BATCH 4
#define INT_SUPPORTRATE INT_BATCH/2

struct table
{
public:
	table()
	{
		count = 0;
		data = vector<vector<int> >(INT_BATCH);
	}
	int count;
	vector<vector<int> > data;
};
typedef map<char, table> MMap;



const MMap preProcessRawData(const vector<string> &input)
{
	MMap result;
	if (input.size()!=INT_BATCH)
	{
		cout << "the input's " << endl;
		return result;
	}
	set<char> lineSet;
	int tid = 0;
	int pos = 0;
	for (auto &line:input)
	{
		if (line.length()==0)
		{
			cout << "occur a empty input line" << endl;
		}
		pos = 0;
		for (auto &c:line)
		{
			if (!lineSet.count(c))
			{
				lineSet.insert(c);
				result[c].count++;
			}
			result[c].data[tid].push_back(pos);
			pos++;
		}
		lineSet.clear();
		tid++;
	}
	for (auto iter = result.begin(); iter != result.end();)
	{
		if (iter->second.count<INT_SUPPORTRATE)
		{
			result.erase(iter++);
		}
		else
		{
			iter++;
		}
	}
	return result;
}


map<char,vector<int> > getAllNext(const MMap &inMap,vector<int> positions)
{
	map<char, vector<int>> result;
	int count = 0;
	for (auto iter = inMap.begin(); iter != inMap.end();++iter)
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

struct currentCharInfo
{
public:
	currentCharInfo()
	{
		currentChar = 0;
		usedNum = 0;
		for (int i = 0; i != 4;++i)
		{
			masks.push_back(true);
		}
	}
	char currentChar;
	int usedNum;
	vector<bool> masks;
};

map<char,currentCharInfo> getAllNextNoOrder(const MMap &inMap,currentCharInfo info)
{
	int count = 0;
	map<char, currentCharInfo> result;
	for (auto iter = inMap.begin(); iter != inMap.end();++iter)
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

void processResult(string result)
{
	cout << result << endl;
	//other sth
}

void getPattern(const MMap &inMap,string prefix, vector<int> positions)
{
	auto allNexts = getAllNext(inMap, positions);
	if (allNexts.size() == 0)
	{
		return;
	}
	else
	{
		for (auto iter = allNexts.begin(); iter != allNexts.end(); ++iter)
		{
			processResult(prefix + (iter->first));
			getPattern(inMap, prefix + (iter->first), iter->second);
		}
	}
}


void getPatterNoOrder(const MMap &inMap, string prefix, currentCharInfo info)
{
	auto allNexts = getAllNextNoOrder(inMap, info);
	if (allNexts.size()==0)
	{
		return;
	}
	else
	{
		for (auto iter = allNexts.begin(); iter != allNexts.end();++iter)
		{
			processResult(prefix + (iter->first));
			getPatterNoOrder(inMap, prefix + (iter->first), iter->second);
		}
	}
}

void Pattern(vector<string> input,bool noOrderMode=false)
{
	MMap inMap = preProcessRawData(input);
	if (inMap.size() == 0)
	{
		cout << "no result" << endl;
	}
	if (noOrderMode)
	{
		currentCharInfo info;
		info.currentChar = 'a' - 1;
		getPatterNoOrder(inMap, "", info);
	}
	else
	{
		getPattern(inMap, "", { -1, -1, -1, -1});
	}

	
}

/*
	abacc	a:0,2
	bacac	  1,3
	cabca	  1,4
	bcaab	  2,3
*/
void testFPattern()
{
	vector<string> input = { "abacce", "bafcac", "cgabca", "hbcaab" };
	vector<string> inputC = { "asakdlfjoasidfoasd", "qoofuopaisdasdnfl", "oisdfpodfpoasidfo", "aopsosidaupoisda" };
	vector<string> input1 = { "abac", "abcac", "babac", "abacc" };
	vector<string> input2 = { "abc", "bac", "cab", "aab" };
	vector<string> input3(input2);
	for (auto e : input1)
	{
		input2.push_back(e);
	}
	//MMap inMap = preProcessRawData(v);
	//map<char, vector<int>> re = getAllNext(inMap, { -1, -1, -1, -1 });
	//Pattern(input2);
	{
		//test No Order
		MMap inMap = preProcessRawData(input3);
		map<char, vector<int>> re = getAllNext(inMap, { -1, -1, -1, -1 });
		currentCharInfo info;
		info.currentChar = 'a' - 1;
		map<char, currentCharInfo> re1 = getAllNextNoOrder(inMap, info);
		Pattern(inputC, true);






	}
}

