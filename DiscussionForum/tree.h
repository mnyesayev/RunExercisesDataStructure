/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
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
		Node(std::string con);//Ctor

		//get&&set func.
		std::string getContent();
		std::list<Node*>* getResponses();
		void setContent(std::string);
	};
	Node* root;
public:
	TreeList();//defult Ctor
	~TreeList();//Dtor
	TreeList(std::string content);//Ctor

	Node* getRoot();
	Node* getNode(std::string content);	//Returns a pointer to a Node by a string

	bool addResponse(std::string father, std::string son);//Adds the son to the father
	//if the operation fails returns false

	bool delSubTree(std::string content);//Deletes the node containing the string and its children
	//if the operation fails returns false

	void print();//Prints the tree in a hierarchical order
	
	void printPath(std::string content);//Prints the path from content to root
	
	bool printSubTree(std::string content);//Prints the subtree in a hierarchical order
	//if the operation fails returns false

	void delTree(std::list<Node*>* temp);//gets list of node* and delete them.
private:
	
	//Auxiliary functions for internal use
	Node* getNode(std::list<Node*>* temp, std::string content);
	std::list<Node*>* printPath(std::list<Node*>* temp, std::string content, std::list<Node*>* lst);
	void print(std::list<Node*>* temp, int space = 1);
	std::list<Node*>* getList(std::list<Node*>*, std::string);
	
};


