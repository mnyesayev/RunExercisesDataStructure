#pragma once

#include <iostream>
#include <list>
class TreeList
{
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
	TreeList();
	~TreeList();
	TreeList(std::string content);
	Node* getNode(std::string content);
	void addResponse(std::string father, std::string son);
	void delSubTree(std::string content);
	void print();
	void printPath(std::string content);
	void printResponse(std::string content);
private:
	Node* getNode(std::list<Node*>* temp, std::string content);
	std::list<Node*>* printPath(std::list<Node*>* temp, std::string content, std::list<Node*>* lst);
	void delTree(std::list<Node*>* temp);
	void print(std::list<Node*>* temp,int space=1);

};

