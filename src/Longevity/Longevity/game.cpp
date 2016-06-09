#include "game.h"
#include "scene_loader.h"

Game::Game() {
	window_ = new sf::RenderWindow(sf::VideoMode(640, 480), "Longevity"); // change window size to scale
	
	view_ = new sf::View(sf::FloatRect(0, 0, 320, 240)); // view size is 1:1 scale
	window_->setView(*view_);

	texture_factory_ = new TextureFactory();
	texture_factory_->RegisterTexture("test", "test.png");

	scene_ = new Scene(texture_factory_);
	SceneLoader scene_loader = SceneLoader();
	scene_loader.Load("test_map.txt", *scene_);
}

Game::~Game() {
	delete view_;
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