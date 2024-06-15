#pragma once

#include "..\Project Framework\Actions\Action.h"
#include "..\Project Framework\Statements\SmplAssign.h"

//Add End Assignment Statement Action
//This class is responsible for 
// 1 - Getting End stat. coordinates from the user
// 2 - Creating an object of End Assignment class
// 3 - Adding the created object to the list of statements
class AddEnd : public Action
{

private:
	Point Position;	//Position where the user clicks to add the stat.
public:
	AddEnd(ApplicationManager* pAppManager);

	//Start Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add a Start statement to the list of statements
	virtual void Execute();

};

