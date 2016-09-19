#include "input_handler.h"
#include "test_command.h"

InputHandler::InputHandler(sf::RenderWindow* window, Camera* camera) {
	window_ = window;
	camera_ = camera;

	move_up_ = new TestCommand();
	move_left_ = new TestCommand();
	move_down_ = new TestCommand();
	move_right_ = new TestCommand();
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
				move_up_->Execute(*camera_);
			}

			if (event.key.code == sf::Keyboard::A) {
				move_left_->Execute(*camera_);
			}

			if (event.key.code == sf::Keyboard::S) {
				move_down_->Execute(*camera_);
			}

			if (event.key.code == sf::Keyboard::D) {
				move_right_->Execute(*camera_);
			}
		}
	}
}