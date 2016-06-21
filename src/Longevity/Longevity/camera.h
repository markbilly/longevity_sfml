#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

class Camera {
public:
	Camera(sf::RenderWindow* window, sf::IntRect view_size);
	~Camera();
	void SetBoundary(int width, int height);
	void Move(int offset_x, int offset_y);
private:
	sf::View* view_;
	sf::RenderWindow* window_;
	sf::IntRect* boundary_;
	sf::Vector2f Camera::GetAdjustedEndWithinBoundary(sf::Vector2f start, sf::Vector2f end);
};

#endif