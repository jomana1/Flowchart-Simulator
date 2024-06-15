#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"
class MultSel :public Action
{
	int c;
	Statement* SelStat;
	Point Position;
	Connector* Conn;
public:
	MultSel(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};

