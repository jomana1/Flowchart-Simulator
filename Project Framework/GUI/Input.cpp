#include "Input.h"
#include "Output.h"
#include <iostream>
using namespace std;

Input::Input(window* pW)
{

	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point &P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}


string Input::GetString(Output *pO) const 
{
	string Str;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Str;
		if(Key == 8 )	//BackSpace is pressed
			Str.resize(Str.size() -1 );			
		else
			Str += Key;
		pO->PrintMessage(Str);
	}
}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D
	double D = 0;
	string Str;
	char Key;
	int sign = 1;
	pO->PrintMessage("Please enter a value");
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return stod("");	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return stod(Str);
		
		if (!(((Key >= 48) && (Key <= 57)) || (Key == 46) || (Key == 45)||(Key==8)))
		{
			pO->PrintMessage("INVALID! Please enter numbers only");
			if(Str.size()!=0)
			Str.resize(Str.size() - 1);
			continue;
		}
		if (Key == 8)	//BackSpace is pressed
		{
			if (Str.size() != 0)
				Str.resize(Str.size() - 1);
		}
		else Str += Key;
		 if (((Key >= 48) && (Key <= 57)) || (Key == 46) || (Key == 45))
		{
			int countDecPoint = 0;
			int countNeg = 0;
			for (int i = 1; i < Str.length(); i++)
			{
				if (Str[i] == '-')
				{
					countNeg++;

				}
			}
			for (int i = 0; i < Str.length(); i++)
			{
				if (Str[i] == '.')
				{
					countDecPoint++;

				}
			}
			if (countDecPoint > 1)
			{
				pO->PrintMessage("INVALID! Please enter only 1 decimal point");
				Str.resize(Str.size() - 1);
				continue;
			}

			if (countNeg != 0)
			{
				pO->PrintMessage("INVALID! Please enter another value");
				Str.resize(Str.size() - 1);
				continue;
			}

		}
			
			pO->PrintMessage(Str);
		
	}



	return D;
}

//ActionType Input::GetUserAction() const
//{	
//	//This function reads the position where the user clicks to determine the desired action
//
//	int x,y;
//	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
//
//	if(UI.AppMode == DESIGN )	//application is in design mode
//	{
//		//[1] If user clicks on the Toolbar
//		if ( y >= 0 && y < UI.TlBrWdth)
//		{	//Check whick Menu item was clicked
//			if( x >= 0 && x < UI.MnItWdth  )
//				return ADD_SMPL_ASSIGN;
//			if( x >= UI.MnItWdth && x < 2* UI.MnItWdth  )		
//				return ADD_CONDITION;
//			if( x >= UI.MnItWdth && x < 3* UI.MnItWdth  )		
//				return ADD_CONNECTOR;
//			if (x >= UI.MnItWdth && x < 4* UI.MnItWdth)
//				return ADD_VAR_ASSIGN;
//			if (x >= UI.MnItWdth && x < 5 * UI.MnItWdth)
//				return ;
//			if (x >= UI.MnItWdth && x < 3 * UI.MnItWdth)
//				return EXIT;
//
//			return DSN_TOOL;	//a click on empty part of the tool bar
//		
//		}
//		
//		//[2] User clicks on the drawing area
//		if ( y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
//		{
//			return SELECT;	//user want to select/unselect a statement in the flowchart
//		}
//		
//		//[3] User clicks on the status bar
//		return STATUS;
//	}
//	else	//Application is in Simulation mode
//	{
//		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
//	}
//
//}


ActionType Input::GetUserAction() const
{	
	//This function reads the position where the user clicks to determine the desired action

	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.TlBrWdth)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			UI.TlBrWdth = (int)round(2 * UI.width / 27);
			UI.MnItWdth = (int)round(UI.width / 27);
			int ClickedItem = (x / UI.MnItWdth);

			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_EXIT: return EXIT;
			case ITM_SMPL_ASSIGN: return ADD_SMPL_ASSIGN;
			case ITM_VAR_ASSIGN: return ADD_VAR_ASSIGN;
			case ITM_OPR_ASSIGN: return ADD_OPR_ASSIGN;
			case ITM_COND: return ADD_CONDITION;
			case ITM_START:return ADD_START;
			case ITM_END:return ADD_END;
			case ITM_SIMPVAL:return ADD_SIMPVAL;
			case ITM_READ: return ADD_READ;
			case ITM_WRITE:return ADD_WRITE;
			case ITM_CONNECTER:return ADD_CONNECTOR;
			case ITM_EDIT:return EDIT_STAT;
			case ITM_EDITCONN:return EDIT_CONNECTION;
			case ITM_COMMENT:return COMMENT;
			case ITM_SELECT:return SELECT;
			case ITM_SLCMULTSEL:return SLCTMULSEL;
			case ITM_DELETE:return DEL;
			case ITM_MOVE:return MOVE;
			case ITM_SAVE:return SAVE;
			case ITM_RESIZE:return RESIZE;
			case ITM_LOAD:return LOAD;
			case ITM_COPY:return COPY;
			case ITM_PASTE:return PASTE;
			case ITM_CUT:return CUT;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_SIM_MODE : return SIM_MODE;
			case ITM_DRAW_ANYWHERE:return DRAW_ANYWHERE;
			default: return DSN_TOOL;
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
		{
			return DRAW_ANYWHERE;	//user want to select/unselect a statement in the flowchart
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		int ClickedItem = (x / UI.MnItWdth);
		if (y >= 0 && y < UI.TlBrWdth)
			switch (ClickedItem)
			{
			case ITM_EXIT2: return EXIT2;
			case ITM_VALIDATE: return VALIDATE;
			case ITM_RUN:return RUN;
			case ITM_STEP:return STEP;
			case ITM_GENERATE:return GENERATE;
			case ITM_DSN_MODE: return DSN_MODE;
			default: return SIM_MODE;
			}
		
		
		
		//return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}
Input::~Input()
{
}
