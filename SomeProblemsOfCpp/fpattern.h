#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define UNUSE -2
#define BATCH

struct table
{
public:
	table()
	{
		count = 0;
		data = vector<vector<int> >(4);
	}
	int count;
	vector<vector<int> > data;
};
typedef map<char, table> MMap;

const MMap preProcessRawData(const vector<string> &input)
{
	MMap result;
	set<char> lineSet;
	int tid = 0;
	int pos = 0;
	for (auto &line:input)
	{
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
	for (auto iter = result.begin(); iter != result.end();++iter)
	{
		if (iter->second.count<2)
		{
			result.erase(iter);
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
		for (int i = 0; i != 4;++i)
		{
			if (re_positions[i] == UNUSE)
			{
				continue;
			}
			for (auto e:iter->second.data[i])
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
		if (count>=2)
		{
			result[iter->first] = re_positions;
		}
	}
	return result;
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
			cout << prefix + (iter->first) << endl;
			getPattern(inMap, prefix + (iter->first), iter->second);
		}
	}
}

void Pattern(vector<string> input)
{
	MMap inMap = preProcessRawData(input);
	getPattern(inMap, "", { -1, -1, -1, -1 });

	
}

/*
	abacc	a:0,2
	bacac	  1,3
	cabca	  1,4
	bcaab	  2,3
*/
void testFPattern()
{
	vector<string> v = { "abacc", "bacac", "cabca", "bcaab" };
	//MMap inMap = preProcessRawData(v);
	//map<char, vector<int>> re = getAllNext(inMap, { -1, -1, -1, -1 });
	Pattern(v);
}

