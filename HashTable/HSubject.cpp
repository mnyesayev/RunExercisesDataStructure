#include "HSubject.h"
using namespace std;
int HSubject::h1(int k)
{
	return k % this->getTableSize();
}

int  HSubject::h2(int k)
{
	return (k % (this->getTableSize() - 1)) + 1;
}

void HSubject::addSubjectAndTitle(string subject, string title)
{
	int i = find(subject);
	if (i != -1)
	{
		getTable()[i].data.push_front(title);
	}
	else
	{
		list<string> lst{ title };
		if (insert(lst, subject))
			cout << "success to add new subject" << endl;
	}
}

void HSubject::printS(string key)
{
	int index = find(key);
	if (index != -1)
	{
		list<string>::iterator it = getTable()[index].data.begin();
		if (it != getTable()[index].data.end())
			cout << "titles:" << endl;
		for (it; it != getTable()[index].data.end(); ++it)
		{
			cout << "	" << *it << endl;
		}
	}
}

void HSubject::printN(string k, int n)
{
	int index = find(key);
	if (index != -1)
	{
		int size;
	
		if (n >= getTable()[index].data.size())
		{
			size = getTable()[index].data.size();
		}
		else
			size = n;
		list<string>::iterator it = getTable()[index].data.begin();
		if (it != getTable()[index].data.end())
			cout << "titles:" << endl;
		int i = 0;
		for (it; i<size; ++it,++i)
		{
			cout << "	" << *it << endl;
		}
	}
}

void HSubject::startNewTable()
{
	for (int i = 0; i < getTableSize(); i++)
	{
		if (getTable()[i].flag != Empty)
		{
			getTable()[i].data.clear();
			getTable()[i].key.clear();
			getTable()[i].flag=Empty;
		}
	}
	setCurSize();
}

void HSubject::print()
{
	for (int i = 0; i < getTableSize(); i++)
	{
		if (getTable()[i].flag == Full)
		{
			cout << "index: " << i;
			cout << " Subject: " << getTable()[i].key << endl;
			list<string>::iterator it = getTable()[i].data.begin();
			cout << "titles:" << endl;
			for (it; it != getTable()[i].data.end(); ++it)
			{
				cout << "	" << *it << endl;
			}
		}
	}
}
