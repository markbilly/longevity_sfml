#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include "entity.h"

class Camera {
public:
	Camera(sf::RenderWindow* window, sf::IntRect view_size);
	~Camera();
	void SetBoundary(int width, int height);
	void Update();
	void SetTarget(Entity* target);
private:
	Entity* target_;
	sf::View* view_;
	sf::RenderWindow* window_;
	sf::IntRect* boundary_;
	sf::Vector2f Camera::GetAdjustedEndWithinBoundary(sf::Vector2f start, sf::Vector2f end);
};

#endif