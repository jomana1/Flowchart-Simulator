#pragma once
#include "..\Project Framework\Actions\Action.h"
#include "..\Project Framework\ApplicationManager.h"

class Load : public Action
{
private:
	string FileName;

public:
	Load(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};

