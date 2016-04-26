#include "game.h"

Game::Game() {
	window_ = new sf::RenderWindow(sf::VideoMode(320, 200), "Longevity");
	texture_factory_ = new TextureFactory();
	texture_factory_->RegisterTexture("test", "test.png");
	tile_texture_ = texture_factory_->CreateTexture("test");
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
}

void Game::Render() {
	window_->clear();

	sf::Sprite sprite;
	sprite.setTexture(*tile_texture_);
	window_->draw(sprite);

	window_->display();
}