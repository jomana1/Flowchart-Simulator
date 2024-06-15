#include "AddSmplAssign.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddSmplAssign::AddSmplAssign(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddSmplAssign::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Simple Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->PrintMessage("Please Enter the LHS : ");
	lhs = pIn->GetString(pOut);
	pOut->PrintMessage("Please Enter the RHS : ");
	rhs = pIn->GetValue(pOut);

	pOut->ClearStatusBar();		
}

void AddSmplAssign::Execute()
{
	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH/2;
	Corner.y = Position.y ;
	
	SmplAssign *pAssign = new SmplAssign(Corner, lhs, rhs);

	pManager->AddStatement(pAssign);

}

