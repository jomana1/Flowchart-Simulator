#include "ApplicationManager.h"
#include "delete.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"
#include "Statements/SmplAssign.h"

#include <sstream>
using namespace std;
//this class is used to delete any selected statement

addDelete::addDelete(ApplicationManager* pAppManager) :Action(pAppManager)
{
	stat = NULL;
}
void addDelete::ReadActionParameters()
{

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("This is Delete action : Click on the statement");
	pIn->GetPointClicked(s);
	stat = pManager->GetStatement(s);
	while (stat == NULL)
	{
		pOut->PrintMessage("This is Delete action : Click on the statement");
		pIn->GetPointClicked(s);
		stat = pManager->GetStatement(s);

	}
	type = stat->GetShape();

	pOut->ClearStatusBar();
}
void addDelete::Execute()
{
	ReadActionParameters();
	Point leftcorne;
	Output* pOut = pManager->GetOutput();
	if (type == "RECT")
	{
		leftcorne.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorne.y = s.y;
		stat->remove(leftcorne, pOut);

	}
	if (type == "Rhombus")
	{
		leftcorne.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorne.y = s.y;
		stat->remove(leftcorne, pOut);
	}
	if (type == "para")
	{
		leftcorne.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorne.y = s.y + UI.ASSGN_HI / 2;
		stat->remove(leftcorne, pOut);
	}
	if (type == "elipseS")
	{

		leftcorne.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorne.y = s.y + UI.ASSGN_HI / 2;
		stat->remove(leftcorne, pOut);

	}
	if (type == "elipseE")
	{

		leftcorne.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorne.y = s.y + UI.ASSGN_HI / 2;
		stat->remove(leftcorne, pOut);

	}

}