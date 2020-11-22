/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include"Item.h" 
using namespace std;

template<typename T, typename K>
class HashTable :public Item<T, K>
{
private:
	int curSize;
	int tableSize;
	int getClosesPrime(int size)
	{
		bool isPrime = false;
		int i = 2;
		int prime = size;

		while (!isPrime)
		{
			i = 2;
			int sqr = sqrt(size);
			while (i != sqr + 1)
			{
				if (size % i == 0)
				{
					break;
				}
				++i;
				if (i == sqr + 1)
				{
					prime = size;
					return prime;
				}
			}
			++size;
		}
	}
protected:
	HashTable(int size)
	{
		curSize = 0;
		tableSize = getClosesPrime(size);
		table.resize(tableSize);
	}
	virtual ~HashTable() {}

	vector<Item<T, K> > table;

	int getTableSize() { return tableSize; }
	int getCurSize() { return curSize; }
	void setCurSize() { curSize = 0; }
	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;
	int hash(K key, int i)
	{
		return (h1(key) + i * h2(key)) % tableSize;
	}
	int find(K k)
	{
		for (int i = 0; i < table.size(); ++i)
		{
			int check = hash(k, i);
			if (table[check].flag == Empty)
				return -1;
			if (table[check].flag == Full && table[check].key == k)
				return check;
		}
		return -1;
	}

	bool insert(T t, K k)
	{
		if (isFull())
		{
			cout << "the table is alredy full";
			return false;
		}
		for (int i = 0; i < table.size(); ++i)
		{
			int check = hash(k, i);
			if (table[check].flag != Full)
			{
				table[check].data = t;
				table[check].key = k;
				if (table[check].flag != Deleted)
					++curSize;
				table[check].flag = Full;
				return true;
			}
		}
	}

	bool isFull()
	{
		return(curSize == tableSize);
	}
	bool setData(Item<T, K> item, int index)
	{
		if (index >= tableSize)
			return false;
		if (table[index].key == item.key)
		{
			table[index] = item;
			table[index].flag = Full;
			return true;
		}
		return false;
	}
	void printTable()
	{
		for (int i = 0; i < table.size(); i++)
		{
			cout << "index: " << i;
			if (table[i].flag == Full)
			{

				cout << " key: " << table[i].key;
				cout << " data: " << table[i].data;
			}
			cout << endl;
		}
	}
public:
	bool deleteKey(K k)
	{
		int index = find(k);
		if (index != -1)
		{
			table[index].flag = Deleted;
			return true;
		}
		return false;
	}

};



