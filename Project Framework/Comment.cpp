#include "Comment.h"
#include "Statements/Statement.h"
#include <sstream>
#include "ApplicationManager.h"
#include "../Project Framework/Actions/Action.h"
#include "..\Project Framework\GUI\input.h"
#include "..\Project Framework\GUI\Output.h"

#include <sstream>

Comment::Comment(ApplicationManager* pAppManager) :Action(pAppManager)
{
}

void Comment::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Click to add comment to the statement");

	pIn->GetPointClicked(Position);
	SelStat = pManager->GetStatement(Position);
	while (SelStat == NULL)
	{
		pOut->PrintMessage("Nothing selected");
		pIn->GetPointClicked(Position);
		SelStat = pManager->GetStatement(Position);
	}


	pOut->ClearStatusBar();
}

void Comment::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Add Comment: ");
	string c= pIn->GetString(pOut);

	SelStat->setComment(c);
	SelStat->PrintInfo(pOut);


}
