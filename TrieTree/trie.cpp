/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/

#include "trie.h"
#include <iostream>

using namespace std;

/// <summary>
/// this func insert a word to the trie if all the letters already exist in the trie
/// is inly mark the last letter as end of word else is add all the letters that need
/// </summary>
/// <param name="str">the string to insert to the trie</param>
void Trie::insertWord(string str)
{
	if (str.empty())return;//didnt get any string to insert
	TrieNode* ptr = root;//ptr to the root
	TrieNode* prev;
	if (root->children == NULL)//in case the trie is empety
	{
		*root->children = new TrieNode[ALPHABET];
	}
	for (int i = 0; i < str.size(); ++i)
	{
		char ch = str[i];
		if (ptr->children[ch - 97] == NULL)
		{
			ptr->children[ch - 97] = new TrieNode();
			ptr->countChildrens++;
		}
		prev = ptr;
		ptr = ptr->children[ch - 97];
		ptr->father = prev;
	}
	ptr->isEndWord = true;
	return;
}

/// <summary>
/// func to delete word from the trie if the word exist so if there is word
/// that contain this word is only mark the last letter as not end of word
/// else is delete all the letters till there is onther word that use this
/// </summary>
/// <param name="str">the string to the delete</param>
/// <returns>true is the word exist and deleted else return false</returns>
bool Trie::deleteWord(string str)
{
	if (str.empty())return false;
	TrieNode* ptr = root;
	TrieNode* prev = NULL;
	//loop to get to the end of the string
	for (int i = 0; i < str.size(); ++i)
	{
		char ch = str[i];
		if (ptr->children[ch - 97] == NULL)
			return false;

		ptr = ptr->children[ch - 97];
	}
	/// <summary>
	/// in case the word not exist
	/// </summary>
	/// <param name="str"></param>
	/// <returns></returns>
	if (!ptr->isEndWord)return false;

	//in case ther is another word that contain this word so no delete any
	//letters ony mark the lasr letter as not end of word
	if (ptr->countChildrens != 0)
	{
		ptr->isEndWord = false;
		return true;
	}

	char ch = str[str.size() - 1];
	ptr = ptr->father;
	ptr->children[ch - 97] = NULL;
	ptr->countChildrens--;
	for (int i = str.size() - 2; i >= 0; --i)
	{
		char ch = str[i];
		ptr = ptr->father;
		if (ptr->children[ch - 97]->isEndWord)
			return true;
		ptr->children[ch - 97] = NULL;
		if (ptr->countChildrens != 1)
		{
			ptr->countChildrens--;
			return true;
		}
		ptr->countChildrens--;
	}
}

/// <summary>
/// func that get string and search if this word exist in the trie and if the first
/// letter exist is will call to the other func with node and string that will check
/// this in recursive 
/// </summary>
/// <param name="str">the string to search</param>
/// <returns>return true if this word exist else return false</returns>
bool Trie::searchWord(string str)
{
	if (str.size() == 1)
	{
		if (root->children[str[0] - 97] != NULL && root->children[str[0] - 97]->isEndWord)return true;
		else return false;
	}
	if (root->children[str[0] - 97] == NULL)return false;
	return searchWord(str.erase(0, 1), root->children[str[0] - 97]);
}

/// <summary>
/// func that get string and print all the words that start with this string 
/// if there is words like this return int>0 else return 0
/// this func will call to the printAllWordsFromPrefix func that will do it in recursive
/// </summary>
/// <param name="str">the string to print all the words that start with this string</param>
/// <returns>return 0 if no words start with this string else return int>0</returns>
int Trie::printAutoSuggestions(string str)
{

	TrieNode* node = root;
	for (int i = 0; i < str.size(); i++)
	{
		char ch = str[i];
		if (node->children[ch - 97] == NULL)
			return 0;
		node = node->children[ch - 97];
	}
	return printAllWordsFromPrefix(str, node);
}

/// <summary>
/// func to print all the words from this node in lexicograghic in recursive
/// it will start in the first letter that exsit in this node and will do it for
/// the next letter etc.. and when he reach to null he return to the prev lrtter
/// and serach for other words and so on..
/// </summary>
/// <param name="str">the string to print all the words that stary withe this string</param>
/// <param name="node">the node to search the string from</param>
/// <returns>int>0 if there is word like this else return 0</returns>
int Trie::printAllWordsFromPrefix(string str, TrieNode* node)
{
	string tmp = str;
	int comp = 0;
	if (node->isEndWord)
	{
		cout << tmp << endl;
		++comp;
	}
	int count = node->countChildrens;
	for (int i = 0; i < 26; i++)
	{
		if (count == 0)
			break;
		if (node->children[i] != NULL)
		{
			char ch = i + 97;
			tmp += ch;
			--count;
			comp = printAllWordsFromPrefix(tmp, node->children[i]);
			tmp.resize(tmp.size() - 1);
		}
	}

	return comp;
}

/// <summary>
/// func that get string and node and check in recursive way if this word exist 
/// and any ctime is cut the first letter and call this func again... till end of the string   
/// </summary>
/// <param name="str">the string to search</param>
/// <param name="node">the node to start the search from</param>
/// <returns>true is if exist else false</returns>
bool Trie::searchWord(string str, TrieNode* node)
{
	if (str.size() == 1)
	{
		if (node->children[str[0] - 97] == NULL)return false;
		if (node->children[str[0] - 97]->isEndWord)return true;
		else return false;
	}
	if (node->children[str[0] - 97] == NULL)return false;
	return searchWord(str.erase(0, 1), node->children[str[0] - 97]);
}

