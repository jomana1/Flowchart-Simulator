#pragma once

#include "../Project Framework/Statements/Statement.h"

//Simple Assignment statement class
//The simple assignment statement assigns a variable to a value
class VarAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;	//Right Handside (Value)

	Connector* pConn;	//Simple Assignment Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	VarAssign(Point Lcorner, string LeftHS = "", string RightHS = "");

	void setLHS(const string& L);
	void setRHS(const string& R);

	string getLHS();
	string getRHS();

	virtual void Draw(Output* pOut) const;
	virtual string GetShape();
	virtual string GetType();

	virtual Point GetLeft();
	virtual Point GetSrc();
	virtual Point GetDst();


	virtual void Move(Point p, Output* poutt);
	virtual void copy(Point p, Output* pOut);
	virtual void cutpaste(Point p, Output* pOut);
	virtual void remove(Point p, Output* pOut);

	virtual void PrintInfo(Output* pOut);
	virtual Statement* GenerateCode(ofstream& OutFile);
	void setConnector(Connector* pConn);

	Connector* getConnector();

	void Save(ofstream& Outputfile);

	void Load(ifstream& Inputfile);

	void Simulate(string* r, string* m, int x);
	
	//virtual void Edit();
};