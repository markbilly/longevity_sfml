#include "player.h"

Player::Player() {
	bounding_box_.setSize(sf::Vector2f(16, 32));
	bounding_box_.setPosition(16, 0);
	bounding_box_.setFillColor(sf::Color::Blue);
}

Player::~Player() {
}