#include "listDiscussion.h"

listDiscussion::listDiscussion(){}

listDiscussion::~listDiscussion()
{
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
/*
bool listDiscussion::deltree1(TreeList::Node* r)
{
	if(r==nullptr)
	   return false;
	else
	{
		for (auto it = lstRoot.begin(); it != lstRoot.end(); ++it)
		{
			if(r->getContent()==(*it)->)

	    }
	}
}
*/