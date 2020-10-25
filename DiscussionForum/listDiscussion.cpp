#include "listDiscussion.h"
using namespace std;
listDiscussion::listDiscussion() {}

listDiscussion::~listDiscussion()
{
	for (auto it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		(*it)->~TreeList();
	}
	lstRoot.clear();
}

void listDiscussion::addNewTree(std::string r)
{
	TreeList* tmp = new TreeList(r);
	lstRoot.push_front(tmp);
}
bool listDiscussion::deltree1(TreeList::Node* r)
{
	if (r == nullptr)
		return false;
	else
	{
		for (auto it = lstRoot.begin(); it != lstRoot.end(); ++it)
		{
			if (r->getContent() == (*it)->getRoot()->getContent())
				(*it)->delSubTree(r->getContent());
			return true;
		}
	}
	return false;
}

bool listDiscussion::addResponse(std::string title, std::string father, std::string son)
{
	if (lstRoot.empty())
		return false;
	for (auto it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		if ((*it)->getRoot()->getContent() == title)
		{
			if ((*it)->addResponse(father, son))
				return true;
		}
	}
	return false;
}

bool listDiscussion::delResponse(std::string title, std::string father)
{
	for (auto it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		if ((*it)->getRoot()->getContent() == title)
		{
			if ((*it)->getRoot()->getContent() == father)
			{
				if (!(*it)->getRoot()->getResponses()->empty()){
					list<Node*>* cur = (*it)->getRoot()->getResponses();
					(*it)->delTree(cur);
				}
				delete* it;
				*it = nullptr;
				this->lstRoot.remove(*it);
				return true;
			}
			else if ((*it)->delSubTree(father))
				return true;
		}
	}
	return false;
}

void listDiscussion::searchAndPrint(std::string val)
{
	bool check = 0;
	for (auto it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		if ((*it)->printResponse(val))
			check = 1;
		(*it)->printPath(val);
	}
	if(check==0)
		cout << "ERROR\n" << endl;
}

void listDiscussion::printAllTrees()
{
	int i = 1;
	for (auto it = lstRoot.begin(); it != lstRoot.end(); ++i, it++)
	{
		cout << "Tree #" << i << endl;
		(*it)->print();
	}
}

void listDiscussion::printSubTree(std::string title, std::string father)
{
	for (auto it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		if ((*it)->getRoot()->getContent() == title)
		{
			(*it)->printResponse(father);
			(*it)->printPath(father);
		}
	}
}
