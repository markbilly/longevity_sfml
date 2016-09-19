#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Graphics.hpp>
#include "command.h"
#include "camera.h"

class InputHandler {
public:
	InputHandler(sf::RenderWindow* window, Camera* camera);
	~InputHandler();
	void HandleInput();
private:
	sf::RenderWindow* window_;
	Camera* camera_;

	Command* move_up_;
	Command* move_left_;
	Command* move_down_;
	Command* move_right_;
};

#endif
