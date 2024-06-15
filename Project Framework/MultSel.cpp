#include "MultSel.h"
#include "GUI/UI_Info.h"

//this class is used to seelect multiple statements

MultSel::MultSel(ApplicationManager* pAppManager) :Action(pAppManager)
{
}

void MultSel::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Click to select multiple statements");
	pIn->GetPointClicked(Position);
	SelStat = pManager->GetStatement(Position);
	Conn = pManager->GetConnector(Position);
	if (Position.y < UI.MnItWdth)
	{
		c++;
		pIn->GetPointClicked(Position);
	}
	else
	{
		while (SelStat == NULL && Conn == NULL)
		{
			pOut->PrintMessage("Nothing has been selected");
			if (Position.y < UI.MnItWdth)
			{
				c = 1;
				break;
			}
			else
			{
				pIn->GetPointClicked(Position);
				SelStat = pManager->GetStatement(Position);
				Conn = pManager->GetConnector(Position);
			}
		}
	}
	pOut->ClearStatusBar();
}

void MultSel::Execute()
{
	Output* pOut = pManager->GetOutput();
	c = 0;
	Input* pIn = pManager->GetInput();
	while (c == 0)
	{
		ReadActionParameters();
		if (c != 1)
		{
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
				}
			}
		}
	}
}
