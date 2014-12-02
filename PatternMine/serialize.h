#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include <iostream>
#include <string>

using namespace std;

class serializable
{
public:
	virtual void save(const string &filename)= 0;
	virtual bool load(const string &filename)= 0;
	virtual void save(string& str)= 0;
};

#endif