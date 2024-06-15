#ifndef DEFS_H
#define DEFS_H

//This file contais some global constants and definitions to be used in the project.

enum ActionType //The actions supported (you can add more if needed)
{
	EXIT, //Exit the application
	ADD_SMPL_ASSIGN,//Add simple assignment statement
	ADD_VAR_ASSIGN,	//Add variable assignment statement
	ADD_OPR_ASSIGN,
	ADD_CONDITION, //Add a conditional statement (for if and while-loop statements)
	ADD_START, //ADD A START
	ADD_END, // ADD A END
	ADD_SIMPVAL, //ADD A SIMPLE VALUE ASSIGNMET
	ADD_READ,
	ADD_WRITE,
	ADD_CONNECTOR, //Add a connector between two statements

	EDIT_STAT,	//Edit a statement
	EDIT_CONNECTION,
	COMMENT, //TO ADD COMMENTS
	SELECT,		//Select a statement, a connector
	SLCTMULSEL, //select multiple cells

	DEL,		//Delete a figure(s)
	MOVE,		//Move a figure(s)
	RESIZE,		//Resize a figure(s)

	SAVE,		//Save all
	LOAD,		//Load a graph from a file
	COPY,
	PASTE,
	CUT,
	UNDO,
	REDO,

		
	STATUS,		//A click on the status bar


	EXIT2,   //Exit the simulation tool bar
	VALIDATE,
	RUN,	//Run
	STEP,	//Step by step
	GENERATE,
	DSN_MODE,    //Switch to Design mode
	DSN_TOOL,	//A click on an empty place in the design tool bar		
	SIM_MODE,   //Switch to simulatiom mode
	DRAW_ANYWHERE,
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you change the menu items order, change the order here too
	ITM_EXIT,
	ITM_SMPL_ASSIGN,//simple assignment statement
	ITM_VAR_ASSIGN,
	ITM_OPR_ASSIGN,
	ITM_COND,		//conditional statement
	ITM_START,
	ITM_END,
	ITM_SIMPVAL,
	ITM_READ,
	ITM_WRITE,
	ITM_CONNECTER,
	ITM_EDIT,
	ITM_EDITCONN,//EDIT A CONNECTION
	ITM_COMMENT,
	ITM_SELECT, //SELECT  UNSELECT
	ITM_SLCMULTSEL, //select multiple items
	ITM_DELETE,
	ITM_MOVE,
	ITM_SAVE,
	ITM_RESIZE,
	ITM_LOAD,
	ITM_COPY,
	ITM_PASTE, // COPY CUT PASTE
	ITM_CUT,
	ITM_UNDO,
	ITM_REDO,
	ITM_SIM_MODE,
	ITM_DRAW_ANYWHERE,

	
	
	//TODO: Add more items names here
	
	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	
};

enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_EXIT2,
	ITM_VALIDATE,
	ITM_RUN,	//Run
	ITM_STEP,	//Step by step
	ITM_GENERATE,
	ITM_DSN_MODE,

	//TODO:Add more items names here
	
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
};

#ifndef NULL
#define NULL 0
#endif

#endif