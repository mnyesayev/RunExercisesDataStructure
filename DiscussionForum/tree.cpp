/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#include "tree.h"

using namespace std;

void TreeList::Node::setContent(string con) { content = con; }

TreeList::Node::Node(string con) :content(con) {}

string TreeList::Node::getContent() { return content; }

list<TreeList::Node*>* TreeList::Node::getResponses()
{
	list<TreeList::Node*>* temp = NULL;
	temp = &responses;
	return temp;
}

TreeList::TreeList() :root(NULL) {}

TreeList::~TreeList()
{
	if (root != NULL)
	{
		if (!root->getResponses()->empty())
			delTree(root->getResponses());
		root = NULL;
	}
}

TreeList::TreeList(string content)
{
	if (root == NULL)
		root = new Node(content);
	else
	{
		if (!root->getResponses()->empty())//if the list no empty
			delTree(root->getResponses());//delete old list 
		root->setContent(content);//update new root
	}
}

TreeList::Node* TreeList::getRoot() { return root; }

/// <summary>
/// Searches for a node by the string given in the parameter
/// </summary>
/// <param name="content"></param>
/// <returns>Node*</returns>
TreeList::Node* TreeList::getNode(string content)
{
	if (root == NULL)
		return NULL;
	if (root->getContent() == content)
		return root;
	if (!root->getResponses()->empty()) {
		Node* tmp = getNode(root->getResponses(), content);//Call to the recursive function
		if (tmp != NULL)
			return tmp;
	}
	return NULL;
}

bool TreeList::addResponse(string father, string son)
{
	Node* curNode = getNode(father);//Search the father at tree
	if (curNode == NULL)
		return false;//not found
	Node* newNode = new Node(son);
	curNode->getResponses()->push_back(newNode);//adds the new node at end of list
	return true;
}

bool TreeList::delSubTree(string content)
{
	list<Node*>* tmp = getList(root->getResponses(), content);//Call to the recursive function that returns the list of "content 
	if (!tmp)
		return false;//not success
	list<Node*>::iterator it;
	for (it = tmp->begin(); it != tmp->end(); ++it)
	{
		if ((*it)->getContent() == content)
		{
			if (!(*it)->getResponses()->empty())
			{
				delTree((*it)->getResponses());//recursive function that delets sons
			}
			//delete father
			delete* it;
			tmp->remove(*it);
			return true;
		}
	}
	return false;//not success
}

void TreeList::print()
{
	//We used the visiting method preorder
	if (root == NULL)
		return;
	else
	{
		cout << root->getContent() << endl;
		if (!root->getResponses()->empty())
			print(root->getResponses());//Call to the recursive function
	}
}
void TreeList::printPath(std::string content)
{
	if (root->getContent() == content) {
		return;
	}
	list<Node*>* lst = new list<Node*>;
	lst->push_front(root);
	if (!root->getResponses()->empty()) {
		lst = printPath(root->getResponses(), content, lst);
	}
	else {
		lst->clear();
		lst = NULL;
	}
	if (lst != NULL) {
		list<Node*>::iterator it;
		for (it = lst->begin(); it != lst->end(); ++it) {
			if (it == lst->begin())
				cout << (*it)->getContent();
			cout << "=>" << (*it)->getContent();
		}
		cout << endl;
	}
	if (lst != NULL && !lst->empty()) {
		lst->clear();
		lst = NULL;
	}
}
bool TreeList::printSubTree(string content)
{
	Node* temp = getNode(content);
	if (temp == NULL) {
		return false;//Not printing occurred
	}
	else
	{
		cout << temp->getContent() << endl;
		if (!temp->getResponses()->empty())
			print(temp->getResponses());//Call to the recursive function
		return true;//Printing occurred 
	}
}
//private functions:

/// <summary>
/// A recursive function that gets a pointer to the list and a string. 
/// searches for the string in the tree by preorder
/// </summary>
/// <param name="temp"></param>
/// <param name="content"></param>
/// <returns>Node*</returns>
TreeList::Node* TreeList::getNode(list<Node*>* temp, string content)
{
	list<Node*>::iterator it;
	for (it = temp->begin(); it != temp->end(); ++it)
	{
		if ((*it)->getContent() == content)
		{
			return *it;//found(stop condition)
		}
		else
		{
			if (!(*it)->getResponses()->empty())
			{
				Node* tmp = getNode((*it)->getResponses(), content);//call recursive
				if (tmp != NULL)
					return tmp;
			}
		}
	}
	return NULL;//not found
}
//recursive func. to build direct path from content to root
list<TreeList::Node*>* TreeList::printPath(list<Node*>* temp, string content, list<Node*>* lst)
{
	list<Node*>::iterator it;
	for (it = temp->begin(); it != temp->end(); ++it)
	{
		lst->push_front(*it);
		if ((*it)->getContent() == content)
		{
			return lst;
		}
		else
		{
			if (!(*it)->getResponses()->empty())
			{
				list<Node*>* tmp = printPath((*it)->getResponses(), content, lst);
				if (tmp != NULL)
					return tmp;
			}
		}
		lst->remove(lst->front());
	}
	return NULL;
}
//delete all tree 
void TreeList::delTree(list<Node*>* cur)
{
	list<Node*>::iterator it;
	for (it = cur->begin(); it != cur->end(); it++)
	{
		if (!(*it)->getResponses()->empty())
			delTree((*it)->getResponses());
		else
		{
			delete* it;
			*it = NULL;
			cur->remove(*it);
			return;
		}
	}
}
/// <summary>
/// A recursive function that gets a pointer to a list and a value with a default of 1 (for printing spaces).
/// And each level you enter the depth of the tree the value increases by 1 and when you return the value decreases by 1
/// ,and here too using in preorder and by all this we can print tree in a hierarchical order
/// </summary>
/// <param name="temp"></param>
/// <param name="space"></param>
void TreeList::print(list<Node*>* temp, int space)
{
	list<Node*>::iterator it;
	for (it = temp->begin(); it != temp->end(); ++it)
	{
		for (int i = 0; i < space; ++i)
			cout << "   ";
		cout << (*it)->getContent() << endl;
		if (!(*it)->getResponses()->empty()) {
			print((*it)->getResponses(), ++space);
			--space;
		}
	}
}

/// <summary>
/// A recursive function that gets a pointer to the list and a string. 
/// searches for the string in the tree by preorder
/// </summary>
/// <param name="temp"></param>
/// <param name="content"></param>
/// <returns> list </returns>
list<TreeList::Node*>* TreeList::getList(list<Node*>* temp, string content)
{
	list<Node*>::iterator it;
	for (it = temp->begin(); it != temp->end(); ++it)
	{
		if ((*it)->getContent() == content)
		{
			return temp;
		}
		else
		{
			if (!(*it)->getResponses()->empty())
			{
				list<Node*>* tmp = getList((*it)->getResponses(), content);
				if (tmp != NULL)
					return tmp;
			}
		}
	}
	return NULL;
}
