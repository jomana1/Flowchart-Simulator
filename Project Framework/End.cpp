#include "End.h"
#include <sstream>
#include<fstream>
#include"ApplicationManager.h"
using namespace std;

End::End(Point L)
{
	Left = L;

	//pConn = NULL;	//No connectors yet


	Inlet.x = Left.x + UI.ASSGN_WDTH / 2;
	Inlet.y = Left.y ;
}

void End::UpdateStatementText()
{

}

void End::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawStart(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "End", Selected);
}
string End::GetShape() {
	Shape = "elipseE";
	return Shape;
}
Point End::GetLeft() {
	return Left;
}
Point End::GetSrc() {
	return Inlet;
}
Point End::GetDst()
{
	return Inlet;
}


//void End::setConnector(Connector* pConn)
//{
//	this->pConn = pConn;
//}

void End::Move(Point p,Output* r )
{
	r->DrawEnddel(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "End", Selected);
	Left = p;
	r->DrawStart(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "End", Selected);
	Inlet.x = Left.x + UI.ASSGN_WDTH / 2;
	Inlet.y = Left.y;

}
void End::copy(Point p, Output* r)
{



}
void End::cutpaste(Point p, Output* r)
{
	r->DrawEnddel(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "End", Selected);
	Left = p;
	r->DrawStart(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "End", Selected);

}
void End::remove(Point p, Output* r)
{
	Point z;
	z.x = 1;
	z.y = 10000000000;

	r->DrawStartdel(Left, UI.ASSGN_WDTH, UI.ASSGN_HI, "START", Selected);
	r->DrawStartdel(z, UI.ASSGN_WDTH, UI.ASSGN_HI, "START", Selected);
	Left = z;
	Draw(r);



}
string End::GetType() {
	type = "END";
	return type;
}
void End::PrintInfo(Output* pout)
{
	string x = to_string(Left.x);
	string y = to_string(Left.y);
	pout->PrintMessage("End Statement (" + x + "," + y + "): " + Text + "//" + getComment());

}
Statement* End::GenerateCode(ofstream& OutFile)
{
	
	OutFile << "\treturn 0;\n}";
	return NULL;
}
void End::Save(ofstream& Outputfile)
{
	Outputfile << "END" << "\t" << ID << "\t" << Left.x << "\t" << Left.y << Text << "\t//" << getComment() << endl;
}
void End::Load(ifstream& Inputfile)
{
	Inputfile >> ID >> Left.x >> Left.y;
}