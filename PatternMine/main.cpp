#include "pattern.h"
#include <time.h>


int main(char *argv[], int argc)
{	
	cout << "PatternMiner test" << endl;
	vector<string> input = { "abacce", "bafcac", "cgabca", "hbcaab" };
	vector<string> inputC = { "asakdlfjoasidfoasd", "qoofuopaisdasdnfl", "oisdfpodfpoasidfo", "aopsosidaupoisda" };
	vector<string> input1 = { "abac", "abcac", "babac", "abacc" };
	vector<string> input2 = { "abc", "bac", "cab", "aab" };
	vector<string> input3(input2);
	for (auto e : input1)
	{
		input2.push_back(e);
	}
	BatchPatternMiner miner;
	miner.setIsOutputToScreen(false);
	clock_t start, finish;
	start = clock();
	miner.inputRawData("data.txt");
	miner.minePatternLasting();
	finish = clock();
	cout << "the duration is " << (double)(finish - start)/CLOCKS_PER_SEC <<" sec"<< endl;
	int i;
	cout << "input any key to exit" << endl;
	cin >> i;
	return 0;
}