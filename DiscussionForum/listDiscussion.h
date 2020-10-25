/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#pragma once
#include "tree.h"
class listDiscussion :public TreeList
{
public:
	listDiscussion();//default Ctor
	~listDiscussion();//Dtor
	
	void addNewTree(std::string r);//Adds a new tree (discussion) at the beginning of the list
    
	//Gets a node and deletes it and its children if it finds a root similar to it
	bool deltree(TreeList::Node* r);//if the operation fails returns false

	//Adds a node (response) in a tree that contains the title at its root
	bool addResponse(std::string title, std::string father, std::string son);
	//if the operation fails returns false
    
	//Deletes the node (comment) and its children in the tree containing the header at its root
	bool delResponse(std::string title, std::string father);//if the operation fails returns false
	
	//Looks for a node in the entire list of discussions that contains the response and prints it
	//in a hierarchical order and then prints the path
	void searchAndPrint(std::string val);//if the operation fails prints "ERROR"

	void printAllTrees();//Prints all the trees in a hierarchical order

	void printSubTree(std::string title, std::string father);
	//Prints the subwood that contains the title and path
private:
	std::list<TreeList*> lstRoot;
};

