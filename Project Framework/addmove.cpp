#include "ApplicationManager.h"
#include "addmove.h"
#include "..\Project Framework\GUI\Input.h"
#include "..\Project Framework\GUI\Output.h"
#include "Statements/SmplAssign.h"

#include <sstream>
using namespace std;
MOve::MOve(ApplicationManager* pAppManager) :Action(pAppManager)
{ 
	stat = NULL;
}
void MOve::ReadActionParameters()
{
	
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("You clicked on move : Click on the statement you want to move");
	pIn->GetPointClicked(s);
	Statement* statt = pManager->GetStatement(s);
	while (statt == NULL)
	{
		pOut->PrintMessage("No shape has been found : Please click on shape, again");
		pIn->GetPointClicked(s);
		 statt = pManager->GetStatement(s);

	}
	type = statt->GetShape();
	stat = statt;
	pOut->PrintMessage("Where do you want to move it?");
	pIn->GetPointClicked(s);
	pOut->ClearStatusBar();
}
void MOve::Execute()
{
	ReadActionParameters();
	bool c = false;
	pManager->setu(c);
	Connector* pconn;
	pconn = stat->getConnector();
	Point leftcorner;
	Point Outlet;
	Point z, r;
	Output* pOut = pManager->GetOutput();
	Point in, out;
	in = stat->GetDst();
	Connector* con1 = pManager->GetConnector(in);
	if ((pconn != NULL)&&(con1 != NULL))
	{
		Point z, r;
		z = pconn->getStartPoint();
		Statement* ds = pconn->getDstStat();
		r = ds->GetDst();
		pOut->DrawConnectordel(z, r);
		pOut->DrawConnectordel(z, r);
		pconn->setSrcStat(stat);
		Point leftcorner;
		Point Outlet;
		Statement* sr = con1->getSrcStat();
		out = sr->GetSrc();
		pOut->DrawConnectordel(out, in);
		pOut->ClearDrawArea();


	}
	else if (pconn != NULL)
	{
		
		{
			Point z, r;
			z = pconn->getStartPoint();
			Statement* ds = pconn->getDstStat();
			r = ds->GetDst();
			pOut->DrawConnectordel(z, r);
			pOut->DrawConnectordel(z, r);
			pconn->setSrcStat(stat);
			Point leftcorner;
			Point Outlet;
			pOut->ClearDrawArea();

		}
	
		}
	else
	{
		bool c = false;
		pManager->setu(c);
	
		if (con1 != NULL)
		{
			Statement* sr = con1->getSrcStat();
			out = sr->GetSrc();
			pOut->DrawConnectordel(out, in);
			pOut->ClearDrawArea();
		}

	}
	
	if (type == "RECT")
	{
	
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y;
		
		Outlet.x = leftcorner.x + UI.ASSGN_WDTH / 2;
		Outlet.y = leftcorner.y + UI.ASSGN_HI;
		if (pconn != NULL)
		pconn->setStartPoint(Outlet);
		stat->Move(leftcorner, pOut);
	
	}
	if (type == "Rhombus")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y;
		Outlet.x = leftcorner.x;
		Outlet.y = leftcorner.y;
		if (pconn != NULL)
			pconn->setStartPoint(Outlet);
		stat->Move(leftcorner, pOut);

	}
	if (type == "para")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y + UI.ASSGN_HI / 2;
		Outlet.x = leftcorner.x + ((3 / 8) * UI.ASSGN_WDTH);
		Outlet.y = leftcorner.y;
		if (pconn != NULL)
		pconn->setStartPoint(Outlet);
		stat->Move(leftcorner, pOut);
	}
	if (type == "elipseS")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y;
		Outlet.x = leftcorner.x + UI.ASSGN_WDTH / 2;
		Outlet.y = leftcorner.y + UI.ASSGN_HI;
		if (pconn != NULL)
			pconn->setStartPoint(Outlet);
		stat->Move(leftcorner, pOut);
		

	}
	if (type == "elipseE")
	{
		leftcorner.x = s.x - UI.ASSGN_WDTH / 2;
		leftcorner.y = s.y;
		Outlet.x = leftcorner.x + UI.ASSGN_WDTH / 2;
		Outlet.y = leftcorner.y;
		if (con1 != NULL)
			con1->setEndPoint(Outlet);
		stat->Move(leftcorner, pOut);



	}

}
