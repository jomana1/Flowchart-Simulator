#pragma once
#include "Statements/Statement.h"

 // class copy is used to copy all the statements in the flow chart
#include "Actions/Action.h"
class Addcopy : public Action
{

private:
	Point s;
	string type;
	Statement* stat;
	//Position where the user clicks to add the stat.
public:
	Addcopy(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};
