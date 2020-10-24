#pragma once

#include <iostream>
#include <list>
class TreeList
{
protected:
	//inner claas Node
	class Node
	{
		std::string content;
		std::list<Node*> responses;
	public:
		Node(std::string con);
		std::string getContent();
		std::list<Node*>* getResponses();
		void setContent(std::string);
	};
	Node* root;
public:
	TreeList();//defult ctor
	~TreeList();//dtor
	TreeList(std::string content);
	Node* getRoot();
	Node* getNode(std::string content);
	bool addResponse(std::string father, std::string son);
	bool delSubTree(std::string content);
	void print();
	void printPath(std::string content);
	void printResponse(std::string content);
private:
	Node* getNode(std::list<Node*>* temp, std::string content);
	std::list<Node*>* printPath(std::list<Node*>* temp, std::string content, std::list<Node*>* lst);
	void delTree(std::list<Node*>* temp);
	void print(std::list<Node*>* temp,int space=1);
	std::list<Node*>* getList(std::list<Node*>*,std::string);
	//
};

