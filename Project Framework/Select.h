#pragma once
#include "..\Project Framework\Actions\Action.h"
#include "../Project Framework/Statements/Statement.h"
#include "ApplicationManager.h"
 //this class is used to select any statement and change it's colors
class Select : public Action
{
private:
	string type;
	Statement* SelStat;
	Point Position;
	Connector* Conn;

public:
	Select(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};