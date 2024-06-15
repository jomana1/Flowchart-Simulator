#include "Validate.h"
#include "ApplicationManager.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"
#include "Statements/SmplAssign.h"

#include <sstream>
using namespace std;
Validate::Validate(ApplicationManager* pAppManager) :Action(pAppManager)
{
}
void Validate::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();


	pOut->ClearStatusBar();

}
void Validate::Execute()
{
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	val1 = pManager->GetStartEnd();
	val2 = pManager->NumConnector();
	if (val1 && val2)
	{
		pOut->PrintMessage("Valid Flowchart ;)!");
	}
	else
		pOut->PrintMessage("Invalid Flowchart :(");
	
}