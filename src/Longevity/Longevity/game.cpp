#include "game.h"

Game::Game() {
	window_ = new sf::RenderWindow(sf::VideoMode(320, 240), "Longevity");
	texture_factory_ = new TextureFactory();
	texture_factory_->RegisterTexture("test", "test.png");

	scene_ = new Scene(texture_factory_, "test_map.txt");
}

Game::~Game() {
	delete window_;
	delete scene_;
	delete texture_factory_;
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

	scene_->Render(window_);

	window_->display();
}