#include "SmplAssign.h"
#include <sstream>
#include<fstream>
#include<string>
using namespace std;

SmplAssign::SmplAssign(Point Lcorner, string LeftHS, double RightHS)
{
	
	LHS = LeftHS;
	RHS = RightHS;
	setx(RHS); 

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}
void SmplAssign::setleft(Point p)
{
	LeftCorner = p;
}

void SmplAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void SmplAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}
string SmplAssign::getLHS()
{
	return LHS;
}
double SmplAssign::getRHS()
{
	return RHS;
}
Connector* SmplAssign::getConn()
{
	return pConn;
}
void SmplAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

//This function should be called when LHS or RHS changes
void SmplAssign::UpdateStatementText()
{
	if(LHS=="")	//No left handside ==>statement have no valid text yet
		Text = "    = ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;

		T<<LHS<<" = "<<RHS;	
		Text = T.str();	 
	}
}
string SmplAssign:: GetShape() {
	Shape = "RECT";
	return Shape;
}

Point SmplAssign::GetLeft() {
	return LeftCorner;
 }
Point SmplAssign::GetSrc() {
	return Outlet;
}
Point SmplAssign::GetDst()
{
	return Inlet;
}
void SmplAssign::Move(Point p,Output*pout)
{
	pout->Drawdeleterec(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	LeftCorner = p;
	UpdateStatementText();
	Draw(pout);

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
	

}
void SmplAssign::copy(Point p, Output* pout)
{
	
	UpdateStatementText();
	pout->DrawAssign(p, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}
void SmplAssign::cutpaste(Point p, Output* pout)
{
	pout->Drawdeleterec(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

	LeftCorner = p;
	UpdateStatementText();
	Draw(pout);

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;

}
void SmplAssign::remove(Point p, Output* pout)
{
	Point z;
	z.x = 100;
	z.y = 1000;

	pout->Drawdeleterec(z, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	pout->Drawdeleterec(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

	LeftCorner = z;
	Draw(pout);
	UpdateStatementText();
	
	
}
void SmplAssign::PrintInfo(Output* pout)
{
	string x = to_string(LeftCorner.x);
	string y = to_string(LeftCorner.y);
	pout->PrintMessage("Simple Assignment Stat ("+x+","+y+"): " + Text + "//" + getComment());

}
string SmplAssign::GetType() {
	type = "SMPL";
	return type;
}
Statement* SmplAssign::GenerateCode(ofstream& OutFile)
{
	if (!(OutFile.is_open()))
		OutFile.open("code.txt", ios::out | ios::app);
	OutFile << "\t" << LHS << "=" << RHS << ";\t" << getComment() << "\n";
	return pConn->getDstStat();
}

Statement* SmplAssign::Simulate()
{/*
	int n = 0;
	double* x = new double[n];
	double val = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (x[i] != x[j])
			{
				n++;
				x[]

					val = RHS;
				x[i] = val;
			}
	}*/
	return pConn->getDstStat();
}

void SmplAssign::setConnector(Connector* pConn) {
	this->pConn = pConn;
}
void SmplAssign::EditSmp(string c, double q)
{
	setLHS(c);
	setRHS(q);
	UpdateStatementText();

}
Connector* SmplAssign::getConnector()
{
	return this->pConn;

}
void SmplAssign::Save(ofstream& Outputfile)
{
	Outputfile << "SMPL" << "\t" << ID << "\t" << LeftCorner.x << "\t" << LeftCorner.y << " " << Text << "\t//" << getComment() << endl;
}
void SmplAssign::Load(ifstream& Inputfile)
{
	Inputfile >> ID >> LeftCorner.x >> LeftCorner.y >> Text;
}