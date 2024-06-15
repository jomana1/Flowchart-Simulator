#include "Statement.h"
 double Statement::x = 0;
Statement::Statement()	
{ 
	Text = "";
	Selected = false;	
	pConn = nullptr;
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

double Statement::getx()
{
	return x;
}

void Statement::setx(double a)
{
	x = a;
}

void Statement::setComment(string c)
{
	Comment = c;
}

string Statement::getComment()
{
	return Comment;
}

void Statement::setConnector(Connector* pConn)
{
	this->pConn = pConn;

}

Connector* Statement::getConnector()
{
	return this->pConn;
}

void Statement::Simulate(string* r, string* m, int x)
{
	
}
void Statement::setID(int x)
{
	ID = x;
}
int Statement::getID()
{
	return ID;
}

void Statement::Editcond(string z, string g, double x)
{
	
}

void Statement::EditSmp(string c, double q)
{
}

void Statement::EditOptrAss(string LHS, string LHS1, string op, string op1, double RHS1)
{
}

void Statement::EditRead(string x)
{
}

void Statement::EditWrite(string x)
{
}

void Statement::setCConnector(Connector* pConn, bool Ctype)
{
	if (Ctype)
		pConnY = pConn;
	else
		pConnN = pConn;
}
