#include "move_commands.h"
#include "entity.h"

void MoveUpCommand::Execute(Entity& entity) {
	entity.Move(0, -1);
}

void MoveLeftCommand::Execute(Entity& entity) {
	entity.Move(-1, 0);
}

void MoveDownCommand::Execute(Entity& entity) {
	entity.Move(0, 1);
}

void MoveRightCommand::Execute(Entity& entity) {
	entity.Move(1, 0);
}