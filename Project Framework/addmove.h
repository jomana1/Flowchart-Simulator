#pragma once
#include "Statements/Statement.h"

//class move is used to move all of the statements with it's connectors

#include "Actions/Action.h"
class MOve : public Action
{

private:
	Point s;
	string type;
	Statement* stat;
	//Position where the user clicks to add the stat.
public:
	MOve(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

