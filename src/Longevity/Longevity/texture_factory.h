#ifndef TEXTURE_FACTORY_H
#define TEXTURE_FACTORY_H

#include <SFML/Graphics.hpp>

class TextureFactory {
public:
	TextureFactory();
	~TextureFactory();
	sf::Texture* CreateTexture(std::string code);
	void RegisterTexture(std::string code, std::string fileName);
private:
	std::map<std::string, sf::Texture*>* textures_;
	std::map<std::string, std::string>* map_;
	std::string GetFileNameFromMap(std::string code);
};

#endif