#include "camera.h"

Camera::Camera(sf::RenderWindow* window, sf::IntRect view_size) {
	window_ = window;
	view_ = new sf::View(sf::FloatRect(view_size));
	SetBoundary(view_size.width, view_size.height);
}

Camera::~Camera() {
	delete boundary_;
}

void Camera::SetBoundary(int width, int height) {
	boundary_ = new sf::IntRect(0, 0, width, height);
}

void Camera::Update() {
	if (target_ != nullptr) {
		window_->setView(*view_);

		sf::Vector2f camera_center = view_->getCenter();
		sf::Vector2f target_center = target_->GetPosition();

		sf::Vector2f new_camera_center = GetAdjustedEndWithinBoundary(camera_center, target_center);
		view_->setCenter(new_camera_center);
	}
}

void Camera::SetTarget(Entity * target) {
	target_ = target;
}

sf::Vector2f Camera::GetAdjustedEndWithinBoundary(sf::Vector2f start, sf::Vector2f end) {
	sf::Vector2f view_size = view_->getSize();

	int min_center_for_boundary_x = ((int)view_size.x / 2);
	int max_center_for_boundary_x = boundary_->width - ((int)view_size.x / 2);

	int min_center_for_boundary_y = ((int)view_size.y / 2);
	int max_center_for_boundary_y = boundary_->height - ((int)view_size.y / 2);

	if (end.x > max_center_for_boundary_x || end.x < min_center_for_boundary_x) {
		end.x = start.x;
	}

	if (end.y > max_center_for_boundary_y || end.y < min_center_for_boundary_y) {
		end.y = start.y;
	}

	return end;
}
