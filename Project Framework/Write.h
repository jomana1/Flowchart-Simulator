#pragma once
#include  "../Project Framework/Statements/Statement.h"

//Simple Assignment statement class
//The simple assignment statement assigns a variable to a value
class Write : public Statement
{
private:
	string var;	//(name of a variable)

	Connector* pConn;	//Simple Assignment Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	Write(Point Lcorner, string v = "");

	void setVAR(const string& v);
	string getVAR();
	void setConnector(Connector* pConn);
	Connector* getConnector();
	virtual void Draw(Output* pOut) const;
	virtual string GetShape();
	virtual Point GetLeft();
	virtual Point GetSrc();
	virtual Point GetDst();
	//virtual Connector* getConn();
	//void setConnector(Connector* pConn);
	virtual void Move(Point p,Output*y);
	virtual void copy(Point p, Output* pOut) ;
	virtual void cutpaste(Point p, Output* pOut);
	virtual void remove(Point p, Output* pOut);
	virtual void PrintInfo(Output* pOut);
	virtual string GetType();
	virtual Statement* GenerateCode(ofstream& OutFile) ;
	void Save(ofstream& OutputFile);
	void Load(ifstream& Inputfile);
	virtual void EditWrite(string x);
};