#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "common.h"


using namespace std;

class DataSource
{
public:
	DataSource()
	{
	}
	virtual vector<string> getBatchInput()
	{
		return vector<string>();
	}
private:

};

class FileDataSource :public DataSource
{
public:
	FileDataSource() :DataSource()
	{}
	FileDataSource(string filename) :_strFilename(filename)
	{}
	bool init();
	void free();
	vector<string> getBatchInput();

private:
	fstream _infile;
	string _strFilename;
};



