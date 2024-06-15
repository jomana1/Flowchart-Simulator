#include "AddWrite.h"
#include "Write.h"

#include "..\Project Framework\ApplicationManager.h"

#include "..\Project Framework\GUI\input.h"
#include "..\Project Framework\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddWrite::AddWrite(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddWrite::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Write Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->PrintMessage("Please Enter the Output : ");
	var = pIn->GetString(pOut);

	pOut->ClearStatusBar();
}

void AddWrite::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
    Corner.y = Position.y + UI.ASSGN_HI / 2;

	Write* pWrite = new Write(Corner, var);

	pManager->AddStatement(pWrite);

}


