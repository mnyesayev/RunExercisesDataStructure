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

list<TreeList::Node*>* TreeList::Node::getResponses()
{
	list<TreeList::Node*>* temp;
	temp = &responses;
	return temp;
}

TreeList::TreeList() :root(nullptr) {}

TreeList::~TreeList()
{
	if (root != nullptr)
	{
		if (!root->getResponses()->empty())
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
		if (!root->getResponses()->empty())
			delTree(root->getResponses());
		root->setContent(content);
	}
}

TreeList::Node* TreeList::getRoot()
{
	return root;
}

TreeList::Node* TreeList::getNode(string content)
{
	if (root == nullptr)
		return nullptr;
	if (root->getContent() == content)
		return root;
	if (!root->getResponses()->empty()) {
		Node* tmp = getNode(root->getResponses(), content);
		if (tmp != nullptr)
			return tmp;
	}
	return nullptr;
}

bool TreeList::addResponse(string father, string son)
{
	Node* curNode = getNode(father);
	if (curNode == nullptr)
		return false;
	Node* newNode = new Node(son);
	curNode->getResponses()->push_back(newNode);
	return true;
}

bool TreeList::delSubTree(string content)
{
	list<Node*>* tmp = getList(root->getResponses(), content);
	if (!tmp)
		return false;
	for (auto it = tmp->begin(); it != tmp->end(); ++it)
	{
		if((*it)->getContent()==content)
		{
		if (!(*it)->getResponses()->empty())
		{
			delTree((*it)->getResponses());
		}
			delete* it;
			tmp->remove(*it);
			return true;
		}
	}
	return false;
}
void TreeList::print()
{
	if (root == nullptr)
		return;
	else
	{
		cout << root->getContent() << endl;
		if (!root->getResponses()->empty())
			print(root->getResponses());
	}
}
void TreeList::printPath(std::string content)
{
	if (root->getContent() == content) {
		//cout << root->getContent();
		return;
	}
	list<Node*>* lst = new list<Node*>;
	lst->push_front(root);
	if (!root->getResponses()->empty()) {
		lst = printPath(root->getResponses(), content, lst);
	}
	else {
		lst->clear();
		lst = nullptr;
	}
	if (lst != nullptr) {
		auto it = lst->begin();
		cout << (*it)->getContent();
		++it;
		for (it; it != lst->end(); ++it) {
			cout << "=>" << (*it)->getContent();
		}
		cout << endl;
	}
	if (lst != nullptr && !lst->empty()) {
		lst->clear();
		lst = nullptr;
	}
}
bool TreeList::printResponse(string content)
{
	Node* temp = getNode(content);
	if (temp == nullptr){
		return false;
	}
	else
	{
		cout << temp->getContent() << endl;
		if (!temp->getResponses()->empty())
			print(temp->getResponses());
		return true;
	}
}

void TreeList::delTree(list<Node*>* cur)
{
	for (auto it = cur->begin(); it != cur->end(); it++)
	{
		if (!(*it)->getResponses()->empty())
			delTree((*it)->getResponses());
		else
		{
			delete* it;
			*it = nullptr;
			cur->remove(*it);
			return;
		}
	}
}

//private functions:


TreeList::Node* TreeList::getNode(list<Node*>* temp, string content)
{
	for (auto it = temp->begin(); it != temp->end(); ++it)
	{
		if ((*it)->getContent() == content)
		{
			return *it;
		}
		else
		{
			if (!(*it)->getResponses()->empty())
			{
				Node* tmp = getNode((*it)->getResponses(), content);
				if (tmp != nullptr)
					return tmp;
			}
		}
	}
	return nullptr;
}

list<TreeList::Node*>* TreeList::printPath(list<Node*>* temp, string content, list<Node*>* lst)
{
	for (auto it = temp->begin(); it != temp->end(); ++it)
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
				if (tmp != nullptr)
					return tmp;
			}
		}
		lst->remove(lst->front());
	}
	return nullptr;
}
void TreeList::print(list<Node*>* temp, int space)
{
	for (auto it = temp->begin(); it != temp->end(); ++it)
	{
		for (int i = 0; i < space; ++i)
			cout << "	";
		cout << (*it)->getContent() << endl;
		if (!(*it)->getResponses()->empty()) {
			print((*it)->getResponses(), ++space);
			--space;
		}
	}
}

std::list<TreeList::Node*>* TreeList::getList(std::list<Node*>* temp, std::string content)
{
	for (auto it = temp->begin(); it != temp->end(); ++it)
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
				if (tmp != nullptr)
					return tmp;
			}
		}
	}
	return nullptr;
}
