#include "datasource.h"


vector<string> FileDataSource::getBatchInput()
{
	string temp;
	vector<string> batchInput;

	while (getline(_infile,temp))
	{
		batchInput.push_back(temp);
		if (batchInput.size()==INT_BATCH)
		{
			return batchInput;
		}
	}
	return batchInput;
}


bool FileDataSource::init()
{
	_infile.open(_strFilename.c_str(), fstream::in);
	if (!_infile)
	{
		cout << "open file " << _strFilename<< " error" << endl;
		_infile.close();
		return false;
	}
	return true;

}


void FileDataSource::free()
{
	this->_infile.close();
}