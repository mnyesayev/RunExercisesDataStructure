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
/// <summary>
/// generic hash table that have vector of generic items who contains
/// key that say where to put the item and data in the item
/// the table have fields of the size and cur size
/// </summary>
template<typename T, typename K>
class HashTable :public Item<T, K>
{
private:
	int curSize;//how many items in the table
	int tableSize;// the size of the table

	/// <summary>
	/// func that get number and return the closest 
	/// prime number to this number for the size of the table
	/// </summary>
	/// <param name="size">the minimum size of table</param>
	/// <returns>the final size of the table as prime number</returns>
	int getClosesPrime(int size)
	{
		bool isPrime = false;
		int i = 2;
		int prime = size;
		//check all numbers till the sqr of tjis number
		//if is not divide==0 is prime 
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
	/// <summary>
	/// constructor get size and build new table with 
	/// the prime number for this 
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="K"></typeparam>
	HashTable(int size)
	{
		curSize = 0;
		tableSize = getClosesPrime(size);
		table.resize(tableSize);
	}
	virtual ~HashTable() {}//dtor

	vector<Item<T, K> > table;//contain all the items in the table

	int getTableSize() { return tableSize; }//getter for the table size
	int getCurSize() { return curSize; }//getter for cur size
	void setCurSize() { curSize = 0; }//seter for cur size
	virtual int h1(K key) = 0; //virtual func for hashing
	virtual int h2(K key) = 0; //virtual func for hashing
	/// <summary>
	/// funk that get the key to inset to the table
	/// and the num of the try to insert using the hash
	/// func to insert the key to the right place
	/// </summary>
	/// <param name="k">key to insert</param>
	/// <returns>the index where is needed to insert</returns>
	int hash(K key, int i)
	{
		return (h1(key) + i * h2(key)) % tableSize;
	}

	/// <summary>
	/// find if the key is in the table or not
	/// </summary>
	/// <param name="t"></param>
	/// <param name="k">the key to search</param>
	/// <returns>if found return the index if not return -1</returns>
	int find(K k)
	{
		//as long as is not empty keep search
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

	/// <summary>
	/// bool func to try insert key in the table
	/// </summary>
	/// <param name="item">the subject </param>
	/// <param name="index"></param>
	/// <returns>if success to insert true if faild return false</returns>
	bool insert(T t, K k)
	{
		//if already full can't insert more and return false
		if (isFull())
		{
			cout << "the table is alredy full";
			return false;
		}
		//check where to insert by hashing
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

	/// <summary>
	///check if the table is already full 
	/// </summary>
	/// <param name="k"></param>
	/// <returns>if full return true</returns>
	bool isFull()
	{
		return(curSize == tableSize);
	}

	/// <summary>
	/// get item and insert him in spesific index
	/// </summary>
	/// <typeparam name="T">the data</typeparam>
	/// <typeparam name="K">the key</typeparam>
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

	/// <summary>
	/// print all the items in the table
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="K"></typeparam>
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
	/// <summary>
	/// delete key from the table 
	/// return true if success else return false
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="K"></typeparam>
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



