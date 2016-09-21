#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
	Entity(sf::RectangleShape* extent, sf::Sprite* sprite, bool isFixed);
	Entity();
	~Entity();

	sf::Vector2f GetPosition();
	bool IsCollision(sf::FloatRect other_shape_bounds);
	void SetVelocity(sf::Vector2f velocity);
	sf::FloatRect GetBounds();

	void Update();
	void Render(sf::RenderWindow* window);
protected:
	sf::Sprite* sprite_;
	sf::RectangleShape* bounding_box_;

	// pixels per frame
	sf::Vector2f velocity_;
	bool isFixed_; // TODO: different sub class for fixed/physical entities?
};

#endif