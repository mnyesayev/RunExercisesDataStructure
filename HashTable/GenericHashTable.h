#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include"Item.h" 
using namespace std;

int getClosesPrime(int);

template<typename T, typename K>
class HashTable :public Item<T, K>
{
private:
	int tableSize;
	vector<Item<T, K>> table;
	int curSize = 0;
public:
	HashTable(int size)
	{
		tableSize = getClosesPrime(size);
		table.resize(tableSize);
		//table = new vector<Item<T, K>>[tableSize];
	}
	~HashTable();
	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;
	int hash(K key, int i)
	{
		return (h1(key) + i * h2(key) % tableSize);
	}
	int find(Item<T, K> item)
	{
		for (int i = 0; i < table.size(); ++i)
		{
			if (table[i].key == item.key)
				return i;
		}
		return -1;
	}

	void insert(Item<T, K> item)
	{
		if (isFull)
		{
			cout << "the table is alredy full";
				return;
		}
		for (int i = 0; i < table.size(); ++i)
		{
			int check = hash(item.key, i);
			if (table[check].flag != full)
			{
				table[check]= item;
				table[check].flag = full;
				++curSize;
				return;
			}
		}
	}

	bool isFull()
	{
		return(curSize == tableSize);
	}
};

template<typename T, typename K>
HashTable<T, K>::~HashTable()
{
}

int getClosesPrime(int size)
{
	bool isPrime = false;
	int i = 2;
	int prime = size;

	while (!isPrime)
	{
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
