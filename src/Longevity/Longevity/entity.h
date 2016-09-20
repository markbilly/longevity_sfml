#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
	sf::Vector2f GetPosition();
	bool IsCollision(sf::FloatRect other_shape_bounds);
	void SetVelocity(sf::Vector2f velocity);

	void Update();
	void Render(sf::RenderWindow* window);
protected:
	Entity();
	sf::Sprite sprite_;
	sf::RectangleShape bounding_box_;

	// pixels per frame
	sf::Vector2f velocity_;
};

#endif