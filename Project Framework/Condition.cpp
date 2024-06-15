#include "Condition.h"
#include <sstream>
#include<fstream>
using namespace std;

Condition::Condition(Point Lcorner, string LeftHS, double RightHS,string h)
{
	LHS = LeftHS;
	RHS = RightHS;
	op = h;
	UpdateStatementText();

	LeftCorner = Lcorner;

	pConnN=pConnY = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y - UI.ASSGN_HI / 2;
	
	Outlet.x = LeftCorner.x;
	Outlet.y = LeftCorner.y;
}

void Condition::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void Condition::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}
void Condition::setop(const string& L)
{
	op = L;
	UpdateStatementText();
}

void Condition::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawConditionalStat(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

/////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!
//This function should be called when LHS or RHS changes
void Condition::UpdateStatementText()
{
	if (LHS == "")	//No left handside ==>statement have no valid text yet
		Text = op;
	else
	{
		//Build the statement text: Left handside then operator then right handside
		ostringstream T;
		T << LHS << op <<RHS;
		Text = T.str();
	}
}
string Condition::GetShape() {
	Shape = "Rhombus";
	return Shape;
}
Point Condition::GetLeft() {
	return LeftCorner;
}
Point Condition::GetSrc() {
	return Outlet;
}
Point Condition::GetDst()
{
	return Inlet;
}
void Condition::Move(Point p,Output*Pout)
{
	Pout->Drawdeletecon(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	LeftCorner = p;
	UpdateStatementText();
	Draw(Pout);

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y - UI.ASSGN_HI / 2;

	Outlet.x = LeftCorner.x;
	Outlet.y = LeftCorner.y;
}
void Condition::copy(Point p, Output* Pout)
{
	
	UpdateStatementText();
	Pout->DrawConditionalStat(p, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
void Condition::remove(Point p, Output* Pout)
{
	Point z;
	z.x = 1;
	z.y = 100000000;
	Pout->Drawdeletecon(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	Pout->Drawdeletecon(z, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	LeftCorner = z;
		Draw(Pout);
}
void Condition::cutpaste(Point p, Output* Pout)
{
	Pout->Drawdeletecon(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	LeftCorner = p;
	UpdateStatementText();
	Draw(Pout);

}
string Condition::GetType() {
	type = "COND";
	return type;
}
void Condition::PrintInfo(Output* pout)
{
	string x = to_string(LeftCorner.x);
	string y = to_string(LeftCorner.y);
	pout->PrintMessage("Conditional Statement (" + x + "," + y + "): " + Text + "//" + getComment());

}
void Condition::setCConnector(Connector* pConn,bool Ctype)
{
	if (Ctype)
		pConnY = pConn;
	else
		pConnN = pConn;
}
//Connector* Statement::getConnector()
//{
//	if (Ctype)
//		return this->pConnY;
//	else
//		return this->pConnN;
//
//}
void Condition::Save(ofstream& Outputfile)
{
	Outputfile << "COND" << "\t" << ID << "\t" << LeftCorner.x << "\t" << LeftCorner.y << " " << Text << "\t//"<<getComment() << endl;
}
void Condition::Load(ifstream& Inputfile)
{
	Inputfile >> ID >> LeftCorner.x >> LeftCorner.y >> Text;
}
Statement* Condition::GenerateCode(ofstream& OutFile)
{
	int whilecheck=0;
	int count=0;
	Statement* pstat= pConnY->getDstStat();
	
	if (!(OutFile.is_open()))
			OutFile.open("code.txt", ios::out );
	
		OutFile << "\tif(" << LHS << op << RHS << ")\t"<<getComment() << "\n\t{\n";
		while (pstat->GetType() != "END")
		{
			pstat = pstat->GenerateCode(OutFile);
		}
	
	OutFile << "\n\t}\n";

	pstat = pConnN->getDstStat();
	
		OutFile << "\telse\n{\n";
		while (pstat->GetType() != "END")
		{
			pstat = pstat->GenerateCode(OutFile);
		}
		OutFile << "\n\t}\n";
	
	return pstat;
}

void Condition::Editcond(string x, string y, double z)
{
	setLHS(x);
	setRHS(z);
	setop(y);
	UpdateStatementText();
}
