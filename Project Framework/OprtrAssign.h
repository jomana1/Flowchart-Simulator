#pragma once
#include "../Project Framework/Statements/Statement.h"

//operator Assignment statement class
//The operator assignment statement assigns a variable to an equation
class OprtrAssign: public Statement
{
private:
	string LHS;	 //Left Handside of the condition (name of a variable)
	double RHS1;	//Right Handside of the equation
	string op;   // the equal operator between the two sides
	string op1;   //the operator of the equation
	string LHS1;   //the left hand side of the equation


	Connector* pConn;	//conditional Stat. has two Connectors to next statement
	Connector* pConn2;

	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

	void Simulate(string* r, string* m, int x);

public:
	OprtrAssign(Point Lcorner, string LeftHS = "", double RightHS = 0, string opo = "", string opo1 = "", string LeftHS1 = "");

	void setLHS(const string& L);
	void setRHS1(double R);
	void setop(const string& j);
	void setop1(const string& k);
	void setLHS1(const string& x);
	string getLHS();
	virtual Connector* getConn();
	void setleft(Point p);
	virtual void Draw(Output* pOut) const;
	virtual string GetShape();
	virtual Point GetLeft() ;
	virtual Point GetSrc() ;
	virtual Point GetDst();
	virtual void Move(Point p,Output*poutt );

	virtual void copy(Point p, Output* pOut);
	virtual void cutpaste(Point p, Output* pOut);
	virtual void remove(Point p, Output* pOut);
	virtual void PrintInfo(Output* pOut);
	virtual string GetType() ;
	virtual Statement* GenerateCode(ofstream& OutFile);
	void setConnector(Connector* pConn);
	virtual void EditOptrAss(string LHS, string LHS1, string op, string op1, double RHS1);
	Connector* getConnector();

	void Save(ofstream& Outputfile);

	void Load(ifstream& Inputfile);



};