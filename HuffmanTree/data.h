/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#pragma once
#include <iostream>
class Data
{
public:
	char letter;
	int frequency;
	Data() { letter = NULL; frequency = 0; }
	Data(char ch) { letter = ch; frequency=1; }
};

