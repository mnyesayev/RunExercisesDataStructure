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

