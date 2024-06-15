#pragma once
#include "Statements/Statement.h"

#include "Actions/Action.h"
class addDelete : public Action
{

private:
	Point s;
	string type;
	Statement* stat;
	//Position where the user clicks to add the stat.
public:
	addDelete(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};