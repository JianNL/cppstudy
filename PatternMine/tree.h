#ifndef TREEE_H
#define TREEE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <algorithm>
#include <assert.h>

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
		if (children.size()>0)
		{
			for (auto iter = children.begin(); iter != children.end();++iter)
			{
				if ((*iter).second!=nullptr)
				{
					delete (*iter).second;
				}
			}
		}
	}
	virtual map<char,node *>& getChildren()
	{
		return children;
	}
	virtual int getCount()
	{
		return 0;
	}
	virtual int incCount()
	{
		return 0;
	}
	virtual const string& getPattern()
	{
		return string("");
	}
	virtual void setPattern(const string &str)
	{}

	virtual NodeType getType()
	{
		return NORMALNODE;
	}
private:
	char data;
	map<char, node *> children;
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
	endnode() :node(), count(1)
	{
	}
	endnode(char c, const string &str) :node(c), count(1), pattern(str)
	{
	}
	~endnode(){}
	int getCount()
	{
		return count;
	}
	int incCount()
	{
		count++;
		return count;
	}
	void setPattern(const string &str)
	{
		this->pattern = str;
	}
	NodeType getType()
	{
		return ENDNODE;
	}
private:
	int count;
	string pattern;

};



class tree
{
public:
	tree()
	{
		root = new normalnode('*');
	}
	~tree()
	{
		if (root)
		{
			delete root;
		}
	}
	void search(const string &str,bool isUpdate=false);
	void fuzzyMatch(const string &str, int threshold);
	void traverse(function<void(const string &)> func);
private:
	node *root;
	vector<string> _tempMatches;
	void _traverse(node *pnode, const string &str,function<void(const string &)> func);
	void _fuzzyMatch(node *pnode, const string &prefix, const string &postfix, int threshold);

};




#endif