#include "tree.h"
using namespace std;

TreeList::Node::Node(std::string con):content(con){}

std::string TreeList::Node::getContent()
{
	return content;
}

list<TreeList::Node*> TreeList::Node::getResponses()
{
	return responses;
}

TreeList::TreeList():root(nullptr){}

TreeList::~TreeList(){}

TreeList::TreeList(std::string content)
{
	if (!root)
		root = new Node(content);
	else
	{
		delete root;
		root = new Node(content);
	}
}

TreeList::Node* TreeList::getNode(std::string content)
{
	if(!root&&root->getContent()==content)
	return root;
	auto temp = root->getResponses();
	
	for ( auto it=temp.begin(); it!=temp.end(); ++it)
	{
		if ((*it)->getContent()==content)
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

TreeList::Node* TreeList::getNode(list<Node*> temp, std::string content)
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

