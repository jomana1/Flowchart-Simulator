#include "Read.h"
#include <sstream>
#include<fstream>
using namespace std;
Read::Read(Point Lcorner, string v)
{

	var = v;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + ((0.5) * UI.ASSGN_WDTH);
	Inlet.y = LeftCorner.y - ((UI.ASSGN_HI));

	Outlet.x = LeftCorner.x + ((3/8)*UI.ASSGN_WDTH );
	Outlet.y = LeftCorner.y;
}

void Read::setVAR(const string& v)
{
	var = v;
	UpdateStatementText();
}
string Read::getVAR()
{
	return var;
}
void Read::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawReadWrite(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void Read::UpdateStatementText()
{
	if (var == "")	//No left handside ==>statement have no valid text yet
		Text = "Input() ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << "Input(" << var << ")";
		Text = T.str();
	}
}
string Read::GetShape() {
	Shape = "para";
	return Shape;
}
Point Read::GetLeft() {
	return LeftCorner;
}
Point Read::GetSrc() {
	return Outlet;
}
Point Read::GetDst()
{
	return Inlet;
}

void Read::Move(Point p,Output*pout)
{
	pout->DrawReadWritedelete(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	LeftCorner = p;
	UpdateStatementText();
	Draw(pout);
	Inlet.x = LeftCorner.x + ((0.5) * UI.ASSGN_WDTH);
	Inlet.y = LeftCorner.y - ((UI.ASSGN_HI));

	Outlet.x = LeftCorner.x + ((3 / 8) * UI.ASSGN_WDTH);
	Outlet.y = LeftCorner.y;
}
void Read::copy(Point p, Output* pout)
{
	
	UpdateStatementText();
	pout->DrawReadWrite(p, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
void Read::cutpaste(Point p, Output* pout)
{
	pout->DrawReadWritedelete(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	LeftCorner = p;
	UpdateStatementText();
	Draw(pout);
}
void Read::remove(Point p, Output* pout)
{
	Point z;
	z.x = 1;
	z.y = 100000;
	pout->DrawReadWritedelete(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	pout->DrawReadWritedelete(z, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	LeftCorner = z;
	Draw(pout);
}
string Read::GetType() {
	type = "READ";
	return type;
}
void Read::PrintInfo(Output* pout)
{
	string x = to_string(LeftCorner.x);
	string y = to_string(LeftCorner.y);
	pout->PrintMessage("Read Statement (" + x + "," + y + "): " + Text + "//" + getComment());

}
Statement* Read::GenerateCode(ofstream& OutFile)
{
	if (!(OutFile.is_open()))
		OutFile.open("code.txt", ios::out | ios::app);
	OutFile << "\t" << "cin >>" << var << ";\t" << getComment() << "\n";
	return pConn->getDstStat();
}

void Read::setConnector(Connector* pConn) {
	this->pConn = pConn;
}
void Read::EditRead(string x)
{
	setVAR(x);
	UpdateStatementText();
}
Connector* Read::getConnector()
{
	return this->pConn;

}
void Read::Save(ofstream& Outputfile)
{
	Outputfile << "READ" << "\t" << ID << "\t" << LeftCorner.x << "\t" << LeftCorner.y << " " << Text << "\t//" << getComment() << endl;
}
void Read::Load(ifstream& Inputfile)
{
	Inputfile >> ID >> LeftCorner.x >> LeftCorner.y >> Text;
}
