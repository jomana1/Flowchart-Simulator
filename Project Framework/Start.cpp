
#include "Start.h"
#include <sstream>
#include<fstream>
using namespace std;

Start::Start(Point L)
{
	Left = L;

	pConn = NULL;	//No connectors yet


	Outlet.x = Left.x + UI.ASSGN_WDTH / 2;
	Outlet.y = Left.y + UI.ASSGN_HI;
}

void Start::UpdateStatementText()
{
	
}

void Start::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawStart(Left, UI.ASSGN_WDTH, UI.ASSGN_HI,"START", Selected);

}
string Start::GetShape() {
	Shape = "elipseS";
	return Shape;
}
Point Start::GetLeft() {
	return Left;
}
Point Start::GetSrc() {
	return Outlet;
}
Point Start::GetDst()
{
	return Outlet;
}

void Start::setConnector(Connector* pConn) {
	this->pConn = pConn;
}
Connector* Start::getConnector()
{
	return this->pConn;

}
void Start::Move(Point p,Output*i)
{
	i->DrawStartdel(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "START", Selected);
	Left = p;
	i->DrawStart(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "START", Selected);
	Outlet.x = Left.x + UI.ASSGN_WDTH / 2;
	Outlet.y = Left.y + UI.ASSGN_HI;

}
void Start::copy(Point p, Output* i)
{



}
void Start::cutpaste(Point p, Output* i)
{
	i->DrawStartdel(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "START", Selected);
	Left = p;
	i->DrawStart(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "START", Selected);


}
void Start::remove(Point p, Output* i)
{
	Point z;
	z.x = 1;
	z.y = 10000000000;

	i->DrawStartdel(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "START", Selected);
	i->DrawStartdel(z, UI.ASSGN_WDTH, UI.ASSGN_HI, "START", Selected);
	Left = z;
	Draw(i);


}
string Start::GetType() {
	type = "STRT";
	return type;
}
void Start::PrintInfo(Output* pout)
{
	string x = to_string(Left.x);
	string y = to_string(Left.y);
	pout->PrintMessage("Start Statement (" + x + "," + y + "): " + Text + "//" + getComment());

}
Statement* Start::GenerateCode(ofstream& OutFile)
{
	
	return pConn->getDstStat();
}
void Start::Save(ofstream& Outputfile)
{
	Outputfile << "STRT" << "\t" << getID() << "\t" << Left.x << "\t" << Left.y << Text << "\t//" << getComment() << endl;
}
void Start::Load(ifstream& Inputfile)
{
	Inputfile >> ID >> Left.x >> Left.y;
}