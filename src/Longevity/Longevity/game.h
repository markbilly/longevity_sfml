#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "tile.h"
#include "texture_factory.h"

class Game {
public:
	Game();
	~Game();
	sf::RenderWindow* GetWindow();
	void ProcessInput();
	void Update();
	void Render();
private:
	Tile tile_;
	sf::RenderWindow* window_;
	TextureFactory* texture_factory_;
	std::vector<sf::Texture*>* tile_textures_;
};

#endif
