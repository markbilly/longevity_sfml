#include "camera.h"

Camera::Camera(sf::RenderWindow* window, sf::FloatRect view_size) {
	window_ = window;
	view_ = new sf::View(view_size);

	Move(0.0f, 0.0f);
}

Camera::~Camera() {
	delete boundary_;
	delete window_;
}

void Camera::SetBoundary(sf::FloatRect boundary) {
	boundary_ = &boundary;
}

void Camera::Move(float offset_x, float offset_y) {
	window_->setView(*view_);
	view_->move(offset_x, offset_y);
}
