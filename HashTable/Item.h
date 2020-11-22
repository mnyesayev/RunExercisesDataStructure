/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#pragma once
enum state { Empty, Full, Deleted };
template <typename T, typename K>
class Item
{
public:
	T data;
	K key;
	state flag;
	Item() { flag = Empty; }
	Item(T d, K k, state f) { data = d; key = k; flag = f; }
};
