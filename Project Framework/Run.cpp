#include "Run.h"
#include "Generate.h"
#include "ApplicationManager.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"
#include <fstream>
#include <sstream>
#include"Statements/Statement.h"
#include"Statements/SmplAssign.h"
#include"Write.h"
#include"Start.h"
#include"Condition.h"
#include"End.h"
#include"VarAssign.h"
#include"Read.h"
#include"..\Project Framework\Statements\Connector.h"
#include"AddOprtrAssign.h"
#include"AddVarAssign.h"
using namespace std;
Run::Run(ApplicationManager* pAppManager, bool stepbystep) :Action(pAppManager)
{
	pStat = nullptr;
	pConn = nullptr;
}
void Run::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("welcomeeeee");
	pOut->ClearStatusBar();


}
void Run::Execute()
{
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	

	/*for (int i = 0; i < pManager->GetStatCount(); i++)
	{
		string type = pManager->GetStatList()[i]->GetType();
		if (type == "STRT")
		{
			pStat = pManager->GetStatList()[i];
			break;
		}
	}*/
	string value;
	Point p;
	for (int i = 0; i < pManager->GetStatCount(); i++)
	{
		string type = pManager->GetStatList()[i]->GetType();
		if (type == "SMPL")
		{
			value = to_string(pStat->getx());
			if (stepbystep)
			{
				pIn->GetPointClicked(p);
				pOut->PrintMessage("output=" + to_string(pStat->getx()));
				pIn->GetPointClicked(p);
			}
		}
		else if (type == "WRT")
		{
			pOut->PrintMessage("output=" + value);
		}
	}

	//pOut->PrintMessage("output=" + to_string(pStat->getx()));
	
	/*string VAR[100];
	string VALUE[100];
	int nVAR = 0;
	int nVALUE = 0;*/
	
	/*for (int i = 0; i < pManager->GetStatCount(); i++)
	{
		pst = pManager->GetStatList()[i];
		if (pManager->GetStatList()[i]->GetType() == "SMPL")
		{
			VAR[nVAR] = ((SmplAssign*)pManager->GetStatList()[i])->getLHS();
			VALUE[nVALUE] = ((SmplAssign*)pManager->GetStatList()[i])->getRHS();
			nVAR++;
			nVALUE++;
			pst->Simulate(VAR, VALUE, nVAR);
		}
		if (pManager->GetStatList()[i]->GetType() == "VAR")
		{
			VAR[nVAR] = ((VarAssign*)pManager->GetStatList()[i])->getLHS();
			VALUE[nVALUE] = ((VarAssign*)pManager->GetStatList()[i])->getRHS();
			nVAR++;
			nVALUE++;
			pst->Simulate(VAR, VALUE, nVAR);
		}
		if (pManager->GetStatList()[i]->GetType() == "SNGLOP")
		{
			VAR[nVAR] = ((OprtrAssign*)pManager->GetStatList()[i])->getLHS();
			VALUE[nVALUE] = ((OprtrAssign*)pManager->GetStatList()[i])->getLHS();
			nVAR++;
			nVALUE++;
			pst->Simulate(VAR, VALUE, nVAR);
		}
		if (pManager->GetStatList()[i]->GetType() == "READ")
		{
			VAR[nVAR] = ((Read*)pManager->GetStatList()[i])->getVAR();
			nVAR++;
		}*/
	}


