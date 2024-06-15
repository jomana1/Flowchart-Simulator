#pragma once
#include "..\Project Framework\Actions\Action.h"
#include "..\Project Framework\Addvarassign.h"

//Add Variable Assignment Statement Action
//This class is responsible for 
// 1 - Getting Variable Assignment stat. coordinates from the user
// 2 - Creating an object of Assignment class and fill it parameters
// 3 - Adding the created object to the list of statements

//Add variable assignment Statement Action
class Addvarassign : public Action
{

private:
	string LHS;
	string RHS;
	Point Position;	//Position where the user clicks to add the stat.
public:
	Addvarassign(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};


