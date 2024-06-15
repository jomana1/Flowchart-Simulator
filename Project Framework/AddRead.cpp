#include "AddRead.h"
#include"Read.h"

#include "..\Project Framework\ApplicationManager.h"

#include "..\Project Framework\GUI\input.h"
#include "..\Project Framework\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddRead::AddRead(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddRead::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Read Statement : Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->PrintMessage("Please Enter the Input : ");
	var = pIn->GetString(pOut);

	pOut->ClearStatusBar();
}

void AddRead::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y + UI.ASSGN_HI / 2;

	Read* pRead = new Read(Corner, var);

	pManager->AddStatement(pRead);

}

