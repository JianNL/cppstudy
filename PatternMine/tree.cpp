#include "tree.h"

void tree::search(const string &str, bool isUpdate/* =false */)
{
	node *current;
	current = root;
	for (int i = 0; i != str.length();++i)
	{
		auto iter = current->getChildren().find(str[i]);
		if (iter!=current->getChildren().end())//�ҵ�
		{
			current = (*iter).second;
			if (i==str.length()-1)
			{
				if (current->getChildren().count('#'))
				{
					cout << "find " << str << " count " << current->getChildren()['#']->incCount() << endl;
				}
				else
				{
					current->getChildren()['#'] = new endnode('#', str);
					cout << "not find " << str << " but insert it" << endl;
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
					current->getChildren()['#'] = new endnode('#', str);
					cout << "not find " << str << " but insert it" << endl;
				}
			}
		}
	}
}


void tree::traverse(function<void(const string &)> func)
{
	_traverse(root,"",func);
}


void tree::_traverse(node *pnode,const string &str,function<void(const string &)> func)
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
			func(s);
		}
		else
		{
			s += iter->first;
			_traverse(iter->second, s, func);
		}
	}
}

void tree::fuzzyMatch(const string &str, int threshold)
{
	_fuzzyMatch(root, "", str, threshold);
}

void tree::_fuzzyMatch(node *pnode, const string &prefix, const string &postfix, int threshold)
{
	if (threshold==0)//˵����ֵ�Ѿ����꣬��������ģ��ƥ��,���뾫ȷƥ��
	{
		//˵��û��Ҫƥ��ĺ�׺��
		map<char, node *>::iterator iter;
		if (postfix.length()==0)
		{
			if (pnode->getChildren().find('#')!=pnode->getChildren().end())
			{
				if (find(_tempMatches.begin(),_tempMatches.end(),prefix)==_tempMatches.end())
				{
					this->_tempMatches.push_back(prefix);
					cout << prefix << endl;
				}

			}
		}
		//û�ҵ���������Ϊ��ֵ�ù������޷�����ƥ�䡣
		else if ((iter=pnode->getChildren().find(postfix[0]))==pnode->getChildren().end())
		{
			return ;
		}
		else
		{
			assert(threshold == 0);
			_fuzzyMatch(iter->second, prefix + postfix, postfix.substr(1), threshold);
		}
	}
	else//˵��������ֵ����
	{
		/*
		��һ�������ֱ���Թ�Ҫƥ��Ĵ� skip
		��������A,B,C
		����ƥ�����A��C
		*/
		for (auto &iter = pnode->getChildren().begin(); iter != pnode->getChildren().end();++iter)
		{
			_fuzzyMatch(iter->second, prefix + iter->first, postfix, threshold - 1);
		}
		/*
		�ڶ��������ɾ��һ��
		��������A��C
		����ƥ�����A��B��C
		*/
		if (postfix.length() != 0)
		{
			_fuzzyMatch(pnode, prefix, postfix.substr(1), threshold - 1);
			/*
			������������滻һ��
			��������A,B,C
			����ƥ�����A,D,C
			*/
			for (auto &iter = pnode->getChildren().begin(); iter != pnode->getChildren().end(); ++iter)
			{
				_fuzzyMatch(iter->second, prefix + iter->first, postfix.substr(1), threshold - 1);
			}
			/*
			�������ƥ��
			*/
			auto iter = pnode->getChildren().find(postfix[0]);
			if (iter != pnode->getChildren().end())
			{
				_fuzzyMatch(iter->second, prefix + iter->first, postfix.substr(1), threshold);
			}

		}

	}
}