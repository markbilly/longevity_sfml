#include "game.h"

Game::Game() {
	circle_radius_ = 0.0f;
	circle_ = sf::CircleShape(circle_radius_);
	circle_.setFillColor(sf::Color::Green);
	window_ = new sf::RenderWindow(sf::VideoMode(320, 200), "Longevity");
	textures_ = new std::vector<sf::Texture*>();

	sf::Texture* test_texture = new sf::Texture();
	test_texture->loadFromFile("test.png");
	textures_->push_back(test_texture);
}

Game::~Game() {
	delete window_;
}

sf::RenderWindow* Game::GetWindow() {
	return window_;
}

void Game::ProcessInput() {

}

void Game::Update() {
	circle_radius_ += 0.1f;
	circle_.setRadius(circle_radius_);
}

void Game::Render() {
	window_->clear();
	window_->draw(circle_);

	//sf::Texture texture;
	//texture.loadFromFile("test.png");

	sf::Sprite sprite;
	sprite.setTexture(*textures_->at(0));

	window_->draw(sprite);

	window_->display();
}