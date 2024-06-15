#pragma once
#include "Statements/Statement.h"

#include "Actions/Action.h"
class ToSim : public Action
{

private:
	Point s;
	
public:
	ToSim(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};

