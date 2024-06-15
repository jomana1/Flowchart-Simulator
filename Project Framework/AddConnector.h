#pragma once


#include "..\Project Framework\Actions\Action.h"
#include"Statements\Connector.h"
#include"Statements\Statement.h"
class AddConnector : public Action
{

private:
	Statement* Src;
	Statement* Dst;
	Point Position;
public:
	AddConnector(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};
