#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "texture_factory.h"

class Scene {
public:
	Scene();
	~Scene();
	void Render();
private:
	std::vector<std::vector<int>*>* tile_map_;
};

#endif