
#include "VarAssign.h"
#include <sstream>
#include<fstream>
using namespace std;

VarAssign::VarAssign(Point Lcorner, string LeftHS, string RightHS)
{
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void VarAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void VarAssign::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();
}
string VarAssign::getLHS()
{
	return LHS;
}
string VarAssign::getRHS()
{
	return RHS;
}



void VarAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}

//This function should be called when LHS or RHS changes
void VarAssign::UpdateStatementText()
{
	if (LHS == "")	//No left handside ==>statement have no valid text yet
		Text = "    = ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << LHS << " = " << RHS;
		Text = T.str();
	}
}
string VarAssign::GetShape() {
	Shape = "RECT";
	return Shape;
}
string VarAssign::GetType() {
	type = "VAR";
	return type;
}
Point VarAssign::GetLeft()
{
	return LeftCorner;
}
Point VarAssign::GetSrc()
{
	return Outlet;
}
Point VarAssign::GetDst()
{
	return Inlet;
}
void VarAssign::Move(Point p, Output* pout)
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
void VarAssign::copy(Point p, Output* pout)
{

	UpdateStatementText();
	pout->DrawAssign(p, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}
void VarAssign::cutpaste(Point p, Output* pout)
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
void VarAssign::remove(Point p, Output* pout)
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
void VarAssign::PrintInfo(Output* pout)
{
	string x = to_string(LeftCorner.x);
	string y = to_string(LeftCorner.y);
	pout->PrintMessage("Variable Assignment Stat (" + x + "," + y + "): " + Text + "//" + getComment());

}
Statement* VarAssign::GenerateCode(ofstream& OutFile)
{
	if (!(OutFile.is_open()))
		OutFile.open("code.txt", ios::out | ios::app);
	OutFile << "\t" << LHS << "=" << RHS << ";\t" << getComment() << "\n";
	return pConn->getDstStat();
}

void VarAssign::setConnector(Connector* pConn) {
	this->pConn = pConn;
}
Connector* VarAssign::getConnector()
{
	return this->pConn;

}
void VarAssign::Save(ofstream& Outputfile)
{
	Outputfile << "VAR" << "\t" << ID << "\t" << LeftCorner.x << "\t" << LeftCorner.y << " " << Text << "\t//" << getComment() << endl;
}
void VarAssign::Load(ifstream& Inputfile)
{
	Inputfile >> ID >> LeftCorner.x >> LeftCorner.y >> Text;
}
void VarAssign::Simulate(string* r, string* m, int x)
{
	string d = m[x - 1];
	for (int i = 0; i < x; i = i + 1)
	{
		if (!d.compare(r[i]))
			m[x - 1] = (m[i]);

	}


}