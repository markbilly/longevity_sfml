#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "texture_factory.h"
#include "entity.h"

class Scene {
public:
	Scene(TextureFactory* texture_factory);
	~Scene();

	void Render(sf::RenderWindow* window);
	void Update();

	void AddEntity(Entity* entity);
	std::map<std::string, std::string>* GetAttributes();
	void SetTileMap(std::vector<std::vector<int>*>* tile_map);
	void AddAttribute(std::pair<std::string, std::string> key_value_pair);
	sf::IntRect Scene::GetSizeInPixels();
private:
	std::vector<std::vector<int>*>* tile_map_;
	TextureFactory* texture_factory_;
	std::map<std::string, std::string>* attributes_;
	std::vector<Entity*> entities_;
};

#endif