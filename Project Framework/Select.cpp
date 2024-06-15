#include "Statements/Statement.h"
#include "Select.h"
#include <sstream>
#include "ApplicationManager.h"
#include "../Project Framework/Actions/Action.h"
#include "..\Project Framework\GUI\input.h"
#include "..\Project Framework\GUI\Output.h"

#include <sstream>

Select::Select(ApplicationManager* pAppManager):Action(pAppManager)
{
}

void Select::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Click to select the statement");

	pIn->GetPointClicked(Position);
	SelStat = pManager->GetStatement(Position);
	Conn = pManager->GetConnector(Position);
	while (SelStat == NULL && Conn == NULL)
	{
		pOut->PrintMessage("Nothing selected");
		pIn->GetPointClicked(Position);
		SelStat = pManager->GetStatement(Position);
		Conn = pManager->GetConnector(Position);
	}
	

	pOut->ClearStatusBar();
}

void Select::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	
	if (SelStat == NULL)
	{
		if (Conn->IsSelected())
		{
			Conn->SetSelected(false);
			Conn->Draw(pOut);
			pOut->ClearStatusBar();
		}
		else 
		{
			Conn->SetSelected(true);
			Conn->Draw(pOut);
			//SelStat->PrintInfo(pOut);
		}
	}
	else 
	{
		if (SelStat->IsSelected())
		{
			SelStat->SetSelected(false);
			SelStat->Draw(pOut);
			pOut->ClearStatusBar();
		}
		else
		{
			SelStat->SetSelected(true);
			SelStat->Draw(pOut);
			SelStat->PrintInfo(pOut);
		}
	}
}
