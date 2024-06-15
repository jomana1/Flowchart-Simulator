#pragma once
#include "..\Project Framework\Actions\Action.h"
class Save : public Action
{
	string fileName;
public:
	Save(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();

	~Save();
};

