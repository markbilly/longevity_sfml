#ifndef COMMAND_H
#define COMMAND_H

#include "camera.h"

class Command {
public:
	virtual ~Command() {}
	virtual void Execute(Camera& camera) = 0;
};

#endif
