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
	sf::Vector2f new_centre = centre + sf::Vector2f(offset_x, offset_y);
	sf::Vector2f view_size = view_->getSize();

	int min_centre_for_boundary_x = ((int)view_size.x / 2);
	int max_centre_for_boundary_x = boundary_->width - ((int)view_size.x / 2);

	int min_centre_for_boundary_y = ((int)view_size.y / 2);
	int max_centre_for_boundary_y = boundary_->height - ((int)view_size.y / 2);

	if (new_centre.x > max_centre_for_boundary_x || new_centre.x < min_centre_for_boundary_x) {
		offset_x = 0;
	}

	if (new_centre.y > max_centre_for_boundary_y || new_centre.y < min_centre_for_boundary_y) {
		offset_y = 0;
	}

	view_->move((float)offset_x, (float)offset_y);
}
