#include<string>

#pragma once
using namespace std;
class Trie
{
	static const int ALPHABET = 26;
	class TrieNode
	{
	public:
		TrieNode* children[ALPHABET];
		TrieNode* father;
		bool isEndWord = false;
		int countChildrens = 0;
		TrieNode()
		{
			*children = NULL;
			father = NULL;
			isEndWord = false;
			countChildrens = 0;
		}
	};
public:
	TrieNode* root;
	Trie() { root = new TrieNode(); }
	void insertWord(string str);
	bool deleteWord(string str);
	bool searchWord(string str);
	void printAllWordsFromPrefix(TrieNode* node);
private:
	bool searchWord(string str, TrieNode* node);
};

