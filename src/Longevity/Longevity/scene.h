#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "texture_factory.h"

class Scene {
public:
	Scene(TextureFactory* texture_factory);
	~Scene();
	void Render(sf::RenderWindow* window);
private:
	std::vector<std::vector<int>*>* tile_map_;
	TextureFactory* texture_factory_;
};

#endif