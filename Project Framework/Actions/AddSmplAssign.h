#ifndef ADD_SMPL_ASSIGN_H
#define ADD_SMPL_ASSIGN_H

#include "Action.h"
#include "..\Statements\SmplAssign.h"

//Add Simple Assignment Statement Action
//This class is responsible for 
// 1 - Getting Assignment stat. coordinates from the user
// 2 - Creating an object of Assignment class and fill it parameters
// 3 - Adding the created object to the list of statements
class AddSmplAssign : public Action
{
	
private:
	string lhs;
	double rhs;
	Point Position;	//Position where the user clicks to add the stat.
public:
	AddSmplAssign(ApplicationManager *pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();
	
	//Create and add an assignemnt statement to the list of statements
	virtual void Execute() ;
	
};

#endif