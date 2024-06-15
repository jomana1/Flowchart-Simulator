#pragma once
#include "..\Project Framework\Actions\Action.h"
#include "../Project Framework/Statements/Statement.h"
#include "ApplicationManager.h"
 //this class is used to select any statement and change it's colors
class Comment : public Action
{
private:
	Statement* SelStat;
	Point Position;
	Connector* Conn;

public:
	Comment(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};