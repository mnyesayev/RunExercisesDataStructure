#pragma once

#include "tree.h"
#include <algorithm>
class listDiscussion:public TreeList
{
public:
	listDiscussion();
	~listDiscussion();
	void addNewTree(std::string r);
	bool deltree1(TreeList::Node* r);
	bool delResponse(std::string title, std::string father, std::string son);
private:
	std::list<TreeList> lstRoot;
};

