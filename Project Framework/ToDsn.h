#pragma once
#include "Statements/Statement.h"

#include "Actions/Action.h"
class ToDsn : public Action
{

private:
	Point s;

public:
	ToDsn(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};

