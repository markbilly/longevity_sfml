#include "scene.h"

Scene::Scene(TextureFactory* texture_factory) {
	texture_factory_ = texture_factory;
	attributes_ = new std::map<std::string, std::string>();
}

Scene::~Scene() {
	delete tile_map_;
	delete texture_factory_;
	delete attributes_;
}

void Scene::Render(sf::RenderWindow* window) {
	int total_rows = tile_map_->size();
	int total_cols = tile_map_->at(0)->size();
	int pos[2] = { 0, 0 };

	for (int row = 0; row < total_rows; row++) {
		for (int col = 0; col < total_cols; col++) {
			sf::Texture texture = *texture_factory_->CreateTexture("test");
			sf::Sprite sprite(texture);
			sprite.setPosition(pos[0], pos[1]);

			if (tile_map_->at(row)->at(col) > 0) {
				window->draw(sprite);
			}

			pos[0] += 16;			
		}
		pos[0] = 0;
		pos[1] += 16;
	}
}

std::map<std::string, std::string>* Scene::GetAttributes() {
	return attributes_;
}

void Scene::SetTileMap(std::vector<std::vector<int>*>* tile_map) {
	tile_map_ = tile_map;
}

void Scene::AddAttribute(std::string key, std::string value) {
	// check for attribute
	std::map<std::string, std::string>::iterator iterator = attributes_->find(key);
	if (iterator == attributes_->end()) {
		// add if not found
		attributes_->insert(std::pair<std::string, std::string>(key, value));
	}
}
