#pragma once
#include "Statements/Statement.h"

#include "Actions/Action.h"
class EditStat : public Action
{

private:
	Point Position;
	string type;
	Statement* ed;
	//Position where the user clicks to add the stat.
public:
    EditStat(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};
