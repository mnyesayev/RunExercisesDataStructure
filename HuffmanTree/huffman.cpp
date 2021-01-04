/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#include "huffman.h"

using namespace std;

void HuffmanTree::buildTree(string word)
{
	this->clear();
	for (int i = 0; i < word.size(); i++)
	{
		char ch = word[i];
		int index = checkData(ch);
		if (index == -1)
		{
			Data* d = new Data(ch);
			this->data.push_back(*d);
		}
		else
		{
			data[index].frequency++;
		}
	}
	for (int i = 0; i < data.size(); i++)
	{
		pQueue.push(new HuffmanNode(data[i].letter, data[i].frequency));
	}
	while (pQueue.size() > 1)
	{
		HuffmanNode* ptr = new HuffmanNode();
		HuffmanNode* tmp1 = pQueue.top();
		pQueue.pop();
		HuffmanNode* tmp2 = pQueue.top();
		pQueue.pop();
		if (tmp1->getFrequency() <= tmp2->getFrequency())
		{
			ptr->setLeft(tmp1);
			ptr->setRight(tmp2);
		}
		else
		{
			ptr->setLeft(tmp2);
			ptr->setRight(tmp1);
		}
		ptr->setFrequency(ptr->getLeft()->getFrequency() + ptr->getRight()->getFrequency());
		pQueue.push(ptr);
	}
	root = pQueue.top();
}

void HuffmanTree::printDetails(string word)
{
	if (root == NULL)
		return;
	string leavs;
	string structTtree;
	string code;
	vector<string> codes;
	inOrder(root, structTtree, codes, code, leavs);
	cout << data.size() << endl;
	cout << leavs << endl;
	cout << structTtree << endl;
	string allCode;
	for (int i = 0; i < word.size(); i++)
	{
		char ch = word[i];
		for (int j = 0; j < leavs.size(); j++)
		{
			if (ch == leavs[j])
			{
				allCode += codes[j];
				break;
			}
		}
	}
	cout << allCode << endl;

}

void HuffmanTree::encode(int n, std::string& letters, std::string& code, std::string word)
{
	this->clear();
	root = new HuffmanNode();
	HuffmanNode* ptr = root;	
	encode(root, letters, code);
	for (int i = 0; i < word.size(); ++i)
	{
		if (!(ptr->getStr().empty()))
		{
			cout << ptr->getStr();
			ptr = root;
		}
		if (word[i] == '0')
		{
			ptr = ptr->getLeft();
			if (!(ptr->getStr().empty()))
			{
				cout << ptr->getStr();
				ptr = root;
			}
		}
		else
		{
			ptr = ptr->getRight();
			if (!(ptr->getStr().empty()))
			{
				cout << ptr->getStr();
				ptr = root;
			}
		}
	}
}

void HuffmanTree::clear()
{
	if (root != NULL)
	{
		delete root;
		root = NULL;
	}
	data.clear();
	while (!pQueue.empty())pQueue.pop();
}

void HuffmanTree::inOrder(HuffmanNode* node, string& sT, vector<string>& codes, string& code, string& leavs)
{
	if (node == NULL)
	{
		sT.resize(sT.size() - 1);
		sT += "1";
		return;
	}
	if (node->getStr() != "")
	{
		codes.push_back(code);
		leavs += node->getStr();
	}
	inOrder(node->getLeft(), sT += "0", codes, code += "0", leavs);
	code.resize(code.size() - 1);
	inOrder(node->getRight(), sT, codes, code += "1", leavs);
	code.resize(code.size() - 1);
}

int HuffmanTree::checkData(char ch)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].letter == ch)
			return i;
	}
	return -1;
}

void HuffmanTree::encode(HuffmanNode* node, std::string& letters, std::string& code)
{
	if (code.size() == 0)return;

	if (code[0] == '0')
	{
		node->setLeft(new HuffmanNode());
		node->setRight(new HuffmanNode());
		code=code.erase(0,1);
	    encode(node->getLeft(), letters, code);
	}
	else
	{
		if (node->getLeft() == NULL)
		{
			node->setStr(letters[0]);
			letters = letters.erase(0,1);
			code = code.erase(0,1);
			return;
		}				
	}
   encode(node->getRight(), letters, code);
}


