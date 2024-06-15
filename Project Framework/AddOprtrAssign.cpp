#include "AddOprtrAssign.h"
#include "..\Project Framework\ApplicationManager.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"

#include <iostream>
using namespace std;
AddOprtrAssign::AddOprtrAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{

}
void AddOprtrAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("You clicked on operation assignment :please add your statement");
	pIn->GetPointClicked(Position);
	pOut->PrintMessage("Please Enter the LHS : ");
	LHS = pIn->GetString(pOut);
	pOut->PrintMessage("Please Enter the equal sign : ");
	op = pIn->GetString(pOut);
	while (op != "=")
	{
		pOut->PrintMessage("Invalid operator assignment, please re-enter the equal sign.");
		op = pIn->GetString(pOut);
	}

	pOut->PrintMessage("Please Enter the 1st part of your equation : ");
	LHS1 = pIn->GetString(pOut);

	pOut->PrintMessage("Please Enter any operator : ");
	op1 = pIn->GetString(pOut);
	while (!(op1 == "+" || op1 == "-" || op1 == "*" || op1 == "/"))
	{
		pOut->PrintMessage("Invalid operator assignment, please re-enter any operator.");
		op1 = pIn->GetString(pOut);
	}
	pOut->PrintMessage("Please Enter the 2nd part of your equation : ");
	RHS1 = pIn->GetValue(pOut);


	pOut->ClearStatusBar();

}
void AddOprtrAssign::Execute()
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;
	OprtrAssign* pAssign = new OprtrAssign(Corner, LHS, RHS1, op, op1, LHS1);

	pManager->AddStatement(pAssign);


}