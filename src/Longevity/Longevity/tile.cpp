#include "tile.h"

Tile::Tile() {

}

Tile::~Tile() {
}

sf::Sprite Tile::GetSprite(std::string image) {
	sf::Texture texture;
	texture.loadFromFile(image);
	sprite_.setTexture(texture);
	return sprite_;
}
