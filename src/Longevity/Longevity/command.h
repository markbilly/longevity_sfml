#ifndef COMMAND_H
#define COMMAND_H

#include "entity.h"

class Command {
public:
	virtual ~Command() {}
	virtual void Execute(Entity& entity) = 0;
};

#endif
