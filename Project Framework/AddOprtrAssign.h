#pragma once
#include "..\Project Framework\Actions\Action.h"
#include "..\Project Framework\OprtrAssign.h"

//Add Operator Assignment Statement Action
//This class is responsible for 
// 1 - Getting Operator Assignment stat. coordinates from the user
// 2 - Creating an object of Assignment class and fill it parameters
// 3 - Adding the created object to the list of statements

class AddOprtrAssign : public Action
{

private:
	string LHS;  // the left side of the assignment (variable part)
	string LHS1;  //the 1st part of the equation (variable part)
	string op;   //the equal operator
	string op1;   //the operator of the equation
	double RHS1;   //the 2nd part of the equation (value part)
	Point Position;	//Position where the user clicks to add the stat.
public:
	AddOprtrAssign(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};