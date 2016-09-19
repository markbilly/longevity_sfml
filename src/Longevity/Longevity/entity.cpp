#include "entity.h"

Entity::Entity() {
}

void Entity::Move(int offset_x, int offset_y) {
	// move bounding box
	sf::Vector2f start_position = bounding_box_.getPosition();
	sf::Vector2f new_position = start_position + sf::Vector2f((float)offset_x, (float)offset_y);
	bounding_box_.setPosition(new_position);
}

sf::Vector2f Entity::GetPosition() {
	return bounding_box_.getPosition();
}

void Entity::Render(sf::RenderWindow* window) {
	// update sprite position
	sprite_.setPosition(bounding_box_.getPosition());

	// render
	window->draw(bounding_box_); // TODO: replace with draw sprite
}