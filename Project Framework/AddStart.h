#pragma once

#include "..\Project Framework\Actions\Action.h"
#include "..\Project Framework\Statements\SmplAssign.h"

//Add Start Assignment Statement Action
//This class is responsible for 
// 1 - Getting start Assignment stat. coordinates from the user
// 2 - Creating an object of  start Assignment 
// 3 - Adding the created object to the list of statements

class AddStart : public Action
{

private:
	Point Position;	//Position where the user clicks to add the stat.
public:
	AddStart(ApplicationManager* pAppManager);

	//Start Assignemt statements position
	virtual void ReadActionParameters();
	
	//Create and add a Start statement to the list of statements
	virtual void Execute();

};
