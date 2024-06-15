#include "AddStart.h"
#include "..\Project Framework\Start.h"

#include "..\Project Framework\ApplicationManager.h"

#include "..\Project Framework\GUI\input.h"
#include "..\Project Framework\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddStart::AddStart(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddStart::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Start Statement : Click to add the statement");

	pIn->GetPointClicked(Position);
}

void AddStart::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	Start* pStart = new Start(Corner);

	pManager->AddStatement(pStart);

}

