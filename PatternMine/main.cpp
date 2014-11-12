#include "BatchPatternMiner.h"
#include "buffer.h"
#include "radarxmlpars.h"
#include <chrono>
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
	{
		//miner test
		/*
		BatchPatternMiner miner;
		miner.setIsOutputToScreen(false);
		clock_t start, finish;
		start = clock();
		miner.inputRawData("data.txt");
		miner.minePatternLasting();
		finish = clock();
		cout << "the duration is " << (double)(finish - start)/CLOCKS_PER_SEC <<" sec"<< endl;
		*/
	}
	{
		//buffer test
		/*
		buffer b;
		thread t1([&b](){
			int i = 100;
			while (i-- > 0)
			{
				b.push({ "0" });
			}
		});
		thread t2([&b](){
			int i = 100;
			this_thread::sleep_for(chrono::seconds(20));
			while (i-->0)
			{
				b.push({ "1" });
			}
		});
		t1.join();
		t2.join();
		*/
	}
	{
		//xmltest
		RadarXmlParser *paser = new RadarXmlParser("test.xml");
		cout << paser->getRadarNumbers() << endl;
		delete paser;
	}
	int i;
	cout << "input any key to exit" << endl;
	cin >> i;
	return 0;
}