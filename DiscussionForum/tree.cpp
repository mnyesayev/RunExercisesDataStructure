#include "tree.h"

using namespace std;

void TreeList::Node::setContent(string con)
{
	content = con;
}

TreeList::Node::Node(string con) :content(con) {}

std::string TreeList::Node::getContent()
{
	return content;
}

list<TreeList::Node*> TreeList::Node::getResponses()
{
	return responses;
}

TreeList::TreeList() :root(nullptr) {}

TreeList::~TreeList()
{
	if (root != nullptr)
	{
		if (!root->getResponses().empty())
			delTree(root->getResponses());
		root = nullptr;
	}
}

TreeList::TreeList(string content)
{
	if (root == nullptr)
		root = new Node(content);
	else
	{
		if (!root->getResponses().empty())
			delTree(root->getResponses());
		root->setContent(content);
	}
}

TreeList::Node* TreeList::getNode(string content)
{
	if (root == nullptr)
		return nullptr;
	if (root->getContent() == content)
		return root;
	if (!root->getResponses().empty()) {
		Node* tmp = getNode(root->getResponses(), content);
		if (tmp != nullptr)
			return tmp;
	}
	return nullptr;
}
void TreeList::addResponse(string father, string son)
{
	Node* curNode = getNode(father);
	if (curNode == nullptr)
		throw "This father not exist";
	Node* newNode = new Node(son);
	curNode->getResponses().push_back(newNode);
}
void TreeList::delSubTree(string content)
{
	Node* curNode = getNode(content);
	if (curNode != nullptr && !curNode->getResponses().empty())
		delTree(curNode->getResponses());
}
void TreeList::print()
{
	if (root == nullptr)
		return;
	else
	{
		cout << root->getContent() << endl;
		if (!root->getResponses().empty())
			print(root->getResponses());
	}
}
void TreeList::printPath(std::string content)
{
	if (root->getContent() == content) {
		cout << root->getContent();
		return;
	}
	list<Node*>* lst = new list<Node*>;
	lst->push_back(root);
	if (!root->getResponses().empty()) {
		lst = printPath(root->getResponses(), content, lst);
	}
	if (lst != nullptr) {
		for (auto it = lst->begin(); it != lst->end(); ++it) {
			cout << (*it)->getContent() << endl << "	";
		}
	}
	lst->clear();
	lst = nullptr;
}
void TreeList::printResponse(string content)
{
	Node* temp = getNode(content);
	if (temp == nullptr)
		return;
	else
	{
		cout << temp->getContent() << endl;
		if (!temp->getResponses().empty())
			print(temp->getResponses());
	}
}
//private functions:
TreeList::Node* TreeList::getNode(list<Node*> temp, string content)
{
	for (auto it = temp.begin(); it != temp.end(); ++it)
	{
		if ((*it)->getContent() == content)
		{
			return *it;
		}
		else
		{
			if (!(*it)->getResponses().empty())
			{
				Node* tmp = getNode((*it)->getResponses(), content);
				if (tmp != nullptr)
					return tmp;
			}
		}
	}
	return nullptr;
}
list<TreeList::Node*>* TreeList::printPath(list<Node*> temp, string content, list<Node*>* lst)
{
	for (auto it = temp.begin(); it != temp.end(); ++it)
	{
		lst->push_back(*it);
		if ((*it)->getContent() == content)
		{
			return lst;
		}
		else
		{
			if (!(*it)->getResponses().empty())
			{
				list<Node*>* tmp = printPath((*it)->getResponses(), content, lst);
				if (tmp != nullptr)
					return tmp;
			}
		}
		lst->remove(lst->back());
	}
	return nullptr;
}
void TreeList::delTree(list<Node*> cur)
{
	for (auto it = cur.begin(); it != cur.end(); it++)
	{
		if (!(*it)->getResponses().empty())
			delTree((*it)->getResponses());
		else
		{
			delete* it;
			*it = nullptr;
		}
	}
}
void TreeList::print(list<Node*> temp, int space)
{
	for (int i = 0; i < space; ++i)
		cout << "	";
	for (auto it = temp.begin(); it != temp.end(); ++it)
	{
		cout << (*it)->getContent() << endl;
		if (!(*it)->getResponses().empty())
			print((*it)->getResponses(), ++space);
	}
}
