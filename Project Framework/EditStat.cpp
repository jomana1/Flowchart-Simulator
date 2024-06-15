#include "EditStat.h"
#include "ApplicationManager.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"
#include "Statements/SmplAssign.h"
#include "Condition.h"

#include <sstream>
using namespace std;
EditStat::EditStat(ApplicationManager* pAppManager) :Action(pAppManager)
{

}
void EditStat::ReadActionParameters()
{

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("edit action:click on what statement want to edit");
	pIn->GetPointClicked(Position);
	ed = pManager->GetStatement(Position);
	while (ed == NULL)
	{
		pOut->PrintMessage("no shape found:please click on shape again");
		pIn->GetPointClicked(Position);
		ed = pManager->GetStatement(Position);

	}
	pOut->ClearStatusBar();
}
void EditStat::Execute()
{
	ReadActionParameters();
	Point leftcorner;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (ed->GetType() == "SMPL")
	{
		string L;
		double q;
		pOut->PrintMessage("Please Enter the LHS : ");
		L = pIn->GetString(pOut);
		pOut->PrintMessage("Please Enter the RHS : ");
		q = pIn->GetValue(pOut);
		ed->EditSmp(L, q);
		pOut->ClearStatusBar();

	}
	else if (ed->GetType() == "COND")
	{
		string l, o;
		double x;
		pOut->PrintMessage("Please Enter the LHS : ");
		l = pIn->GetString(pOut);
		pOut->PrintMessage("Please Enter the op : ");
		o = pIn->GetString(pOut);
		pOut->PrintMessage("Please Enter the rhs : ");
		x = pIn->GetValue(pOut);
		ed->Editcond(l, o, x);
		pOut->ClearStatusBar();


	}
	else if (ed->GetType() == "WRT")
	{
		string x;
		pOut->PrintMessage("Please Enter the Output : ");
		x = pIn->GetString(pOut);
		ed->EditWrite(x);
		pOut->ClearStatusBar();

	}
	else if (ed->GetType() == "SNGLOP")
	{
		string x, y, z, w;
		double c;
		pOut->PrintMessage("Please Enter the LHS : ");
		x= pIn->GetString(pOut);
		pOut->PrintMessage("Please Enter the equal sign : ");
		y = pIn->GetString(pOut);
		while (y != "=")
		{
			pOut->PrintMessage("Invalid operator assignment, please re-enter the equal sign.");
			y = pIn->GetString(pOut);
		}

		pOut->PrintMessage("Please Enter the 1st part of your equation : ");
		z = pIn->GetString(pOut);

		pOut->PrintMessage("Please Enter any operator : ");
		w = pIn->GetString(pOut);
		while (!(w == "+" || w == "-" || w == "*" || w == "/"))
		{
			pOut->PrintMessage("Invalid operator assignment, please re-enter any operator.");
			w = pIn->GetString(pOut);
		}
		pOut->PrintMessage("Please Enter the 2nd part of your equation : ");
		c = pIn->GetValue(pOut);
		ed->EditOptrAss(x, z, y, w, c);
		pOut->ClearStatusBar();

	}
	else if (ed->GetType() == "READ")
	{
		string x;
		pOut->PrintMessage("Please Enter the Input : ");
		x = pIn->GetString(pOut);
		ed->EditRead(x);
		pOut->ClearStatusBar();
	}


}
