/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#include "HSubject.h"
using namespace std;

/// <summary>
/// destructor that clear all the table
/// </summary>
HSubject::~HSubject()
{
	startNewTable();
}

/// <summary>
/// the first hash func that get string and 
/// claculate the askii of each letter *128^his palce in the string
/// all this % table size
/// </summary>
/// <param name="k">the string to insert</param>
/// <returns>the index to insert to</returns>
int HSubject::h1(string k)
{

	int ch = 0;
	for (int i = 0; i < k.size(); i++)
	{
		ch += ((long long)(k[i] * pow(128, i))) % this->getTableSize();
	}
	return ch;
}

/// <summary>
/// the second hash func that get string and 
/// claculate the askii of each letter *128^his palce in the string
/// all this (% table size-1)+1 
/// </summary>
/// <param name="k"></param>
/// <returns></returns>
int  HSubject::h2(string k)
{
	int ch = 0;
	for (int i = 0; i < k.size(); i++)
	{
		ch += ((long long)(k[i] * pow(128, i))) % this->getTableSize();
	}
	return (ch % (this->getTableSize() - 1)) + 1;
}

/// <summary>
/// get the sucject and the respond and if the subject exist in the table
/// add new respons yo yhis subject else create new subject add this to
/// the table and add the response to there
/// </summary>
/// <param name="subject"></param>
/// <param name="title"></param>
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

/// <summary>
/// get subject and print all the responses of this subject
/// if is not exist print error
/// </summary>
/// <param name="key"></param>
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

/// <summary>
/// get subject and number of responses to print
/// and print the number of responses of this subject
/// if not exist print error
/// </summary>
/// <param name="key">subject</param>
/// <param name="n">number of responses to print</param>
void HSubject::printN(string key, int n)
{
	int index = find(key);
	if (index != -1)
	{
		int size;
		//if the number big than what inside prunt all responses
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

/// <summary>
/// clear all the table and start it as new table
/// </summary>
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


/// <summary>
/// print all the items in the table
/// </summary>
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
