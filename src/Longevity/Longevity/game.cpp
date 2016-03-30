#include "game.h"

Game::Game() {
	circle_radius_ = 0.0f;
	circle_ = sf::CircleShape(circle_radius_);
	circle_.setFillColor(sf::Color::Green);
}

Game::~Game() {

}

sf::RenderWindow* Game::GetWindow() {
	sf::RenderWindow window(sf::VideoMode(320, 200), "Longevity");
	return &window;
}

void Game::ProcessInput() {

}

void Game::Update() {
	circle_radius_ += 0.1f;
	circle_.setRadius(circle_radius_);
}

void Game::Render(sf::RenderWindow *window) {
	window->clear();
	window->draw(circle_);
	window->display();
}