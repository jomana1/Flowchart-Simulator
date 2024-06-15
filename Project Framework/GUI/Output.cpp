#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 900;
	UI.height = 700;
	UI.wx = 15;
	UI.wy = 15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StBrWdth = 50;
	UI.TlBrWdth = 50;
	UI.MnItWdth = 80;

	UI.DrawClr = MAROON;
	UI.Delete = WHITE;
	UI.HiClr = DARKTURQUOISE;
	UI.MsgClr = MAROON;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");

	//pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height - UI.StBrWdth, UI.width, UI.height - UI.StBrWdth);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the Design Menu
void Output::CreateDesignToolBar()
{
	ClearToolBar();
	UI.AppMode = DESIGN;	//Design Mode
	int i = 0;
	//fill the tool bar 
	//You can draw the tool bar icons in any way you want.
	UI.TlBrWdth = (int)round(2 * UI.width / 27);
	UI.MnItWdth = (int)round(UI.width / 27);
	pWind->DrawImage("images1\\exit.jpg", 0, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\Assign.jpg", UI.MnItWdth, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\varassign.jpeg", UI.MnItWdth * 2, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\opassign.jpeg", UI.MnItWdth * 3, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\Condition.jpg", UI.MnItWdth * 4, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\start.jpeg", UI.MnItWdth * 5, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\end.jpeg", UI.MnItWdth * 6, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\simple_value.jpeg", UI.MnItWdth * 7, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\Read.jpg", UI.MnItWdth * 8, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\Write.jpg", UI.MnItWdth * 9, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\connector.jpeg", UI.MnItWdth * 10, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\edit.jpeg", UI.MnItWdth * 11, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\editconnection.jpeg", UI.MnItWdth * 12, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\Comment.jpg", UI.MnItWdth * 13, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\select.jpeg", UI.MnItWdth * 14, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\multiplesel.jpeg", UI.MnItWdth * 15, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\delete.jpeg", UI.MnItWdth * 16, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\move.jpeg", UI.MnItWdth * 17, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\Save.jpeg", UI.MnItWdth * 18, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\resize.jpeg", UI.MnItWdth * 19, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\load.jpeg", UI.MnItWdth * 20, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\copy.jpeg", UI.MnItWdth * 21, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\paste.jpeg", UI.MnItWdth * 22, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\cut.jpeg", UI.MnItWdth * 23, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\undo.jpeg", UI.MnItWdth * 24, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\redo.jpeg", UI.MnItWdth * 25, 0, UI.MnItWdth, UI.MnItWdth);
	pWind->DrawImage("images1\\simulate.jpeg", UI.MnItWdth * 26, 0, UI.MnItWdth, UI.MnItWdth);

	//Draw a line under the toolbar
	//pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);	

}

void Output::CreateSimulationToolBar()
{
	int i = 0;
	ClearToolBar();
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	UI.TlBrWdth = UI.width / 27;
	UI.MnItWdth = UI.TlBrWdth;
	pWind->DrawImage("images1\\exit.jpg", 0, 0, UI.MnItWdth, UI.TlBrWdth);
	pWind->DrawImage("images1\\validate.jpg", UI.MnItWdth * ++i, 0, UI.MnItWdth, UI.TlBrWdth);
	pWind->DrawImage("images1\\Run.jpg", UI.MnItWdth * ++i, 0, UI.MnItWdth, UI.TlBrWdth);
	pWind->DrawImage("images1\\StepByStep.jpg", ++i * UI.MnItWdth, 0, UI.MnItWdth, UI.TlBrWdth);
	pWind->DrawImage("images1\\generatec++.jpeg", ++i * UI.MnItWdth, 0, UI.MnItWdth, UI.TlBrWdth);
	pWind->DrawImage("images1\\design.jpeg", ++i * UI.MnItWdth, 0, UI.MnItWdth, UI.TlBrWdth);


}
void Output::ClearToolBar()
{
	//Clear Tool bar by drawing a filled white rectangle
	UI.TlBrWdth = UI.width / 27;
	UI.MnItWdth = UI.TlBrWdth;
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.TlBrWdth);
	pWind->SetPen(BLACK, 1);
	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);

}
////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(BLACK, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StBrWdth, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	UI.TlBrWdth = UI.width / 27;
	UI.MnItWdth = UI.TlBrWdth;
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.TlBrWdth, UI.width, UI.height - UI.StBrWdth);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgClr, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StBrWdth / 1.5), msg);
}

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//
void Output::Drawdeleterec(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(WHITE, 3);	//use highlighting color
	else
		pWind->SetPen(WHITE, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(WHITE, 2);
	pWind->DrawString(Left.x + width / 4 - Text.length() / 2, Left.y + height / 4, Text);

}



//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4 - Text.length() / 2, Left.y + height / 4, Text);

}
void Output::DrawStartdel(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.Delete, 3);	//use highlighting color
	else
		pWind->SetPen(UI.Delete, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(WHITE, 2);
	pWind->DrawString(Left.x + width / 4 + 10, Left.y + height / 4 + 5, Text);

}
void Output::DrawStart(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4 + 10, Left.y + height / 4 + 5, Text);

}
void Output::DrawEnddel(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.Delete, 3);	//use highlighting color
	else
		pWind->SetPen(UI.Delete, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(WHITE, 2);
	pWind->DrawString(Left.x + width / 2 - 15, Left.y + height / 2 - 7, Text);

}
void Output::DrawEnd(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 2 - 15, Left.y + height / 2 - 7, Text);

}
void Output::Drawdeletecon(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.Delete, 3);	//use highlighting color
	else
		pWind->SetPen(UI.Delete, 3);	//use normal color

	//Draw the rhombus
	int x[4];
	int y[4];
	x[0] = Left.x;
	x[1] = x[0] + width / 2;
	x[2] = x[1] + width / 2;
	x[3] = x[1];
	y[0] = Left.y;
	y[1] = y[0] + height / 2;
	y[2] = y[0];
	y[3] = y[0] - height / 2;

	pWind->DrawPolygon(x, y, 4);

	//Write statement text
	pWind->SetPen(WHITE, 2);
	pWind->DrawString(Left.x + width / 6, Left.y - height / 6, Text);
}
void Output::DrawConditionalStat(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color

	//Draw the rhombus
	int x[4];
	int y[4];
	x[0] = Left.x;
	x[1] = x[0] + width / 2;
	x[2] = x[1] + width / 2;
	x[3] = x[1];
	y[0] = Left.y;
	y[1] = y[0] + height / 2;
	y[2] = y[0];
	y[3] = y[0] - height / 2;

	pWind->DrawPolygon(x, y, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 6, Left.y - height / 6, Text);
	pWind->DrawString(Left.x - 40, Left.y - height / 3, "YES");
	pWind->DrawString(Left.x + width + 20, Left.y - height / 3, "NO");
}
void Output::DrawReadWritedelete(Point TopLeft, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.Delete, 3);	//use highlighting color
	else
		pWind->SetPen(UI.Delete, 3);	//use normal color

	//Draw the Parallelogram (read and write statements)
	int x[4];
	int y[4];
	x[0] = TopLeft.x;
	x[1] = x[0] + width;
	x[2] = x[1] - width / 4;
	x[3] = x[0] - width / 4;
	y[0] = TopLeft.y;
	y[1] = y[0];
	y[2] = y[0] - height;
	y[3] = y[2];

	pWind->DrawPolygon(x, y, 4);

	//Write statement text
	pWind->SetPen(WHITE, 2);
	pWind->DrawString(TopLeft.x + width / 8 - Text.size(), TopLeft.y - height / 2, Text);
}
void Output::DrawReadWrite(Point TopLeft, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color

	//Draw the Parallelogram (read and write statements)
	int x[4];
	int y[4];
	x[0] = TopLeft.x;
	x[1] = x[0] + width;
	x[2] = x[1] - width / 4;
	x[3] = x[0] - width / 4;
	y[0] = TopLeft.y;
	y[1] = y[0];
	y[2] = y[0] - height;
	y[3] = y[2];

	pWind->DrawPolygon(x, y, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(TopLeft.x + width / 8 - Text.size(), TopLeft.y - height / 2, Text);
}
//void Output::DrawWrite(Point TopLeft, int width, int height, string Text, bool Selected)
//{
//	if (Selected)	//if stat is selected, it should be highlighted
//		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
//	else
//		pWind->SetPen(UI.DrawClr, 3);	//use normal color
//
//	//Draw the Parallelogram
//	int x[4];
//	int y[4];
//	x[0] = TopLeft.x;
//	x[1] = x[0] + width;
//	x[2] = x[1] - width / 4;
//	x[3] = x[0] - width / 4;
//	y[0] = TopLeft.y;
//	y[1] = y[0];
//	y[2] = y[0] - height;
//	y[3] = y[2];
//
//	pWind->DrawPolygon(x, y, 4);
//
//	//Write statement text
//	pWind->SetPen(BLACK, 2);
//	pWind->DrawString(TopLeft.x + width / 6, TopLeft.y - height / 4, Text);
//}
void Output::DrawConnector(Point Start, Point End, bool Selected) {
	if (Selected)	//if connector is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color

	pWind->DrawLine(Start.x, Start.y, End.x, Start.y);
	pWind->DrawLine(End.x, Start.y, End.x, End.y);
	if (abs(Start.x - End.x) <= 5)
		Start.x = End.x;
	if (abs(Start.y - End.y) <= 5)
		Start.y = End.y;

	if (Start.x == End.x && Start.y > End.y)
	{
		pWind->DrawLine(End.x - 10, End.y + 10, End.x, End.y);
		pWind->DrawLine(End.x + 10, End.y + 10, End.x, End.y);
	}
	else if (Start.x > End.x && Start.y == End.y)
	{
		pWind->DrawLine(End.x + 10, End.y - 10, End.x, End.y);
		pWind->DrawLine(End.x + 10, End.y + 10, End.x, End.y);
	}
	else if (Start.x == End.x && Start.y < End.y)
	{
		pWind->DrawLine(End.x - 10, End.y - 10, End.x, End.y);
		pWind->DrawLine(End.x + 10, End.y - 10, End.x, End.y);
	}
	else if (Start.x < End.x && Start.y == End.y)
	{
		pWind->DrawLine(End.x - 10, End.y - 10, End.x, End.y);
		pWind->DrawLine(End.x - 10, End.y + 10, End.x, End.y);
	}

	if (Start.x > End.x && Start.y > End.y)
	{
		pWind->DrawLine(End.x - 10, End.y + 10, End.x, End.y);
		pWind->DrawLine(End.x + 10, End.y + 10, End.x, End.y);
	}
	if (Start.x < End.x && Start.y < End.y)
	{
		pWind->DrawLine(End.x + 10, End.y - 10, End.x, End.y);
		pWind->DrawLine(End.x - 10, End.y - 10, End.x, End.y);
	}
	if (Start.x > End.x && Start.y < End.y)
	{
		pWind->DrawLine(End.x - 10, End.y - 10, End.x, End.y);
		pWind->DrawLine(End.x + 10, End.y - 10, End.x, End.y);
	}
	if (Start.x < End.x && Start.y > End.y)
	{
		pWind->DrawLine(End.x + 10, End.y + 10, End.x, End.y);
		pWind->DrawLine(End.x - 10, End.y + 10, End.x, End.y);
	}
	//Write statement text
	//pWind->SetPen(BLACK, 2);
	//pWind->DrawString(TopLeft.x + width / 4, TopLeft.y + height / 4, Text);
}
void Output::DrawConnectordel(Point Start, Point End, bool Selected)
{
	if (Selected)	//if connector is selected, it should be highlighted
		pWind->SetPen(WHITE, 3);	//use highlighting color
	else
		pWind->SetPen(WHITE, 3);	//use normal color

	pWind->DrawLine(Start.x, Start.y, End.x, Start.y);
	pWind->DrawLine(End.x, Start.y, End.x, End.y);
	if (abs(Start.x - End.x) <= 5)
		Start.x = End.x;
	if (abs(Start.y - End.y) <= 5)
		Start.y = End.y;

	if (Start.x == End.x && Start.y > End.y)
	{
		pWind->DrawLine(End.x - 10, End.y + 10, End.x, End.y);
		pWind->DrawLine(End.x + 10, End.y + 10, End.x, End.y);
	}
	else if (Start.x > End.x && Start.y == End.y)
	{
		pWind->DrawLine(End.x + 10, End.y - 10, End.x, End.y);
		pWind->DrawLine(End.x + 10, End.y + 10, End.x, End.y);
	}
	else if (Start.x == End.x && Start.y < End.y)
	{
		pWind->DrawLine(End.x - 10, End.y - 10, End.x, End.y);
		pWind->DrawLine(End.x + 10, End.y - 10, End.x, End.y);
	}
	else if (Start.x < End.x && Start.y == End.y)
	{
		pWind->DrawLine(End.x - 10, End.y - 10, End.x, End.y);
		pWind->DrawLine(End.x - 10, End.y + 10, End.x, End.y);
	}

	if (Start.x > End.x && Start.y > End.y)
	{
		pWind->DrawLine(End.x - 10, End.y + 10, End.x, End.y);
		pWind->DrawLine(End.x + 10, End.y + 10, End.x, End.y);
	}
	if (Start.x < End.x && Start.y < End.y)
	{
		pWind->DrawLine(End.x + 10, End.y - 10, End.x, End.y);
		pWind->DrawLine(End.x - 10, End.y - 10, End.x, End.y);
	}
	if (Start.x > End.x && Start.y < End.y)
	{
		pWind->DrawLine(End.x - 10, End.y - 10, End.x, End.y);
		pWind->DrawLine(End.x + 10, End.y - 10, End.x, End.y);
	}
	if (Start.x < End.x && Start.y > End.y)
	{
		pWind->DrawLine(End.x + 10, End.y + 10, End.x, End.y);
		pWind->DrawLine(End.x - 10, End.y + 10, End.x, End.y);
	}
	//Write statement text
}
//////////////////////////////////////////////////////////////////////////////////////////

Output::~Output()
{
	delete pWind;
}

