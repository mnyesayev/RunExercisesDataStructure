/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#pragma once
/// <summary>
/// enum for the state of the key in the table
/// </summary>
enum state { Empty, Full, Deleted };

/// <summary>
/// template class for item to put in the hash table
/// </summary>
/// <typeparam name="T">the data in the item</typeparam>
/// <typeparam name="K">the key of the item</typeparam>
template <typename T, typename K>
class Item
{
public:
	T data;
	K key;
	state flag;
	Item() { flag = Empty; }//ctor
	Item(T d, K k, state f) { data = d; key = k; flag = f; }//ctor
};
