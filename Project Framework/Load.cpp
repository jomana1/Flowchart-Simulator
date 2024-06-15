#include <fstream>
#include "..\Project Framework\Load.h"
#include "..\Project Framework\Statements\Statement.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"
#include "..\Project Framework\ApplicationManager.h"
#include <sstream>
#include "..\Project Framework\Start.h"
#include "..\Project Framework\End.h"
#include "..\Project Framework\Read.h"
#include "..\Project Framework\Write.h"
#include "..\Project Framework\Statements\Connector.h"
#include "..\Project Framework\Statements\SmplAssign.h"


//constructor: set the ApplicationManager pointer inside this action
Load::Load(ApplicationManager* pApp) :Action(pApp)
{

}


void Load::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("you clicked on load : Enter file name");
	FileName = pIn->GetString(pOut);
	pOut->PrintMessage("Flowchart has been loaded from" + FileName);
}

void Load::Execute()
{
	ReadActionParameters();
	Output* pOut;
	ifstream myfile;
	myfile.open(FileName);
	pManager->LoadAll(myfile);
	myfile.close();
	pOut = pManager->GetOutput();



}