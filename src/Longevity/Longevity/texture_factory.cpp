#include "texture_factory.h"

TextureFactory::TextureFactory() {
	textures_ = new std::map<std::string, sf::Texture*>();
	resource_map_ = new std::map<std::string, std::string>();
}

TextureFactory::~TextureFactory() {
	textures_->clear();
	delete textures_;
}

sf::Texture* TextureFactory::CreateTexture(std::string code) {
	// check for texture
	std::map<std::string, sf::Texture*>::iterator iterator = textures_->find(code);
	if (iterator == textures_->end()) {
		// not found
		sf::Texture* new_texture = new sf::Texture();
		new_texture->loadFromFile(GetFileNameFromMap(code)); // TODO: what if code does not get a file name
		textures_->insert(std::pair<std::string, sf::Texture*>(code, new_texture));
		return new_texture;
	}
	else {
		// found
		return iterator->second;
	}
}

void TextureFactory::RegisterTexture(std::string code, std::string fileName) {
	resource_map_->insert(std::pair<std::string, std::string>(code, fileName));
}

std::string TextureFactory::GetFileNameFromMap(std::string code) {
	// check for file name
	std::map<std::string, std::string>::iterator iterator = resource_map_->find(code);
	if (iterator != resource_map_->end()) {
		// found
		return iterator->second;
	}

	return 0;
}
