#ifndef STATEMENT_H
#define STATEMENT_H

#include "..\defs.h"
#include "Connector.h"
//class Output;
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
//Base class for all Statements
class Statement
{
protected:
	int ID;			//Each Statement has an ID
	string Text;	//Statement text (e.g.  "X = 5" OR "if(salary > 3000)" and so on )
	bool Selected;	//true if the statement is selected on the folwchart
	string Shape;
	string type;
	static double x;
	Connector* pConn;
	Connector* pConnY; //connectors used for condition branches
	Connector* pConnN;
	string Comment ="";
	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:

	Statement();
	void SetSelected(bool s);
	bool IsSelected() const;
	static double getx();
	static void setx(double a);
	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	
	void setComment(string c);
	string getComment();
	virtual string GetShape() = 0;
	virtual string GetType() = 0;
	virtual Point GetLeft() = 0;

	virtual Point GetSrc() = 0;
	virtual Point GetDst() = 0;
	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type	


	virtual void Save(ofstream& OutFile) = 0;	//Save the Statement parameters to a file
	virtual void Load(ifstream& Inputfile) = 0;	//Load the Statement parameters from a file


	virtual void Move(Point p, Output* pOut) = 0;//Move the Statement on the flowchart
	virtual void copy(Point p, Output* pOut) = 0;	//Move the Statement on the flowchart
	virtual void cutpaste(Point p, Output* pOut) = 0;
	virtual void remove(Point p, Output* pOut) = 0;
	//virtual void Edit() ;		//Edit the Statement parameter
	virtual void setConnector(Connector* pConn);
	Connector* getConnector();
	virtual void setCConnector(Connector* pConn,bool Ctype);
	virtual Statement* GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file
	virtual void Simulate(string* r, string* m, int x);	//Execute the statement in the simulation mode
	void setID(int x);
	int getID();
	virtual void Editcond(string z, string g, double x);
	virtual void EditSmp(string c, double q);
	virtual void EditOptrAss(string LHS, string LHS1, string op, string op1, double RHS1);
	virtual void EditRead(string x);
	virtual void EditWrite(string x);


	virtual void PrintInfo(Output* pOut) = 0;	//print all Statement info on the status bar
	
	///TODO: Add more functions if needed
};

#endif