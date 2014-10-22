#ifndef TREEEOFUNORDER_H
#define TREEEOFUNORDER_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>

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



class treeunorder
{
public:
	treeunorder()
	{
		root = new normalnode('*');
	}
	~treeunorder()
	{
		if (root)
		{
			delete root;
		}
	}
	bool search(const string &str,bool isUpdate=false,bool isNoOrder=false);
	void traverse(function<void(const string &)> func);
private:
	node *root;
	void _traverse(node *pnode, const string &str,function<void(const string &)> func);

};




#endif