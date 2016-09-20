#include "entity.h"

Entity::Entity() {
}

sf::Vector2f Entity::GetPosition() {
	return bounding_box_.getPosition();
}

void Entity::Update() {
	// move based on velocity
	sf::Vector2f current_position = bounding_box_.getPosition();
	sf::Vector2f new_position = current_position + velocity_;

	bounding_box_.setPosition(new_position);
}

void Entity::Render(sf::RenderWindow* window) {
	// update sprite position
	sprite_.setPosition(bounding_box_.getPosition());

	// render
	window->draw(bounding_box_); // TODO: replace with draw sprite
}

bool Entity::IsCollision(sf::IntRect other_shape_bounds) {
	return bounding_box_.getTextureRect().intersects(other_shape_bounds);
}

void Entity::SetVelocity(sf::Vector2f velocity) {
	velocity_ = velocity;
}
