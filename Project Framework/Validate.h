#pragma once
#include "Statements/Statement.h"

#include "Actions/Action.h"
class Validate : public Action
{

private:
	bool val1;
	bool val2;

public:
	Validate(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};
