#pragma once

#include "../Project Framework/Statements/Statement.h"

//Condition Assignment statement class
//The sCondition assignment statement assigns a variable to a value
class Condition : public Statement
{
private:
	string LHS;	//Left Handside of the condition (name of a variable)
	double RHS;	//Right Handside (Value)
	string op;

	Connector* pConnY;	//conditional Stat. has two Connectors to next statement
	Connector* pConnN;
	bool Ctype;
	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement
	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	Condition(Point Lcorner, string LeftHS = "", double RightHS = 0, string opo = "");

	void setLHS(const string& L);
	void setRHS(double R);
	void setop(const string& j);
	virtual void Draw(Output* pOut) const;

	virtual string GetShape();
	virtual Point GetLeft();
	virtual Point GetSrc();
	virtual Point GetDst();
	virtual void Move(Point p,Output*pOut);
	virtual void copy(Point p, Output* pOut);
	virtual void remove(Point p, Output* pOut);
	virtual void cutpaste(Point p, Output* pOut);
	virtual void PrintInfo(Output* pOut);
	void setCConnector(Connector* pConn,bool Ctype);
	//bool getConnType();
	virtual string GetType();
	void Save(ofstream& Outputfile);
	void Load(ifstream& Inputfile);
	virtual Statement* GenerateCode(ofstream& OutFile);
	virtual void Editcond(string x, string y, double z);
	//virtual void Edit();
};
