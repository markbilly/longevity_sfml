#include "game.h"

Game::Game() {
	window_ = new sf::RenderWindow(sf::VideoMode(320, 200), "Longevity");
	texture_factory_ = new TextureFactory();
	texture_factory_->RegisterTexture("test", "test.png");

	tile_textures_ = new std::vector<sf::Texture*>();
	tile_textures_->push_back(texture_factory_->CreateTexture("test"));
	tile_textures_->push_back(texture_factory_->CreateTexture("test"));
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

	int pos = 0;
	for (int i = 0; i < tile_textures_->size(); i++) {
		sf::Sprite sprite(*tile_textures_->at(i));
		sprite.setPosition(pos, 0);
		window_->draw(sprite);
		pos += 26;
	}

	window_->display();
}