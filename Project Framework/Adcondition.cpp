#include "Adcondition.h"
#include "..\Project Framework\ApplicationManager.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"

#include <iostream>
using namespace std;
Addcondition::Addcondition(ApplicationManager* pAppManager) :Action(pAppManager)
{}
void Addcondition::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(" you clicked on Add condition: Please add your condition");
	pIn->GetPointClicked(Position);
	pOut->PrintMessage("Please Enter the LHS : ");
	LHS = pIn->GetString(pOut);
	pOut->PrintMessage("Please Enter any operator : ");
	op = pIn->GetString(pOut);
	pOut->PrintMessage("Please Enter the RHS : ");
	RHS = pIn->GetValue(pOut);

	pOut->ClearStatusBar();

}
void Addcondition::Execute()
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Condition* pAssign = new Condition(Corner, LHS, RHS, op);

	pManager->AddStatement(pAssign);


}
