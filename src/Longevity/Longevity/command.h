#ifndef COMMAND_H
#define COMMAND_H

#include "player.h"

class Command {
public:
	virtual ~Command() {}
	virtual void Execute(Player& entity) = 0;
};

#endif
