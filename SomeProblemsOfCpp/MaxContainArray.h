#include <iostream>
#include <string>

using namespace std;




//"abcddddacdaacdbdeaacdeabecbe"
//返回能包围abcde五个字母的最小区间
void MaxContainArray(const string &str)
{
	cout << "MaxContainArray" << endl;
	int len = str.length();
	int map[5] = { 0 };
	int currentmax = 0;
	int max = len+1;
	int pos = len;
	for (int i = 0; i != len;++i)
	{
		map[str[i] - 'a'] = 1;
		currentmax = map[0];
		for (int j = 0; j != 5;++j)
		{
			if ((str[i]-'a')!=j)
			{
				map[j] = (map[j] == 0 ? 0 : map[j] + 1);
				currentmax = (map[j] > currentmax ? map[j] : currentmax);
			}
		}
		if (map[0]*map[1]*map[2]*map[3]*map[4]==0)
		{
			continue;
		}
		else
		{
			if (currentmax<max)
			{
				max = currentmax;
				pos = i;
			}
		}
	}
	cout << "the result is " << max << endl;
	cout << "the pos is " << pos - max + 1 << " to " << pos << endl;
	cout << string(str.begin()+pos-max+1,str.begin()+pos+1) << endl;

}




void testMaxContainArray()
{
	string str = "abcddddacbaaaadebabababaacdbdaaaaaaeddeacadeeebdeabecbe";
	MaxContainArray(str);
}







