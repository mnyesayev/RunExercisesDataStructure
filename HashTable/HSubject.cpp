/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#include "HSubject.h"
using namespace std;
HSubject::~HSubject()
{
	startNewTable();
}
int HSubject::h1(string k)
{

	int ch = 0;
	for (int i = 0; i < k.size(); i++)
	{
		ch += ((long long)(k[i] * pow(128, i))) % this->getTableSize();
	}
	return ch;
}

int  HSubject::h2(string k)
{
	int ch = 0;
	for (int i = 0; i < k.size(); i++)
	{
		ch += ((long long)(k[i] * pow(128, i))) % this->getTableSize();
	}
	return (ch % (this->getTableSize() - 1)) + 1;
}

void HSubject::addSubjectAndTitle(string subject, string title)
{
	int i = find(subject);
	if (i != -1)
	{
		table[i].data.push_front(title);
	}
	else
	{
		list<string> lst;
		lst.push_back(title);
		if (!insert(lst, subject))
			cout << "ERROR" << endl;
	}
}

void HSubject::printS(string key)
{
	int index = find(key);
	if (index != -1)
	{
		list<string>::iterator it = table[index].data.begin();
		if (it == table[index].data.end())
			cout << "ERROR";
		for (it; it != table[index].data.end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
		cout << "ERROR" << endl;
}

void HSubject::printN(string key, int n)
{
	int index = find(key);
	if (index != -1)
	{
		int size;
		if (n >= table[index].data.size())
		{
			size = table[index].data.size();
		}
		else
			size = n;
		list<string>::iterator it = table[index].data.begin();
		if (it == table[index].data.end())
			cout << "ERROR";
		int i = 0;
		for (it; i < size; ++it, ++i)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
		cout << "ERROR" << endl;
}

void HSubject::startNewTable()
{
	for (int i = 0; i < getTableSize(); i++)
	{
		if (table[i].flag != Empty)
		{
			table[i].data.clear();
			table[i].key.clear();
			table[i].flag = Empty;
		}
	}
	setCurSize();
}

void HSubject::print()
{
	for (int i = 0; i < getTableSize(); i++)
	{
		if (table[i].flag == Full)
		{
			cout << "index: " << i;
			cout << " Subject: " << table[i].key << endl;
			list<string>::iterator it = table[i].data.begin();
			cout << "titles:" << endl;
			for (it; it != table[i].data.end(); ++it)
			{
				cout << "	" << *it << endl;
			}
		}
	}
}
