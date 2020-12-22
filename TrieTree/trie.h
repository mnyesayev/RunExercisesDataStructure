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
		bool isEndWord;
		int countChildrens;
		TrieNode()
		{
			*children = NULL;
			father = NULL;
			isEndWord = false;
			countChildrens = 0;
		}
		~TrieNode()
		{
			for (int i = 0; i < ALPHABET; i++)
			{
				if (children[i] != NULL)
					delete children[i];
			}
		}
	};
public:
	TrieNode* root;
	Trie() { root = new TrieNode(); }
	~Trie() { if (root != NULL) delete root; }
	void insertWord(string str);
	bool deleteWord(string str);
	bool searchWord(string str);
	int printAutoSuggestions(string str);
private:
	int printAllWordsFromPrefix(string str, TrieNode* node);
	bool searchWord(string str, TrieNode* node);
};

