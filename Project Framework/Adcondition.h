#pragma once

#include "..\Project Framework\Actions\Action.h"
#include "..\Project Framework\Condition.h"
//Add Condition Assignment Statement Action
//This class is responsible for 
// 1 - Getting Condition stat. coordinates from the user
// 2 - Creating an object of Assignment class and fill it parameters
// 3 - Adding the created object to the list of statements

class Addcondition : public Action
{

private:
	string LHS;  
	string op;
	double RHS;
	Point Position;	//Position where the user clicks to add the stat.
public:
	Addcondition(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};


