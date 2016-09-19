#include "test_command.h"

void TestCommand::Execute(Camera & camera) {
	camera.Move(2, 2);
}