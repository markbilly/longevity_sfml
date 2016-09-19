#include "input_handler.h"
#include "move_commands.h"
#include "player.h"

InputHandler::InputHandler(sf::RenderWindow* window, Player* player) {
	window_ = window;
	player_ = player;

	move_up_ = new MoveUpCommand();
	move_left_ = new MoveLeftCommand();
	move_down_ = new MoveDownCommand();
	move_right_ = new MoveRightCommand();
}

InputHandler::~InputHandler() {
	delete move_up_;
	delete move_left_;
	delete move_down_;
	delete move_right_;
}

void InputHandler::HandleInput() {
	sf::Event event;

	while (window_->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window_->close();
		}

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::W) {
				move_up_->Execute(*player_);
			}

			if (event.key.code == sf::Keyboard::A) {
				move_left_->Execute(*player_);
			}

			if (event.key.code == sf::Keyboard::S) {
				move_down_->Execute(*player_);
			}

			if (event.key.code == sf::Keyboard::D) {
				move_right_->Execute(*player_);
			}
		}
	}
}