#include "camera.h"

Camera::Camera(sf::RenderWindow* window, sf::IntRect view_size) {
	window_ = window;
	view_ = new sf::View(sf::FloatRect(view_size));
	SetBoundary(view_size.width, view_size.height);

	Move(0, 0);
}

Camera::~Camera() {
	delete boundary_;
}

void Camera::SetBoundary(int width, int height) {
	boundary_ = new sf::IntRect(0, 0, width, height);
}

void Camera::Move(int offset_x, int offset_y) {
	window_->setView(*view_);

	sf::Vector2f centre = view_->getCenter();
	sf::Vector2f view_size = view_->getSize();

	int distance_to_edge_x = boundary_->width - ((int)view_size.x / 2) - (int)centre.x - offset_x;
	int distance_to_edge_y = boundary_->height - ((int)view_size.y / 2) - (int)centre.y - offset_y;

	// TODO: deal with negative offsets

	if (distance_to_edge_x <= 0) {
		offset_x = 0;
	}

	if (distance_to_edge_y <= 0) {
		offset_y = 0;
	}

	view_->move((float)offset_x, (float)offset_y);
}
