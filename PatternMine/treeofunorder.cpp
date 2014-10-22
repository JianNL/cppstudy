#include "treeofunorder.h"

//有序false的结尾是# 无序true的结尾是$
bool treeunorder::search(const string &str, bool isUpdate/* =false */,bool isNoOrder/* =false */)
{
	node *current;
	current = root;
	for (int i = 0; i != str.length();++i)
	{
		auto iter = current->getChildren().find(str[i]);
		if (iter!=current->getChildren().end())
		{
			current = (*iter).second;
			if (i==str.length()-1)
			{
				if (!isNoOrder)
				{
					if (current->getChildren().count('#'))
					{
						cout << "find " << str << " count " << current->getChildren()['#']->incCount() << endl;
						return true;
					}
					else
					{
						current->getChildren()['#'] = new endnode('#', str);
						cout << "not find " << str << " but insert it" << endl;
						return false;
					}

				}
				else
				{
					if (current->getChildren().count('$'))
					{
						cout << "find " << str << " count " << current->getChildren()['$']->incCount() << endl;
						return true;
					}
					else
					{
						current->getChildren()['$'] = new endnode('$', str);
						cout << "not find " << str << " but insert it" << endl;
						return false;
					}

				}
			}
		}
		else
		{
			if (isUpdate)
			{
				node *newnode = new normalnode(str[i]);
				current->getChildren().insert(pair<char, node *>(str[i], newnode));
				current = newnode;
				if (i==str.length()-1)
				{
					if (!isNoOrder)
					{
						current->getChildren()['#'] = new endnode('#', str);
						cout << "not find " << str << " but insert it" << endl;
						return false;
					}
					else
					{
						current->getChildren()['$'] = new endnode('$', str);
						cout << "not find " << str << " but insert it" << endl;
						return false;
					}
				}
			}
		}
	}
}


void treeunorder::traverse(function<void(const string &)> func)
{
	_traverse(root,"",func);
}


void treeunorder::_traverse(node *pnode,const string &str,function<void(const string &)> func)
{
	if (pnode==nullptr)
	{
		return;
	}
	string s;
	for (auto iter = pnode->getChildren().begin(); iter != pnode->getChildren().end();++iter)
	{
		s = str;
		if (iter->first=='#')
		{
			s = s + " order ";
			func(s);
		}
		else if (iter->first=='$')
		{
			s = s + " no order";
			func(s);
		}
		else
		{
			s += iter->first;
			_traverse(iter->second, s, func);
		}
	}
}