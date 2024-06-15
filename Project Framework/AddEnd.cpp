#include "AddEnd.h"
#include "End.h"
#include "..\Project Framework\ApplicationManager.h"

#include "..\Project Framework\GUI\input.h"
#include "..\Project Framework\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddEnd::AddEnd(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddEnd::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("End Statement : Click to add the statement");

	pIn->GetPointClicked(Position);
}

void AddEnd::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	End* pEnd = new End(Corner);

	pManager->AddStatement(pEnd);

}

