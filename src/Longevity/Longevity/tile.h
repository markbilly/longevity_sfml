#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
public:
	Tile(std::string fileName);
	~Tile();
	sf::Sprite* GetSprite();
private:
	sf::Texture sprite_texture_;
	sf::Sprite sprite_;
};

#endif