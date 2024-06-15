#include "ToSim.h"
#include "ApplicationManager.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"
#include "Statements/SmplAssign.h"

//this class is used to switch from design tool bar to simulation tool bar
#include <sstream>
using namespace std;
ToSim::ToSim(ApplicationManager* pAppManager) :Action(pAppManager)
{
}
void ToSim::ReadActionParameters()
{

	
}
void ToSim::Execute()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearToolBar();
	pOut->CreateSimulationToolBar();
	pOut->ClearStatusBar();
}