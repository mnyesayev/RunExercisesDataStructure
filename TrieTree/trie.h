/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/

#include<string>

#pragma once
using namespace std;
/// <summary>
/// class trie to store words like dictionary
/// </summary>
class Trie
{
	static const int ALPHABET = 26;
	/// <summary>
	/// this is class for one node in the trie witc contain pointer for
	/// the chikdren array in the size of the alphabet and pointer to his father
	/// bool if this word is end of word and counter for how many children exist now
	/// </summary>
	class TrieNode
	{
	public:
		TrieNode* children[ALPHABET];
		TrieNode* father;
		bool isEndWord;
		int countChildrens;
		/// <summary>
		/// default constructor 
		/// </summary>
		TrieNode()
		{
			*children = NULL;
			father = NULL;
			isEndWord = false;
			countChildrens = 0;
		}
		
		//destructor that delete all the array of the children
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
	//field
	TrieNode* root;
	
	Trie() { root = new TrieNode(); }//ctor
	//dtor that work in recursive all node will delete all his children
	~Trie() { if (root != NULL) delete root; }
	void insertWord(string str);//func to insert word
	bool deleteWord(string str);//func to delete word
	bool searchWord(string str);//func to search if word exist
	//func that get string and show all the words in the trie that start in this string
	int printAutoSuggestions(string str);
private:
	//the func for recursive for print auto suggestions func
	int printAllWordsFromPrefix(string str, TrieNode* node);
	//the func for recursive for the search word func
	bool searchWord(string str, TrieNode* node);
};

