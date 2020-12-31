#include "huffman.h"
using namespace std;


void HuffmanTree::buildTree(string word)
{

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
		pQueue.push(new HuffmanNode(data[i].letter,data[i].frequency));
	}
	while (pQueue.size()>1)
	{
		HuffmanNode* ptr = new HuffmanNode();
		HuffmanNode* tmp1 = pQueue.top();
		pQueue.pop();
		HuffmanNode* tmp2 = pQueue.top();
		pQueue.pop();
		if (tmp1->getFrequency() == tmp2->getFrequency())
		{
			ptr->setLeft(tmp2);
			ptr->setRight(tmp1);
		}
		else
		{
			ptr->setLeft(tmp1);
			ptr->setRight(tmp2);
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
	inOrder(root, structTtree, codes,code,leavs);
	cout << data.size()<<endl;
	cout << leavs<<endl;
	cout << structTtree<<endl;
	string allCode;
	for (int i = 0; i < word.size(); i++)
	{
		char ch = word[i];
		for (int j = 0; j < leavs.size(); j++)
		{
			if (ch ==leavs[j])
			{
				allCode += codes[j];
				break;
			}
		}
	}
	cout << allCode<<endl;

}

void HuffmanTree::inOrder(HuffmanNode* node, string& sT, vector<string>& codes,string& code, string& leavs)
{
	if (node==NULL)
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
	inOrder(node->getLeft(), sT += "0",codes,code+="0",leavs);
	code.resize(code.size() - 1);
	inOrder(node->getRight(), sT ,codes,code+="1",leavs);
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


