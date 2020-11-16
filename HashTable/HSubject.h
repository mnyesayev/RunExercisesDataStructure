#pragma once
#include "GenericHashTable.h"
#include <list>
#include <string>
class HSubject :public HashTable<std::list<std::string>,std::string >
{
public:
	HSubject(int size) :HashTable(size) {}
	int h1(int k) override;
	int h2(int k)override;
	void addSubjectAndTitle(string ,string);
	void printS(string key);
	void printN(string k, int n);
	void startNewTable();
	void print();
};
