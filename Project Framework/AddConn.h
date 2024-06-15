#pragma once

#include "ApplicationManager.h"
#include "..\Project Framework\Actions\Action.h"
#include"Statements\Connector.h"
#include"Statements\Statement.h"
class AdConnector : public Action
{

private:
	Statement* Src;
	Statement* Dst;
	Point Position;
	bool Ctype;
public:
	AdConnector(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};
