#include "player.h"

Player::Player() {
	bounding_box_.setSize(sf::Vector2f(16, 32));
	bounding_box_.setPosition(16, 0);
	bounding_box_.setFillColor(sf::Color::Blue);
}

Player::~Player() {
}

void Player::Move(int offset_x, int offset_y) {
	// move bounding box
	sf::Vector2f start_position = bounding_box_.getPosition();
	sf::Vector2f new_position = start_position + sf::Vector2f((float)offset_x, (float)offset_y);
	bounding_box_.setPosition(new_position);
}