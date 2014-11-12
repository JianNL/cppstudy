#include "relationtable.h"

RelationTable::RelationTable(int num, set<string> *sets, vector<map<string, string> > *pmaps) :
table(vector<vector<unsigned int> >(num - 1)),
pAttributeSet(sets),
pMaps(pmaps),
isFinish(false)
{
	this->num = num;
	for (int i = 0; i < num - 1;++i)
	{
		table[i] = vector<unsigned int>(num - 1 - i);
	}
}


int RelationTable::get(int x, int y)
{
	if (!CanUse())
	{
		return -1;
	}
	if (x==y)
	{
		return -1;
	}
	if (x>y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
	return table[x - 1][y - 1];
}


void RelationTable::buildTable()
{
	if (CanUse())
	{
		cout << "the table has been built " << endl;
		return;
	}
	assert(!CanUse());
	//得到所有雷达属性的bitmap
	for (auto radar:(*pMaps))
	{
		unsigned int bitmap = 0;
		for (auto iter = radar.begin(); iter != radar.end();++iter)//对于雷达的每个属性
		{
			int pos = getPosInSets(iter->first);
			assert(pos >= 0);
			assert(pos <= (sizeof(unsigned int)* 8));
			bitmap = bitmap| (1 << pos);
		}//得到一个雷达所有属性的bitmap
		this->radarsBitMaps.push_back(bitmap);
	}











}


int RelationTable::getPosInSets(const string &element)
{
	int result = -1;
	for (auto e : (*pAttributeSet))
	{
		result++;
		if (e==element)
		{
			return result;
		}
	}
	return -1;
}