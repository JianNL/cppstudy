#include "tree.h"

void tree::search(const string &str, bool isUpdate/* =false */)
{
	if (str.length()==0)
	{
		return;
	}
	shared_ptr<node> current = root;
	for (int i = 0; i != str.length();++i)
	{
		auto iter = current->getChildren().find(str[i]);
		if (iter!=current->getChildren().end())//找到
		{
			current = (*iter).second;
			if (i==str.length()-1)
			{
				if (current->getChildren().count('#'))
				{
					cout << "find " << str << endl;
				}
				else
				{
					current->getChildren()['#'] = shared_ptr<node>(new endnode('#', str));
					cout << "not find " << str << " but insert it" << endl;
				}
			}
		}
		else
		{
			if (isUpdate)
			{
				shared_ptr<node> newnode(new normalnode(str[i]));
				current->getChildren().insert(pair<char, shared_ptr<node> >(str[i], newnode));
				current = newnode;
				if (i==str.length()-1)
				{
					current->getChildren()['#'] = shared_ptr<node>(new endnode('#', str));
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


void tree::_traverse(shared_ptr<node> pnode,const string &str,function<void(const string &)> func)
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

void tree::_fuzzyMatch(shared_ptr<node> pnode, const string &prefix, const string &postfix, int threshold)
{
	if (threshold==0)//说明阈值已经用完，不能再有模糊匹配,必须精确匹配
	{
		//说明没有要匹配的后缀了
		map<char, shared_ptr<node> >::iterator iter;
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
		//没找到，但是因为阈值用光所以无法继续匹配。
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
	else//说明还有阈值可用
	{
		/*
		第一种情况，直接略过要匹配的串 skip
		树里面有A,B,C
		我们匹配的是A，C
		*/
		for (auto &iter = pnode->getChildren().begin(); iter != pnode->getChildren().end();++iter)
		{
			_fuzzyMatch(iter->second, prefix + iter->first, postfix, threshold - 1);
		}
		/*
		第二种情况，删掉一个
		树里面有A，C
		我们匹配的是A，B，C
		*/
		if (postfix.length() != 0)
		{
			_fuzzyMatch(pnode, prefix, postfix.substr(1), threshold - 1);
			/*
			第三种情况，替换一个
			树里面有A,B,C
			我们匹配的是A,D,C
			*/
			for (auto &iter = pnode->getChildren().begin(); iter != pnode->getChildren().end(); ++iter)
			{
				_fuzzyMatch(iter->second, prefix + iter->first, postfix.substr(1), threshold - 1);
			}
			/*
			最后，正常匹配
			*/
			auto iter = pnode->getChildren().find(postfix[0]);
			if (iter != pnode->getChildren().end())
			{
				_fuzzyMatch(iter->second, prefix + iter->first, postfix.substr(1), threshold);
			}

		}

	}
}


void tree::save(const string& filename)
{
	fstream file(filename, ios::out);
	string str;
	save(str);
	file << str;
	file.close();
}


void tree::save(string &str)
{
	this->_traverse(root,"",[&str](const string& s)
	{
		str = str + s + '#';
	});
	cout << str << endl;
}

bool tree::load(const string &str)
{
	if (root->getChildren().size()!=0)
	{
		return false;
	}
	if (str.length()==0)
	{
		return false;
	}
	string temp = str;
	int pos = temp.find_first_of('#');
	while (pos!=string::npos)
	{
		this->search(temp.substr(0, pos),true);
		temp = temp.substr(pos + 1);
		pos = temp.find_first_of('#');
	}
	return true;

}
