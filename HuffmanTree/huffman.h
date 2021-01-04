/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#pragma once
#include <string>
#include<vector>
#include "data.h"
#include <queue>

class compareNode;

class HuffmanTree:Data
{
private:
	friend class compareNode;
	//friend class Data;
	class HuffmanNode 
	{
	
		std::string str;
		int frequency;
		HuffmanNode* left;
		HuffmanNode* right;
		friend class compareNode;
	public:
		HuffmanNode() { frequency = 0; left = NULL; right = NULL; }
		HuffmanNode(char ch, int frequency) { this->str += ch; this->frequency = frequency; left = NULL; right = NULL;
		}
		void setStr(std::string st) { str = st; }
		std::string getStr() { return str; }
		void setFrequency(int f) { frequency = f; }
		int getFrequency() { return frequency; }
		void setLeft(HuffmanNode* p) { left = p; }
		HuffmanNode* getLeft() { return left; }
		void setRight(HuffmanNode* p) { right = p; }
		HuffmanNode* getRight() { return right; }
	};
public:
	HuffmanNode* root;
	std::vector < Data > data;
	//std::vector<int> frequencyPerLatter;
	HuffmanTree() { root = NULL; }
	void buildTree(std::string word);
	void printDetails(std::string word);
private :
	class compareNode
	{
	public:
		bool operator()(HuffmanTree::HuffmanNode* const& n1, HuffmanTree::HuffmanNode* const& n2)
		{
			return n1->getFrequency() > n2->getFrequency();
		}
	};
	void inOrder(HuffmanNode*, std::string&, std::vector<std::string>&, std::string&, std::string&);
	int checkData(char ch);
	std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, compareNode> pQueue;
};



