#include "trie.h"
#include <iostream>

using namespace std;
void Trie::insertWord(string str)
{
	if (str.empty())return;
	TrieNode* ptr = root;
	TrieNode* prev;
	if (root->children == NULL)
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

bool Trie::deleteWord(string str)
{
	if (str.empty())return false;
	TrieNode* ptr = root;
	TrieNode* prev = NULL;
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

