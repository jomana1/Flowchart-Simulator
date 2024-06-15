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
 
//this class is used to generate the code file of C++ using the flowchart
 
Generate::Generate(ApplicationManager* pAppManager) :Action(pAppManager)
{
}
void Generate::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();


		pOut->ClearStatusBar();
	
	
}
void Generate::Execute()
{
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	Statement* pStat = nullptr;
	Connector* pConn = nullptr;
	ofstream output("code.txt");
	
	output << "#include <iostream>\nusing namespace std;\n\nint main()\n{";
	for (int i = 0; i < pManager->GetStatCount(); i++)
	{
		string type = pManager->GetStatList()[i]->GetType();
		if (type == "STRT")
		{
			pStat = pManager->GetStatList()[i];
			break;
		}
	}
	
	string VAR[100];
	int nVAR = 0;
	for (int i = 0; i < pManager->GetStatCount(); i++)
	{
		if (pManager->GetStatList()[i]->GetType() == "READ")
		{
			VAR[nVAR] = ((Read*)pManager->GetStatList()[i])->getVAR();
			nVAR++;
		}
		if (pManager->GetStatList()[i]->GetType() == "SMPL")
		{
			VAR[nVAR] = ((SmplAssign*)pManager->GetStatList()[i])->getLHS();
			nVAR++;
		}
		if (pManager->GetStatList()[i]->GetType() == "VAR")
		{
			VAR[nVAR] = ((VarAssign*)pManager->GetStatList()[i])->getLHS();
			nVAR++;
		}
		if (pManager->GetStatList()[i]->GetType() == "SNGLOP")
		{
			VAR[nVAR] = ((OprtrAssign*)pManager->GetStatList()[i])->getLHS();
			nVAR++;
		}
		
	}
	for (int i = 0; i < nVAR; i++)//to avoid any doublication
	{
		for (int j = 0; j < i; j++)
			if (VAR[i] == VAR[j])
				VAR[i] = "";
	}
	for (int i = 0; i < nVAR; i++)
	{
		if (VAR[i] != "")
			output << "\tdouble " << VAR[i] << ";\n";
	}
	while (pStat->GetType() != "END")
	{
		
		pStat=pStat->GenerateCode(output);
		
	}
	pStat->GenerateCode(output);
	output.close();
	pOut->PrintMessage("C++ code has been generated in code.txt");
}

