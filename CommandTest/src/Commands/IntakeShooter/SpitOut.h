#ifndef SpitOut_H
#define SpitOut_H

#include "CommandBase.h"
#include "WPILib.h"

class SpitOut: public CommandBase
{
	bool finished;
public:
	SpitOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
