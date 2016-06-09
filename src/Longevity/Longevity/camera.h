#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

class Camera {
public:
	Camera(sf::RenderWindow* window, sf::FloatRect view_size);
	~Camera();
	void SetBoundary(sf::FloatRect boundary);
	void Move(float offset_x, float offset_y);
private:
	sf::View* view_;
	sf::RenderWindow* window_;
	sf::FloatRect* boundary_;
};

#endif