#include "listDiscussion.h"

listDiscussion::listDiscussion(){}

listDiscussion::~listDiscussion()
{
}

void listDiscussion::addNewTree(std::string r)
{
	lstRoot.push_back(TreeList(r));
}
bool listDiscussion::deltree1(TreeList::Node* r)
{
	if (r == nullptr)
		return false;
	else
	{
		for (auto it = lstRoot.begin(); it != lstRoot.end(); ++it)
		{
			
			if (r->getContent() == (*it).root->getContent())

		}
	}
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