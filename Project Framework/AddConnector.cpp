#include "AddConnector.h"


#include "..\Project Framework\ApplicationManager.h"

#include "..\Project Framework\GUI\input.h"
#include "..\Project Framework\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddConnector::AddConnector(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddConnector::ReadActionParameters()
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
	
	pOut->ClearStatusBar();
}

void AddConnector::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	

	Connector* pConn = new Connector(Src, Dst);

	pManager->AddConnector(pConn);

}

