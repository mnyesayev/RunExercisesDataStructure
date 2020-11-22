/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#pragma once
#include "GenericHashTable.h"
#include <list>
#include <string>
class HSubject :public HashTable<std::list<std::string>, std::string >
{
public:
	HSubject(int size) :HashTable(size) {}
	~HSubject();
	int h1(string k);
	int h2(string k);
	void addSubjectAndTitle(string, string);
	void printS(string key);
	void printN(string k, int n);
	void startNewTable();
	void print();
};
