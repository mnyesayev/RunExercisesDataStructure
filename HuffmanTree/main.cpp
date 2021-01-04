/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "huffman.h"

using namespace std;
int main()
{
	int choice,numOfLetters;
	string word,letters,encode;
    HuffmanTree* t = new HuffmanTree();
	cout << "enter 1 to encode a text\n";
	cout << "enter 2 to decode a text\n";
	cout << "enter 3 to exit\n";

	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:

			cout << "enter the original text" << endl;
			cin >> word;
			cout << "The encoded string is:\n";
			t->buildTree(word);
			t->printDetails(word);
			//Build Huffman tree given the data inside "word".
			//Then find the code of each letter.
			//Then print the output - number of leaves, order of letters, tree structure and the encoded text - according to the explanation in the exercise.

			break;
		case 2:
			//input the number of leaves, the  order of letters, tree structure and the encoded text.
			//build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
			//Given the Huffman Tree and the encoded text, find the original text, and print it. 
			cout << "enter n:\n";
			cin >> numOfLetters;
			cout << "enter the letters:\n";
			cin >> letters;
			cout << "enter the encoded structure:\n";
			cin >> encode;
			cout << "enter the encoded text:\n";
			cin >> word;
			cout << "The decoded string is:";
			t->encode(numOfLetters, letters, encode, word);
			cout << endl;
			break;
		case 3:

			break;
		default: cout << "ERROR " << endl;  break;
		}
	} while (choice != 3);
	return 0;
}