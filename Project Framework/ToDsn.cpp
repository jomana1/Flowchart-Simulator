#include "ToDsn.h"
#include "ApplicationManager.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"
#include "Statements/SmplAssign.h"

//this class is used to switch from simulation to design mode

#include <sstream>
using namespace std;
ToDsn::ToDsn(ApplicationManager* pAppManager) :Action(pAppManager)
{
}
void ToDsn::ReadActionParameters()
{


}
void ToDsn::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearToolBar();
	pOut->CreateDesignToolBar();
	pOut->ClearStatusBar();
}