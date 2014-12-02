#ifndef TREEE_H
#define TREEE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <algorithm>
#include <memory>
#include <assert.h>
#include <fstream>
#include "serialize.h"

using namespace std;

class node
{
public:
	enum NodeType
	{
		NORMALNODE, 
		ENDNODE
	};
	node() :data(' ')
	{}
	node(char c) :data(c)
	{}
	virtual ~node()
	{
	
	}
	virtual map<char,shared_ptr<node> >& getChildren()
	{
		return children;
	}
	virtual const string& getPattern()
	{
		return "";
	}
	virtual void setPattern(const string &str)
	{}

	virtual NodeType getType()
	{
		return NORMALNODE;
	}
private:
	char data;
	map<char, shared_ptr<node> > children;
};

class normalnode:public node
{
public:
	normalnode() :node()
	{}
	normalnode(char c) :node(c)
	{}
	NodeType getType()
	{
		return NORMALNODE;
	}
private:
};


class endnode :public node
{
public:
	endnode() :node()
	{
	}
	endnode(char c, const string &str) :node(c), pattern(str)
	{
	}
	~endnode(){}
	void setPattern(const string &str)
	{
		this->pattern = str;
	}
	NodeType getType()
	{
		return ENDNODE;
	}
private:
	string pattern;

};



class tree :public serializable
{
public:
	tree() :root(new normalnode('*'))
	{
	}
	~tree()
	{
	}
	void search(const string &str,bool isUpdate=false);
	void fuzzyMatch(const string &str, int threshold);
	void traverse(function<void(const string &)> func);
	void save(string &str);
	void save(const string& filename);
	bool load(const string& filename);
	void clear();
private:
	shared_ptr<node> root;
	vector<string> _tempMatches;
	void _traverse(shared_ptr<node> pnode, const string &str,function<void(const string &)> func);
	void _fuzzyMatch(shared_ptr<node> pnode, const string &prefix, const string &postfix, int threshold);

};




#endif