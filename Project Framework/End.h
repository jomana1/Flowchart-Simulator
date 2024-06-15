#pragma once

#include "../Project Framework/Statements/Statement.h"

//End Assignment statement class
class End : public Statement
{
private:

	//Connector* pConn;	//End Stat. has one Connector to next statement

	Point Inlet;	//A point a connection leaves the ellipse

	Point Left;	//left point of ellipse

	virtual void UpdateStatementText();

public:
	End(Point L);
	virtual void Draw(Output* pOut) const;
	virtual string GetShape();
	virtual Point GetLeft();
	virtual Point GetSrc();
	virtual Point GetDst();
	//virtual Connector* getConn();
	//void setConnector(Connector* pConn);
	virtual void Move(Point p,Output*u);
	virtual void copy(Point p, Output* pOut);
	virtual void cutpaste(Point p, Output* pOut);
	virtual void remove(Point p, Output* pOut);
	virtual void PrintInfo(Output* pOut);
	virtual string GetType();
	virtual  Statement* GenerateCode(ofstream& OutFile);
	void Save(ofstream& Outputfile);
	void Load(ifstream& Inputfile);
	//virtual void Edit();
};