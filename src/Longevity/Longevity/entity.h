#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
	void Move(int offset_x, int offset_y);
	sf::Vector2f GetPosition();
	void Render(sf::RenderWindow* window);
	sf::RectangleShape bounding_box_;
protected:
	Entity();
	sf::Sprite sprite_;
};

#endif