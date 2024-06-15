#pragma once
#include "Statements/Statement.h"

#include "Actions/Action.h"
class Run : public Action
{

private:
	Statement* pStat;
	Connector* pConn;
	bool stepbystep;
	
		//Position where the user clicks to add the stat.
public:
	Run(ApplicationManager* pAppManager,bool stepbystep=false);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

