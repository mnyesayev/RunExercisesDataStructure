/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#pragma once
#include "GenericHashTable.h"
#include <list>
#include <string>

/// <summary>
/// hash table that the key is string and the data is list of strings
/// </summary>
class HSubject :public HashTable<std::list<std::string>, std::string >
{
public:
	HSubject(int size) :HashTable(size) {}//ctor
	~HSubject();//dtor
	int h1(string k);//the hash func
	int h2(string k);//the haSH FUNC
	void addSubjectAndTitle(string, string);
	void printS(string key);
	void printN(string k, int n);
	void startNewTable();
	void print();
};
