#include "entity.h"

Entity::Entity(sf::RectangleShape* extent, sf::Sprite* sprite, bool isFixed) {
	sprite_ = sprite;
	bounding_box_ = extent;
	isFixed_ = isFixed;
}

Entity::Entity() {
}

Entity::~Entity() {
}

sf::Vector2f Entity::GetVelocity() {
	return velocity_;
}

sf::Vector2f Entity::GetPosition() {
	return bounding_box_->getPosition();
}

void Entity::Update() {
	if (!isFixed_) {
		// move based on velocity
		sf::Vector2f current_position = bounding_box_->getPosition();
		sf::Vector2f new_position = current_position + velocity_;

		bounding_box_->setPosition(new_position);
	}
}

void Entity::Render(sf::RenderWindow* window) {
	// update sprite position
	sprite_->setPosition(bounding_box_->getPosition());

	// render
	window->draw(*bounding_box_); // TODO: replace with draw sprite
}

bool Entity::IsCollision(sf::FloatRect other_shape_bounds) {
	sf::FloatRect entity_bounds = GetBounds();
	return entity_bounds.intersects(other_shape_bounds);
}

void Entity::SetVelocity(sf::Vector2f velocity) {
	velocity_ = velocity;
}

void Entity::SetPosition(sf::Vector2f position) {
	bounding_box_->setPosition(position);
}

sf::FloatRect Entity::GetBounds() {
	return bounding_box_->getGlobalBounds();
}
