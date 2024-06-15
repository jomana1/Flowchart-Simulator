#include "..\Project Framework\OprtrAssign.h"
#include <sstream>
#include <fstream>

using namespace std;

OprtrAssign::OprtrAssign(Point Lcorner, string LeftHS, double RightHS1, string h, string b, string LeftHS1)
{
	LHS = LeftHS;
	LHS1 = LeftHS1;
	RHS1 = RightHS1;
	op = h;
	op1 = b;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void OprtrAssign::setLHS(const string& A)
{
	LHS = A;
	UpdateStatementText();
}
void OprtrAssign::setLHS1(const string& X)
{
	LHS1 = X;
	UpdateStatementText();
}

string OprtrAssign::getLHS()
{
	return LHS;
}

Connector* OprtrAssign::getConn()
{
	return pConn;
}

void OprtrAssign::setleft(Point p)
{
	LeftCorner=p;
}

void OprtrAssign::setRHS1(double R)
{
	RHS1 = R;
	UpdateStatementText();
}
void OprtrAssign::setop(const string& L)
{
	op = L;
	UpdateStatementText();
}
void OprtrAssign::setop1(const string& K)
{
	op1 = K;
	UpdateStatementText();
}


Point OprtrAssign::GetLeft()
{
	return LeftCorner;
}

Point OprtrAssign::GetSrc()
{
	return Outlet;
}

Point OprtrAssign::GetDst()
{
	return Inlet;
}

void OprtrAssign::Move(Point p, Output* pout)
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

void OprtrAssign::copy(Point p, Output* pout)
{

	UpdateStatementText();
	pout->DrawAssign(p, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

void OprtrAssign::cutpaste(Point p, Output* pOut)
{
	pOut->Drawdeleterec(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

	LeftCorner = p;
	UpdateStatementText();
	Draw(pOut);

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void OprtrAssign::remove(Point p, Output* pOut)
{
	Point z;
	z.x = 100;
	z.y = 1000;

	pOut->Drawdeleterec(z, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	pOut->Drawdeleterec(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

	LeftCorner = z;
	Draw(pOut);
	UpdateStatementText();
}

void OprtrAssign::PrintInfo(Output* pOut)
{
	string x = to_string(LeftCorner.x);
	string y = to_string(LeftCorner.y);
	
	pOut->PrintMessage("Single Operator Stat (" + x + "," + y + "): " + Text + "//" + getComment());


}

string OprtrAssign::GetType()
{
	type = "SNGLOP";
	return type;
}

Statement* OprtrAssign::GenerateCode(ofstream& OutFile)
{
	if (!(OutFile.is_open()))
		OutFile.open("code.txt", ios::out | ios::app);
	OutFile << "\t" << LHS << "=" << LHS1 << op1<<RHS1<< ";\t" << getComment() << "\n";
	return pConn->getDstStat();
}

void OprtrAssign::setConnector(Connector* pConn)
{
	this->pConn = pConn;
}

void OprtrAssign::EditOptrAss(string LHS, string LHS1, string op, string op1, double RHS1)
{
	setLHS(LHS);
	setLHS1(LHS1);
	setop(op);
	setop1(op1);
	setRHS1(RHS1);
	UpdateStatementText();
}

Connector* OprtrAssign::getConnector()
{
	return this->pConn;
}

void OprtrAssign::Save(ofstream& Outputfile)
{
	Outputfile << "SNGLOP" << ID << "\t" << LeftCorner.x << "\t" << LeftCorner.y << " " << Text << "\t//" << getComment() << endl;
}

void OprtrAssign::Load(ifstream& Inputfile)
{
	Inputfile >> ID >> LeftCorner.x >> LeftCorner.y >> Text;
}

void OprtrAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}

string OprtrAssign::GetShape()
{
	Shape = "RECT";
	return Shape;
}

/////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!
//This function should be called when LHS or RHS changes
void OprtrAssign::UpdateStatementText()
{
	if (LHS == "")	//No left handside ==>statement have no valid text yet
		Text = op;
	else
	{
		//Build the statement text: Left handside then operator then right handside
		ostringstream T;
		T << LHS << op << LHS1 << op1 << RHS1;
		Text = T.str();
	}

}
void OprtrAssign::Simulate(string* r, string* m, int x)
{
	int dess = 0;
	string h;
	string d = m[x - 1];
	for (int i = 0; i < x; i = i + 1)
	{
		if (!d.compare(r[i]))
		{
			h = m[i];
			dess = i;
		}
	}
	d = '+';
	if (!op1.compare(d))
	{
		m[dess] = h + to_string(RHS1);
	}







}