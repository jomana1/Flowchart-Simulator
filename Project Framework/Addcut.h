#pragma once
#include "Statements/Statement.h"

//cut action is used to cut the any statement and paste it where the user wants

#include "Actions/Action.h"
class AddCut : public Action
{

private:
	Point s;
	string type;
	Statement* stat;
	//Position where the user clicks to add the stat.
public:
	AddCut(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};