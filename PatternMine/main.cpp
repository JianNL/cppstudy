#include "BatchPatternMiner.h"
#include "buffer.h"
#include "tree.h"
#include <chrono>
#include <time.h>
#include "testCereal.h"


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
		miner.setIsOutputToScreen(true);
		clock_t start, finish;
		start = clock();
		miner.inputRawData(input1);
		miner.minePatternOnce(true);
		miner.reset();
		miner.inputRawData(input1);
		miner.minePatternOnce();
		miner.reset();
		*/
		/*
		miner.inputRawData(input1);
		miner.minePatternOnce(true);
		*/
		/*
		finish = clock();
		cout << "the duration is " << (double)(finish - start)/CLOCKS_PER_SEC <<" sec"<< endl;
		cout << "traverse the tree" << endl;
		miner.traverse([](const string &str){
			cout << str << endl;
		});
		*/
	}
	{
		//tree of no order test
		tree tree1;
		clock_t start, finish;
		start = clock();
		tree1.search("abc", true);
		tree1.search("abccc", true);
		tree1.search("abc");
		tree1.search("aaaaccc", true);
		tree1.search("aaaaccc", true);
		tree1.search("abc", true);
		tree1.search("abccc", true);
		tree1.search("abc");
		tree1.search("aaaaccc", true);
		tree1.search("aaaaccc", true);
		tree1.search("abb", true);
		tree1.fuzzyMatch("abc", 1);
		finish = clock();
		cout << "the duration is " << (double)(finish - start)/CLOCKS_PER_SEC <<" sec"<< endl;

	}
	{
		//testCereal
		test();

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
	int i;
	cout << "input any key to exit" << endl;
	cin >> i;
	return 0;
}