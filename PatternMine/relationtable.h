#ifndef RELATIONTABLE_H
#define RELATIONTABLE_H

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <array>
#include <assert.h>


using namespace std;

class RelationTable
{
public:
	RelationTable(int num,set<string> *sets,vector<map<string,string> > *pmaps);
	int get(int x, int y);
	void buildTable();
	bool CanUse()
	{
		return isFinish;
	}
private:
	bool isFinish;
	vector<vector<unsigned int> > table;
	set<string> *pAttributeSet;
	vector<string> AttributeVec;
	vector<map<string, string> > *pMaps;
	vector<unsigned int> radarsBitMaps;
	int getPosInSets(const string &element);
	int num;
};



#endif