/*
Authors:
Matan Netanel Yesayev ,ID:207883729
Asher Mentzer,ID:312505563
*/
#include "listDiscussion.h"
using namespace std;
listDiscussion::listDiscussion() {}

listDiscussion::~listDiscussion()
{
	list<TreeList*>::iterator it;
	for ( it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		(*it)->~TreeList();
	}
	lstRoot.clear();
}

void listDiscussion::addNewTree(std::string r)
{
	TreeList* tmp = new TreeList(r);
	lstRoot.push_front(tmp);//add to head of list
}
bool listDiscussion::deltree(TreeList::Node* r)
{
	if (r == NULL)
		return false;
	else
	{
		list<TreeList*>::iterator it;
		for (it = lstRoot.begin(); it != lstRoot.end(); ++it)
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
		return false;//not success
	list<TreeList*>::iterator it;
	for ( it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		if ((*it)->getRoot()->getContent() == title)
		{
			if ((*it)->addResponse(father, son))//call to func. of TreeList 
				return true;//success
		}
	}
	return false;//not success
}

bool listDiscussion::delResponse(std::string title, std::string father)
{
	list<TreeList*>::iterator it;
	for ( it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		if ((*it)->getRoot()->getContent() == title)
		{
			if ((*it)->getRoot()->getContent() == father)
			{
				if (!(*it)->getRoot()->getResponses()->empty())
				{
					list<Node*>* cur = (*it)->getRoot()->getResponses();
					(*it)->delTree(cur);
				}
				delete* it;
				*it = NULL;
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
    bool check=0;//A Boolean variable to check if printing has occurred
	list<TreeList*>::iterator it;
	for ( it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		if((*it)->printSubTree(val))
		    check=1;
		(*it)->printPath(val);
	}
	if(check==0)
	    cout << "ERROR\n" << endl;
}

void listDiscussion::printAllTrees()
{
	int i = 1;
	list<TreeList*>::iterator it;
	for ( it = lstRoot.begin(); it != lstRoot.end(); ++i, it++)
	{
		cout << "Tree #" << i << endl;
		(*it)->print();
	}
}

void listDiscussion::printSubTree(std::string title, std::string father)
{
	list<TreeList*>::iterator it;
	for ( it = lstRoot.begin(); it != lstRoot.end(); it++)
	{
		if ((*it)->getRoot()->getContent() == title){
			(*it)->printSubTree(father);
			(*it)->printPath(father);
		}
	}
}
