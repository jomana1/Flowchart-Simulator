#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Statements\Statement.h"
class Input;
class Output;


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxCount = 200 };	//Max no of statements/connectors in a single flowchart

private:
	int StatCount;		//Actual number of statements
	int ConnCount;		//Actual number of connectors
	Statement* StatList[MaxCount];	//List of all statements (Array of pointers)
	Connector* ConnList[MaxCount];	//List of all connectors (Array of pointers)

	Statement *pSelectedStat; //a pointer to the last selected statement

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;


public:	
	bool u;
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Actions Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void setu(bool c);
	int GetStatCount();
	Statement** GetStatList();
	
	// -- Statements/Connector Management Functions
	void AddStatement(Statement* pStat); //Adds a new Statement to the Flowchart
	Statement *GetStatement(Point P) const;	//search for a statement where point P belongs

	void SaveAll(ofstream& OutputFile);

	void AddConnector(Connector* pConn); //Adds a new Connector to the Flowchart
	Connector *GetConnector(Point P) const;	//search for a Connector where point P belongs


	Statement *GetSelectedStatement() const;	//Returns the selected Statement
	void SetSelectedStatement(Statement *pStat); //Set the Statement selected by the user

		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	
	void LoadAll(ifstream& InputFile);

	bool GetStartEnd();
	bool NumConnector();
};

#endif