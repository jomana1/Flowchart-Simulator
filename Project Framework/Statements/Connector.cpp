#include "Connector.h"
#include "Statement.h"
#include "..\Adcondition.h"
#include <sstream>
#include <fstream>

Connector::Connector(Statement* Src, Statement* Dst,bool Ctype)	
//When a connector is created, it must have a source statement and a destination statement
//There are no free connectors in the folwchart
{
	
	SrcStat = Src;
	DstStat = Dst;
	if (SrcStat->GetType() == "COND")
		SrcStat->setCConnector(this, Ctype);
	else
		SrcStat->setConnector(this);
	this->Ctype = Ctype;
}
Connector::Connector(Statement* Src, Statement* Dst)
//When a connector is created, it must have a source statement and a destination statement
//There are no free connectors in the folwchart
{

	SrcStat = Src;
	DstStat = Dst;
	SrcStat->setConnector(this);
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}

void Connector::SetSelected(bool s)
{
	Selected = s;
}

bool Connector::IsSelected() const
{
	return Selected;
}


void Connector::Draw(Output* pOut) const 
{
	if (SrcStat->GetShape() == "Rhombus")
	{

		Point Start = SrcStat->GetSrc();
		Point End = DstStat->GetDst();
		if (Ctype)
			pOut->DrawConnector(Start, End,Selected);
		else if (!Ctype)
		{
			Start.x = Start.x + UI.ASSGN_WDTH;
			pOut->DrawConnector(Start, End, Selected);
		}
		///TODO: Call output to draw a connector from SrcStat to DstStat on the output window


	}
	
	else {
		Point Start = SrcStat->GetSrc();
		Point End = DstStat->GetDst();
		pOut->DrawConnector(Start, End, Selected);
	}
}
void Connector::Save(ofstream& Outputfile)
{
	Outputfile << SrcStat->getID() << "\t" << DstStat->getID() << "\t";
	if (SrcStat->GetType() == "COND")
	{
		if (Ctype == true)
			Outputfile << "1";
		else
			Outputfile << "2";
	}
	else
		Outputfile << "0";

	Outputfile << "\n";
}
void Connector::Load(ifstream& Inputfile)
{
	//InputFile << StartStat << EndStat;
}



