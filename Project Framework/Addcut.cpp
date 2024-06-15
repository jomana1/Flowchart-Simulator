#include "ApplicationManager.h"
#include "Addcut.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"
#include "Statements/SmplAssign.h"

#include <sstream>
using namespace std;
AddCut::AddCut(ApplicationManager* pAppManager):Action(pAppManager)
{
	stat = NULL;
}
void AddCut::ReadActionParameters()
{

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("You Clicked on cut  action : Click on the statement you want to cut");
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
	pOut->PrintMessage("Where do you want to paste it?");
	pIn->GetPointClicked(s);
	pOut->ClearStatusBar();
}
void AddCut::Execute()
{
	ReadActionParameters();
	Point leftcorner;
	Output* pOut = pManager->GetOutput();
	if (type == "RECT")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y;
		stat->cutpaste(leftcorner, pOut);

	}
	if (type == "Rhombus")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y;
		stat->cutpaste(leftcorner, pOut);
	}
	if (type == "para")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y + UI.ASSGN_HI / 2;
		stat->cutpaste(leftcorner, pOut);
	}
	if (type == "elipseS")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y;
		stat->Move(leftcorner, pOut);


	}
	if (type == "elipseE")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y;
		stat->Move(leftcorner, pOut);



	}


}