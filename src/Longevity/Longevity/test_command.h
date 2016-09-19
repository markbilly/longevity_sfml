#ifndef TESTCOMMAND_H
#define TESTCOMMAND_H

#include "command.h"
#include "camera.h"

class TestCommand : public Command {
public:
	virtual void Execute(Camera& camera);
};

#endif
