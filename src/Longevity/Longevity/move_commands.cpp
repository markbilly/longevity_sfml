#include "move_commands.h"
#include "player.h"

void MoveUpCommand::Execute(Player& entity) {
	entity.Move(0, -1);
}

void MoveLeftCommand::Execute(Player& entity) {
	entity.Move(-1, 0);
}

void MoveDownCommand::Execute(Player& entity) {
	entity.Move(0, 1);
}

void MoveRightCommand::Execute(Player& entity) {
	entity.Move(1, 0);
}