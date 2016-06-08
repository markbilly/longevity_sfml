#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "texture_factory.h"

class Scene {
public:
	Scene(TextureFactory* texture_factory);
	~Scene();
	void Render(sf::RenderWindow* window);
	std::map<std::string, std::string>* GetAttributes();
	void SetTileMap(std::vector<std::vector<int>*>* tile_map);
	void AddAttribute(std::string key, std::string value);
private:
	std::vector<std::vector<int>*>* tile_map_;
	TextureFactory* texture_factory_;
	std::map<std::string, std::string>* attributes_;
};

#endif