#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
public:
	Tile();
	~Tile();
	sf::Sprite GetSprite(std::string image);
private:
	sf::Sprite sprite_;
};

#endif