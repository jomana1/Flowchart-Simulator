#include <fstream>
#include "Save.h"
#include "Actions/Action.h"
#include "Statements/Statement.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include <fstream>

Save::Save(ApplicationManager* pApp) :Action(pApp)
{

}
void Save::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("you clicked on Save : Enter file name");
	fileName = pIn->GetString(pOut);
}
void Save::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ofstream myfile;
	myfile.open(fileName);
	pManager->SaveAll(myfile);
	myfile.close();
}
Save::~Save()
{

}