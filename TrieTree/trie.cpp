#include "trie.h"


void Trie::insertWord(string str)
{
	if (str.empty())return;
	TrieNode* ptr = root;
	TrieNode* prev;
	/*if (root->children[ch - 97] == nullptr)
	{
		ptr->children[ch - 97] = new TrieNode();
		if (str.size() > 1)
		{
			ptr = ptr->children[ch - 97];
			ptr->father = root;
			for (int i = 1; i < str.size(); ++i)
			{
				char ch = str[i];
				ptr->children[ch - 97] = new TrieNode();
				prev = ptr;
				ptr = ptr->children[ch - 97];
				ptr->father = prev;
			}
			ptr->isEndWord = true;
			return;
		}
		else
		{
			ptr->children[ch - 97]->isEndWord = true;
			return;
		}
	}
	else
	{*/
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
	TrieNode* prev=NULL;
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

	char ch = str[str.size()-1];
	ptr = ptr->father;
	ptr->children[ch - 97] = NULL;
	ptr->countChildrens --;
	for (int i = str.size()-2; i >= 0; --i)
	{
		char ch = str[i];
		ptr = ptr->father;
		if (ptr->children[ch - 97]->isEndWord)
			return true;
		ptr->children[ch - 97] = NULL;
		ptr->countChildrens--;
		if (ptr->countChildrens != 1)
			return true;
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

void Trie::printAllWordsFromPrefix(TrieNode* node)
{

}

bool Trie::searchWord(string str, TrieNode* node)
{
	if (str.size() == 1)
	{
		if (node->children[str[0] - 97]->isEndWord)return true;
		else return false;
	}
	if (node->children[str[0] - 97] == NULL)return false;
	return searchWord(str.erase(0, 1), node->children[str[0] - 97]);
}

