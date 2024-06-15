#include "ApplicationManager.h"
#include "Actions\AddSmplAssign.h"
#include "AddConn.h"
#include "Statements/Connector.h"
#include "AddRead.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Adcondition.h"
#include "AddStart.h"
#include "AddEnd.h"
#include "AddWrite.h"
#include "addmove.h"
#include "Addcopy.h"
#include "Statements/Statement.h"
#include "Addcut.h"
#include "delete.h"
#include "Select.h"
#include"ToSim.h"
#include"ToDsn.h"
#include"Addcut.h"
#include"Generate.h"
#include <fstream>
#include "Save.h"
#include "Load.h"
#include "Start.h"
#include "End.h"
#include "Read.h"
#include "Write.h"
#include "Condition.h"
#include "VarAssign.h"
#include "Statements/SmplAssign.h"
#include"AddOprtrAssign.h"
#include"AddVarAssign.h"
#include"OprtrAssign.h"
#include"VarAssign.h"
#include"Validate.h"
#include"MultSel.h"
#include"Comment.h"
#include"Run.h"
#include"EditStat.h"

//Constructor 

ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}
void ApplicationManager::setu(bool m)
{
	u = m;     //
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	u = false;
	Action* pAct = NULL;
	
	//According to ActionType, create the corresponding action object
	switch (ActType)
	{
		case ADD_SMPL_ASSIGN:
			pAct = new AddSmplAssign(this);
			break;
		case ADD_VAR_ASSIGN:
			pAct = new Addvarassign(this);
			break;
		case ADD_OPR_ASSIGN:
			pAct = new AddOprtrAssign(this);
			break;

		case ADD_CONDITION:
			pAct = new Addcondition(this);
			//create AddCondition Action here

			break;
		case ADD_READ:
			pAct = new AddRead(this);
			break;
		case ADD_WRITE:
			pAct = new AddWrite(this);
			break;

		case ADD_START:
			pAct = new AddStart(this);
			break;

		case ADD_END:
			pAct = new AddEnd(this);
			break;
		case EDIT_STAT:
			pAct = new EditStat(this);
			break;
		case SELECT:
			pAct = new Select(this);

			break;
		case SLCTMULSEL:
			pAct = new MultSel(this);

			break;
		case COMMENT:
			pAct = new Comment(this);
			break;
		case ADD_CONNECTOR:
			pAct = new AdConnector(this);
			break;
		case EXIT:
			break;
		case MOVE:
			pAct = new MOve(this);
			break;
		case COPY:
			pAct = new Addcopy(this);
			break;
		case CUT:
			pAct = new AddCut(this);
			break;
		case SIM_MODE:
			pAct = new ToSim(this);
			break;
		case DSN_MODE:
			pAct = new ToDsn(this);
				break;
		case VALIDATE:
			pAct = new Validate(this);
			break;
		case RUN:
			pAct = new Run(this);
			break;
		case SAVE:
			pAct = new Save(this);
			break;

		case LOAD:
			pAct = new Load(this);
			break;
		case STEP: 
			pAct = new Run(this, true); break;
		case GENERATE:
			pAct = new Generate(this);
			break;
		case DEL:
			pAct = new addDelete(this);
			break;

		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}
int ApplicationManager::GetStatCount()
{
	return StatCount;
}
Statement** ApplicationManager::GetStatList()
{

	return StatList;
}
Connector* ApplicationManager::GetConnector(Point P) const
{
	Point a, b;
	int x1,x3;
	int x2;
	int y1;
	int y2;
	Statement* src;
	Statement* dr;
	
		for (int i=0; i < ConnCount; i++)
		{
			src = ConnList[i]->getSrcStat();
			dr=ConnList[i]->getDstStat();
			a = src->GetSrc();
			b = dr->GetDst();
			x1 = a.x;
			y1 = a.y;
			x2 = b.x;
			y2 = b.y;
			x3 = P.x + UI.ASSGN_WDTH;
			if (((P.x == x1) && (P.y == y1)) || ((P.x == x2) && (P.y == y2)))
				return ConnList[i];
			if ((x1 == x3) && (P.y == y1))
				return ConnList[i];
		}
		return NULL;
	}





//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//
//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}
void ApplicationManager::AddConnector(Connector* pConn) 
{
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;
}


////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i]->GetShape() == "RECT")
		{
			Point Z = StatList[i]->GetLeft();
			if ((P.x >= Z.x && P.x <= Z.x + UI.ASSGN_WDTH) && (P.y >= Z.y && P.y <= Z.y + UI.ASSGN_HI))
			{
				return StatList[i];
			}
		}
		if (StatList[i]->GetShape() == "Rhombus")
		{
			Point Z = StatList[i]->GetLeft();
			if ((P.x >= Z.x && P.x <= Z.x + UI.ASSGN_WDTH) && (P.y >= (Z.y - (UI.ASSGN_HI / 2)) && P.y <= (Z.y + (UI.ASSGN_HI / 2))))
			{
				return StatList[i];
			}

		}
		if (StatList[i]->GetShape() == "para")
		{
			Point Z = StatList[i]->GetLeft();
			if ((P.x >= Z.x && P.x <= Z.x + UI.ASSGN_WDTH) && (P.y <= Z.y && P.y >= Z.y - UI.ASSGN_HI))
			{
				return StatList[i];
			}
		}
		if (StatList[i]->GetShape() == "elipseS")
		{
			Point Z = StatList[i]->GetLeft();
			if ((P.x >= Z.x && P.x <= Z.x + UI.ASSGN_WDTH) && (P.y >= Z.y && P.y <= Z.y + UI.ASSGN_HI))
			{
				return StatList[i];
			}
		}
			if (StatList[i]->GetShape() == "elipseE")
			{
				Point Z = StatList[i]->GetLeft();
				if ((P.x >= Z.x && P.x <= Z.x + UI.ASSGN_WDTH) && (P.y >= Z.y && P.y <= Z.y + UI.ASSGN_HI))
				{
					return StatList[i];
				}
			}


		}


		///Add your code here to search for a statement given a point P(x,y)	

		return NULL;
	}
void ApplicationManager::SaveAll(ofstream& OutputFile)
{

	OutputFile << StatCount << endl;
	for (int i = 0; i < StatCount; i++)
	{
		//each iteration statement base pointer points to a different derived object
		//and calls it's version of the pure virtual function Save

		StatList[i]->setID(i + 1);     
		StatList[i]->Save(OutputFile);

	}

	OutputFile << ConnCount << endl;
	for (int i = 0; i < ConnCount; i++)
	{
		ConnList[i]->Save(OutputFile);

	}

	pOut->PrintMessage("Flowchart has been saved, check your folders.");
}


void ApplicationManager::LoadAll(ifstream& InputFile)
{
	int numofstat;
	InputFile >> numofstat;
	
	for (int i = 0; i < numofstat; i++)
	{
		string TypeStatement;
		InputFile >> TypeStatement;
		Statement* pStatement;
		Point P;
		P.x = 1; P.y = 1;

		if (TypeStatement == "STRT") {

			pStatement = new Start(P);  //Polymorphism base points to derive.

		}
		else if (TypeStatement == "END") {

			pStatement = new End(P);

		}
		else if (TypeStatement == "READ") {

			pStatement = new Read(P);

		}
		else if (TypeStatement == "WRITE") {

			pStatement = new Write(P);
		}
		else if (TypeStatement == "COND") {

			pStatement = new Condition(P);

		}
		else if (TypeStatement == "SMPL") {

			pStatement = new SmplAssign(P);
		}
		else if (TypeStatement == "VAR") {

			pStatement = new VarAssign(P);
		}
		else if (TypeStatement == "SNGLOP") {

			pStatement = new OprtrAssign(P);
		}

		pStatement->Load(InputFile); //each iteration statement base pointer points to a different derived object
		                              //and calls it's version of the pure virtual function Load
		AddStatement(pStatement);

	}


	int numofConnectors;
	InputFile >> numofConnectors;
	int StartStat;
	int EndStat;
	int y;

	Connector* Conn;
	for (int i = 0; i < numofConnectors; i++)
	{
		InputFile >> StartStat;
		InputFile >> EndStat;
		InputFile >> y;

		Conn = new Connector(StatList[StartStat - 1], StatList[EndStat - 1], false);
		
		AddConnector(Conn);
	}

}

bool ApplicationManager::GetStartEnd()
{
	int c = 0;
	for (int i = 0;i < StatCount;i++)
	{
		if (StatList[i]->GetType() == "STRT")
		{
			c++;
		}
		else if (StatList[i]->GetType() == "END")
		{
			c++;
		}

	}
	if (c == 2)
		return true;
	else 
		return false;
}
bool ApplicationManager::NumConnector()
{
	int c = 0;
	Point* p = new Point[StatCount];
	Point* q = new Point[ConnCount];
	for (int w = 0; w < StatCount; w++)
		*p = StatList[w]->GetDst();
	for (int j = 0; j < ConnCount; j++)
		*q = ConnList[j]->getEndPoint();




	for (int i = 0; i < StatCount; i++)
	{
		c = 0;
		if (StatList[i]->GetShape() == "elipseS")
		{
			c = 1;
		}
		for (int z = 0; z < ConnCount; z++)
		{
			if ((p[i].x == q[z].x) && (p[i].y == q[i].y))
				c = 1;
		}

	}
	if (c == 1)
		return true;
	else
		return false;
}
	////////////////////////////////////////////////////////////////////////////////////


//Returns the selected statement
	Statement* ApplicationManager::GetSelectedStatement() const
	{
		return pSelectedStat;
	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	if ( u==true)
	{
		return;
	}
	if (UI.AppMode != SIMULATION)
	{ 	//Draw all statements
		for (int i = 0; i < StatCount; i++)
			StatList[i]->Draw(pOut);

		//Draw all connections
		for (int i = 0; i < ConnCount; i++)
			ConnList[i]->Draw(pOut);
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
