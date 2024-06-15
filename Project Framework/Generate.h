#pragma once
#include "..\Project Framework\Actions\Action.h"
#include "..\Project Framework\ApplicationManager.h"

class Generate : public Action
{
private:
	Point Position;
	Statement* Stat;
public:
	Generate(ApplicationManager* pAppManager);


	virtual void ReadActionParameters();


	virtual void Execute();
};
