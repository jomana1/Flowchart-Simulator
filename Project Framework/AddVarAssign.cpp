#include "Addvarassign.h"
#include "..\Project Framework\VarAssign.h"
#include "..\Project Framework\ApplicationManager.h"

#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
Addvarassign::Addvarassign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Addvarassign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Simple Variable Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->PrintMessage("Please Enter the LHS : ");
	LHS = pIn->GetString(pOut);
	pOut->PrintMessage("Please Enter the RHS : ");
	RHS = pIn->GetString(pOut);

	pOut->ClearStatusBar();
}

void Addvarassign::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	VarAssign* pAssign = new VarAssign(Corner, LHS, RHS);

	pManager->AddStatement(pAssign);

}