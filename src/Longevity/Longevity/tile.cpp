#include "tile.h"

Tile::Tile(std::string fileName) {
	sprite_texture_ = sf::Texture();
	sprite_texture_.loadFromFile(fileName);
	
	sprite_ = sf::Sprite(sprite_texture_);
}

Tile::~Tile() {
}

sf::Sprite* Tile::GetSprite() {
	return &sprite_;
}
