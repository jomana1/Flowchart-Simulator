#ifndef SMPL_ASSIGN_H
#define SMPL_ASSIGN_H

#include "Statement.h"
#include "..\ApplicationManager.h"
//Simple Assignment statement class
//The simple assignment statement assigns a variable to a value
class SmplAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	double RHS;	//Right Handside (Value)
	
	Connector *pConn;	//Simple Assignment Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();
	
public:
	SmplAssign(Point Lcorner, string LeftHS="", double RightHS=0);
	
	void setLHS(const string &L);
	void setRHS(double R);
	string getLHS();
	double getRHS();
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
	virtual Statement* Simulate();
	void setConnector(Connector* pConn);
	virtual void EditSmp(string c, double q);
	Connector* getConnector();

	void Save(ofstream& Outputfile);

	void Load(ifstream& Inputfile);
	
	//virtual void Edit();
};

#endif