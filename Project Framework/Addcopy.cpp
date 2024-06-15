#include "ApplicationManager.h"
#include "Addcopy.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"
#include "Statements/SmplAssign.h"

#include <sstream>
using namespace std;
Addcopy::Addcopy(ApplicationManager* pAppManager) :Action(pAppManager)
{
	stat = NULL;
}
void Addcopy::ReadActionParameters()
{

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("You clicked on Cpy action : Click on which statement you want it copied");
	pIn->GetPointClicked(s);
	Statement* statt = pManager->GetStatement(s);
	while (statt == NULL)
	{
		pOut->PrintMessage("No shape has been found : Please click on the shape again");
		pIn->GetPointClicked(s);
		statt = pManager->GetStatement(s);

	}
	type = statt->GetShape();
	stat = statt;
	pOut->PrintMessage("Where do you want it copied?");
	pIn->GetPointClicked(s);
	pOut->ClearStatusBar();
}
void Addcopy::Execute()
{
	ReadActionParameters();
	Point leftcorner;
	Output* pOut = pManager->GetOutput();
	if (type == "RECT")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y;
		stat->copy(leftcorner, pOut);

	}
	if (type == "Rhombus")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y;
		stat->copy(leftcorner, pOut);
	}
	if (type == "para")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y + UI.ASSGN_HI / 2;
		stat->copy(leftcorner, pOut);
	}


}