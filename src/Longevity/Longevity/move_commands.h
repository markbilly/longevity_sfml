#ifndef MOVECOMMANDS_H
#define MOVECOMMANDS_H

#include "command.h"

class MoveUpCommand : public Command {
public:
	virtual void Execute(Player& entity);
};

class MoveLeftCommand : public Command {
public:
	virtual void Execute(Player& entity);
};

class MoveDownCommand : public Command {
public:
	virtual void Execute(Player& entity);
};

class MoveRightCommand : public Command {
public:
	virtual void Execute(Player& entity);
};

#endif
