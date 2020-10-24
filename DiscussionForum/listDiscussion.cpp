#include "listDiscussion.h"
using namespace std;
listDiscussion::listDiscussion(){}

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
	TreeList* tmp=new TreeList(r);
	lstRoot.push_back(tmp);
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
	for (auto it = lstRoot.begin(); it!=lstRoot.end(); it++)
	{
		if ((*it)->getRoot()->getContent() == title)
		{
			if((*it)->addResponse(father, son))
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
			if ((*it)->getRoot()->getResponses()->empty()) {
				delete* it;
				*it = nullptr;
				this->lstRoot.remove(*it);
				return true;
			}
			if ((*it)->delSubTree(father))
				return true;
		}
	}
	return false;
}

void listDiscussion::searchAndPrint(std::string val)
{
	for (auto it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		(*it)->printResponse(val);
		(*it)->printPath(val);
	}
}

void listDiscussion::printAllTrees()
{
	int i = 1;
	for (auto it = lstRoot.begin(); it != lstRoot.end(); ++i,it++)
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
			(*it)->printResponse(father);
	}
}
