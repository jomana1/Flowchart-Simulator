#include "AddConn.h"

#include "..\Project Framework\ApplicationManager.h"

#include "..\Project Framework\GUI\input.h"
#include "..\Project Framework\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AdConnector::AdConnector(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AdConnector::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage(" Click on the Source statment");

	pIn->GetPointClicked(Position);
	Src = pManager->GetStatement(Position);

	while (Src == NULL)
	{
		pOut->PrintMessage("No statement selected");
		pIn->GetPointClicked(Position);
		Src = pManager->GetStatement(Position);
	}
	pOut->PrintMessage(" Click on the destenation statment");

	pIn->GetPointClicked(Position);
	Dst = pManager->GetStatement(Position);

	while (Dst == NULL)
	{
		pOut->PrintMessage("No statement selected");
		pIn->GetPointClicked(Position);
		Dst = pManager->GetStatement(Position);
	}
	if (Src->GetType() == "COND")
	{
		pOut->PrintMessage("YES or NO (y/n)");
	string type = pIn->GetString(pOut);
	if (type == "y")
		Ctype = true;
	else if (type == "n")
		Ctype = false;
	else if (type != "y")
		pOut->PrintMessage("YES or NO (y/n) onlyy!");
    }
	pOut->ClearStatusBar();
}

void AdConnector::Execute()
{
	ReadActionParameters();




	Connector* pConn = new Connector(Src, Dst,Ctype);

	pManager->AddConnector(pConn);

}

