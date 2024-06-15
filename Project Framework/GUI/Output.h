#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int);
	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar();//Tool bar of the simulation mode

	void CreateStatusBar();

	Input* CreateInput(); //creates a pointer to the Input object	
	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea();	//Clears the drawing area
	void ClearToolBar();
	// -- Statements Drawing Functions
	void DrawAssign(Point Left, int width, int height, string Text, bool Selected = false);

	//TODO: Add similar functions for drawing all other statements.
	//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
	//		Decide the parameters that should be passed to each of them
	void Drawdeleterec(Point Left, int width, int height, string Text, bool Selected = false);
	void Drawdeletecon(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawEnd(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawEnddel(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawStart(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawStartdel(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawConditionalStat(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawReadWrite(Point TopLeft, int width, int height, string Text, bool Selected = false);
	void DrawReadWritedelete(Point TopLeft, int width, int height, string Text, bool Selected = false);
	//void DrawWrite(Point TopLeft, int width, int height, string Text, bool Selected = false);
	void DrawConnector(Point Start, Point End, bool Selected = false);
	void DrawConnectordel(Point Start, Point End, bool Selected = false);

	void PrintMessage(string msg);	//Prints a message on Status bar

	~Output();
};

#endif