#include "Write.h"
#include "ApplicationManager.h"
#include<fstream>
#include <sstream>

using namespace std;
Write::Write(Point Lcorner, string v)
{

	var = v;

	UpdateStatementText();

	LeftCorner = Lcorner;

	//pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + ((3 / 8) * UI.ASSGN_WDTH);
	Inlet.y = LeftCorner.y - ((UI.ASSGN_HI));

	Outlet.x = LeftCorner.x + ((3 / 8) * UI.ASSGN_WDTH);
	Outlet.y = LeftCorner.y;
}

void Write::setVAR(const string& v)
{
	var = v;
	UpdateStatementText();
}
string Write::getVAR()
{
	return var;
}
//Connector* Write::getConn()
//{
//	return pConn;
//}
void Write::setConnector(Connector* pConn) {
	this->pConn = pConn;
}
Connector* Write::getConnector()
{
	return this->pConn;

}
void Write::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawReadWrite(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}

//This function should be called when LHS or RHS changes
void Write::UpdateStatementText()
{
	if (var == "")	//No left handside ==>statement have no valid text yet
		Text = "Output() ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << "Output(" << var << ")";
		Text = T.str();
	}
}
string Write::GetShape() {
	Shape = "para";
	return Shape;
}
Point Write::GetLeft() {
	return LeftCorner;
}
Point Write::GetSrc() {
	return Outlet;
}
Point Write::GetDst()
{
	return Inlet;
}
void Write::Move(Point p,Output*y)
{
	y->DrawReadWritedelete(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	LeftCorner = p;
	UpdateStatementText();
	Draw(y);
	Inlet.x = LeftCorner.x + ((3 / 8) * UI.ASSGN_WDTH);
	Inlet.y = LeftCorner.y - ((UI.ASSGN_HI));

	Outlet.x = LeftCorner.x + ((3 / 8) * UI.ASSGN_WDTH);
	Outlet.y = LeftCorner.y;


}
void Write::copy(Point p, Output* y)
{

	
	UpdateStatementText();
	y->DrawReadWrite(p, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}
void Write::cutpaste(Point p, Output* y)
{
	y->DrawReadWritedelete(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	LeftCorner = p;
	UpdateStatementText();
	Draw(y);

}
void Write::remove(Point p, Output* y)
{
	Point z;
	z.x = 1;
	z.y = 10000;
	y->DrawReadWritedelete(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	y->DrawReadWritedelete(z, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	LeftCorner = z;
	Draw(y);
}
string Write::GetType() {
	type = "WRT";
	return type;
}
void Write::PrintInfo(Output* pout)
{
	string x = to_string(LeftCorner.x);
	string y = to_string(LeftCorner.y);
	pout->PrintMessage("Write Statement (" + x + "," + y + "): " + Text+"//"+getComment());

}
Statement* Write::GenerateCode(ofstream& OutFile)
{
	if (!(OutFile.is_open()))
		OutFile.open("code.txt", ios::out | ios::app);
	OutFile << "\t" << "cout <<" << var << ";\t"<<getComment() << "\n";
	return pConn->getDstStat();
}
void Write::Save(ofstream& OutputFile)
{
	OutputFile << "WRITE" << "\t" << ID << "\t" << LeftCorner.x << "\t" << LeftCorner.y << " " << Text << "\t//" << getComment() << endl;
}
void Write::Load(ifstream& Inputfile)
{
	Inputfile >> ID >> LeftCorner.x >> LeftCorner.y >> Text;
}

void Write::EditWrite(string x)
{
	setVAR(x);
}
