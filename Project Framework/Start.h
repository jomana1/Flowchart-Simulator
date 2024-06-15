#pragma once

#include "../Project Framework/Statements/Statement.h"

class Start : public Statement
{
private:

	Connector* pConn;	//Start Stat. has one Connector to next statement

	Point Outlet;	//A point a connection leaves the ellipse

	Point Left;	//left point of ellipse


	virtual void UpdateStatementText();
public:
	Start(Point L);
	virtual void Draw(Output* pOut) const;
	virtual string GetShape();
	virtual Point GetLeft();
	virtual Point GetSrc();
	virtual Point GetDst();
	void setConnector(Connector* pConn);
	Connector* getConnector();
	virtual void Move(Point p,Output*i);
	virtual void copy(Point p, Output* pOut);
	virtual void cutpaste(Point p, Output* pOut);
	virtual void remove(Point p, Output* pOut);
	virtual void PrintInfo(Output* pOut);
	virtual string GetType();
	virtual Statement* GenerateCode(ofstream& OutFile);
	void Save(ofstream& Outputfile);
	void Load(ifstream& Inputfile);
	//virtual void Edit();
};