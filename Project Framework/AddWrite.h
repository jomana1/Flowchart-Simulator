#pragma once
#pragma once

#include "..\Project Framework\Actions\Action.h"
#include "..\Project Framework\Statements\SmplAssign.h"

//Add Write Assignment Statement Action
//This class is responsible for 
// 1 - Getting Write Assignment stat. coordinates from the user
// 2 - Creating an object of Assignment class and fill it parameters
// 3 - Adding the created object to the list of statements

class AddWrite : public Action
{

private:
	string var;
	Point Position;	//Position where the user clicks to add the stat.
public:
	AddWrite(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

